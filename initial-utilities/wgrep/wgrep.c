//
// Created by YoonSeok Oh on 11/17/23.
//
// ./wgrep foo bar.txt
//
// - [X] a. If no given argument, print "wgrep: searchterm [file ...]" with a new line and exit 1
// - [X] b. If empty string given, `wgrep` can either match NO lines or match ALL lines
// - [X] c. Cannot open, then print "wgrep: cannot open file", and exit with 1
// - [X] d. If search term given but no file, then read from `stdin` (use `fgets()`)
// - [X] e. Argument can range from zero to multiple
// - [X] f. If works, exit with 0
// - [X] g. Case sensitive

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // No argument given. Condition b.
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }


    // only one argument provided
    if (argc == 2) {
        // file provided but empty string
        if (strchr(argv[argc-1], ',') != NULL) {
            const char *filename = argv[argc-1];
            FILE *file = fopen(filename, "r");

            // Check if there is a file
            if (file == NULL) {
                // but weird file..
                printf("wgrep: cannot open file\n");
                fclose(file);
                return 1;
            } else{
                // it opens
                return 0;
            }
        } else {
            // only string provided
            const char *searchTerm = argv[1];
            char *line = NULL;
            size_t len = 0;
            ssize_t read;
            while ((read = getline(&line, &len, stdin)) != -1) {
                if (strstr(line, searchTerm) != NULL) {
                    printf("%s", line);
                }
            }
            return 0;
        }
    } else {
        // more than 1 search file
        const char *searchTerm = argv[1];
        for (int i = 2; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                printf("wgrep: cannot open file\n");
                return 1;
            }
            char *line = NULL;
            size_t len = 0;
            ssize_t read;
            while ((read = getline(&line, &len, fp)) != -1) {
                if (strstr(line, searchTerm) != NULL) {
                    printf("%s", line);
                }
            }
            fclose(fp);
        }
    }


    return 0;
}