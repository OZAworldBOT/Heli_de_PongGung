/*
*	�v���C���[�̃N���X
*
*	2015/05/27		Y.Ozawa
*/

#pragma once

class Camera;
class Model;
class Texture;
class Graphic;
class BUllet;

//���q�̃f�[�^�[
struct p_point
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 accel;
	int deathCount;
	bool exist;
};

class Player
{
	//-----------------------------------------------------
	//	�v���C���[�֘A
	//-----------------------------------------------------
	//	X�t�@�C��
	Graphic *player;
	D3DXVECTOR3 Position;		//	�v���C���[�̍��W
	D3DXVECTOR3 Rotation;		//	�v���C���[�̌X��
	D3DXVECTOR3 Scale;			//	�v���C���[�̊g�嗦
	D3DXVECTOR3 oldPlayerPos;	//	�O�t���[���̃v���C���[�̍��W
	D3DXVECTOR3 oldPlayerRot;	//	�O�t���[���̃v���C���[�̌X��

	//-----------------------------------------------------
	//	�J�����֘A
	//-----------------------------------------------------
	D3DXVECTOR3 camera_Pos;		//	�J�����̍��W
	D3DXVECTOR3 camera_Rot;		//	�J�����̌X��
	D3DXVECTOR3 oldCameraRot;	//	�O�t���[���̃J�����̌X��

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

	Camera *camera;
	Model *model;
	Texture *texture;
	Bullet *bullet;

public:

	//	�f�t�H���g�R���X�g���N�^
	Player();

	//	�f�X�g���N�^
	~Player();

	//	�v���C���[�̓���
	void Move();

	//	�`�悷��
	void Draw();

	//	������
	void InitPlayer();
	void InitBullet();

	//	�V���b�g
	void Shot();

	//	���
	void Release();
};






