#pragma once
#include <Novice.h>
#include <cmath>
#define _USE_MATH_DEFINES

//シーン名を列挙型で定義
enum SCENE {
	TITLE,//タイトル
	STAGE,//ステージ
	END,//エンド
	sceneNum,//シーン無し
};

/// <summary>
/// シーンチェンジの関数ポインタ
/// </summary>
typedef void (*P_SceneChange)(int&,int);

/// <summary>
/// シーンをステージに変更
/// </summary>
void SceneChange(int &scene,int nexScene);

//シーン内での処理を行う基底クラス
class IScene {

public://静的メンバ変数

	static inline const int kSceneNum = sceneNum;//シーンの数

	static inline P_SceneChange p_nextSceneNo_;//次のシーンの関数ポインタ

protected://メンバ変数

	//シーン番号を管理する変数
	static int sceneNo_;

	static inline int fadeColor_ = 0u;//フェード用の色

	static inline bool isFadeOutStart_ = false;//フェードをスタートする用のフラグ

public://メンバ関数

	//継承先で実装される関数
	//抽象クラスなので純粋仮想関数とする
	virtual void Initialise() = 0;
	virtual void Update(const char* keys, const char* preKeys,int &scene) = 0;
	virtual void Draw() = 0;

	/// <summary>
	/// 仮想のデストラクタ
	/// </summary>
	virtual ~IScene() = default;

	/// <summary>
	/// シーン番号のゲッター
	/// </summary>
	/// <returns></returns>
	int GetSceneNo();

	/// <summary>
	/// シーン切り替え
	/// </summary>
	/// <param name="second"></param>
	/// <param name="scene"></param>
	static void SceneChangeTimeOut(int second,int scene);

	/// <summary>
	/// フェードアウト用のボックスの色のセッター
	/// </summary>
	/// <param name="fadeColor"></param>
	void SetFadeColor(int fadeColor);

	/// <summary>
	/// フェードアウトをスタートするかどうかのフラグのセッター
	/// </summary>
	/// <param name="isFadeOutStart"></param>
	void SetIsFadeOutStart(bool isFadeOutStart);

protected://メンバ関数

	/// <summary>
	/// シーンを切り替え用のコールバック関数
	/// </summary>
	/// <param name="second">どれくらいの時間待たせたいか(秒)</param>
	/// <param name="sceneNo">切り替え先のシーンナンバー</param>
	/// <param name="nexSceneNo">次のシーンナンバー</param>
	static void SetTimeOut(int second, P_SceneChange p_nextScene, int nexSceneNo);

	/// <summary>
	/// シーン切り替え時のフェードアウト
	/// </summary>
	/// <param name="second">どれくらいの時間待たせたいか(秒)</param>
	/// <param name="sceneNo">切り替え先のシーンナンバー</param>
	/// <param name="nexSceneNo">次のシーンナンバー</param>
	static void FadeOut(int second, P_SceneChange p_nextScene, int nexSceneNo);

	/// <summary>
	/// フェードアウト用のボックス
	/// </summary>
	void DrawFadeOut();

	/// <summary>
	/// シーンについて
	/// </summary>
	/// <param name="sceneName"></param>
	void SceneNameAndBackground(const char* sceneName, const char* nextSceneName,uint32_t backgroundColor);
};

