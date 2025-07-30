project(vhidriver-test)

file(GLOB_RECURSE ${PROJECT_NAME}_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)


if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})
else()
    # win32 application
    add_executable(${PROJECT_NAME} WIN32 ${${PROJECT_NAME}_SRC})
    # hide terminal window
    target_link_options(${PROJECT_NAME} PRIVATE "/ENTRY:mainCRTStartup")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\"")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)

target_link_libraries(${PROJECT_NAME} PRIVATE user32 cfgmgr32 Advapi32 hid)
