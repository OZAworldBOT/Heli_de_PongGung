/*
*	�A�v���P�[�V�����̃G���g���[�|�C���g�ƃ��C�����[�v
*
*	2015/05/18		Y.Ozawa
*/

#include "Lib.h"
#include <memory>
#include "Player.h"
#include "Stage.h"

using namespace std;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int cmdShow)
{
	//	�R���\�[�����J��
	OpenConsole();

	//	�A�v���P�[�V�������s�����\�z
	unique_ptr<Application> app(new Application("�w���Ń|���I�K���I�I", Rect(0, 0, 800, 600), false, hInst, cmdShow));
	unique_ptr<Light> light(new Light());
	unique_ptr<Player> player(new Player());
	unique_ptr<Stage> stage(new Stage());

	while (app->Loop())
	{
		player->Move();
		player->Draw();


		stage->View();
		//	�G�X�P�[�v�L�[����������Q�[���I��
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
	}

	return 0;
}


