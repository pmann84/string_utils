cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_NAME "test_string_utils")
set(
	SOURCES 
		test_string_conversions.cpp 
		test_string_endswith.cpp 
		test_string_join.cpp 
		test_string_replace.cpp
		test_string_split.cpp
		test_string_startswith.cpp
		test_string_trim.cpp
		test_string_case.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC string_utils)

target_link_libraries(${PROJECT_NAME} PUBLIC gtest)
target_link_libraries(${PROJECT_NAME} PUBLIC gtest_main)
target_link_libraries(${PROJECT_NAME} PUBLIC gmock)
target_link_libraries(${PROJECT_NAME} PUBLIC gmock_main)