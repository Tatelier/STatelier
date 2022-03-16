#pragma once

#include <IInput.h>

namespace STatelier
{
	class InputControl;

	class Input : public IInput
	{
	public:
		virtual int GetCount(int keyCode) const override;

		virtual bool GetKeyDown(int keyCode) const override;
		virtual bool GetKeyUp(int keyCode) const override;
		virtual bool GetKey(int keyCode) const override;

		virtual void Update();
		virtual void Reset() override;
		virtual bool IsEnabled() const override;
		virtual void SetEnabled(bool enabled) override;
		Input(InputControl* pInputControl);
	private:
		InputControl* m_pInputControl;
		int bytes[256] = { 0 };
		bool m_enabled = true;
	};
}