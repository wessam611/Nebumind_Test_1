cmake_minimum_required(VERSION 2.8)
project(TEST_1)


find_package(Eigen3 REQUIRED)

include_directories(
${PROJECT_SOURCE_DIR}/include
${EIGEN3_INCLUDE_DIR}
)


file(GLOB SOURCES "src/*.cpp")

add_executable(test_1 ${SOURCES})
target_link_libraries(test_1 
${EIGEN3_LIBS})