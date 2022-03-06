#include "MusicalScore.h"

#include <iostream>
#include <fstream>
#include <regex>

#include <CourseFactory.h>
#include <Score.h>

namespace STatelier::Score
{
	const std::string& MusicalScore::GetTitle()
	{
		return m_title;
	}
	const std::string& MusicalScore::GetSubTitle()
	{
		return m_subTitle;
	}
	const std::string& MusicalScore::GetKana()
	{
		return m_kana;
	}
	std::shared_ptr<ScoreList> MusicalScore::CreateScoreList(const std::vector<CourseType> courseTypeList)
	{
		std::ifstream ifs(m_filePath);

		if (!ifs)
		{
			return std::make_shared<ScoreList>();
		}

		std::string line;
		std::regex regex("(\\S+):(.+)");
		std::smatch match;

		int lineCount = 0;

		ScoreInfo scoreInfo;
		std::shared_ptr<ScoreList> scoreList = std::make_shared<ScoreList>(courseTypeList.size());

		while (std::getline(ifs, line))
		{
			lineCount++;

			// コメント削除
			{
				int pos = line.find("//");
				line = line.substr(0, pos);
			}

			// CRを削除
			{
				int pos = line.find("\r");
				line = line.substr(0, pos);
			}

			std::string match01 = match[1].str();
			std::string val = match[2].str();

			CourseType currentCourseType = CourseType::VeryHardA;
			double currentlevel = 0.0;

			if (std::regex_match(line, match, regex))
			{
				if ("BPM" == match01)
				{
					scoreInfo.startBPM = std::stod(val);
				}
				else if ("OFFSET" == match01)
				{
					scoreInfo.offsetMillisec = std::stod(val) * 1000;
				}
				else if ("COURSE" == match01)
				{
					CourseType courseType;
					if (Course::TryGetCourseTypeFromText(val, &courseType))
					{
						scoreInfo.courseType = courseType;
					}
				}
				else if ("LEVEL" == match01)
				{
					scoreInfo.level = std::stod(val);
				}
			}
			else if (line.starts_with("#START"))
			{
				auto score = std::make_shared<Score>();

				scoreInfo.p_ifs = &ifs;
				scoreInfo.lineCount = lineCount;

				score->Load(&scoreInfo);
				scoreList->push_back(score);
			}
		}

		return scoreList;
	}
	int MusicalScore::Load(const std::string& filePath)
	{
		m_filePath = filePath;

		std::ifstream ifs(filePath);

		if (!ifs)
		{
			return -1;
		}

		std::string line;
		std::regex regex("(\\S+):(.+)");
		std::smatch match;

		CourseFactory courseFactory;

		CourseList courses;
		std::shared_ptr<Course> currentCourse = courseFactory.Create();

		int lineCount = 0;
		while (std::getline(ifs, line))
		{
			lineCount++;

			// コメント削除
			{
				int pos = line.find("//");
				line = line.substr(0, pos);
			}

			// CRを削除
			{
				int pos = line.find("\r");
				line = line.substr(0, pos);
			}

			if (std::regex_match(line, match, regex))
			{
				std::string match01 = match[1].str();
				std::string val = match[2].str();

				if ("TITLE" == match01)
				{
					m_title = val;
				}
				else if ("COURSE" == match01)
				{
					CourseType courseType;
					if (Course::TryGetCourseTypeFromText(val, &courseType))
					{
						currentCourse->SetCourseType(courseType);
					}
				}
				else if ("LEVEL" == match01)
				{
					currentCourse->SetLevel(std::stod(val));
				}
			}
			else if (line.starts_with("#START"))
			{
				if (currentCourse->GetLevel() != -1)
				{
					courses.push_back(currentCourse);
					currentCourse = courseFactory.Create();
				}
			}
		}

		m_courseList->clear();
		AddCourse(courses, CourseType::Easy);
		AddCourse(courses, CourseType::Normal);
		AddCourse(courses, CourseType::Hard);
		AddCourse(courses, CourseType::VeryHardA);
		AddCourse(courses, CourseType::VeryHardB);

		return 0;
	}
	MusicalScore::MusicalScore()
	{
		m_courseList = std::make_shared<CourseList>();
	}
	void MusicalScore::AddCourse(const CourseList& courses, CourseType courseType)
	{
		auto c = std::find_if(courses.begin(), courses.end(), [courseType](std::shared_ptr<Course> x) { return x->GetCourseType() == courseType; });

		if (c != courses.end())
		{
			m_courseList->push_back(*c);
		}
		else
		{
			CourseFactory courseFactory;
			auto temp = courseFactory.Create();
			temp->SetCourseType(courseType);
			m_courseList->push_back(temp);
		}
	}
}