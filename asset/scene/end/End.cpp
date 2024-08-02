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
void End::Update(const char* keys, const char* preKeys, int& scene) {
	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		isFadeOutStart_ = true;//フェードアウトのスタート
		scene = TITLE;
	}
}

//描画
void End::Draw() {
	//シーンについて
	IScene::SceneNameAndBackground("END", "TITLE", 0x00FF0099);
	//フェードアウト
	IScene::DrawFadeOut();
}
