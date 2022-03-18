cmake_minimum_required(VERSION 3.8)
project(coreclrhelper)
enable_language(CXX)
SET(CMAKE_BUILD_TYPE RelWithDebInfo)

if(${APPLE})
  set(DefaultBuildOS "OSX")
  add_definitions(-DPLATFORM_UNIX)
  add_definitions(-DPAL_STDCPP_COMPAT)
elseif(${WIN32})
  set(DefaultBuildOS "Windows")
else()
  set(DefaultBuildOS "Linux")
  add_definitions(-DPLATFORM_UNIX)
  # add_definitions(-DPAL_STDCPP_COMPAT)
  # add_definitions(-DPAL_IMPLEMENTATION)
  add_definitions(-DFEATURE_PAL_ANSI)
  add_definitions(-DHOST_64BIT)
  add_definitions(-DHOST_UNIX)
  add_definitions(-DHOST_AMD64)
  add_definitions(-DTARGET_AMD64)
  add_definitions(-DTARGET_UNIX)
  add_definitions(-DUNICODE)
  add_definitions(-D_UNICODE)
  add_definitions(-D_FEATURE_NO_HOST)
  add_definitions(-D__ILDASM__)
  add_definitions(-DFEATURE_CORECLR)

endif()
add_compile_options(-nostdinc)
if(${CMAKE_SIZEOF_VOID_P} EQUAL "8")
  set(DefaultBuildArch "x64")
  add_definitions(-DBIT64)
else()
  set(DefaultBuildArch "x86")
endif()
set(CORECLR_PATH "${PROJECT_SOURCE_DIR}/../../../")
set(BuildOS ${DefaultBuildOS} CACHE STRING "Operating system for build.")
set(BuildArch ${DefaultBuildArch} CACHE STRING "Build architecture (x64, x86)")
set(BuildType "Debug" CACHE STRING "Build type (Release, Debug)")
set(Output "coreclrhelper")
if(${WIN32})
  add_compile_options(
    -fPIC
    -fms-extensions
    -std=c++14
  )
else()
  set(THREADS_PREFER_PTHREAD_FLAG ON)
  find_package(Threads REQUIRED)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-strict-aliasing")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-invalid-noreturn -Wno-ignored-attributes")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fms-extensions -fPIC")
  # set (CMAKE_SHARED_LINKER_FLAGS "-static-libstdc++") 
endif()

file(GLOB SOURCES
  "${CORECLR_PATH}/src/ildasm/ceeload.cpp"
  "${CORECLR_PATH}/src/pal/prebuilt/idl/corprof_i.cpp"
  "*.cpp"
  "*.c"
)

add_library(${Output} STATIC ${SOURCES})
target_link_libraries(${Output} coreclrpal)
target_link_libraries(${Output} ildasm_so)

# We include files in two steps to force the order that the compiler chooses
include_directories(SYSTEM
  "${CORECLR_PATH}/src"
  "${CORECLR_PATH}/src/inc"
  "${CORECLR_PATH}/src/ildasm"
  "${CORECLR_PATH}/src/pal/inc"
  "${CORECLR_PATH}/src/pal/inc/rt"
  "${CORECLR_PATH}/src/pal/inc/rt/cpp"
  "${CORECLR_PATH}/src/pal/src/include"
  "${CORECLR_PATH}/src/pal/prebuilt/inc"
)

include_directories(
  "${CORECLR_PATH}/src"
  "${CORECLR_PATH}/src/inc"
  "${CORECLR_PATH}/src/ildasm"
  "${CORECLR_PATH}/src/pal/inc"
  "${CORECLR_PATH}/src/pal/inc/rt/cpp"
  "${CORECLR_PATH}/src/pal/src/include"
  "${CORECLR_PATH}/src/pal/prebuilt/inc"
)