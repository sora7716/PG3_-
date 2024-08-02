#include "GameManager.h"

//コンストラクタ
GameManager::GameManager() {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, (int)kWindowWidth, (int)kWindowHeight);
	//初期シーンの初期化
	currentSceneNo_ = TITLE;
	prevSceneNo_ = sceneNum;
}

//デストラクタ
GameManager::~GameManager() {
}

//この関数でゲームループを呼び出す
int GameManager::Run() {
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		//シーンの生成と初期化
		SceneCreate();
	
		//更新処理
		sceneArr_[currentSceneNo_]->Update(keys, preKeys);

		//描画
		sceneArr_[currentSceneNo_]->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0;
}

//シーンチェック
void GameManager::SceneCheck(){
	currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();
}

//シーン変更チェック
void GameManager::SceneChangeCheck(){
	if (prevSceneNo_ != currentSceneNo_) {
		sceneArr_[currentSceneNo_]->Initialise();
		prevSceneNo_ = currentSceneNo_;
	}
}

//シーンの生成
void GameManager::SceneCreate(){
	//シーンチェック
	SceneCheck();

	if (prevSceneNo_ != currentSceneNo_) {
		//各シーンの配列
		switch (currentSceneNo_) {
		case TITLE:
			sceneArr_[TITLE] = make_unique<Title>();
			sceneArr_[END] = nullptr;
			break;
		case STAGE:
			sceneArr_[STAGE] = make_unique<Stage>();
			sceneArr_[TITLE] = nullptr;
			break;
		case END:
			sceneArr_[END] = make_unique<End>();
			sceneArr_[STAGE] = nullptr;
			break;
		}
	}

	//シーン変更チェック
	SceneChangeCheck();
}


