# Let's start from header-only API target. It only contains include path and our API header.
add_library (SerializationAPI INTERFACE "Serializer.hpp")
target_include_directories (SerializationAPI INTERFACE "..")

# Declare common library target that will be used by both our implementations.
# NOTE: In order for implementation detection to work properly we need to make this library shared too.
#       Implementation detection will flag `no destructor` link error if we link it as static like before.
add_library (SerializationCommon SHARED "Common/SerializerPrivate.cpp" "Common/SerializerPrivate.hpp")
target_link_libraries (SerializationCommon PUBLIC SerializationAPI)
target_compile_definitions (SerializationCommon PRIVATE SERIALIZATION_IMPLEMENTATION)

# Declare Development implementation library.
add_library (SerializationDevelopment SHARED "Development/Serializer.cpp")
target_link_libraries (SerializationDevelopment PUBLIC SerializationCommon)
target_compile_definitions (SerializationDevelopment PRIVATE SERIALIZATION_IMPLEMENTATION)
set_target_properties (SerializationDevelopment PROPERTIES OUTPUT_NAME "Development/Serialization")

# Declare Production implementation library.
add_library (SerializationProduction SHARED "Production/Serializer.cpp")
target_link_libraries (SerializationProduction PUBLIC SerializationCommon)
target_compile_definitions (SerializationProduction PRIVATE SERIALIZATION_IMPLEMENTATION)
set_target_properties (SerializationProduction PROPERTIES OUTPUT_NAME "Production/Serialization")
