#pragma once

#include <cstdint>

// Declare whether we're exporting or importing dynamic symbols. Needed only for Windows builds.
#ifdef SERIALIZATION_IMPLEMENTATION
#    define SERIALIZATION_API __declspec(dllexport)
#else
#    define SERIALIZATION_API __declspec(dllimport)
#endif

// We are using PImpl approach to hide implementation data from user code.
// https://en.cppreference.com/w/cpp/language/pimpl
// It also allows to easily switch DLLs.
//
// The other approach is to use inplace fixed size array, which is better for
// this case, but makes  tutorial much less readable. So I've decided to sacrifice
// performance for readability, because performance means nothing here.
struct SerializerImplementation;

class SERIALIZATION_API Serializer final
{
public:
    explicit Serializer (const char *_outputFileName) noexcept;

    Serializer (const Serializer &_other) = delete;

    Serializer (Serializer &&_other) noexcept;

    ~Serializer () noexcept;

    void WriteInt32 (int32_t _number) noexcept;

    void WriteAsciiString (const char *_string) noexcept;

    void WriteAsciiComment (const char *_string) noexcept;

private:
    // We cannot use std::unique_ptr here because SerializerImplementation is undefined.
    SerializerImplementation *implementation = nullptr;
};
