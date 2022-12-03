/*
 * Released under the terms of the Apache license.
 *
 * Author:
 *     Richard Zak <richard.j.zak@gmail.com>
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"strtok.h"

int main() {
    printf("Demo for `better_strtok`. Not really a useful program.\n");

    char pipe_separated_string[] = "some|pipes|here|separating|the|string";
    size_t position = 0, next = 0, i = 0;
    char* piece;

    printf("Original: %s\n", pipe_separated_string);
    while((piece = strtok_ng(pipe_separated_string, strlen(pipe_separated_string), "|", &position, &next)) != NULL) {
        for(i = 0; i < next; i++) {
            printf("%c", piece[i]);
        }
        printf("\n");
    }

    char *last = strtok_ng_last(pipe_separated_string, strlen(pipe_separated_string), "|");
    printf("Last item: %s\n", last);

    printf("\n== Testing delimiter size = 2 ==\n\n");

    char doubleDelim[] = "a--new--string--longer--delimiter";
    position = 0, next = 0, i = 0;

    printf("Original: %s\n", doubleDelim);
    while((piece = strtok_ng(doubleDelim, strlen(doubleDelim), "--", &position, &next)) != NULL) {
        for(i = 0; i < next; i++) {
            printf("%c", piece[i]);
        }
        printf("\n");
    }

    last = strtok_ng_last(doubleDelim, strlen(doubleDelim), "--");
    printf("Last item: %s\n", last);

    printf("\n== Delimiter not found ==\n\n");

    char missingDelim[] = "new-string-no-delimiter";
    position = 0, next = 0, i = 0;

    printf("Original: %s\n", missingDelim);
    while((piece = strtok_ng(missingDelim, strlen(missingDelim), "|", &position, &next)) != NULL) {
        for(i = 0; i < next; i++) {
            printf("%c", piece[i]);
        }
        printf("\n");
    }

    last = strtok_ng_last(missingDelim, strlen(missingDelim), "|");
    printf("Last item: %s\n", last);

    return EXIT_SUCCESS;
}