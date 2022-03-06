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
	bool Course::TryGetCourseTypeFromText(const std::string& courseName, CourseType* courseType)
	{
		std::string courseNameUpper = courseName;

		std::transform(courseNameUpper.begin(), courseNameUpper.end(), courseNameUpper.begin(), [](unsigned char c) { return toupper(c); });

		if ("EASY" == courseNameUpper
			|| "0" == courseNameUpper
			)
		{
			*courseType = CourseType::Easy;
		}
		else if ("NORMAL" == courseNameUpper
			|| "1" == courseNameUpper
			)
		{
			*courseType = CourseType::Normal;
		}
		else if ("HARD" == courseNameUpper
			|| "2" == courseNameUpper
			)
		{
			*courseType = CourseType::Hard;
		}
		else if ("VERYHARDA" == courseNameUpper
			|| "3" == courseNameUpper
			|| "ONI" == courseNameUpper
			)
		{
			*courseType = CourseType::VeryHardA;
		}
		else if ("VERYHARDB" == courseNameUpper
			|| "4" == courseNameUpper
			|| "URA" == courseNameUpper
			|| "EDIT" == courseNameUpper
			)
		{
			*courseType = CourseType::VeryHardB;
		}
		else
		{
			return false;
		}

		return true;
	}
}