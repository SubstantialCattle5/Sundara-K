/**
 * HTTPRequest.h declaration file for HTTPRequest.c file
 * 
 * Created by nilay 
 * 16th December 2023
 */

#ifndef HTTPRequest_h
#define HTTPRequest_h

#include "../../DataStructure/Dictionary/Dictionary.h"

// MARK: DATA TYPES

struct HTTPRequest
{
    struct Dictionary request_line;
    struct Dictionary header_fields;
    struct Dictionary body;
    
    /**
     * Search for a key in the request object.
     * @param request - the request object
     * @param key - the key to search for
     * @return void pointer to the value if found, NULL if not
    */
    void *(*http_request_search)(struct HTTPRequest *request, char *key);

};

// MARK: CONSTRUCTORS

struct HTTPRequest http_request_constructor(char *request_string);
void http_request_destructor(struct HTTPRequest *request);


#endif /* HTTPRequest_h */