#pragma once

#include <string>
#include <array>
#include <MessageBoxType.h>

#include <functional>

namespace STatelier
{
    struct MessageBoxInfoExe
    {
        std::u8string content = u8"OK";
        std::function<void()> func;
    };
    struct MessageBoxInfo
    {
        MessageBoxType messageBoxType = MessageBoxType::Info;

        std::u8string header;
        std::u8string content;

        std::array<MessageBoxInfoExe, 4> messageBoxInfoExe;
    };
}