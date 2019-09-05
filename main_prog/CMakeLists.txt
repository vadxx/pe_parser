project(main_prog)

add_executable(${PROJECT_NAME}
    # MAIN
    ${PROJECT_SOURCE_DIR}/src/main.cc
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/
    ${PROJECT_SOURCE_DIR}/src/
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    static::pe
)