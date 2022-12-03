/*
 * Released under the terms of the Apache license.
 *
 * Author:
 *     Richard Zak <richard.j.zak@gmail.com>
 */

#ifndef _STRTOK_H__
#define _STRTOK_H__

#include<stddef.h>

/**
 * A string tokenizer function which aims to be thread-safe.
 *
 * @param haystack is the string containing the data to be tokenized
 * @param haystack_len is the size of the haystack
 * @param delim is the delimiter, can be multiple characters
 * @param pos is a pointer where the initial value is zero, used for bookkeeping to know where to start next
 * @param next is an optional pointer which indicates the size of the returned string
 * @return the offset string from the original buffer containing the next token
 */
char* strtok_ng(const char* haystack, const size_t haystack_len, const char* delim, size_t *pos, size_t *next);

/**
 * A string tokenizer function which aims to be thread-safe, returns pointer to the last token
 *
 * @param haystack is the string containing the data to be tokenized
 * @param haystack_len is the size of the haystack
 * @param delim is the delimiter, can be multiple characters
 * @return the offset string from the original buffer containing the last token
 */
char* strtok_ng_last(const char* haystack, const size_t haystack_len, const char* delim);

#endif