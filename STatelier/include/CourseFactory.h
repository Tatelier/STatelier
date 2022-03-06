#pragma once

#include <memory>

namespace STatelier::Score
{
	class Course;
	/**
	 * @brief Course�C���X�^���X�t�@�N�g��
	*/
	class CourseFactory
	{
	public:
		std::shared_ptr<Course> Create();
	};
}