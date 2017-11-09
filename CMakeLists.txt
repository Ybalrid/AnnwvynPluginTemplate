cmake_minimum_required(VERSION 3.6.3)


set (CMAKE_CXX_STANDARD 14)
set(PLUGIN_NAME "PluginTemplate")


project(${PLUGIN_NAME})

file(GLOB Sources *.cpp)
file(GLOB Headers *.hpp)


if(MSVC)
    #Configure compilation parameters
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /W4 /fp:fast /bigobj /Gy /D \"_UNICODE\" /D \"UNICODE\" /D \"NOMINMAX\"")
    string(REPLACE "/O2" "/Ox" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /Ot /Oi")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
endif()


include_directories(
    $ENV{AnnwvynSDK64}/Annwvyn/include
    /usr/local/include/Annwvyn
)


link_directories($ENV{AnnwvynSDK64}/Annwvyn/lib/
    $ENV{HOME}/AnnwvynDeps/openvr/lib/linux64/
    /usr/local/lib/
    )

add_library(${PLUGIN_NAME} MODULE ${Sources} ${Headers})

target_link_libraries(${PLUGIN_NAME} Annwvyn)


