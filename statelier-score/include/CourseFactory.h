#pragma once

#include <memory>

namespace STatelier::Score
{
	class Course;
	/**
	 * @brief Courseインスタンスファクトリ
	*/
	class CourseFactory
	{
	public:
		std::shared_ptr<Course> Create();
	};
}