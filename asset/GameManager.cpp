#include "GameManager.h"

//コンストラクタ
GameManager::GameManager() {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, (int)kWindowWidth, (int)kWindowHeight);
	//初期シーンの初期化
	currentSceneNo_ = TITLE;//現在のシーン
	prevSceneNo_ = SCENE_NULL;//過去のシーン
	IScene::p_nextSceneNo_ = SceneChange;//次のシーンの検出する関数ポインタ
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
		sceneArr_[currentSceneNo_]->Update(keys, preKeys, tempSceneNo_);

		//描画
		sceneArr_[currentSceneNo_]->Draw();

		//シーンを切り替える
		SceneChangeTimeOut();

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
void GameManager::SceneCheck() {
	currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();
}

//シーン変更チェック
void GameManager::SceneChangeCheck() {
	sceneArr_[currentSceneNo_]->Initialise();
	prevSceneNo_ = currentSceneNo_;
}

//シーンの生成
void GameManager::SceneCreate() {
	//シーンチェック
	SceneCheck();

	//前のシーンと今のシーンが違った場合今のシーンを生成する
	if (prevSceneNo_ != currentSceneNo_) {
		sceneArr_[currentSceneNo_]->SetFadeColor(0x00000000);//フェードに使ったボックスの色を透明にセット
		sceneArr_[currentSceneNo_]->SetIsFadeOutStart(false);//フェードアウトを行うかのフラグをfalseにセット
		//各シーンの配列
		switch (currentSceneNo_) {
		case TITLE:
			tempSceneNo_ = TITLE;//仮のシーンにTITLEを代入
			sceneArr_[TITLE] = make_unique<Title>();//タイトルシーンの生成
			sceneArr_[END] = nullptr;//エンドシーンを空にする
			break;
		case STAGE:
			tempSceneNo_ = STAGE;//仮のシーンにSTAGEを代入
			sceneArr_[STAGE] = make_unique<Stage>();//ステージシーンの生成
			sceneArr_[TITLE] = nullptr;//タイトルシーンを空にする
			break;
		case END:
			tempSceneNo_ = END;//仮のシーンにENDを代入
			sceneArr_[END] = make_unique<End>();//エンドシーンの生成
			sceneArr_[STAGE] = nullptr;//ステージシーンを空にする
			break;
		}

		//シーン変更チェック
		SceneChangeCheck();
	}
}

//シーンを切り替えるときのコールバック関数
void GameManager::SceneChangeTimeOut() {
	if (prevSceneNo_ != tempSceneNo_) {
		int second = 3;
		IScene::SceneChangeTimeOut(second, tempSceneNo_);
	}
}


