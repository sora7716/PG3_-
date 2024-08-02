#include "asset/GameManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	unique_ptr<GameManager>gameManager = make_unique<GameManager>();

	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
