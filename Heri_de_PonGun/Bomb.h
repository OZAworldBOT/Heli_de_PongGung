/*
*	���e�̃N���X
*	
*	2015/05/30		Y.Ozawa
*/

#pragma once


class Texture;
class Graphic;

//���q�̃f�[�^�[
struct bomb_point
{
	D3DXVECTOR3 pos;			//	�e�ۂ̍��W
	D3DXVECTOR3 accel;			//	�e�ۂ̏���
	int deathCount;				//	�e�ۂ̐�������
	bool exist;					//	�e�ۂ������Ă��邩�ǂ���
};

class Bomb
{
private:

	Texture *texture;
	Graphic *bomb;
	bomb_point *bombPoint;

public:

	//	�f�t�H���g�R���X�g���N�^
	Bomb();

	//	�f�X�g���N�^
	~Bomb();

	//	�`�悷��
	void Draw(D3DXVECTOR3 Pos[], float Size, bool Alpha);

	//	������
	void InitBullet();

	//	���
	void Release();

};













