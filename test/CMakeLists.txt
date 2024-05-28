cmake_minimim_required(VERSION 3.0)
project(geotests)

set(CMAKE_CXX_STANDARD 17)

add_executable(TESTS 
	#add files
)

target_compile_options(geotests PRIVATE -Wall -Wextra -pedantic)
target_link_libraries(geotests gtest gtest_main)

enable_testing()

gtest_discover_tests(geotests)