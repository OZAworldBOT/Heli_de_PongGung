/*
*	プレイヤーのクラス
*
*	2015/05/27		Y.Ozawa
*/

#pragma once

class Camera;
class Model;
class Texture;
class Graphic;

//粒子のデーター
struct p_point
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 accel;
	int deathCount;
	bool exist;
};

class Player
{
	//	Xファイル
	Graphic *player;

	D3DXVECTOR3 Position;		//	プレイヤーの座標
	D3DXVECTOR3 Rotation;		//	プレイヤーの回転
	D3DXVECTOR3 Scale;			//	プレイヤーの拡大率

	D3DXVECTOR3 camera_Pos;		//	カメラの座標
	D3DXVECTOR3 camera_Rot;		//	カメラの回転

	D3DXVECTOR3 oldPlayerPos;
	D3DXVECTOR3 oldPlayerRot;
	D3DXVECTOR3 oldCameraRot;

private:

	float cameraAngle;		//カメラの角度

private:

	Camera *camera;
	Model *model;
	Texture *texture;

public:

	//	デフォルトコンストラクタ
	Player();

	//	デストラクタ
	~Player();

	//	プレイヤーの動作
	void Move();

	//	描画する
	void Draw();

	//	初期化
	void InitPlayer();

	//	解放
	void Release();
};






