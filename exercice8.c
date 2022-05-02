#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LEN 81

// [x] 1. File path comes in argument. Read arguments.
// [x] 2. Handle number of arguments errors.
// [ ] 3. Read each line of file and print.
// [ ] 4. Return line number n or return number of lines.

int main(int argc, char **argv) {
    int n;
    char *path;
    if(argc != 3) {
        fprintf(stderr, "[LOG]: Number of arguments not equal to three.\n");
        exit(1);
    } else {
        n = atoi(argv[1]);
        path = argv[2];
        // fprintf(stdout, "[LOG]: Number of arguments is correct.\n");
        fprintf(stdout, "n: %d\npath: %s\n", n, path);
    }

    FILE *flot = fopen(path, "r");
    if(flot == NULL) {
        fprintf(stderr, "[LOG]: File could not be opened.\n");
        exit(1);
    }else {
        fprintf(stdout, "[LOG]: File opened.\n");
    }

    char tab[LEN];


    char *ligne = fgets(tab, LEN, flot);
    int c = 0;
    while(ligne != NULL) {
        // fprintf(stdout, "*");
        n--;
        c++;
        if (n == 0) {
            fprintf(stdout, "[LOG]: Line -> %s\n", ligne); 
            break;
        }
        ligne = fgets(tab, LEN, flot);
    }

    pclose(flot);
    if (n > 0) {
        fprintf(stdout, "[LOG]: Total number of line: %d\n", c);
    }
    return 0;
}