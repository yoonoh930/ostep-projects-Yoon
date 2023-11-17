#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Check if the program received a file name
  if (argc < 2) {
    return 0; // required per the detail
  }

  for (int i = 0; i < argc; i++) {

    if (i == 0) continue;

      const char *filename = argv[i];
      FILE *file = fopen(filename, "r");

  // Check if there is a file
      if (file == NULL) {
        printf("wcat: cannot open file\n");
        fclose(file);
        return 1;
      }

      int c;
      while ((c = fgetc(file)) != EOF)
        putchar(c);

      if (ferror(file))
        puts("I/O error when reading");

      fclose(file);
  }

   return 0;
}
