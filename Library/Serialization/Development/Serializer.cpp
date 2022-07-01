#include <Serialization/Common/SerializerPrivate.hpp>
#include <Serialization/Serializer.hpp>

Serializer::Serializer (const char *_outputFileName) noexcept
    : implementation (new SerializerImplementation {std::ofstream {_outputFileName, std::ofstream::out}})
{
}

void Serializer::WriteInt32 (int32_t _number) noexcept
{
    implementation->output << _number << std::endl;
}

void Serializer::WriteAsciiString (const char *_string) noexcept
{
    implementation->output << _string << std::endl;
}

void Serializer::WriteAsciiComment (const char *_string) noexcept
{
    implementation->output << "# " << _string << std::endl;
}
