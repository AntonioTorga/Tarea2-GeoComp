#include <gtest/gtest.h>
#include <Poligono.h>
#include <vector>
#include <cmath>

TEST(RandomPointsTests, CreateAHundredRandomPoints) {
	std::vector<Punto<long long>> cloud = randomPoints(100, 100);
	EXPECT_EQ(cloud.size(), 100);
	std::vector<Punto<long long>> square = createConvexPolygon(4, 200);
	cloud.insert(cloud.end(), square.begin(), square.end());
	Poligono<long long> convex_hull = grahamScan(cloud);
	EXPECT_EQ(convex_hull.get_vertices().size(), 4);
}

TEST(RandomPointsTests, LargeAmountOfRandomPointsNtotheFourth) {
	std::vector<Punto<long long>> cloud = randomPoints(10000, 10000);
	EXPECT_EQ(cloud.size(), 10000);
	std::vector<Punto<long long>> square = createConvexPolygon(4, 20000);
	cloud.insert(cloud.end(), square.begin(), square.end());
	Poligono<long long> convex_hull = grahamScan(cloud);
	EXPECT_EQ(convex_hull.get_vertices().size(), 4);
}

TEST(RandomPointsTests, LargeAmountOfRandomPointsNtotheFifth) {
	std::vector<Punto<long long>> cloud = randomPoints(100000, 10000);
	EXPECT_EQ(cloud.size(), 100000);
	std::vector<Punto<long long>> square = createConvexPolygon(4, 20000);
	cloud.insert(cloud.end(), square.begin(), square.end());
	Poligono<long long> convex_hull = grahamScan(cloud);
	EXPECT_EQ(convex_hull.get_vertices().size(), 4);
}

TEST(RandomPointsTests, LargeAmountOfRandomPointsNtotheSixth) {
	std::vector<Punto<long long>> cloud = randomPoints(1000000, 10000);
	EXPECT_EQ(cloud.size(), 1000000);
	std::vector<Punto<long long>> square = createConvexPolygon(4, 20000);
	cloud.insert(cloud.end(), square.begin(), square.end());
	Poligono<long long> convex_hull = grahamScan(cloud);
	EXPECT_EQ(convex_hull.get_vertices().size(), 4);
}


TEST(RandomPointsTests, CreateAHundredSemiRandomPointsThirtyPercentCH) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(100, 30, 100);
	EXPECT_EQ(cloud.size(), 100);
	Poligono<long long> convex_hull = grahamScan(cloud);
	EXPECT_EQ(convex_hull.get_vertices().size(), 30);
}

TEST(RandomPointsTests, CreateAHundredSemiRandomPointsThirtyDot3PercentCH) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(100, 30.3, 100);
	EXPECT_EQ(cloud.size(), 100);
	Poligono<long long> convex_hull = grahamScan(cloud);
	EXPECT_EQ(convex_hull.get_vertices().size(), 31);
}

//fails when space~amount and percent is close to 100, it shouldn't fail if using double
//but for simplicity im using that function only on integers.
TEST(RandomPointsTests, CreateAHundredSemiRandomPointsNinetyNinePercentCH) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(100, 99, 1000);
	EXPECT_EQ(cloud.size(), 100);
	Poligono<long long> convex_hull = grahamScan(cloud);
 	EXPECT_EQ(convex_hull.get_vertices().size(), 99);
}

TEST(RandomPointsTests, LargeAmountOfSemiRandomPoints) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(10000, 5, 10000);
	EXPECT_EQ(cloud.size(), 10000);
	Poligono<long long> convex_hull = grahamScan(cloud);
	EXPECT_EQ(convex_hull.get_vertices().size(), 500);
}
TEST(RandomPointsTests, LargeAmountOfSemiRandomPointsHalfOnCH) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(10000, 50, 1000000);
	EXPECT_EQ(cloud.size(), 10000);
	Poligono<long long> convex_hull = grahamScan(cloud);
	EXPECT_EQ(convex_hull.get_vertices().size(), 5000);
}
TEST(RandomPointsTests, LargerAmountOfSemiRandomPoints) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(100000, 10, 10000000);
	EXPECT_EQ(cloud.size(), 100000);
	Poligono<long long> convex_hull = grahamScan(cloud);
	EXPECT_EQ(convex_hull.get_vertices().size(), 10000);
}