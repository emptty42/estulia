cmake_minimum_required(VERSION 3.0)

project(estulia)
set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Wreturn-type -Werror=return-type -Wunreachable-code -Werror")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

link_directories(/opt/gamedev/lib)
include_directories(/opt/gamedev/include)

add_executable(estulia  # Entity.cpp Entity.hpp
                        src/Game.cpp   src/Game.hpp
                        src/View.cpp   src/View.hpp
                        src/World.cpp  src/World.hpp
                        )
target_link_libraries(estulia gf0 gfcore0)


file(COPY Monospace.ttf DESTINATION ${CMAKE_BINARY_DIR})
