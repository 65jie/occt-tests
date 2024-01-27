# CMakeList.txt : CMake project for geom-modeling-test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("geom-tests")

set(TARGET_NAME geom-tests)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

# Collect c/c + + files and assign them to the variable SRC_LIST_C
# ${CMAKE_CURRENT_SOURCE_DIR} represents the current item directory of CMakeLists.txt
file(GLOB SRC_LIST_C
    "src/*.cpp"
    "src/*/*.cpp"
    "src/*/*/*.cpp"
    "src/*/*/*/*/*.cpp"
    "test/*.cpp"
)

# Specify the. h header file directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc
                    ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/../occt/include
)

# Specify the lib link library file directory
if(WIN32)
    link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/lib/win/${CMAKE_BUILD_TYPE}
        ${CMAKE_CURRENT_SOURCE_DIR}/../occt/win/${CMAKE_BUILD_TYPE}/lib
    )
elseif(APPLE)
    # TODO:
elseif(UNIX)
    link_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/lib/linux/
        ${CMAKE_CURRENT_SOURCE_DIR}/../occt/linux/${CMAKE_BUILD_TYPE}/lib
    )
endif(WIN32)

# Add source to this project's executable.
add_executable(${TARGET_NAME} ${SRC_LIST_C})

# Specify the project link library gtest and gtest_main
target_link_libraries(${TARGET_NAME}
    gtest
    gtest_main
    TKBO
    TKernel
    TKG3d
    TKGeomAlgo
)

if(WIN32)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        #gtest
        ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/lib/win/${CMAKE_BUILD_TYPE}/gtest.dll
        ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/lib/win/${CMAKE_BUILD_TYPE}/gtest_main.dll
        #dest
        $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
    file(GLOB OCCT_DLLS "${CMAKE_CURRENT_SOURCE_DIR}/../occt/win/${CMAKE_BUILD_TYPE}/bin/*.dll")
    # message("OCCT_DLLS LIST IS: ${OCCT_DLLS}")
    foreach (dll ${OCCT_DLLS})
		add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
            COMMENT "Copying dll ${dll}..."
			COMMAND ${CMAKE_COMMAND} -E copy_if_different ${dll}
			#dest
			$<TARGET_FILE_DIR:${TARGET_NAME}>
		)
    endforeach()
elseif(APPLE)
    #
elseif(UNIX)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND cp -a  ${CMAKE_CURRENT_SOURCE_DIR}/../gtest/lib/linux/*.so* ${CMAKE_CURRENT_SOURCE_DIR}/../bin
    )
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND cp -a  ${CMAKE_CURRENT_SOURCE_DIR}/../occt/linux/bin/*.so* ${CMAKE_CURRENT_SOURCE_DIR}/../bin
    )
endif(WIN32)
