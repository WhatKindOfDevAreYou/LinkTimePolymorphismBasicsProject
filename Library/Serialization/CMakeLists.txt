# Let's start from header-only API target. It only contains include path and our API header.
add_library (SerializationAPI INTERFACE "Serializer.hpp")
target_include_directories (SerializationAPI INTERFACE "..")

# Declare common library target that will be used by both our implementations.
add_library (SerializationCommon STATIC "Common/SerializerPrivate.cpp" "Common/SerializerPrivate.hpp")
target_link_libraries (SerializationCommon PUBLIC SerializationAPI)

# Declare Development implementation library.
add_library (SerializationDevelopment STATIC "Development/Serializer.cpp")
target_link_libraries (SerializationDevelopment PUBLIC SerializationCommon)

# Declare Production implementation library.
add_library (SerializationProduction STATIC "Production/Serializer.cpp")
target_link_libraries (SerializationProduction PUBLIC SerializationCommon)
