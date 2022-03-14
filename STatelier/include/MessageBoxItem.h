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
						header = "Info";
					}
					break;
				case MessageBoxType::Warning:
					{
						header = "Warning";
					}
					break;
				case MessageBoxType::Error:
					{
						header = "Error";
					}
					break;
			}
		}
		const MessageBoxInfo& GetInfo()
		{
			return info;
		}

		const std::string& GetHeader()
		{
			return header;
		}

		const unsigned int GetTypeColor()
		{
			switch (info.messageBoxType)
			{
				case MessageBoxType::Info:
					{
						return 0x3089CC;
					}
					break;
				case MessageBoxType::Warning:
					{
						return 0xBBBB00;
					}
					break;
				case MessageBoxType::Error:
					{
						return 0xFF8888;
					}
					break;
				default:
					return 0xFFFFFF;
			}
		}
	private:
		MessageBoxInfo info;
		std::string header;
	};
}