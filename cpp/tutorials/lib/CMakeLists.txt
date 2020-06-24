set(CMAKE_C_STANDARD 99)
aux_source_directory(. SRC)
add_library(lib ${SRC})
set_target_properties(lib PROPERTIES OUTPUT_NAME "lib")