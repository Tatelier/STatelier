#pragma once
#include <string>
#include <sstream>
#include <cstdint>

namespace SimilarDotNet::System::Text
{
    class StringBuilder
    {
    public:
        StringBuilder* Append(const std::u8string& text);
        StringBuilder* Append(int32_t value);
        bool TryToString(std::u8string* text);
        bool TryToString(std::string* text);
        StringBuilder* Clear();
    private:
        std::stringstream ss;
    };
};