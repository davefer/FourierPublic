cmake_minimum_required(VERSION 3.10)

project(DataBroadcaster)

set(CMAKE_BUILD_TYPE Debug)

add_executable(DataBroadcaster 
                src/main.cpp
                src/databroadcasterapp.cpp
                src/serialreader.cpp
                src/datapacket.cpp
              )

add_custom_command(TARGET DataBroadcaster POST_BUILD
    COMMAND chmod +x $<TARGET_FILE:DataBroadcaster>
    COMMENT "Making DataBroadcaster executable"
)