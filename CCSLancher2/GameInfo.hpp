# pragma once
# include <Siv3D.hpp>

struct Game {

	// �Q�[���^�C�g��(�t��)
	String title;

	// ���s�t�@�C���̃p�X
	FilePath path;

	// �Q�[���̉摜
	Texture screenshot;

	// readme�t�@�C���̃p�X
	FilePath rdmPath;

	// readme�̓��e
	Texture readme;

	// �Q�[���J���c�[��
	String tools;

	// �Q�[���W������
	String kind;

	// �J����
	String staff;

	// �}�E�X���g�p���邩
	bool useMouse = false;

	// �L�[�{�[�h���g�p���邩
	bool useKeyboard = false;

	// �Q�[���p�b�h���g�p���邩
	bool useGamepad = false;

	// �u���E�U�ŋN������K�v�����邩�ǂ���
	bool isWebApp = false;

	// ���悪���邩�ǂ���
	// bool hasMovie = false;

	// �Љ��

};