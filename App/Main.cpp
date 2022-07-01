#include <Serialization/Serializer.hpp>

int main ()
{
    Serializer serializer {"Test.out"};
    serializer.WriteAsciiComment ("This is test file comment line.");
    serializer.WriteAsciiString ("Hello, world!");
    serializer.WriteInt32 (1024);
    return 0;
}
