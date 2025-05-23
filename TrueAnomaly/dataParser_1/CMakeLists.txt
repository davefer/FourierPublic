cmake_minimum_required(VERSION 3.10)

project(DataParser)

add_executable(DataParser 
                src/main.cpp
                src/dataparserapp.cpp)

add_custom_command(TARGET DataParser POST_BUILD
    COMMAND chmod +x $<TARGET_FILE:DataParser>
    COMMENT "Making DataParser executable"
)