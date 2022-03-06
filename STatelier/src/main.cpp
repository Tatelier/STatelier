//#include "DxLib.h"
//#include "Supervision.h"
//
// 

#include<windows.h>

#include <SelectItemControl.h>
#include <Supervision.h>

using namespace STatelier::SongSelect;

// ƒvƒƒOƒ‰ƒ€‚Í WinMain ‚©‚çŽn‚Ü‚è‚Ü‚·
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	STatelier::Supervision::Initialize();
	STatelier::Supervision::GetInstance()->Run();
	STatelier::Supervision::Finalize();

	//auto selectItemControl = new SelectItemControl();
	//selectItemControl->Load("Resources/Score/Root");
	//auto musicalScore = std::dynamic_pointer_cast<MusicalScoreSelectItem>(selectItemControl->GetCurrent())->GetBase();
	//
	//auto courseList = std::vector<CourseType>();
	//courseList.push_back(CourseType::VeryHardA);
	//auto score = musicalScore->CreateScoreList(courseList);

	return 0;
}