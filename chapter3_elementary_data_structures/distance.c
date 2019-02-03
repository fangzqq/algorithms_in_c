#include <math.h>
#include "Point.h"

float distance(point a, point b)
{
    float x = a.x - b.x, y = a.y - b.y;
    return sqrt(x*x + y*y);
}
