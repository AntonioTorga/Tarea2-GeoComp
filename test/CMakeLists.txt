add_executable(
    GeoTests
    convexHullTests.cpp
    randomPointsTest.cpp
)

target_link_libraries(
    GeoTests
    gtest_main
    GeoCPP
)

include(GoogleTest)
gtest_discover_tests(GeoTests)