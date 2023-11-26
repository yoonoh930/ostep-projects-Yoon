//
// Created by YoonSeok Oh on 11/21/23.
//
// prompt> ./wzip file.txt > file.z
//
// - [X] a. No file specified, "wzip: file1 [file2 ...]" (followed by a newline)
// - [ ] b. aaaaaaaaaabbbb becomes 10a4b
// - [ ] c. If multiple file, zip into a single file
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    int count = 0;
    int chr;
    int c;
    for (int i = 1; i < argc; i++) {
        const char *filename = argv[i];
        FILE *file = fopen(filename, "r");

        while ((c = fgetc(file)) != EOF) {
            // first
            if (count == 0) {
                chr = c;
                count++;
                continue;
            }
            // different from the previous chr
            if (chr != c) {
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&chr, sizeof(char), 1, stdout);
                chr = c;
                count = 1;
                continue;
            } else {
                count++;
            }

        }
        fclose(file);


    }
    fwrite(&count, sizeof(int), 1, stdout);
    fwrite(&chr, sizeof(char), 1, stdout);

    return 0;
}

