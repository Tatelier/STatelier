#pragma once


namespace STatelier
{
	class IInput
	{
	public:
		virtual void Update() = 0;
		virtual int GetCount(int keyCode) = 0;
	};
}