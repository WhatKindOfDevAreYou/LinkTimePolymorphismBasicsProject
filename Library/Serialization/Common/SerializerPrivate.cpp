#include <Serialization/Common/SerializerPrivate.hpp>

Serializer::Serializer (Serializer &&_other) noexcept : implementation (_other.implementation)
{
    _other.implementation = nullptr;
}

Serializer::~Serializer () noexcept
{
    delete implementation;
}
