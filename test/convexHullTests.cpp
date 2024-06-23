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

TEST(ConvexHullBorderCase, TestGiftWrappingColinear){}

TEST(ConvexHullBorderCase, TestGrahamScanColinear){}

TEST(ConvexHullBorderCase, TestGiftWrappingManyPoints) {}

TEST(ConvexHullBorderCase, TestGrahamScanManyPoints) {}