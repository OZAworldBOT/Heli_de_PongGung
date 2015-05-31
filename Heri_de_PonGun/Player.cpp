/*
*	�v���C���[�̃N���X
*
*	2015/05/27		Y.Ozawa
*/

#include <time.h>
#include "Lib.h"
#include "Player.h"


extern LPDIRECT3DDEVICE9 d3dDevice;
extern LPDIRECTINPUTDEVICE8 dinputDevice;
D3DXVECTOR3 inputState;					//	�v���C���[�̍��W���擾
D3DXVECTOR3 bulletState[BULLET_MAX];	//	�v���C���[�̒e�̍��W���擾
D3DXVECTOR3 bombState[BOMB_MAX];		//	�v���C���[�̔��e�̍��W���擾

//	�R���X�g���N�^
Player::Player()
{
	camera = new Camera();
	player = new Graphic();
	tako = new Graphic();

	model = new Model[2];
	model[0].LoadMesh("Model/Heli.x");
	model[1].LoadMesh("Model/tako.x");
	texture = new Texture[2];
	texture[0].LoadTexture("Texture/enemy2.png");
	texture[1].LoadTexture("Texture/RedSkin.png");

	bullet = new Bullet();
	bomb = new Bomb();

	DebugLog("�v���C���[�𐶐����܂����B\n");

	InitPlayer();
	InitBullet();
	InitBomb();
}

//	�f�X�g���N�^
Player::~Player()
{
	Release();
}

//	������
void Player::InitPlayer()
{
	Position = D3DXVECTOR3(0, 10, 0);
	Rotation = D3DXVECTOR3(0, D3DXToRadian(90), 0);
	Scale = D3DXVECTOR3(0.05, 0.05, 0.05);

	camera_Pos = D3DXVECTOR3(0, 15, -10);
	camera_Rot = D3DXVECTOR3(D3DXToRadian(10), 0, 0);

	DebugLog("�v���C���[�����������܂����B\n");
}

void Player::InitBullet()
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		bullet_Count[i] = 0;
		bullet_Exist[i] = false;
		bullet_flag = false;
		bullet_death[i] = true;
	}
}

void Player::InitBomb()
{
		bomb_Exist = false;
		bomb_flag = false;
		bomb_death = true;
}

//	�������
void Player::Release()
{
	delete camera;
	delete player;
	delete tako;
	delete[] model;
	delete[] texture;
	delete bullet;
	delete bomb;
}

//	����
void Player::Move()
{
	//�ړ�����	�L�[�{�[�h�ő���
	if (GetAsyncKeyState(0x57))
	{
		Position.x += sin(Rotation.y) * 1.0f;
		Position.z += cos(Rotation.y) * 1.0f;
	}
	if (GetAsyncKeyState(0x53))
	{
		Position.x -= sin(Rotation.y) * 1.0f;
		Position.z -= cos(Rotation.y) * 1.0f;
	}
	if (GetAsyncKeyState(0x41))
	{
		Position.x += sin(Rotation.y - D3DXToRadian(90)) * 1.0f;
		Position.z += cos(Rotation.y - D3DXToRadian(90)) * 1.0f;
	}
	if (GetAsyncKeyState(0x44))
	{
		Position.x += sin(Rotation.y + D3DXToRadian(90)) * 1.0f;
		Position.z += cos(Rotation.y + D3DXToRadian(90)) * 1.0f;
	}
	oldPlayerPos.x = Position.x;
	oldPlayerPos.z = Position.z;


	//�J�����ړ�		�}�E�X�̓����ɍ��킹��
	DIMOUSESTATE2 dims;

	if (SUCCEEDED(dinputDevice->GetDeviceState(sizeof(DIMOUSESTATE2), &dims)))
	{
		cameraAngle += dims.lX * 0.005f;
		if (cameraAngle > D3DX_PI)
		{
			cameraAngle -= 2 * D3DX_PI;
		}
		
		camera_Rot.x += dims.lY * 0.005f;
		if (camera_Rot.x < D3DXToRadian(5))
		{
			camera_Rot.x = D3DXToRadian(5);
		}
		if (camera_Rot.x > D3DXToRadian(5))
		{
			camera_Rot.x = D3DXToRadian(5);
		}

	}

	//�v���C���[���J�����̒��S�ɂƂ炦��
	camera_Pos.x = Position.x - 10 * sinf(cameraAngle);
	camera_Pos.z = Position.z - 10 * cosf(cameraAngle);

	camera_Rot.y += dims.lX * 0.005f;
	Rotation.y = camera_Rot.y + D3DXToRadian(0);
	oldPlayerRot.y = Rotation.y;
	oldCameraRot.x = camera_Rot.x;

	inputState = oldPlayerPos;
}

//	�V���b�g
void Player::Shot()
{
	BulletShot();
	BombShot();
}

//	�`��
void Player::Draw()
{
	camera->View(camera_Pos, camera_Rot);
	player->DrawModelTexture(Position, Rotation, Scale, model[0], texture[0]);
}


