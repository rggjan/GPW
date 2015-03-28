cmake_minimum_required(VERSION 3.2)
project(GPW)

# Appends the cmake/modules path inside the MAKE_MODULE_PATH variable which stores the
# directories of additional CMake modules (eg MacroOutOfSourceBuild.cmake):
set(CMAKE_MODULE_PATH ${GPW_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})


set(SOURCES_CLIENT
  Sources/custom_type.h
  Sources/Client
  Sources/Client/main.cpp
  Sources/Client/client.cpp
  Sources/Client/client.h
)

set(SOURCES_SERVER
  Sources/custom_type.h
  Sources/Server/main.cpp
  Sources/Server/server_user.cpp
  Sources/Server/server_user.h
  Sources/Server/server.cpp
  Sources/Server/server.h
)

# Find clanlib
set(ClanLib_MAJOR_VERSION 3)
set(ClanLib_MINOR_VERSION 0)

find_package(ClanLib COMPONENTS Network REQUIRED)

# Include clanlib
include_directories(${ClanLib_INCLUDE_DIRS})

# Add compiler flags
add_definitions(${ClanLib_DEFINITIONS})

add_executable(gpw_client ${SOURCES_CLIENT})
add_executable(gpw_server ${SOURCES_SERVER})

# Link with clanlib
target_link_libraries(gpw_client ${ClanLib_LIBRARIES} pthread)
target_link_libraries(gpw_server ${ClanLib_LIBRARIES} pthread)

set_property(TARGET gpw_client PROPERTY CXX_STANDARD 11)
set_property(TARGET gpw_server PROPERTY CXX_STANDARD 11)
