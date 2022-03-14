#pragma once

#include <string>
#include <array>
#include <MessageBoxType.h>

#include <functional>

namespace STatelier
{
    struct MessageBoxInfoExe
    {
        std::string content = "OK";
        std::function<void()> func;
    };
    struct MessageBoxInfo
    {
        MessageBoxType messageBoxType = MessageBoxType::Info;

        std::string header;
        std::string content;

        std::array<MessageBoxInfoExe, 5> messageBoxInfoExe;
    };
}