/*
 * Released under the terms of the Apache license.
 *
 * Author:
 *     Richard Zak <richard.j.zak@gmail.com>
 */

#include<string.h>
#include "strtok.h"

char* strtok_ng(const char* haystack, const size_t haystack_len, const char* delim, size_t *pos, size_t *next) {
    if (*pos >= haystack_len)
        return NULL;
    size_t i;
    char* start = (char*) haystack + *pos;
    const size_t delim_len = strlen(delim);

    while(*pos <= haystack_len) {
        char found = 1; // true
        for(i = 0; i < delim_len; i++) {
            if (haystack[(*pos)+i] != delim[i]) {
                found = 0; // false
                break;
            }
        }

        (*pos) += 1;

        if (found) {
            (*pos) += delim_len-1;
            if (next != NULL) {
                size_t counter = 0;
                size_t new_len = strlen(start);
                while(counter <= new_len) {
                    char found_again = 1; // true
                    for(i = 0; i < delim_len; i++) {
                        if (start[counter+i] != delim[i]) {
                            found_again = 0; // false
                            break;
                        }
                    }

                    if (found_again) {
                        break;
                    }
                    counter += 1;
                }
                *next = counter;
            }

            return start;
        }
    }

    if (next != NULL) {
        // if we've gotten here, then we must be at the last token
        *next = strlen(start);
    }

    return start;
}


char* strtok_ng_last(const char* haystack, const size_t haystack_len, const char* delim) {
    size_t pos = 0;
    char* segment = strtok_ng(haystack, haystack_len, delim, &pos, NULL);
    char* last = segment;
    while(segment != NULL) {
        last = segment;
        segment = strtok_ng(haystack, haystack_len, delim, &pos, NULL);
    }
    return last;
}
