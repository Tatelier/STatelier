#include "Input.h"

namespace Tatelier {

	int Input::GetCount(int key)
	{
		return m_CountArray[key];
	}

	Input& Input::GetInstance()
	{
		static Input input;
		return input;
	}

	bool Input::GetKey(int key)
	{
		return GetCount(key) > 0;
	}

	bool Input::GetKeyUp(int key)
	{
		return GetCount(key) == -1;
	}

	bool Input::GetKeyDown(int key)
	{
		return GetCount(key) == 1;
	}

	void Input::Update()
	{
		if (GetHitKeyStateAll(m_ByteArray) == 0) {
			for (int i = 0; i < ARRAY_SIZE; i++) {
				if (m_ByteArray[i] > 0) {
					m_CountArray[i]++;
				}
				else {
					if (m_CountArray[i] > 0) {
						m_CountArray[i] = -1;
					}
					else {
						m_CountArray[i] = 0;
					}
				}
			}
		}
	}
}