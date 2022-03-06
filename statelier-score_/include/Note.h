#pragma once

#include <cstdint>
#include "DLLExport.h"
#include "NoteType.h"

namespace STatelier::Score {
	class DLL_EXPORT Note {
	public:
		NoteType GetNoteType();
		void SetNoteType(NoteType value);

		int32_t GetStartMillisec();
		void SetStartMillisec(int32_t value);
	private:
		NoteType m_noteType;
		int32_t m_startMillisec;
	};
}