//-----------------------------------------------------------------------------------------------------------
//	�ȉ��v���C���[�̍U���֘A�̓�����L�q
//-----------------------------------------------------------------------------------------------------------

//	�e�ۂ̃V���b�g
void Player::BulletShot()
{
	if (GetAsyncKeyState(VK_LBUTTON) && bullet_flag == false)
	{
		/*
		*	���N���b�N����bullet_flag��false�̂Ƃ��ɏ�������������
		*/
		srand((unsigned int)time(NULL));

		for (int i = 0; i < BULLET_MAX; i++)
		{
			bullet_Pos[i].x = oldPlayerPos.x;
			bullet_Pos[i].z = oldPlayerPos.z;
			bullet_Rot[i].y = oldPlayerRot.y;
			bullet_Rot[i].x = oldCameraRot.x;

			bullet_Exist[i] = true;
		}
	}

	for (int i = 0; i < BULLET_MAX; i++)
	{
		/*
		*	�e�̏������L�q	�A�̂悤�Ɍ����邽�ߗ�����D3DXVec3Normalize���g�p
		*/
		if (bullet_Exist[i] == true)
		{
			bullet_Count[i]++;
			if (bullet_Count[i] < 30)
			{
				bullet_flag = true;
				bullet_death[i] = false;
				D3DXVec3Normalize(&bullet_Accel[i], &D3DXVECTOR3(rand() % 100 - 50, rand() % 100 - 50, rand() % 100 - 40));
				bullet_Pos[i].x += (sin(bullet_Rot[i].y) * (2.0f + i) * cos(bullet_Rot[i].x)) + bullet_Accel[i].x * 0.7f;
				bullet_Pos[i].z += (cos(bullet_Rot[i].y) * (2.0f + i) * cos(bullet_Rot[i].x)) + bullet_Accel[i].z * 0.7f;
				bullet_Pos[i].y = Position.y + bullet_Accel[i].y * 0.5f;

				if (bullet_death[i] == false)
				{
					bullet->Draw(&bullet_Pos[i]);
				}

				Hit();
			}
			if (bullet_Count[i] > 30)
			{
				bullet_flag = false;
				bullet_death[i] = true;
				bullet_Exist[i] = false;
				bullet_Count[i] = 0;
			}
			if (bullet_death[i] == true)
			{
				bullet_Pos[i].y = 1000.0f;
			}
		}
		bulletState[i] = bullet_Pos[i];
	}

}

//	���e�̃V���b�g
void Player::BombShot()
{
	if (GetAsyncKeyState(VK_RBUTTON) && bomb_flag == false)
	{
		srand((unsigned int)time(NULL));

		/*
		*	���N���b�N����bomb_flag��false�̂Ƃ��ɏ�������������
		*/
		bomb_Pos.x = oldPlayerPos.x;
		bomb_Pos.z = oldPlayerPos.z + 0.5f;
		bomb_Pos.y = Position.y + 2.0f;
		bomb_Rot.y = oldPlayerRot.y;
		bomb_Rot.x = oldCameraRot.x;

		bomb_Exist = true;
	}

		/*
		*	�e�̏������L�q	�A�̂悤�Ɍ����邽�ߗ�����D3DXVec3Normalize���g�p
		*/

	if (bomb_Exist == true)
	{
		bomb_flag = true;
		bomb_death = false;
		timeCount += 0.5f;
		bomb_Pos.y -= 0.5f + (timeCount * sin(bomb_Rot.x) - 1.5f);
		bomb_Pos.x += (sin(bomb_Rot.y) * (2.0f) * cos(bomb_Rot.x));
		bomb_Pos.z += (cos(bomb_Rot.y) * (2.0f) * cos(bomb_Rot.x));

		//bomb->Draw(&bomb_Pos[i]);
		tako->DrawModelTexture(bomb_Pos, bomb_Rot, D3DXVECTOR3(2, 2, 2), model[1], texture[1]);

		Hit();
		if (bomb_Pos.y < 0)
		{
			bomb_flag = false;
			bomb_death = true;
			bomb_Exist = false;
			timeCount = 0;

		}
	}
}

//	�����蔻��
void Player::Hit()
{
	//	�G�̍��W
	extern D3DXVECTOR3 enemy_Collider[ENEMY_MAX];

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		for (int j = 0; j < BULLET_MAX; j++)
		{
			enemy_Radius[i] = 10.0f;
			bullet_Radius[j] = 0.5f;

			if ((enemy_Collider[i].x - bullet_Pos[j].x) * (enemy_Collider[i].x - bullet_Pos[j].x) +
				(enemy_Collider[i].y - bullet_Pos[j].y) * (enemy_Collider[i].y - bullet_Pos[j].y) +
				(enemy_Collider[i].z - bullet_Pos[j].z) * (enemy_Collider[i].z - bullet_Pos[j].z) <=
				(bullet_Radius[j] + enemy_Radius[i]) * (bullet_Radius[j] + enemy_Radius[i]))
			{
				bullet_death[i] = true;
			}

		}
	}

}





