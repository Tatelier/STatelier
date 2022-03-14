#pragma once
#include <string>
#include <memory>
#include <algorithm>

#include "CourseType.h"
#include <vector>

namespace STatelier::Score
{
	class Course;

	using CourseList = std::vector<std::shared_ptr<Course>>;

	class Course
	{
	public:
		double GetLevel();
		void SetLevel(double level);
		CourseType GetCourseType();
		void SetCourseType(CourseType courseType);
		static bool TryGetCourseTypeFromText(const std::string& courseName, CourseType* courseType);
	private:
		double m_level = -1;
		CourseType m_courseType = CourseType::VeryHardA;
	};
}