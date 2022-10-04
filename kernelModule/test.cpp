#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    char x;
    int y;
    int (*add_ptr)(int a, int b);
    int sub() {
        return x-y;
    };
} Point;

int add(int a, int b) {
    return a+b;
}
 
int main(void) {
    Point p;
    p.x = 3;
    p.y = 4;
    Point* g;
    g = &p;
    p.add_ptr = add;
    p.add_ptr(3,3);
    printf("%d\n", p.add_ptr(2,3));
    printf("%d\n", p.sub());
    printf("%d\n", g->sub());
    printf("%d\n", g->add_ptr(4, 5));
    return EXIT_SUCCESS;
}