#pragma once

#include <string>
#include <vector>

#include <export.h>

#include "Course.h"

namespace STatelier::Score
{
	class Score;

	using ScoreList = std::vector<std::shared_ptr<Score>>;

	class DLL_EXPORT MusicalScore
	{
	public:
		MusicalScore();

		const std::string& GetTitle();
		const std::string& GetSubTitle();
		const std::string& GetKana();

		std::shared_ptr<ScoreList> CreateScoreList(const std::vector<CourseType>& courseTypeList);
		int Load(const std::string& filePath);
	private:
		std::string m_filePath = "";
		std::string m_title = "no title";
		std::string m_subTitle = "";
		std::string m_kana = "";

		std::shared_ptr<CourseList> m_courseList;

		void AddCourse(const CourseList& courses, CourseType courseType);
	};

}