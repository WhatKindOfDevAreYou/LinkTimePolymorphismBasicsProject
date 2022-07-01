cmake_minimum_required (VERSION 3.21)
project (LinkTimePolymorphismBasicsProject)

set (CMAKE_CXX_STANDARD 20)

set (SOURCES
        "App/Main.cpp"
        "Library/Serialization/Serializer.hpp"
        "Library/Serialization/Common/SerializerPrivate.cpp"
        "Library/Serialization/Common/SerializerPrivate.hpp")

if (DEVELOPMENT)
    list (APPEND SOURCES "Library/Serialization/Development/Serializer.cpp")
else ()
    list (APPEND SOURCES "Library/Serialization/Production/Serializer.cpp")
endif ()

add_executable (App ${SOURCES})
target_include_directories (App PRIVATE "Library/")
