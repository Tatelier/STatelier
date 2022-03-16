#pragma once

#include <IInput.h>
#include <vector>

namespace STatelier::SongSelect
{
    class PlayerInput
        : public IInput
    {
    public:
        const static int INPUT_LEFT = -1;
        const static int INPUT_RIGHT = -2;

        virtual int GetCount(int keyCode) const override;

        virtual bool GetKeyUp(int keyCode) const override;

        virtual bool GetKeyDown(int keyCode) const override;

        virtual bool GetKey(int keyCode) const override;

        virtual void Update() override;

        virtual void Reset() override;

        virtual bool IsEnabled() const override;

        virtual void SetEnabled(bool enabled) override;

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
        void SetBaseInput(IInput* pBaseInput);
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