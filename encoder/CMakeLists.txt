add_library(pico_encoder Encoder.h Encoder.cpp)

target_link_libraries(pico_encoder pico_stdlib hardware_gpio )

target_include_directories(pico_encoder PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
