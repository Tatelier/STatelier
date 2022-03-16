#include <System/Text/StringBuilder.hpp>

#include <iostream>

namespace SimilarDotNet::System::Text
{
	StringBuilder* StringBuilder::Append(const std::u8string& text)
	{
		ss << (const char*)text.c_str();
		return this;
	}
	StringBuilder* StringBuilder::Append(int32_t value)
	{
		ss << value;
		return this;
	}
	bool StringBuilder::TryToString(std::u8string* text)
	{
		*text = (const char8_t*)(ss.str().c_str());
		return true;
	}
	bool StringBuilder::TryToString(std::string* text)
	{
		*text = ss.str();
		return true;
	}

	StringBuilder* StringBuilder::Clear()
	{
		ss.clear();

		return this;
	}
}

int main(void)
{
	using namespace SimilarDotNet::System::Text;

	StringBuilder sb;

	sb.Append(u8"aiueo")->Append(u8"‚¨‚¯");
	std::string a;
	if (sb.TryToString(&a))
	{
		std::cout << (const char*)a.c_str();
	}
}