#pragma once

#include <cstdint>
#include <memory>

struct SerializerImplementation;

class Serializer final
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
    SerializerImplementation *implementation;
};
