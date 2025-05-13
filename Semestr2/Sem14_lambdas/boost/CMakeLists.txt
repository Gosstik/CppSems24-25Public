cmake_minimum_required(VERSION 3.28.0)
project(BoostProject VERSION 0.1.0)

#-------------------------------------------------------------------------------

# Include(FetchContent)

# FetchContent_Declare(
#   Catch2
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   # GIT_TAG        v3.4.0 # or a later release
#   GIT_TAG        v3.8.0
# )

# FetchContent_MakeAvailable(Catch2)

if(POLICY CMP0167)
   cmake_policy(SET CMP0167 OLD)
endif()
find_package(Boost 1.73 CONFIG REQUIRED)
# find_package(Boost 1.73 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

#-------------------------------------------------------------------------------

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")
add_executable(1_bind "${CMAKE_CURRENT_SOURCE_DIR}/src/1_bind.cpp")
target_link_libraries(1_bind PRIVATE ${Boost_LIBRARIES})
