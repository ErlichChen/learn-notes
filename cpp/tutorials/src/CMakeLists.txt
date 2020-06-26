set(CMAKE_C_STANDARD 99)
include_directories(../include)
add_executable(app main.c ../include/12_scope.h ../include/13_memory.h)
target_link_libraries(app lib)