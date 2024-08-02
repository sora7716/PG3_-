#include "Title.h"

//コンストラクタ
Title::Title() {
}

//デストラクタ
Title::~Title() {
}

//初期化
void Title::Initialise() {
	fadeColor_ = 0x00000000;//fadeカラーの初期化
}

//更新
void Title::Update(const char* keys, const char* preKeys, int& scene) {
	
	//エンターを押したらフェードアウトスタート
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		isFadeOutStart_ = true;
		scene = STAGE;
	}
}

//描画
void Title::Draw() {
	//シーンについて
	IScene::ScreenPrintScene("TITLE", "STAGE");

	//フェードアウト
	IScene::DrawFadeOut();
}
