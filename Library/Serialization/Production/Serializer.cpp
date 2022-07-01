#define _CRT_SECURE_NO_WARNINGS

#include <Serialization/Common/SerializerPrivate.hpp>
#include <Serialization/Serializer.hpp>

Serializer::Serializer (const char *_outputFileName) noexcept
    : implementation (
          new SerializerImplementation {std::ofstream {_outputFileName, std::ofstream::out | std::ofstream::binary}})
{
}

void Serializer::WriteInt32 (int32_t _number) noexcept
{
    // It is incorrect to save ints like this because it ignores endianness. But it is ok enough for our sample.
    implementation->output.write (reinterpret_cast<const char *> (&_number), sizeof (_number));
}

void Serializer::WriteAsciiString (const char *_string) noexcept
{
    // We are adding 1 to strlen in order to capture zero terminator.
    implementation->output.write (_string, strlen (_string) + 1u);
}

void Serializer::WriteAsciiComment (const char *_string) noexcept
{
    // There is no comments in production files.
}
