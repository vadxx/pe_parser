cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
project(BIN_ANALYSE)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/release)
include_guard()

add_subdirectory(main_prog)
add_subdirectory(pe_reader)

# Copy main binary file from /build to /release
install(FILES
    ${PROJECT_BINARY_DIR}/main_prog/main_prog
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

install(FILES
    ${PROJECT_BINARY_DIR}/pe_reader/lib_pe_reader.a
    DESTINATION ${CMAKE_INSTALL_PREFIX}
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
) 