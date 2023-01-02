#include <stdio.h>
#include "Point.h"

Point Point_value(double x, double y) {
    Point init = {x, y};
    return init;
}

void Point_print(Point* self) {
    printf("Point: (%f, %f)\n", self->x, self->y);
}
