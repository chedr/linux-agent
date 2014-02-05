# This builds gtest and gmock
# Additionally, this defines the add_unit_test macro

enable_testing()

# Build GTest and GMock, fetch_testing_tools needs to have been run first
set(GMOCK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gmock/")
set(GTEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/gmock/gtest/")
if (EXISTS ${GMOCK_DIR} AND EXISTS ${GTEST_DIR})
    include_directories(${GTEST_DIR})
    include_directories(${GTEST_DIR}/include)
    include_directories(${GMOCK_DIR})
    include_directories(${GMOCK_DIR}/include)
    add_library(gtest ${GTEST_DIR}/src/gtest-all.cc)
    add_library(gmock_main ${GMOCK_DIR}/src/gmock-all.cc
                           ${GMOCK_DIR}/src/gmock_main.cc)
else()
    add_library(FATAL_ERROR "gmock can't be found, run ./fetch_testing_tools")
endif()

add_custom_target(check)
# usage: add_unit_test(test_name test_sources...)
# Note that add_unit_test automatically finds test/${test_name}.cc
# find_library(Protobuf) must have been called before calling this
macro(add_unit_test test_name)
    add_executable(${test_name} EXCLUDE_FROM_ALL test/${test_name}.cc ${ARGN})
    add_dependencies(${test_name} gtest)

    include_directories(${CMAKE_CURRENT_BINARY_DIR})
    target_link_libraries(${test_name} glog)
    target_link_libraries(${test_name} gtest)
    if (NOT EXISTS ${GMOCK_DIR})
        target_link_libraries(${test_name} gmock)
    endif()
    target_link_libraries(${test_name} gmock_main)

    # TODO set_tests_properties should do this so we don't need to do the
    # bash -c hack here, but can't seem to get it to work
    #
    # set_tests_properties(${test_name} PROPERTIES ENVIRONMENT
    #                      GLOG_minloglevel=2)
    add_custom_target(ctest_${test_name} 
                      ${CMAKE_CURRENT_BINARY_DIR}/${test_name}
                      WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

    add_test(${test_name} ${test_name})

    add_dependencies(ctest_${test_name} ${test_name})
    add_dependencies(check ctest_${test_name})
endmacro()

