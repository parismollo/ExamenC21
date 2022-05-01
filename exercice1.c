#include <stdio.h>
#include <string.h>

int main(void) {
    char* s = "abcdefghijkl"; // s -> a. 
    int i = 4;
    
    printf("A=%c\n", *(s+i)); // a ->b ->c ->d ->e, we return the value at adress s+4, i.e. = e, we move 4 adresses forward.
    printf("B=%c\n", s[++i]); // ++i = 5. Effets de bord. s[5] i.e = f. Same thing as *(p+5) 

    char* c = s + 5; // c -> e. (6th letter/ adress)
    printf("longueur c=%zd\n", strlen(c)); // zd used for type size_t and it return the len of 5 up to strlen(s) = 7 (counting the first letter 6th 7th 8th 9th 10th 11th 12th). 
    printf("c decale =  %c\n", c[-2]); // prints d<- e<- f, i.e. =  d

    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pt = &tab[7]; // pt->adress that contains 8
    int *pu = &tab[1]; // pt->adress that contains 2

    printf("diff = %td\n", pt - pu); // used for print diff between pointers. 8 - 2 = 6 
}