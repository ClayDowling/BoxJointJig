include_directories(../src .)

set(TESTPROJECT test-${PROJECT_NAME})

add_executable(${TESTPROJECT}
    test_hardware.cpp

    ../src/hardware.cpp
    )

target_link_libraries(${TESTPROJECT}
    PRIVATE
    Catch2::Catch2WithMain
)

catch_discover_tests(${TESTPROJECT})