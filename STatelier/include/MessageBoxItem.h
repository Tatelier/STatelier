#pragma once
#include <string>

#include <MessageBoxInfo.h>

namespace STatelier
{
	class MessageBoxItem
	{
	public:
		MessageBoxItem()
		{

		}
		void Init(const MessageBoxInfo& info)
		{
			this->info = info;

			switch (info.messageBoxType)
			{
				case MessageBoxType::Info:
					{
						header = u8"Info";
					}
					break;
				case MessageBoxType::Warning:
					{
						header = u8"Warning";
					}
					break;
				case MessageBoxType::Error:
					{
						header = u8"Error";
					}
					break;
			}
		}
		const MessageBoxInfo& GetInfo()
		{
			return info;
		}

		const std::u8string& GetHeader()
		{
			return header;
		}

	private:
		MessageBoxInfo info;
		std::u8string header;
	};
}