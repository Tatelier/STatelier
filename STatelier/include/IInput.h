#pragma once

namespace STatelier
{
	class IInput
	{
	public:
		virtual void Update() = 0;
		virtual int GetCount(int keyCode) const = 0;
		virtual void SetEnabled(bool enabled) = 0;
		virtual bool IsEnabled() const = 0;
	};
}