#include "Point.h"

typedef struct Test
{
    void (*pp)(Point* self);
} Test;


int main() {
    Point a = Point_value(1.0, 2.0);
    Point_print(&a);
    Test t;
    t.pp = Point_print;
    t.pp(&a); 
}