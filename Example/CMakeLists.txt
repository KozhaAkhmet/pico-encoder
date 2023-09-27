add_executable(Example 
    main.cpp
    )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(Example 
pico_stdlib
hardware_uart 
hardware_gpio
hardware_timer
pico_encoder
)

pico_enable_stdio_usb(Example 1)
pico_enable_stdio_uart(Example 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(Example)
