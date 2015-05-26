/*
*	�e�ۂ̃N���X
*
*	2015/05/27		Y.Ozawa
*/

#pragma once

class Texture;
class Graphic;

//���q�̃f�[�^�[
struct b_point
{
	D3DXVECTOR3 pos;			//	�e�ۂ̍��W
	D3DXVECTOR3 accel;			//	�e�ۂ̏���
	int deathCount;				//	�e�ۂ̐�������
	bool exist;					//	�e�ۂ������Ă��邩�ǂ���
};

class Bullet
{
	D3DXVECTOR3 Position;		//	�e�ۂ̍��W
	D3DXVECTOR3 Rotation;		//	�e�ۂ̉�]
	
private:

	Texture *texture;
	Graphic *bullet;
	b_point *bulletPoint;

public:

	//	�f�t�H���g�R���X�g���N�^
	Bullet();

	//	�f�X�g���N�^
	~Bullet();

	//	�`�悷��
	void Draw();

	//	������
	void InitBullet();

	//	���
	void Release();

};