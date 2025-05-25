cmake_minimum_required(VERSION 3.10)

project(DataBroadcaster)

add_executable(DataBroadcaster 
                src/databroadcasterapp.cpp
                src/serialreader.cpp
                src/datapacket.cpp
                src/main.cpp
              )

add_custom_command(TARGET DataBroadcaster POST_BUILD
    COMMAND chmod +x $<TARGET_FILE:DataBroadcaster>
    COMMENT "Making DataBroadcaster executable"
)