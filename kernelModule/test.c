#include <stdio.h>
#include <stdlib.h>

char test(char a, int b);

typedef struct Point
// Intention: typedef struct Point -> Point
{
    char a;
    int b;
    char (*test_p)(char a, int b);
} Point; // <- alias

int main()
{
    Point p;
    p.a = 'c';
    p.b = 26;
    p.test_p = test;
    printf("'%c'+%d=%c\n", p.a, p.b, p.test_p(p.a, p.b));
    printf("Size of Struct: %ld", sizeof(Point));
    return 0;
}

char test(char a, int b) {
    return (char)(a + b);
}