# general info
cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME FightClubGameAppCMake)
project(${PROJECT_NAME} VERSION 1.0.0)

message(STATUS "----------- Project files generation for ${PROJECT_NAME} -----------------")

#common options
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

message("Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})


message("CMAKE_CURRENT_SOURCE DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
set_property(GLOBAL PROPERTY USE_FOLDER ON)
set(CMAKE_SUPPRESS_REGENERATION  TRUE)
#cpp options

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /FA")

#app options

# sources
set(SOURCES 
Source/main.cpp
   )

  

  set(MATH_SOURCES Source/Utils/Math.cpp)
  set(MATH_INCLUDES Source/Utils/Math.h)

  set(DLL_GAME_SOURCES
   Source/Game/Weapon.cpp
   Source/Game/Character.cpp
)
  set(DLL_GAME_INCLUDES
 Source/Game/Weapon.h
  Source/Game/Character.h
)

#   source_group("Source files/Utils" FILES "Source/Utils/Math.cpp")
# source_group("Header files/Utils" FILES "Source/Utils/Math.h")

source_group("Source files/Game" FILES "Source/Game/Weapon.cpp"  "Source/Game/Character.cpp")
source_group("Header files/Game" FILES "Source/Game/Weapon.h"  "Source/Game/Character.h")


# targets
add_executable(${PROJECT_NAME} ${SOURCES})
add_library(MathLib STATIC ${MATH_SOURCES} ${MATH_INCLUDES})
add_library(${PROJECT_NAME}Lib SHARED ${DLL_GAME_SOURCES} ${DLL_GAME_INCLUDES})
add_executable(${PROJECT_NAME}TestRunner Source/Tests/main.cpp)


target_compile_definitions(${PROJECT_NAME}Lib PRIVATE _EXPORTING)
target_compile_definitions(${PROJECT_NAME} PUBLIC _IMPORTING)
  
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Lib)
target_link_libraries(${PROJECT_NAME}Lib PRIVATE MathLib)
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE MathLib)
target_link_libraries(${PROJECT_NAME}TestRunner PRIVATE ${PROJECT_NAME}Lib)

#includes
message("CMAKE_CURRENT_SOURCE_DIR:  ${CMAKE_CURRENT_SOURCE_DIR}")
# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
# target_include_directories(${PROJECT_NAME}Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source)
# target_include_directories(${PROJECT_NAME}TestRunner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source) 

set(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}TestRunner ${PROJECT_NAME}Lib)

foreach(target IN LISTS TARGETS)
  target_include_directories(${target} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source) 
endforeach(<loop_)


message("SOURCES: ${SOURCES}")
message("INCLUDES: ${INCLUDES}")



# if(MSVC)

if(${WIN32})#if(WIN32)
message("Running on Windows")
elseif(LINUX)
message("Running on Linux")

endif()

if(${MSVC_TOOLSET_VERSION} EQUAL 143)
  MESSAGE("!!!!!!!!!!!!!")
endif()

message("using ${CMAKE_CXX_COMPILER_ID} comiler")
message("MSVC version: ${MSVC_VERSION}")
message("MSVC toolset version: ${MSVC_TOOLSET_VERSION}")

target_compile_options(${PROJECT_NAME} PRIVATE /FAc)
# endif()


message("Compiler flags: ${CMAKE_CXX_FLAGS}")
message("Compiler debug flags: ${CMAKE_CXX_FLAGS_DEBUG}")
message("Compiler release flags: ${CMAKE_CXX_FLAGS_RELEASE}")
message("Configuration types: ${CMAKE_CONFIGURATION_TYPES}")