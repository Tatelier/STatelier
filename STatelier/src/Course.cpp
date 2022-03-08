#include "..\include\Course.h"

namespace STatelier::Score
{
	double Course::GetLevel()
	{
		return m_level;
	}
	void Course::SetLevel(double level)
	{
		m_level = level;
	}
	CourseType Course::GetCourseType()
	{
		return m_courseType;
	}
	void Course::SetCourseType(CourseType courseType)
	{
		m_courseType = courseType;
	}
	bool Course::TryGetCourseTypeFromText(const std::string& courseName, CourseType* pCourseType)
	{
		std::string courseNameUpper = courseName;

		std::transform(courseNameUpper.begin(), courseNameUpper.end(), courseNameUpper.begin(), [](unsigned char c) { return toupper(c); });

		if ("EASY" == courseNameUpper
			|| "0" == courseNameUpper
			)
		{
			*pCourseType = CourseType::Easy;
		}
		else if ("NORMAL" == courseNameUpper
			|| "1" == courseNameUpper
			)
		{
			*pCourseType = CourseType::Normal;
		}
		else if ("HARD" == courseNameUpper
			|| "2" == courseNameUpper
			)
		{
			*pCourseType = CourseType::Hard;
		}
		else if ("VERYHARDA" == courseNameUpper
			|| "3" == courseNameUpper
			|| "ONI" == courseNameUpper
			)
		{
			*pCourseType = CourseType::VeryHardA;
		}
		else if ("VERYHARDB" == courseNameUpper
			|| "4" == courseNameUpper
			|| "URA" == courseNameUpper
			|| "EDIT" == courseNameUpper
			)
		{
			*pCourseType = CourseType::VeryHardB;
		}
		else
		{
			return false;
		}

		return true;
	}
}