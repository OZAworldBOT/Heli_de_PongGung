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
class Bomb;
class Razer;

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
	float		timeCount;		//	�o�ߎ���

	//-----------------------------------------------------
	//	�v���C���[�֘A
	//-----------------------------------------------------
	//	X�t�@�C��
	Graphic		*player;
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
	//	�ʏ�e
	D3DXVECTOR3 bullet_Pos[BULLET_MAX];			//	�e�̍��W
	D3DXVECTOR3 bullet_Rot[BULLET_MAX];			//	�e�̌X��
	D3DXVECTOR3 bullet_Accel[BULLET_MAX];		//	�e�̏���
	D3DXVECTOR3 oldBulletPos[BULLET_MAX];		//	�O�t���[���̒e�̍��W
	int			bullet_Count[BULLET_MAX];		//	�e�̐�������
	bool		bullet_Exist[BULLET_MAX];		//	�e�������Ă邩�ǂ���
	bool		bullet_flag;					//	�e�̐���t���O
	bool		bullet_death[BULLET_MAX];		//	�e���G�ɓ�������
	float		bullet_Radius[BULLET_MAX];		//	�e�̔��a
	float		enemy_Radius[ENEMY_MAX];		//	�G�̔��a

	//	���e
	D3DXVECTOR3 bomb_Pos;							//	���e�̍��W
	D3DXVECTOR3 bomb_Rot;							//	���e�̌X��
	D3DXVECTOR3 bomb_Accel;							//	���e�̏���
	D3DXVECTOR3 oldBombPos;							//	�O�t���[���̔��e�̍��W
	bool		bomb_Exist;							//	���e�������Ă邩�ǂ���
	bool		bomb_flag;							//	���e�̐���t���O
	bool		bomb_death;							//	���e���G�ɓ�������
	bool		bomb_Alpha;							//	Z�o�b�t�@�[���s�����ǂ���
	float		bomb_Radius;						//	���e�̔��a
	float		bomb_Size;							//	���e�̑傫��
	int			bomb_Count;							//	���e�̐�������
	D3DXVECTOR3 bombExplosion_Rot[BOMB_MAX];		//	�����̌X��
	D3DXVECTOR3 bombExplosion_Pos[BOMB_MAX];		//	�����̍��W
	D3DXVECTOR3 bombExplosion_Accel[BOMB_MAX];		//	�����̏���
	D3DXVECTOR3 oldBombExplosionPos[BOMB_MAX];		//	�O�t���[���̔����̍��W
	D3DXVECTOR3 MinRange;							//	�����̍ŏ��͈�
	D3DXVECTOR3 MaxRange;							//	�����̍ő�͈�
	bool		bombExplosion_Exist[BOMB_MAX];		//	�����������Ă邩�ǂ���
	bool		bombExplosion_Death[BOMB_MAX];		//	�������G�ɓ�������
	bool		bombExplosion_Alpha;				//	Z�o�b�t�@�[���s�����ǂ���
	float		bombExplosion_Radius[BOMB_MAX];		//	�����̔��a
	float		bombExplosion_Size;					//	�����̑傫��
	int			bombExplosion_Count[BOMB_MAX];		//	�����̐�������

	//	���[�U�[
	D3DXVECTOR3 razer_Pos[RAZER_MAX];			//	���[�U�[�̍��W
	D3DXVECTOR3 razer_Rot[RAZER_MAX];			//	���[�U�[�̌X��
	D3DXVECTOR3 razer_Accel[RAZER_MAX];			//	���[�U�[�̏���
	D3DXVECTOR3 oldRazerPos[RAZER_MAX];			//	�O�t���[���̃��[�U�[�̍��W
	int			razer_Count[RAZER_MAX];			//	���[�U�[�̐�������
	bool		razer_Exist[RAZER_MAX];			//	���[�U�[�������Ă邩�ǂ���
	bool		razer_flag;						//	���[�U�[�̐���t���O
	bool		razer_death[RAZER_MAX];			//	���[�U�[���G�ɓ�������
	float		razer_Radius[RAZER_MAX];		//	���[�U�[�̔��a


private:

	float cameraAngle;		//�J�����̊p�x

private:

	Camera *camera;
	Model *model;
	Texture *texture;
	Bullet *bullet;
	Bomb *bomb;
	Razer *razer;

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
	void InitBomb();
	void InitRazer();

	//	�V���b�g
	void Shot();

	//	�e�ۂ̃V���b�g
	void BulletShot();

	//	���e�̃V���b�g
	void BombShot();

	//	���[�U�[�̃V���b�g
	void RazerShot();

	//	�����蔻��
	void Hit();

	//	���
	void Release();
};






