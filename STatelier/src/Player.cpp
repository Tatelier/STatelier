#include "Player.h"


namespace STatelier::SongSelect
{
    IInput* Player::GetInput()
    {
        return m_pInput;
    }
    void Player::SetInput(IInput* pInput)
    {
        m_pInput = pInput;
    }
}