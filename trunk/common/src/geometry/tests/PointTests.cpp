#include "geometry/Point.h"

#include "test/Test.h"

using namespace geo;

TEST(Point3D)
{
  // Construction.
  Point3D p(1, 2, 3);
  
  // Access by index.
  ASSERT_EQUAL(p[0], 1);
  ASSERT_EQUAL(p[1], 2);
  ASSERT_EQUAL(p[2], 3);
  
  // Access by x, y, z.
  ASSERT_EQUAL(p.x, 1);
  ASSERT_EQUAL(p.y, 2);
  ASSERT_EQUAL(p.z, 3);
  
  // Copy construction.
  Point3D p2(p);
  ASSERT_EQUAL(p2.x, 1);
  ASSERT_EQUAL(p2.y, 2);
  ASSERT_EQUAL(p2.z, 3);
  
  // Editing elements.
  p2.x = 10;
  p2.y = 20;
  p2.z = 30;
  ASSERT_EQUAL(p2.x, 10);
  ASSERT_EQUAL(p2.y, 20);
  ASSERT_EQUAL(p2.z, 30);
  p2[0] = 5;
  p2[1] = 10;
  p2[2] = 15;
  ASSERT_EQUAL(p2.x, 5);
  ASSERT_EQUAL(p2.y, 10);
  ASSERT_EQUAL(p2.z, 15);
  
  // Assignment.
  p2 = p;
  ASSERT_EQUAL(p2.x, 1);
  ASSERT_EQUAL(p2.y, 2);
  ASSERT_EQUAL(p2.z, 3);

  // Addition.
  auto p3 = p2 + Vector3D(1, 2, 3);
  ASSERT_EQUAL(p3.x, 2);
  ASSERT_EQUAL(p3.y, 4);
  ASSERT_EQUAL(p3.z, 6);
  
  p3 += Vector3D(1, 2, 3);
  ASSERT_EQUAL(p3.x, 3);
  ASSERT_EQUAL(p3.y, 6);
  ASSERT_EQUAL(p3.z, 9);
  
  // Subtraction.
  p3 -= Vector3D(1, 2, 3);
  ASSERT_EQUAL(p3.x, 2);
  ASSERT_EQUAL(p3.y, 4);
  ASSERT_EQUAL(p3.z, 6);
  
  p3 = p2 - Vector3D(1, 2, 3);
  ASSERT_EQUAL(p3.x, 0);
  ASSERT_EQUAL(p3.y, 0);
  ASSERT_EQUAL(p3.z, 0);
  
  // Equality.
  ASSERT(p == p2);
  ASSERT(p != p3);
  
  // Comparator.
  ASSERT(p3 < p);
  ASSERT(!(p < p3));
  ASSERT(!(p < p2));
  ASSERT(!(p2 < p));
};