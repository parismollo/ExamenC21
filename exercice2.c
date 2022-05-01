#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct elem {
    struct elem *next;
    int data;
}elem;


elem *getnext(int data) {
    elem *next = malloc(sizeof(elem));
    assert(next != NULL);
    next->data = data;
    next->next = NULL;
    return next;
}

int main() {
    int somme;
    elem *cur;

    elem* l = malloc(sizeof(elem));
    l->data = 1;
    l->next = getnext(5);
    l->next->next = getnext(3);


    for (somme = 0, cur = l; cur != NULL; somme = somme + cur->data, cur = cur->next);
    printf("somme = %d\n", somme);

    free(l->next->next);
    free(l->next);
    free(l);
    
    
}