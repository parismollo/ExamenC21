#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


char *get_field(char *line, char del, int pos) {
    char *delim = &del;
    char *copy = malloc(sizeof(char)*strlen(line));
    int counter = 0;

    assert(copy != NULL);
    strcpy(copy, line);
    
    char *token = strtok(copy, delim);
    if(strcmp(token, "\n") == 0) {
        return token;
    }

    if(pos == counter) {
        return token;
    }

    while (token != NULL) {
        token = strtok(NULL, delim);
        if (strcmp(token, "\n") == 0) {
            return token;
        }
        counter++;
        if(counter == pos) {
            return token;
        }
    }
    return NULL;
}


int main() {
    // FILE *flot = fopen("input.csv", "r");
    // int i;
    // while((i = fgetc(flot)) != EOF) {
    //     printf("%c", i);
    // }
    // fclose(flot);
    char *s = "Hello;my;name;is;Paris\n";
    char *c = get_field(s, ';', 4);
    printf("%s\n", c);
}