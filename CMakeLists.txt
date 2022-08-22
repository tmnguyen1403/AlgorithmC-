cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
project(Hello)

add_executable(sliding_window "Problems/sliding_window_maximum.cpp")
add_executable(group_anagrams "Problems/Arrays_Hashing/group_anagrams.cpp")
add_executable(group_anagrams_faster "Problems/Arrays_Hashing/group_anagrams_faster.cpp")


# Test BigEndian Modules
# include (TestBigEndian)

# TEST_BIG_ENDIAN(IS_BIG_ENDIAN)

# if(IS_BIG_ENDIAN)

# message("BIG_ENDIAN")

# else()

# message("LITTLE_ENDIAN")

# endif()
