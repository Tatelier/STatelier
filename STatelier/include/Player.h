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

    class PlayerInput
        : public IInput
    {
    public:
        const static int INPUT_LEFT = -1;
        const static int INPUT_RIGHT = -2;
        
        virtual int GetCount(int keyCode) const override
        {
            switch (keyCode)
            {
                case INPUT_LEFT:
                    // TODO: pLeftInputListを使う処理に変更する
                    return pBaseInput->GetCount(keyCode);
                case INPUT_RIGHT:
                    // TODO: pRightInputListを使う処理に変更する
                    return pBaseInput->GetCount(keyCode);
                default:
                    return pBaseInput->GetCount(keyCode);
            }
        }

        virtual void Update() override
        {
            pBaseInput->Update();
        }

        virtual bool IsEnabled() const override
        {
            return pBaseInput->IsEnabled();
        }

        virtual void SetEnabled(bool enabled) override
        {
            pBaseInput->SetEnabled(enabled);
        }

        template<typename iterator>
        void SetLeftInput(iterator begin, iterator end)
        {
            SetInput(leftInputList, begin, end);
        }

        template<typename iterator>
        void SetRightInput(iterator begin, iterator end)
        {
            SetInput(rightInputList, begin, end);
        }

        PlayerInput()
        {
        }
        void SetBaseInput(IInput* pBaseInput)
        {
            this->pBaseInput = pBaseInput;
        }
    private:
        template<typename iterator>
        void SetInput(std::vector<int>& list, iterator begin, iterator end)
        {
            list.clear();

            for (; begin != end; ++begin)
            {
                list.push_back(*begin);
            }
        }
        IInput* pBaseInput;
        std::vector<int> leftInputList;
        std::vector<int> rightInputList;
    };

}