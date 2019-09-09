project(_pe_reader)

add_library(${PROJECT_NAME}
    STATIC
    ${PROJECT_SOURCE_DIR}/src/base/reader.cpp
    ${PROJECT_SOURCE_DIR}/src/pe_reader.cpp
)
add_library(static::pe ALIAS ${PROJECT_NAME})


target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/
    ${PROJECT_SOURCE_DIR}/src/
)