# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

project("testdll")

set(dlldir "${PROJECT_SOURCE_DIR}/libDll")

include_directories(${dlldir})

#1 try how lib
#add_library(dllprint SHARED IMPORTED)
#set_target_properties(dllprint PROPERTIES
#        IMPORTED_LOCATION ${dlldir}/Dll1.lib)

#2 try how lib file
add_library(dllprint SHARED ${dlldir}/Dll1.lib)
set_target_properties(dllprint PROPERTIES LINKER_LANGUAGE CXX)

#3 try how dll file
#add_library(dllprint SHARED ${dlldir}/Dll1.dll)
#set_target_properties(dllprint PROPERTIES LINKER_LANGUAGE CXX)

#4 try how cpp or h file
# cpp not needed, just for test
#add_library(dllprint SHARED testdll.h)
#set_target_properties(dllprint PROPERTIES LINKER_LANGUAGE CXX)

#link native-lib to use in java
add_library( native-lib SHARED native-lib.cpp )
find_library( log-lib log )
target_link_libraries( native-lib ${log-lib} )

target_link_libraries( dllprint ${log-lib} )

#end try link native-lib to dllpint
target_link_libraries( native-lib ${dllprint} )