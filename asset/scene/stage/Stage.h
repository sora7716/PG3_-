#pragma once
#include "asset/scene/IScene.h"
#include "asset/gameObject/player/Player.h"
#include "asset/gameObject/bullet/Bullet.h"
#include "asset/gameObject/Command.h"
#include "asset/gameObject/InputHandle.h"
#include <vector>
using namespace std;

/// <summary>
/// ステージシーンのクラス
/// </summary>
class Stage :public IScene {

private://メンバ変数

	InputHandle* inputHandle_ = nullptr;//入力を受け取る
	IPlayerCommand* iPlayerCommand_ = nullptr;//プレイヤーコマンド
	IBulletCommand* iBulletCommand_ = nullptr;//弾コマンド
	Player* player_ = nullptr;//プレイヤー
	vector<Bullet*>bullets_ = { nullptr };//弾

public://静的メンバ変数

	static inline const int kBulletNum = 10;//球の数

public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Stage();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Stage();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialise()override;

	/// <summary>
	/// 更新
	/// </summary>
	void Update(const char* keys, const char* preKeys, int& scene)override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw()override;

private://メンバ関数

	/// <summary>
	/// 弾の場所を初期化　
	/// </summary>
	/// <param name="num">どれくらい再帰するか</param>
	void BulletInitialize(int num);
};

