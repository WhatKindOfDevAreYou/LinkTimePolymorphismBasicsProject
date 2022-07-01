cmake_minimum_required (VERSION 3.21)
project (LinkTimePolymorphismBasicsProject)

set (CMAKE_CXX_STANDARD 20)

# Build system option that is used for implementation selection.
option (DEVELOPMENT "Whether to use development serialization library." OFF)

# Declare core set of sources, that are used in any case.
set (SOURCES
        "App/Main.cpp"
        "Library/Serialization/Serializer.hpp"
        "Library/Serialization/Common/SerializerPrivate.cpp"
        "Library/Serialization/Common/SerializerPrivate.hpp")

# Depending on build system option append source file with implementation.
if (DEVELOPMENT)
    list (APPEND SOURCES "Library/Serialization/Development/Serializer.cpp")
else ()
    list (APPEND SOURCES "Library/Serialization/Production/Serializer.cpp")
endif ()

# Finally, create our application target.
add_executable (App ${SOURCES})
target_include_directories (App PRIVATE "Library/")
