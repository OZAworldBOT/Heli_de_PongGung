/*
*	�G�̃N���X
*
*	2015/05/28		Y.Ozawa
*/

#pragma once

class Texture;
class Model;
class Graphic;
class Bullet;

//���q�̃f�[�^�[
struct e_point
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 accel;
	int deathCount;
	bool exist;
};


class Enemy
{
	//-----------------------------------------------------
	//	�G�֘A
	//-----------------------------------------------------
	Graphic *enemy;							//	X�t�@�C��
	D3DXVECTOR3 Position[ENEMY_MAX];		//	�G�̍��W
	D3DXVECTOR3 Rotation[ENEMY_MAX];		//	�G�̌X��
	D3DXVECTOR3 Scale[ENEMY_MAX];			//	�G�̊g�嗦
	D3DXVECTOR3 oldEnemyPos[ENEMY_MAX];		//	�O�t���[���̓G�̍��W
	D3DXVECTOR3 oldEnemyRot[ENEMY_MAX];		//	�O�t���[���̓G�̌X��


	//-----------------------------------------------------
	//	�U���֘A
	//-----------------------------------------------------
	D3DXVECTOR3 bullet_Pos[BULLET_MAX];			//	�e�̍��W
	D3DXVECTOR3 bullet_Rot[BULLET_MAX];			//	�e�̌X��
	D3DXVECTOR3 bullet_Accel[BULLET_MAX];		//	�e�̏���
	D3DXVECTOR3 bullet_Radius[BULLET_MAX];		//	�e�̔��a
	int			bullet_Count[BULLET_MAX];		//	�e�̐�������
	bool		bullet_Exist[BULLET_MAX];		//	�e�������Ă邩�ǂ���
	bool		bullet_flag;					//	�e�̐���t���O

private:

	float cameraAngle;		//�J�����̊p�x

private:

	Model *model;
	Texture *texture;
	Bullet *bullet;

public:

	//	�f�t�H���g�R���X�g���N�^
	Enemy();

	//	�f�X�g���N�^
	~Enemy();

	//	�G�̓���
	void Move();

	//	�`�悷��
	void Draw();

	//	������
	void InitEnemy();
	void InitBullet();

	//	�U��
	void Shot();

	//	���
	void Release();
};








