cmake_minimum_required (VERSION 3.12 FATAL_ERROR)

project (billy2020 VERSION 0.1)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

# Export compile commands for completion engines (optional)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set option to control setting the resource path variable
option(USE_INSTALL_RESOURCE_PATH "Set resource path to install location" OFF)

if(NOT USE_INSTALL_RESOURCE_PATH)
  set(RESOURCE_PATH "${PROJECT_SOURCE_DIR}/content/")
else()
  set(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}/content/")
endif()

# Generate config.h
configure_file(include/config.h.in config.h)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Compile executable
set(PROJECT_SOURCES
    src/start.cpp
    src/Game.cpp
    src/LoadMap.cpp
    src/Player.cpp
    src/ResourceDispatcher.cpp
    src/ResourceManager.cpp
    src/TilesMap.cpp
    src/Animation.cpp
    include/Game.h
    include/LoadMap.h
    include/Player.h
    include/ResourceDispatcher.h
    include/ResourceManager.h
    include/TilesMap.h
    include/Animation.h
)

add_executable(Billy ${PROJECT_SOURCES})

# Set include directory search paths
target_include_directories(Billy 
  PRIVATE
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
  )

# Set executable RPATH
set_target_properties(Billy
PROPERTIES
	INSTALL_RPATH
	  "${CMAKE_INSTALL_PREFIX}/lib"
)

# Link executable to required SFML modules
target_link_libraries(Billy sfml-graphics sfml-audio)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Set executable install location
install(TARGETS Billy DESTINATION bin)

# Set install location for resources
install(DIRECTORY content
  DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
)
