#include "Note.h"

namespace STatelier::Score {
	NoteType Note::GetNoteType()
	{
		return m_noteType;
	}
	void Note::SetNoteType(NoteType value)
	{
		m_noteType = value;
	}
	int32_t Note::GetStartMillisec() {
		return m_startMillisec;
	}

	void Note::SetStartMillisec(int32_t value) {
		m_startMillisec = value;
	}
}