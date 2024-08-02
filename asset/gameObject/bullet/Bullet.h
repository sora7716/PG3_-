#pragma once
#include <Novice.h>
#include "Vector2.h"
#include <cmath>
#define _USE_MATH_DEFINES

/// <summary>
/// 弾
/// </summary>
class Bullet{

public://構造体など
	typedef struct BulletMaterial {
		Vector2 position;
		Vector2 velocity;
		float radius;
		uint32_t color;
		bool isAlive = false;
	}BulletMaterial;

private://メンバ変数

	BulletMaterial bullet_;//弾

public://静的メンバ変数
	static inline const float kSpeed = 5.0f;//弾の飛ぶスピード

public://メンバ関数
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bullet();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Bullet();

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="position">ポジション</param>
	void Initialize(Vector2 position);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 削除
	/// </summary>
	/// <param name="position">ポジション</param>
	void Destroy(Vector2 position);

	/// <summary>
	/// 生存フラグのゲッター
	/// </summary>
	/// <returns></returns>
	bool GetIsAlive();

	/// <summary>
	/// 生存フラグのセッター
	/// </summary>
	/// <param name="isAlive"></param>
	void SetIsAlive(bool isAlive);

public://コマンド

	/// <summary>
	/// 上へ移動
	/// </summary>
	void Shot();

};

