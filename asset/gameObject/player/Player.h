#pragma once
#include <Vector2.h>
#include <Novice.h>
#include <cmath>
#define _USE_MATH_DEFINES

/// <summary>
/// プレイヤークラス
/// </summary>
class Player {

public://構造体など

	//プレイヤーの素材
	typedef struct PlayerMaterial {
		Vector2 position;
		float radius;
		Vector2 velocity;
		uint32_t color;
	}PlayerMaterial;

private://メンバ変数

	PlayerMaterial player_ = {};

public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// プレイヤーのマテリアルのセッター
	/// </summary>
	/// <param name="material">プレイヤーのマテリアル</param>
	void SetPlayerMaterial(PlayerMaterial material);

	/// <summary>
	/// ポジションのゲッター
	/// </summary>
	/// <returns></returns>
	Vector2 GetPosition();

public://コマンド

	/// <summary>
	/// 右へ移動
	/// </summary>
	void MoveRight();

	/// <summary>
	/// 左へ移動
	/// </summary>
	void MoveLeft();

	/// <summary>
	/// 上へ移動
	/// </summary>
	void MoveUp();

	/// <summary>
	/// 下へ移動
	/// </summary>
	void MoveDown();
};

