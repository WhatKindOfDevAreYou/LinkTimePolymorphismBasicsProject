add_executable (App "Main.cpp")

# Link required implementation library depending on build option.
if (DEVELOPMENT)
    target_link_libraries (App PRIVATE SerializationDevelopment)
else ()
    target_link_libraries (App PRIVATE SerializationProduction)
endif ()
