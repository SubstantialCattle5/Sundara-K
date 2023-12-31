/**

 * 
 * HTTPRequest.c created for the networking library. 
 * Meant to handle the HTTP request and parse it into a data structure.
 * 
 * Created by Nilay Nath on 16th December 23.
 * 
*/
//

#include "HTTPRequest.h"

#include "../../DataStructure/list/Queue.h"

#include <string.h>
#include <stdlib.h>


/**
 * 
 * HTTPRequest is a data structure that represents an HTTP request.
 * It is composed of three dictionaries: request_line, header_fields, and body.
 * The request_line dictionary contains the method, uri, and http_version.
 * The header_fields dictionary contains the key value pairs of the header fields.
 * The body dictionary contains the key value pairs of the body.
 * 
 * Also has a search function that searches for a key in the request_line, header_fields, and body.
 * It provides a better user experince since user don't really need to search through different sections since for
 * them it should feel like one function.
 * 
*/


// MARK: PRIVATE MEMBER METHODS

// Functions for extracting the constituent elements from a request string.
void extract_request_line_fields(struct HTTPRequest *request, char *request_line);
void extract_header_fields(struct HTTPRequest *request, char *header_fields);
void extract_body(struct HTTPRequest *request, char *body);

// MARK: PUBLIC MEMBER METHODS
// function to the search the key in the request_line, header_fields, and body.
void *http_request_search(struct HTTPRequest *request, char *key);


// MARK: CONSTRUCTORS

// Creates an initialized instance of an HTTPRequest using a properly formatted string.
struct HTTPRequest http_request_constructor(char *request_string)
{
    // New request object.
    struct HTTPRequest request;
    request.http_request_search = http_request_search;

    // Convert from string literal and replace the blank line with a vertical |
    char requested[strlen(request_string)];
    strcpy(requested, request_string);
    for (int i = 0; i < strlen(requested) - 2; i++)
    {
        if (requested[i] == '\n' && requested[i + 1] == '\n')
        {
            // This makes it possible to separate header fields from the request body.
            requested[i + 1] = '|';
        }
    }
    // Separate the request string.
    char *request_line = strtok(requested, "\n");
    printf("Request line: %s\n", request_line);
    char *header_fields = strtok(NULL, "|");
    char *body = strtok(NULL, "|");

    // Parse each section as needed.
    extract_request_line_fields(&request, request_line);
    extract_header_fields(&request, header_fields);
    extract_body(&request, body);
    // Return the final product.
    return request;
};

// Destroy a request by freeing the memory in each constituent dictionary.
void http_request_destructor(struct HTTPRequest *request)
{
    dictionary_destructor(&request->request_line);
    dictionary_destructor(&request->header_fields);
    dictionary_destructor(&request->body);
}

// MARK: PRIVATE MEMBER METHODS

// Parses out the request line to retrieve the method, uri, and http version.
void extract_request_line_fields(struct HTTPRequest *request, char *request_line)
{
    // Copy the string literal into a local instance.
    char fields[strlen(request_line)];
    strcpy(fields, request_line);
    // Separate the string on spaces for each section.
    char *method = strtok(fields, " ");
    char *uri = strtok(NULL, " ");
    char *http_version = strtok(NULL, "\0");
    // Insert the results into the request object as a dictionary.
    struct Dictionary request_line_dict = dictionary_constructor(compare_string_keys);
    request_line_dict.insert(&request_line_dict, "method", sizeof("method"), method, sizeof(char[strlen(method)]));
    request_line_dict.insert(&request_line_dict, "uri", sizeof("uri"), uri, sizeof(char[strlen(uri)]));
    request_line_dict.insert(&request_line_dict, "http_version", sizeof("http_version"), http_version, sizeof(char[strlen(http_version)]));
    // Save the dictionary to the request object.
    request->request_line = request_line_dict;
    if (request->request_line.search(&request->request_line, "GET", sizeof("GET")))
    {
        extract_body(request, (char *)request->request_line.search(&request->request_line, "uri", sizeof("uri")));
    }
}

