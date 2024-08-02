#include "End.h"

//コンストラクタ
End::End() {
}

/// <summary>
/// デストラクタ
/// </summary>
End::~End() {
}

//初期化
void End::Initialise() {

}

//更新
void End::Update(const char* keys, const char* preKeys) {
	int second = 2;//どれくらいの時間待つか
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		isFadeOutStart_ = true;//フェードアウトのスタート
		p_nextSceneNo_ = SceneChange;
	}
	//フェードアウト
	IScene::FadeOut(second, p_nextSceneNo_,TITLE);
}

//描画
void End::Draw() {
	//シーンについて
	IScene::ScreenPrintScene("END", "TITLE");
	//フェードアウト
	IScene::DrawFadeOut();
}
