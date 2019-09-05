project(_pe_reader)

add_library(${PROJECT_NAME}
    STATIC
    # BASE
    ${PROJECT_SOURCE_DIR}/src/base/reader.cc

    ${PROJECT_SOURCE_DIR}/src/pe_reader.cc
)
add_library(static::pe ALIAS ${PROJECT_NAME})


target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/
    ${PROJECT_SOURCE_DIR}/src/
)