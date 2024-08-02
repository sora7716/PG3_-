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
void Title::Update(const char* keys, const char* preKeys) {

	

	int second = 2;//何秒待ってほしいか
	
	//エンターを押したらフェードアウトスタート
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		isFadeOutStart_ = true;
		p_nextSceneNo_ = SceneChange;
	}
	//フェードアウトとシーン切り替え
	IScene::FadeOut(second, p_nextSceneNo_,STAGE);
}

//描画
void Title::Draw() {
	//シーンについて
	IScene::ScreenPrintScene("TITLE", "STAGE");

	//フェードアウト
	IScene::DrawFadeOut();
}
