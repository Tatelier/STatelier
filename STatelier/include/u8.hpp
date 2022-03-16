#pragma once

#include <array>
#include <string>

namespace STatelier::UTF8
{
	int GetCharU8(const char8_t* text, int size, int startIndex, std::array<char8_t, 7>* resultChar)
	{
		if (startIndex >= size)
		{
			return -1;
		}

		char8_t initial = text[startIndex];

		int resultSize = 1;

		if ((initial & 0xF0) == 0xF0)
		{
			resultSize = 4;
		}
		else if ((initial & 0xE0) == 0xE0)
		{
			resultSize = 3;
		}
		else if ((initial & 0xC0) == 0xC0)
		{
			resultSize = 2;
		}
		else if ((initial & 0x80) == 0x80)
		{
			return -2;
		}
		else
		{
			resultSize = 1;
		}

		int k = 0;
		for (int i = startIndex; i < startIndex + resultSize; i++)
		{
			resultChar->data()[k] = text[i];
			k++;
		}
		resultChar->data()[k] = '\0';

		return resultSize;
	}

	/**
	 * @brief UTF8�^�̕�����1�����擾����
	 * @param text �擾��������
	 * @param startIndex �擾�J�n�ʒu
	 * @param resultChar �擾����1����
	 * @return �擾����1�����̃T�C�Y
	*/
	int GetCharU8(const std::u8string& text, int startIndex, std::array<char8_t, 7>* resultChar)
	{
		return GetCharU8(text.c_str(), text.size(), startIndex, resultChar);
	}
}