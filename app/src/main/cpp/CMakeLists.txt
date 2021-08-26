# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

project("testdll")

set(dlldir "${PROJECT_SOURCE_DIR}/libDll")

include_directories(${dlldir})

#https://medium.com/@sourav.bh/build-a-native-android-library-or-module-using-ndk-and-cmake-71988b00b5dd

#todo try this https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#manual:cmake-buildsystem(7)
#todo try MODULE
#todo try https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html#genex:TARGET_FILE_BASE_NAME
#todo try add_executable() dll

#1 try how lib
add_library(dllprint_imp_lib SHARED IMPORTED)
set_target_properties(dllprint_imp_lib PROPERTIES
        IMPORTED_LOCATION ${dlldir}/Dll1.lib)

#2 try how lib file
add_library(dllprint_lib SHARED ${dlldir}/Dll1.lib)
set_target_properties(dllprint_lib PROPERTIES LINKER_LANGUAGE CXX)

#3 try how dll file
add_library(dllprint_dll SHARED ${dlldir}/Dll1.dll)
set_target_properties(dllprint_dll PROPERTIES LINKER_LANGUAGE CXX)


#4 try how cpp or h file
# cpp not needed, just for test
#todo https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#interface-libraries
add_library(dllprint_h INTERFACE)
#set_target_properties(dllprint_h PROPERTIES LINKER_LANGUAGE CXX)

add_library(dllprint_cpp SHARED testdll.cpp)

#set_property(TARGET dllprint PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE ON)

#target_compile_definitions(dllprint_h dllprint_lib)


#link native-lib to use in java
add_library( native-lib SHARED native-lib.cpp )
find_library( log-lib log )
target_link_libraries( native-lib ${log-lib} )


#add_executable(Tutorial native-lib)
#target_link_libraries(Tutorial PUBLIC dllprint)

#target_link_libraries( dllprint ${log-lib} )

#END try link native-lib to dllpint
#target_link_libraries( native-lib ${dllprint} )

#try https://cmake.org/cmake/help/v2.8.10/cmake.html#command:add_dependencies
#add_library(dllprint_dep SHARED IMPORTED)
#set_target_properties(dllprint_dep PROPERTIES
#        IMPORTED_LOCATION ${dlldir}/Dll1.lib)
#add_dependencies(dllprint dllprint_dep)

#todo what this? https://developer.android.com/studio/projects/gradle-external-native-builds#groovy