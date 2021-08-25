# Defines the minimal version allowed of cmake
cmake_minimum_required (VERSION 3.20)

# Set the C++ standard to c++17
set (CMAKE_CXX_STANDARD 20
     CACHE PATH "C++ Standard version")

# Set to "ON" to debug makefile commands
set (CMAKE_VERBOSE_MAKEFILE ON)

project (3way_panned)

# Adds the daemon executable to the project
add_executable(${PROJECT_NAME})

find_package (PkgConfig REQUIRED) 
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)

# Includes the Cmake file from the 3way_panned component
add_subdirectory(3way_panned)

# Add the source files to the lib
target_sources (${PROJECT_NAME}
                PRIVATE
                    main.cpp)

# Adds several directories to the include path
target_include_directories (${PROJECT_NAME}
                            PUBLIC
                                ${GTKMM_INCLUDE_DIRS})

# Links the libs
target_link_libraries(${PROJECT_NAME}
                      PRIVATE
                            ${GTKMM_LIBRARIES})

# Adds flags to the compiler
target_compile_options(${PROJECT_NAME}
                       PUBLIC
                            ${GTKMM_OTHER})
