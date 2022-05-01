#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point;

double distance(const point *a, const point *b) {
    int calc = ((a->x - b->x) * (a->x - b->x)) + ((a->y - b->y) * (a->y - b->y));
    double d = sqrt(calc);
    return d;
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
    printf("double =  %lf\n", d);
    return 0;
}