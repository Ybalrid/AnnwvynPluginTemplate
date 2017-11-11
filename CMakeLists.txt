cmake_minimum_required(VERSION 3.6.3)


set(CMAKE_CXX_STANDARD 14)
set(PLUGIN_NAME "PluginTemplate")

#basic configuration
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE) 

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /W4 /fp:fast /bigobj /Gy /D \"_UNICODE\" /D \"UNICODE\" /D \"NOMINMAX\"")
    string(REPLACE "/O2" "/Ox" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /Ot /Oi")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
endif()


STRING(REPLACE "\\" "/" AnnSDK "$ENV{AnnwvynSDK64}")

#Path for additional CMake module shipped with the Annwvyn SDK 
#Where to find additional modules
if(WIN32)
    set(CMAKE_MODULE_PATH 
        ${CMAKE_MODULE_PATH}
        ${AnnSDK}/CMakeModules
        ${AnnSDK}/Ogre21SDK/CMake
        ${AnnSDK}/BtOgre21/CMake
        )
endif()
if(UNIX)
    set(
        CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        /usr/lib/OGRE/cmake 
        /usr/local/lib/OGRE/cmake 
        /usr/lib/BtOgre21/CMake 
        /usr/local/lib/BtOgre21/CMake
        ~/AnnwvynDeps/CMakeModules
        )
endif()

#Set path required for CMake modules
set(OGRE_HOME $ENV{AnnwvynSDK64}/Ogre21SDK CACHE PATH "Ogre install")
set(BULLET_ROOT $ENV{AnnwvynSDK64}/bullet3 CACHE PATH "Bullet install")
set(BtOgre21_ROOT $ENV{AnnwvynSDK64}/BtOgre21/build/bin/ CACHE PATH "BtOgre21 install")
set(OIS_ROOT $ENV{AnnwvynSDK64}/OIS CACHE PATH "OIS install")
set(ENV{OPENALDIR} $ENV{AnnwvynSDK64}/AL/openal-soft/build/install CACHE PATH "OpenAL install")
set(ENV{GLFW_LOCATION} $ENV{AnnwvynSDK64}/glfw/build/install CACHE PATH "GLFW install") 
set(TinyXML2_ROOT $ENV{AnnwvynSDK64}/tinyxml2/build/install CACHE PATH "TinyXML2 install")
set(SNDFILE_WINDOWS_INSTALL $ENV{AnnwvynSDK64}/libsndfile CACHE PATH "libsndfile install")


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

find_package(OGRE COMPONENTS Overlay HlmsPbs HlmsUnlit REQUIRED)
find_package(Bullet REQUIRED)
find_package(BtOgre21 REQUIRED)
find_package(OpenAL REQUIRED)
find_package(TinyXML2 REQUIRED)
find_package(SNDFILE REQUIRED)
find_package(OIS REQUIRED)
find_package(OpenAL REQUIRED)

include_directories(
    $ENV{AnnwvynSDK64}/Annwvyn/include
    /usr/local/include/Annwvyn
    ##Engine dependencies
    #Graphics
    ${OGRE_INCLUDE_DIRS}
    ${OGRE_HlmsPbs_INCLUDE_DIRS}
    ${OGRE_HlmsUnlit_INCLUDE_DIRS}
    #Physics
    ${BULLET_INCLUDE_DIRS}
    ${BtOgre21_INCLUDE_DIRS}
    #Input 
    ${OIS_INCLUDE_DIRS}
    #OpengL Support
    ${GLEW_INCLUDE_DIRS}
    ${GLFW_INCLUDE_DIR}
    #Audio 
    ${OPENAL_INCLUDE_DIR}
    ${SNDFILE_INCLUDE_DIRS}
	${AnnSDK}/chaiscript

    )


link_directories($ENV{AnnwvynSDK64}/Annwvyn/lib/
    $ENV{HOME}/AnnwvynDeps/openvr/lib/linux64/
    )

add_library(${PLUGIN_NAME} MODULE ${Sources} ${Headers})

target_link_libraries(${PLUGIN_NAME} Annwvyn)


