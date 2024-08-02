#pragma once
#include <memory>
#include "scene/IScene.h"
#include "scene/title/Title.h"
#include "scene/stage/Stage.h"
#include "scene/end/End.h"
using namespace std;
//ゲームの処理
class GameManager {

public://静的メンバ変数

	static inline const char* kWindowTitle = "GC2B_01_イイヅカ_ソラ";
	static inline const float kWindowWidth = 1280.0f;
	static inline const float kWindowHeight = 720.0f;
	static inline const int kKeyNum = 256;

private://メンバ変数

	//シーンを保持するメンバ変数
	unique_ptr<IScene> sceneArr_[IScene::kSceneNum];

	//どのステージシーンを呼び出すかの変数
	int currentSceneNo_;//現在のシーン
	int prevSceneNo_;//前のシーン

	// キー入力結果を受け取る箱
	char keys[kKeyNum] = { 0 };
	char preKeys[kKeyNum] = { 0 };

public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameManager();

	/// <summary>
	/// この関数でゲームループを呼び出す
	/// </summary>
	/// <returns></returns>
	int Run();

private://メンバ関数
	
	/// <summary>
	/// シーンチェック
	/// </summary>
	void SceneCheck();

	/// <summary>
	/// シーンの要素チェック
	/// </summary>
	void SceneChangeCheck();

	/// <summary>
	/// シーンの生成
	/// </summary>
	void SceneCreate();
};

