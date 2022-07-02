add_executable (App "Main.cpp")

# Link required implementation library depending on build option.
if (DEVELOPMENT)
    target_link_libraries (App PRIVATE SerializationDevelopment)
else ()
    target_link_libraries (App PRIVATE SerializationProduction)
endif ()

# We need to copy runtime libraries to our executable folder.
add_custom_command (
        TARGET App POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_RUNTIME_DLLS:App> $<TARGET_FILE_DIR:App>
        COMMAND_EXPAND_LISTS)
