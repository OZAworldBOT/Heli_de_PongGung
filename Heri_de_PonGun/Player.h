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
class BUllet;
class Bomb;

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
	float		timeCount;		//	経過時間

	//-----------------------------------------------------
	//	プレイヤー関連
	//-----------------------------------------------------
	//	Xファイル
	Graphic		*player;
	Graphic		*tako;
	D3DXVECTOR3 Position;		//	プレイヤーの座標
	D3DXVECTOR3 Rotation;		//	プレイヤーの傾き
	D3DXVECTOR3 Scale;			//	プレイヤーの拡大率
	D3DXVECTOR3 oldPlayerPos;	//	前フレームのプレイヤーの座標
	D3DXVECTOR3 oldPlayerRot;	//	前フレームのプレイヤーの傾き

	//-----------------------------------------------------
	//	カメラ関連
	//-----------------------------------------------------
	D3DXVECTOR3 camera_Pos;		//	カメラの座標
	D3DXVECTOR3 camera_Rot;		//	カメラの傾き
	D3DXVECTOR3 oldCameraRot;	//	前フレームのカメラの傾き

	//-----------------------------------------------------
	//	攻撃関連
	//-----------------------------------------------------
	//	通常弾
	D3DXVECTOR3 bullet_Pos[BULLET_MAX];			//	弾の座標
	D3DXVECTOR3 bullet_Rot[BULLET_MAX];			//	弾の傾き
	D3DXVECTOR3 bullet_Accel[BULLET_MAX];		//	弾の初速
	D3DXVECTOR3 oldBulletPos[BULLET_MAX];		//	前フレームの弾の座標
	int			bullet_Count[BULLET_MAX];		//	弾の生存時間
	bool		bullet_Exist[BULLET_MAX];		//	弾が生きてるかどうか
	bool		bullet_flag;					//	弾の制御フラグ
	bool		bullet_death[BULLET_MAX];		//	弾が敵に当たった
	float		bullet_Radius[BULLET_MAX];		//	弾の半径
	float		enemy_Radius[ENEMY_MAX];		//	敵の半径

	//	爆弾
	D3DXVECTOR3 bomb_Pos;							//	弾の座標
	D3DXVECTOR3 bomb_Rot;							//	弾の傾き
	D3DXVECTOR3 bombExplosion_Pos[BOMB_MAX];		//	爆風の座標
	D3DXVECTOR3 bombExplosion_Rot[BOMB_MAX];		//	爆風の傾き
	D3DXVECTOR3 bomb_Accel[BOMB_MAX];				//	弾の初速
	D3DXVECTOR3 oldBombPos[BOMB_MAX];				//	前フレームの弾の座標
	bool		bomb_Exist;							//	弾が生きてるかどうか
	bool		bomb_flag;							//	弾の制御フラグ
	bool		bomb_death;							//	弾が敵に当たった
	float		bomb_Radius[BOMB_MAX];				//	弾の半径
	bool		bombExplosion_Exist[BOMB_MAX];		//	爆風が生きてるかどうか
	bool		bombExplosion_Death[BOMB_MAX];		//	爆風が敵に当たった
	int			bombExplosion_Count[BOMB_MAX];		//	弾の生存時間


private:

	float cameraAngle;		//カメラの角度

private:

	Camera *camera;
	Model *model;
	Texture *texture;
	Bullet *bullet;
	Bomb *bomb;

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
	void InitBullet();
	void InitBomb();

	//	ショット
	void Shot();

	//	弾丸のショット
	void BulletShot();

	//	爆弾のショット
	void BombShot();

	//	当たり判定
	void Hit();

	//	解放
	void Release();
};






