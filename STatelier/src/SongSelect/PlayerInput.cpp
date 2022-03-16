#include <SongSelect/PlayerInput.h>

namespace STatelier::SongSelect
{
    int PlayerInput::GetCount(int keyCode) const
    {
        switch (keyCode)
        {
            case INPUT_LEFT:
                // TODO: pLeftInputList���g�������ɕύX����
                return pBaseInput->GetCount(keyCode);
            case INPUT_RIGHT:
                // TODO: pRightInputList���g�������ɕύX����
                return pBaseInput->GetCount(keyCode);
            default:
                return pBaseInput->GetCount(keyCode);
        }
    }
    
    bool PlayerInput::GetKeyUp(int keyCode) const
    {
        switch (keyCode)
        {
            case INPUT_LEFT:
                // TODO: pLeftInputList���g�������ɕύX����
                return pBaseInput->GetKeyUp(keyCode);
            case INPUT_RIGHT:
                // TODO: pRightInputList���g�������ɕύX����
                return pBaseInput->GetKeyUp(keyCode);
            default:
                return pBaseInput->GetKeyUp(keyCode);
        }
    }
    bool PlayerInput::GetKeyDown(int keyCode) const
    {
        switch (keyCode)
        {
            case INPUT_LEFT:
                // TODO: pLeftInputList���g�������ɕύX����
                return pBaseInput->GetKeyDown(keyCode);
            case INPUT_RIGHT:
                // TODO: pRightInputList���g�������ɕύX����
                return pBaseInput->GetKeyDown(keyCode);
            default:
                return pBaseInput->GetKeyDown(keyCode);
        }
    }
    bool PlayerInput::GetKey(int keyCode) const
    {
        switch (keyCode)
        {
            case INPUT_LEFT:
                // TODO: pLeftInputList���g�������ɕύX����
                return pBaseInput->GetKey(keyCode);
            case INPUT_RIGHT:
                // TODO: pRightInputList���g�������ɕύX����
                return pBaseInput->GetKey(keyCode);
            default:
                return pBaseInput->GetKey(keyCode);
        }
    }
    void PlayerInput::Update()
    {
        pBaseInput->Update();
    }
    void PlayerInput::Reset()
    {
        pBaseInput->Reset();
    }
    bool PlayerInput::IsEnabled() const
    {
        return pBaseInput->IsEnabled();
    }
    void PlayerInput::SetEnabled(bool enabled)
    {
        pBaseInput->SetEnabled(enabled);
    }
    void PlayerInput::SetBaseInput(IInput* pBaseInput)
    {
        this->pBaseInput = pBaseInput;
    }
}