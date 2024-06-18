cmake_minimum_required(VERSION 3.11)
project(GeoCPP)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/Punto.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Vector.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Poligono.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Utils.cpp	
)

set(HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/include/GeoCPP/Punto.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/GeoCPP/Vector.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/GeoCPP/Poligono.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/GeoCPP/Utils.h
)

add_library(GeoCPP ${SOURCES} ${HEADERS})
target_include_directories(GeoCPP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/GeoCPP)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${HEADERS})

target_link_libraries(main PUBLIC GeoCPP)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/GeoCPP)
