#pragma once
/**
 * @brief �V�X�e���f�B���N�g�����擾����N���X
 * @file SystemDirectory.Class.h
 * @date 2008/03/10
 */

#pragma once
#include <string>

 /**
   * @brief �V�X�e���f�B���N�g�����擾����N���X
   * @code
   * �C���X�^���X�����Ȃ��ŁA�ÓI�Ɏg�p����
   *
   * �� 1 :
   * // Windows �f�B���N�g�����擾
   * std::string windir = SystemDirectory::windows();
   * @endcode
   */
class SystemDirectory {
public:
	static std::string windows();
	static std::string system();
	static std::string programFiles();
	static std::string programFilesCommon();
	static std::string profiles();
	static std::string font();
	static std::string resources();

private:
	static std::string getShellDirectory(int nFolder);
};