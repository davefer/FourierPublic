cmake_minimum_required(VERSION 3.10)

project(DataBroadcaster)

add_executable(DataBroadcaster 
                src/main.cpp
                src/databroadcasterapp.cpp)

add_custom_command(TARGET DataBroadcaster POST_BUILD
    COMMAND chmod +x $<TARGET_FILE:DataBroadcaster>
    COMMENT "Making DataBroadcaster executable"
)