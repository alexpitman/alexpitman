#include "geometry/Vector.h"

#include "test/Test.h"

using namespace geo;

TEST(Vector3D)
{
  // Construction.
  Vector3D v(1, 2, 3);
  
  // Access by index.
  ASSERT_EQUAL(v[0], 1);
  ASSERT_EQUAL(v[1], 2);
  ASSERT_EQUAL(v[2], 3);
  
  // Access by x, y, z.
  ASSERT_EQUAL(v.x, 1);
  ASSERT_EQUAL(v.y, 2);
  ASSERT_EQUAL(v.z, 3);
  
  // Copy construction.
  Vector3D v2(v);
  ASSERT_EQUAL(v2.x, 1);
  ASSERT_EQUAL(v2.y, 2);
  ASSERT_EQUAL(v2.z, 3);
  
  // Editing elements.
  v2.x = 10;
  v2.y = 20;
  v2.z = 30;
  ASSERT_EQUAL(v2.x, 10);
  ASSERT_EQUAL(v2.y, 20);
  ASSERT_EQUAL(v2.z, 30);
  v2[0] = 5;
  v2[1] = 10;
  v2[2] = 15;
  ASSERT_EQUAL(v2.x, 5);
  ASSERT_EQUAL(v2.y, 10);
  ASSERT_EQUAL(v2.z, 15);
  
  // Assignment.
  v2 = v;
  ASSERT_EQUAL(v2.x, 1);
  ASSERT_EQUAL(v2.y, 2);
  ASSERT_EQUAL(v2.z, 3);

  // Addition.
  auto v3 = v + v2;
  ASSERT_EQUAL(v3.x, 2);
  ASSERT_EQUAL(v3.y, 4);
  ASSERT_EQUAL(v3.z, 6);
  
  v3 += v;
  ASSERT_EQUAL(v3.x, 3);
  ASSERT_EQUAL(v3.y, 6);
  ASSERT_EQUAL(v3.z, 9);
  
  // Subtraction.
  v3 -= v;
  ASSERT_EQUAL(v3.x, 2);
  ASSERT_EQUAL(v3.y, 4);
  ASSERT_EQUAL(v3.z, 6);
  
  v3 = v2 - v;
  ASSERT_EQUAL(v3.x, 0);
  ASSERT_EQUAL(v3.y, 0);
  ASSERT_EQUAL(v3.z, 0);
  
  // Equality.
  ASSERT(v == v2);
  ASSERT(v != v3);
  
  // Comparator.
  ASSERT(v3 < v);
  ASSERT(!(v < v3));
  ASSERT(!(v < v2));
  ASSERT(!(v2 < v));
  
  // Length.
  ASSERT_EQUAL(v.Length(), num::Sqrt(14));
  ASSERT_EQUAL(v.LengthSquared(), 14);
  ASSERT_EQUAL(v3.Length(), 0);
  ASSERT_EQUAL(v3.LengthSquared(), 0);
};