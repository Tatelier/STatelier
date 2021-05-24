#pragma once

#include <string>
#include <vector>

namespace Tatelier {

	struct ErrorItem {
		unsigned int ErrorCode = 0x80000000;
		std::string Text = "Undefined";
	};

	class Error : public std::vector<ErrorItem> {
	public:
	};

	/**
	 * @brief �G���[�i�[�ϐ�
	 */
	extern thread_local Error err;
}