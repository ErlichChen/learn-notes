set(CMAKE_C_STANDARD 99)
include_directories(../include)
add_executable(app main.c)
target_link_libraries(app lib)