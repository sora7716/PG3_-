#include "IScene.h"
#include "asset/GameManager.h"
#include <Windows.h>
#include <string>

//タイトルシーンで初期化
int IScene::sceneNo_ = TITLE;

// シーン番号のゲッター
int IScene::GetSceneNo() { return sceneNo_; }

// シーン切り替え
void IScene::SceneChangeTimeOut(int second, int scene) {
	int nextScene = TITLE;
	[scene, &nextScene]() {
		if (scene == TITLE) {
			nextScene = TITLE;
		}
		else if (scene == STAGE) {
			nextScene = STAGE;
		}
		else if (scene == END) {
			nextScene = END;
		}
		return nextScene;
	}();
	FadeOut(second, p_nextSceneNo_, nextScene);
}

//フェードアウト用のボックスの色のセッター
void IScene::SetFadeColor(int fadeColor){
	fadeColor_ = fadeColor;
}

//フェードアウトをスタートするかどうかのフラグのセッター
void IScene::SetIsFadeOutStart(bool isFadeOutStart){
	isFadeOutStart_ = isFadeOutStart;
}

//シーン切り替えようのコールバック関数
void IScene::SetTimeOut(int second, P_SceneChange p_nextScene, int nexSceneNo) {
	Sleep(second * 1000);
	p_nextScene(sceneNo_, nexSceneNo);
}

//シーン切り替え時のフェードアウト
void IScene::FadeOut(int second, P_SceneChange p_nextScene, int nexSceneNo) {
	//フェードアウト
	if (isFadeOutStart_) {
		fadeColor_ += 0x00000001;
	}
	//コールバック関数を読んでシーンを変更
	if (fadeColor_ >= 0x000000ff) {
		SetTimeOut(second, p_nextScene, nexSceneNo);//コールバック関数
	}
}

//フェードアウト用のボックス
void IScene::DrawFadeOut() {
	//フェード用のボックス
	Novice::DrawBox(0, 0, (int)GameManager::kWindowWidth, (int)GameManager::kWindowHeight, 0.0f, fadeColor_, kFillModeSolid);
}

//シーンについて
void IScene::SceneNameAndBackground(const char* sceneName, const char* nextSceneName,uint32_t backgroundColor) {
	//シーン名
	Novice::ScreenPrintf(0, 0, sceneName);
	//シーンの切り替え
	string nextScene = "Press Enter ChangeScene " + string(nextSceneName);
	Novice::ScreenPrintf(0, 20, nextScene.c_str());

	//背景
	Novice::DrawBox(0,0,(int)GameManager::kWindowWidth,(int)GameManager::kWindowHeight,0.0f,backgroundColor,kFillModeSolid);
}

//シーンを変更
void SceneChange(int& scene, int nexScene) {
	scene = nexScene;
}
