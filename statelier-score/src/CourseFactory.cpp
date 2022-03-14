#include "CourseFactory.h"

#include <Course.h>

namespace STatelier::Score
{
	std::shared_ptr<Course> CourseFactory::Create()
	{
		return std::make_shared<Course>();
	}
}