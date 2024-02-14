#include "Point.hpp"

/**
 * • a, b, c: The vertices of our beloved triangle
 * • point: The point to check.
 * • Returns: True if the point is inside the triangle. False otherwise.
Thus, if the point is a vertex or on edge, it will return False.
*/

float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
   float calculatedArea =  (x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0;
   
   if (calculatedArea < 0)
      return (-calculatedArea);
   return (calculatedArea);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
       /* Calculate area of triangle ABC */
   float A = area (a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());
  
   /* Calculate area of triangle PBC */ 
   float A1 = area (point.getX().toFloat(), point.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());
  
   /* Calculate area of triangle PAC */ 
   float A2 = area (point.getX().toFloat(), point.getY().toFloat(), a.getX().toFloat(), a.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat());
  
   /* Calculate area of triangle PAB */  
   float A3 = area (point.getX().toFloat(), point.getY().toFloat(), a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat());
    
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}