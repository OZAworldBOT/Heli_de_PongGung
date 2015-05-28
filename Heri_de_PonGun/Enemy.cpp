/*
*	�G�̃N���X
*
*	2015/05/28		Y.Ozawa
*/

#include "Lib.h"
#include "Enemy.h"


extern LPDIRECT3DDEVICE9 d3dDevice;


//	�R���X�g���N�^
Enemy::Enemy()
{
	enemy = new Graphic[ENEMY_MAX];
	model = new Model("Model/alien.x");
	texture = new Texture("Texture/GreenSkin.png");
	bullet = new Bullet();

	DebugLog("�G�𐶐����܂����B\n");

	InitEnemy();
	InitBullet();
}

//	�f�X�g���N�^
Enemy::~Enemy()
{
	Release();
}

//	�G�̏�����
void Enemy::InitEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		Position[i] = D3DXVECTOR3(100, 0, 0);
		Rotation[i] = D3DXVECTOR3(0, 0, 0);
		Scale[i] = D3DXVECTOR3(1, 1, 1);

		DebugLog("�G�����������܂����B\n");
	}
}

//	�G�̒e�̏�����
void Enemy::InitBullet()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		bullet_Count[BULLET_MAX] = 0;
		bullet_Exist[BULLET_MAX] = false;
		bullet_Radius[BULLET_MAX] = D3DXVECTOR3(0.5, 0.5, 0.5);
		bullet_flag = false;
	}
}

//	�������
void Enemy::Release()
{
	delete enemy;
	delete model;
	delete texture;
	delete bullet;
}

//	�G�̓���
void Enemy::Move()
{

}

//	�G�̍U��
void Enemy::Shot()
{

}

//	�G�̕`��
void Enemy::Draw()
{

}