// Parses out the header fields.
void extract_header_fields(struct HTTPRequest *request, char *header_fields)
{
    // Copy the string literal into a local instance.
    char fields[strlen(header_fields)];
    strcpy(fields, header_fields);
    // Save each line of the input into a queue.
    struct Queue headers = queue_constructor();
    char *field = strtok(fields, "\n");
    while (field)
    {
        headers.push(&headers, field, sizeof(char[strlen(field)]));
        field = strtok(NULL, "\n");
    }
    // Initialize the request's header_fields dictionary.
    request->header_fields = dictionary_constructor(compare_string_keys);
    // Use the queue to further extract key value pairs.
    char *header = (char *)headers.peek(&headers);
    while (header)
    {
        char *key = strtok(header, ":");
        char *value = strtok(NULL, "\0");
        if (value)
        {
            // Remove leading white spaces.
            if (value[0] == ' ')
            {
                value++;
            }
            // Push the key value pairs into the request's header_fields dictionary.
            request->header_fields.insert(&request->header_fields, key, sizeof(char[strlen(key)]), value, sizeof(char[strlen(value)]));
            // Collect the next field from the queue.
        }
        headers.pop(&headers);
        header = (char *)headers.peek(&headers);
    }
    printf("Header fields: %s\n", (char *)request->header_fields.search(&request->header_fields, "Host", sizeof("Host")));
    // Destroy the queue.
    queue_destructor(&headers);
}

// Parses the body according to the content type specified in the header fields.
void extract_body(struct HTTPRequest *request, char *body)
{
    // Check what content type needs to be parsed
    char *content_type = (char *)request->header_fields.search(&request->header_fields, "Content-Type", sizeof("Content-Type"));
    if (content_type)
    {
        // Initialize the body_fields dictionary.
        struct Dictionary body_fields = dictionary_constructor(compare_string_keys);
        if (strcmp(content_type, "application/x-www-form-urlencoded") == 0)
        {
            // Collect each key value pair as a set and store them in a queue.
            struct Queue fields = queue_constructor();
            char *field = strtok(body, "&");
            while (field)
            {
                fields.push(&fields, field, sizeof(char[strlen(field)]));
            }
            // Iterate over the queue to further separate keys from values.
            field = fields.peek(&fields);
            while (field)
            {
                char *key = strtok(field, "=");
                char *value = strtok(NULL, "\0");
                // Remove unnecessary leading white space.
                if (value[0] == ' ')
                {
                    value++;
                }
                // Insert the key value pair into the dictionary.
                body_fields.insert(&body_fields, key, sizeof(char[strlen(key)]), value, sizeof(char[strlen(value)]));
                // Collect the next item in the queue.
                fields.pop(&fields);
                field = fields.peek(&fields);
            }
            // Destroy the queue.
            queue_destructor(&fields);
        }
        else
        {
            // Save the data as a single key value pair.
            body_fields.insert(&body_fields, "data", sizeof("data"), body, sizeof(char[strlen(body)]));
        }
        // Set the request's body dictionary.
        request->body = body_fields;
    }
}

// MARK: PUBLIC MEMBER METHODS

void *http_request_search(struct HTTPRequest *request, char *key)
{
    // Array of pointers to the search spaces (request line, header fields, body)
    unsigned long size = sizeof(char[strlen(key)]);
    char *searchSpaces[] = {
        (char *)request->request_line.search(&request->request_line, key, size),
        (char *)request->header_fields.search(&request->header_fields, key, size),
        (char *)request->body.search(&request->body, key, size)};

    // Iterate through the search spaces
    for (int i = 0; i < sizeof(searchSpaces) / sizeof(searchSpaces[0]); i++)
    {
        if (searchSpaces[i])
        {
            return searchSpaces[i];
        }
    }

    // If not found in any section, return NULL
    return NULL;
}
