#ifndef POINT_H
#define POINT_H

typedef struct Point
{
  double x;
  double y;
} Point;


/**
 * @brief 
 * Initialize and return a Point struct value
 * @param x 
 * @param y 
 * @return Point 
 */
Point Point_value(double x, double y);

/**
 * @brief 
 * Print a representation of a Point to stdout.
 * @param self 
 */
void Point_print(Point* self);

#endif