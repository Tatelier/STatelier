#pragma once
#include <IInput.h>
#include <vector>

namespace STatelier::SongSelect
{
    class Player
    {
    public:
        IInput* GetInput();
        void SetInput(IInput* pInput);
    private:
        IInput* m_pInput;
    };


}