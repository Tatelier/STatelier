#include "SystemDirectory.h"

#include <Lmcons.h>
#include <shlobj.h>
#include <userenv.h>
#include <windows.h>

// ------------------------------------------------------------------
// �����N���郉�C�u����
// ------------------------------------------------------------------
#pragma comment(lib, "userenv.lib")

// ------------------------------------------------------------------
// �}�N��
// ------------------------------------------------------------------
/**
 * @brief �f�B���N�g�����상�\�b�h�p�̍ő�p�X������
 *
 * MAX_PATH �� 260 �o�C�g�������Ȃ��̂ŁA����Ȃ��ꍇ�ɔ�����
 * 4096 �o�C�g�Ɋg��
 */
#define SYSTEMDIRECTORY_MAX_PATH (4096)

 // ------------------------------------------------------------------
 // �v���C�x�[�g���\�b�h
 // ------------------------------------------------------------------
std::string SystemDirectory::getShellDirectory(int nFolder)
{
	HRESULT result;
	LPITEMIDLIST pidl;
	std::string str;
	IMalloc* pMalloc;

	SHGetMalloc(&pMalloc);
	result = ::SHGetSpecialFolderLocation(NULL,
		nFolder,
		&pidl);

	if (FAILED(result)) {
		pMalloc->Release();
		str.assign("\0", 1);
		return str;
	}

	str.assign("\0", SYSTEMDIRECTORY_MAX_PATH + 1);
	::SHGetPathFromIDList(pidl, (LPTSTR)str.c_str());

	pMalloc->Free(pidl);
	pMalloc->Release();

	return str;
}

// ------------------------------------------------------------------
// �p�u���b�N���\�b�h
// ------------------------------------------------------------------

/**
 * @brief Windows �f�B���N�g���̃t���p�X���擾
 *
 * @code
 * // �o�͗� (�I�[�� \ �͊܂܂Ȃ�)
 * C:\WINDOWS
 * @endcode
 *
 * @return Windows �f�B���N�g���̃p�X
 * @note ���s�������͋�̕������Ԃ�
 */
std::string SystemDirectory::windows()
{
	unsigned int result;
	std::string str;

	str.assign("\0", SYSTEMDIRECTORY_MAX_PATH + 1);
	result = ::GetSystemWindowsDirectory((LPTSTR)str.c_str(),
		SYSTEMDIRECTORY_MAX_PATH);

	return str;
}

/**
 * @brief �V�X�e���t�@�C���̃f�B���N�g���̃t���p�X���擾
 *
 * @code
 * // �o�͗� (�I�[�� \ �͊܂܂Ȃ�)
 * C:\WINDOWS\system32
 * @endcode
 *
 * @attention IE5 �ȍ~�܂��� Windows 2000 �ȍ~
 * @return �V�X�e���t�@�C���̃f�B���N�g���̃p�X
 * @note ���s�������͋�̕������Ԃ�
 */
std::string SystemDirectory::system()
{
	return getShellDirectory(CSIDL_SYSTEM);
}

/**
 * @brief Program Files �̃f�B���N�g�����t���p�X�Ŏ擾
 *
 * @code
 * // �o�͗� (�I�[�� \ �͊܂܂Ȃ�)
 * C:\Program Files
 * @endcode
 *
 * @attention IE5 �ȍ~�܂��� Windows 2000 �ȍ~
 * @return Program Files �̃f�B���N�g��
 * @note ���s�������͋󕶎����Ԃ�
 */
std::string SystemDirectory::programFiles()
{
	return getShellDirectory(CSIDL_PROGRAM_FILES);
}

/**
 * @brief Program Files\\Common Files �̃f�B���N�g�����t���p�X�Ŏ擾
 *
 * @code
 * // �o�͗� (�I�[�� \ �͊܂܂Ȃ�)
 * C:\Program Files\Common Files
 * @endcode
 *
 * @attention Windows Me �ȊO�� IE5 �ȍ~ (NT, 2000, XP)
 * @return Program Files\Common Files �̃f�B���N�g��
 * @note ���s�������͋󕶎����Ԃ�
 */
std::string SystemDirectory::programFilesCommon()
{
	return getShellDirectory(CSIDL_PROGRAM_FILES_COMMON);
}

/**
 * @brief Documents and Settings �̃f�B���N�g�����t���p�X�Ŏ擾
 *
 * @code
 * // �o�͗� (�I�[�� \ �͊܂܂Ȃ�)
 * C:\Documents and Settings
 * @endcode
 *
 * @return Documents and Settings �̃f�B���N�g��
 * @note ���s�������͋󕶎����Ԃ�
 */
std::string SystemDirectory::profiles()
{
	BOOL result;
	DWORD size;

	std::string str;
	str.assign("\0", SYSTEMDIRECTORY_MAX_PATH + 1);
	size = SYSTEMDIRECTORY_MAX_PATH;

	result = ::GetProfilesDirectory((LPTSTR)str.c_str(), &size);

	if (result == 0)
		str.assign("\0", 1);

	return str;
}

/**
 * @brief �t�H���g�̃f�B���N�g�����t���p�X�Ŏ擾
 *
 * @code
 * // �o�͗� (�I�[�� \ �͊܂܂Ȃ�)
 * C:\WINDOWS\Fonts
 * @endcode
 *
 * @return �A�v���P�[�V�����f�[�^�̃f�B���N�g��
 * @note ���s�������͋󕶎����Ԃ�
 */
std::string SystemDirectory::font()
{
	return getShellDirectory(CSIDL_FONTS);
}

/**
 * @brief ���\�[�X�t�@�C���̃f�B���N�g�����t���p�X�Ŏ擾
 *
 * ���̃f�B���N�g���ɂ́A�f�X�N�g�b�v�e�[�}��������悤�ł��B
 *
 * @code
 * // �o�͗� (�I�[�� \ �͊܂܂Ȃ�)
 * C:\Windows\Resources
 * @endcode
 *
 * @attention Windows Vista �ȍ~
 * @return ���\�[�X�t�@�C���̃f�B���N�g��
 * @note ���s�������͋󕶎����Ԃ�
 */
std::string SystemDirectory::resources()
{
	return getShellDirectory(CSIDL_RESOURCES);
}