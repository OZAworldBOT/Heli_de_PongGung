/*
*	�v���C���[�̃N���X
*
*	2015/05/27		Y.Ozawa
*/

#include "Lib.h"
#include "Player.h"
#include "Shot.h"

extern LPDIRECT3DDEVICE9 d3dDevice;
extern LPDIRECTINPUTDEVICE8 dinputDevice;

//	�R���X�g���N�^
Player::Player()
{
	camera = new Camera();
	player = new Graphic();
	model = new Model();
	texture = new Texture();

	DebugLog("�v���C���[�𐶐����܂����B\n");

	InitPlayer();
}

//	�f�X�g���N�^
Player::~Player()
{
	delete camera;
	delete player;
	delete model;
	delete texture;

	Release();
}

//	������
void Player::InitPlayer()
{
	model = new Model("Model/Heli.x");
	texture = new Texture("Texture/enemy2.png");


	Position = D3DXVECTOR3(0, 10, 0);
	Rotation = D3DXVECTOR3(0, D3DXToRadian(90), 0);
	Scale = D3DXVECTOR3(0.05, 0.05, 0.05);

	camera_Pos = D3DXVECTOR3(0, 15, -10);
	camera_Rot = D3DXVECTOR3(D3DXToRadian(10), 0, 0);

	DebugLog("�v���C���[�����������܂����B\n");
}

//	�������
void Player::Release()
{

}

//	����
void Player::Move()
{
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
		if (camera_Rot.x < D3DXToRadian(0))
		{
			camera_Rot.x = D3DXToRadian(0);
		}
		if (camera_Rot.x > D3DXToRadian(30))
		{
			camera_Rot.x = D3DXToRadian(30);
		}

	}

	//�v���C���[���J�����̒��S�ɂƂ炦��
	camera_Pos.x = Position.x - 10 * sinf(cameraAngle);
	camera_Pos.z = Position.z - 10 * cosf(cameraAngle);

	camera_Rot.y += dims.lX * 0.005f;
	Rotation.y = camera_Rot.y + D3DXToRadian(0);


}

//	�`��
void Player::Draw()
{
	camera->View(camera_Pos, camera_Rot);
	player->DrawModelTexture(Position, Rotation, Scale, *model, *texture);
}




