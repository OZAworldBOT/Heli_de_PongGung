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
	//	X�t�@�C��
	Graphic *player;

	D3DXVECTOR3 Position;		//	�v���C���[�̍��W
	D3DXVECTOR3 Rotation;		//	�v���C���[�̉�]
	D3DXVECTOR3 Scale;			//	�v���C���[�̊g�嗦

	D3DXVECTOR3 camera_Pos;		//	�J�����̍��W
	D3DXVECTOR3 camera_Rot;		//	�J�����̉�]

	D3DXVECTOR3 oldPlayerPos;
	D3DXVECTOR3 oldPlayerRot;
	D3DXVECTOR3 oldCameraRot;

private:

	float cameraAngle;		//�J�����̊p�x

private:

	Camera *camera;
	Model *model;
	Texture *texture;

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

	//	���
	void Release();
};






