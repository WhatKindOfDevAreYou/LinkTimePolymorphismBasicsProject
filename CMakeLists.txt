cmake_minimum_required (VERSION 3.21)
project (LinkTimePolymorphismBasicsProject)

set (CMAKE_CXX_STANDARD 20)

# Build system option that is used for implementation selection.
option (DEVELOPMENT "Whether to use development serialization library." OFF)

# Just add our subscripts for application and library.
add_subdirectory (App)
add_subdirectory (Library/Serialization)
