/*
*	”š’e‚ÌƒNƒ‰ƒX
*
*	2015/05/30		Y.Ozawa
*/

#include "Lib.h"

Bomb::Bomb()
{
	bombPoint = new bomb_point[BOMB_MAX];
	for (int i = 0; i < BOMB_MAX; i++)
	{
		bombPoint[i].deathCount = 0;
		//bombPoint[i].pos = D3DXVECTOR3(0, 0, 0);
		bombPoint[i].exist = TRUE;
	}
	texture = new Texture("Texture/ball.bmp");
	bomb = new Graphic();

}

Bomb::~Bomb()
{
	delete texture;
	delete bomb;
	delete[] bombPoint;
}

void Bomb::Draw(D3DXVECTOR3 Pos[])
{
	Vertex3 *vertex = new Vertex3[BOMB_MAX];

	for (int i = 0; i < BOMB_MAX; i++)
	{
		bombPoint[i].pos = Pos[i];

		vertex[i].pos = bombPoint[i].pos;
		vertex[i].size = 1.0f;
		vertex[i].color = 0xffffffff;

	}

	bomb->DrawPointSprite(vertex, BOMB_MAX, *texture);
	delete[] vertex;
}