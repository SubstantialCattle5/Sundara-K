/**
 *
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
};

// MARK: CONSTRUCTORS

struct HTTPRequest http_request_constructor(char *request_string);
void http_request_destructor(struct HTTPRequest *request);


#endif /* HTTPRequest_h */