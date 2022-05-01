#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point;

typedef struct node {
    struct node *next;
    point p;
}node;

double distance(const point *a, const point *b) {
    int calc = ((a->x - b->x) * (a->x - b->x)) + ((a->y - b->y) * (a->y - b->y));
    double d = sqrt(calc);
    return d;
}

node *getNewNode(int px, int py) {
    node *next = malloc(sizeof(node));
    assert(next != NULL);
    next->p = (point) {.x = px, .y = py};
    next->next = NULL;

    return next;
}

node *ajouter_point(node *lpoint, point p, int pos) {
    node *newNode = malloc(sizeof(node));
    assert(newNode != NULL);
    newNode->p = p;

    if(pos == 0 || lpoint == NULL) { //I'm not sure about this.
        newNode->next = lpoint;
        return newNode;
    }

    int counter = 0;
    node *current;
    for(current = lpoint; current!=NULL; current = current->next) {
        if (counter == pos - 1) {
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
        counter++;
    
        if(current->next == NULL) {
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
    }
    return lpoint;
}

void loop_and_print(node *l) {
    node *current = NULL;
    for(current = l; current!=NULL; current = current->next) {
        printf("Node: (%lf, %lf) -> ", current->p.x, current->p.y);
        // printf("Something ...");
    }
}

double perim(node *lpoint) {
    double perim;
    node *current = NULL;
    

    for(perim = 0, current = lpoint; current->next != NULL; current = current->next) {
        double dist = distance(&(current->p), &(current->next->p));
        perim += dist;
    }

    perim += distance(&(lpoint->p), &(current->p));
    return perim;
}

int main() {
    point *a = malloc(sizeof(point));
    assert(a != NULL);
    a->x = 10;
    a->y = 10;

    point *b = malloc(sizeof(point));
    assert(b != NULL);
    b->x = 12;
    b->y = 12;

    double d = distance(a, b);
    printf("distance =  %lf\n", d);

    free(a);
    free(b);

    node *lp = getNewNode(1, 1);
    assert(lp != NULL);
    lp->next = getNewNode(2, 2);
    lp->next->next = getNewNode(5, 5);

    double p = perim(lp);
    printf("perim =  %lf\n", p);

    free(lp->next->next);
    free(lp->next);
    free(lp);


    node *first = getNewNode(1, 1);
    loop_and_print(first);
    printf("\n");
    first = ajouter_point(first, (point) {.x = 2, .y = 2}, 0);
    first = ajouter_point(first, (point) {.x = 3, .y = 3}, 0);
    first = ajouter_point(first, (point) {.x = 4, .y = 4}, 0);
    loop_and_print(first);
    printf("\n");
    // printf("%lf\n", first->p.x);

    return 0;
}