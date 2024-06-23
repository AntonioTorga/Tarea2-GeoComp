#include <gtest/gtest.h>
#include <Poligono.h>
#include <vector>
#include <cmath>

TEST(ConvexHullNormal, TestBaseGiftWrapping) {
    std::vector<Punto<int>> cloud = {
        Punto(-29, 33),
        Punto(-20, -4),
        Punto(32, -28),
        Punto(-1, 50),
        Punto(-11, -5),
        Punto(-49, 31),
        Punto(-34, -43),
        Punto(6, -44),
        Punto(-35, 40),
        Punto(-15, 36)
    };
    Poligono<int> result = giftWrapping(cloud);
    std::vector<Punto<int>> result_vertices = result.get_vertices();
    EXPECT_EQ(result_vertices.size(), 6);
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(-1, 50)) != result_vertices.end());
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(-35, 40)) != result_vertices.end());
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(-49, 31)) != result_vertices.end());
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(-34, -43)) != result_vertices.end());
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(6, -44)) != result_vertices.end());
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(32, -28)) != result_vertices.end());
}

TEST(ConvexHullNormal, TestBaseGrahamScan) {
    std::vector<Punto<int>> cloud = { 
        Punto(-29, 33), 
        Punto(-20, -4), 
        Punto(32, -28), 
        Punto(-1, 50), 
        Punto(-11, -5), 
        Punto(-49, 31), 
        Punto(-34, -43), 
        Punto(6, -44), 
        Punto(-35, 40), 
        Punto(-15, 36) 
    };

    Poligono<int> result = grahamScan(cloud);
    std::vector<Punto<int>> result_vertices = result.get_vertices();
    EXPECT_EQ(result_vertices.size(), 6);
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(-1, 50)) != result_vertices.end());
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(-35, 40)) != result_vertices.end());
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(-49,31)) != result_vertices.end());
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(-34,-43)) != result_vertices.end());
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(6, -44)) != result_vertices.end());
    ASSERT_TRUE(std::find(result_vertices.begin(), result_vertices.end(), Punto<int>(32,-28)) != result_vertices.end());
}

TEST(ConvexHullEquality, TenPoints) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(10, 50, 100);
    Poligono<long long> gs_result = grahamScan(cloud);
    Poligono<long long> gf_result = giftWrapping(cloud);
    std::vector<Punto<long long>> gs_vertices = gs_result.get_vertices();
    std::vector<Punto<long long>> gf_vertices = gf_result.get_vertices();
    EXPECT_EQ(gs_vertices.size(), gf_vertices.size());
    std::sort(gs_vertices.begin(), gs_vertices.end(), compareLeftmostDownmost<long long>);
    std::sort(gf_vertices.begin(), gf_vertices.end(), compareLeftmostDownmost<long long>);
    EXPECT_EQ(gs_vertices, gf_vertices);
    for (int i = 0; i < gs_vertices.size(); i++) {
        EXPECT_EQ(gs_vertices[i], gf_vertices[i]);
    }
}

TEST(ConvexHullEquality, HundredPoints) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(100, 50, 1000);
    Poligono<long long> gs_result = grahamScan(cloud);
    Poligono<long long> gf_result = giftWrapping(cloud);
    std::vector<Punto<long long>> gs_vertices = gs_result.get_vertices();
    std::vector<Punto<long long>> gf_vertices = gf_result.get_vertices();
    EXPECT_EQ(gs_vertices.size(), gf_vertices.size());
    std::sort(gs_vertices.begin(), gs_vertices.end(), compareLeftmostDownmost<long long>);
    std::sort(gf_vertices.begin(), gf_vertices.end(), compareLeftmostDownmost<long long>);
    //check equality of vertices one by one
    for (int i = 0; i < gs_vertices.size(); i++) {
        EXPECT_EQ(gs_vertices[i], gf_vertices[i]);
    }
}

TEST(ConvexHullEquality, ThousandPoints) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(1000, 50, 10000);
    Poligono<long long> gs_result = grahamScan(cloud);
    Poligono<long long> gf_result = giftWrapping(cloud);
    std::vector<Punto<long long>> gs_vertices = gs_result.get_vertices();
    std::vector<Punto<long long>> gf_vertices = gf_result.get_vertices();
    EXPECT_EQ(gs_vertices.size(), gf_vertices.size());
    std::sort(gs_vertices.begin(), gs_vertices.end(), compareLeftmostDownmost<long long>);
    std::sort(gf_vertices.begin(), gf_vertices.end(), compareLeftmostDownmost<long long>);
    for (int i = 0; i < gs_vertices.size(); i++) {
        EXPECT_EQ(gs_vertices[i], gf_vertices[i]);
    }
}

TEST(ConvexHullEquality, NinetyPercentCH) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(100, 90, 10000);
	Poligono<long long> gs_result = grahamScan(cloud);
	Poligono<long long> gf_result = giftWrapping(cloud);
	std::vector<Punto<long long>> gs_vertices = gs_result.get_vertices();
	std::vector<Punto<long long>> gf_vertices = gf_result.get_vertices();
	EXPECT_EQ(gs_vertices.size(), gf_vertices.size());
    EXPECT_EQ(gs_vertices.size(), 90);
	std::sort(gs_vertices.begin(), gs_vertices.end(), compareLeftmostDownmost<long long>);
	std::sort(gf_vertices.begin(), gf_vertices.end(), compareLeftmostDownmost<long long>);
	for (int i = 0; i < gs_vertices.size(); i++) {
		EXPECT_EQ(gs_vertices[i], gf_vertices[i]);
	}
}

TEST(ConvexHullEquality, NinetyPercentCHManyPoints) {
	std::vector<Punto<long long>> cloud = semiRandomPoints(10000, 90, 10000000);
	Poligono<long long> gs_result = grahamScan(cloud);
	Poligono<long long> gf_result = giftWrapping(cloud);
	std::vector<Punto<long long>> gs_vertices = gs_result.get_vertices();
	std::vector<Punto<long long>> gf_vertices = gf_result.get_vertices();
	EXPECT_EQ(gs_vertices.size(), gf_vertices.size());
	EXPECT_EQ(gs_vertices.size(), 9000);
	std::sort(gs_vertices.begin(), gs_vertices.end(), compareLeftmostDownmost<long long>);
	std::sort(gf_vertices.begin(), gf_vertices.end(), compareLeftmostDownmost<long long>);
	for (int i = 0; i < gs_vertices.size(); i++) {
		EXPECT_EQ(gs_vertices[i], gf_vertices[i]);
	}
}