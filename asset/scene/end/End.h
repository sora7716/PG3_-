#pragma once
#include "asset/scene/IScene.h"
/// <summary>
/// エンドシーンのクラス
/// </summary>
class End :public IScene {

private://メンバ変数

public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	End();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~End();

	/// <summary>
    /// 初期化
    /// </summary>
	void Initialise()override;

	/// <summary>
	/// 更新
	/// </summary>
	void Update(const char* keys, const char* preKeys)override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw()override;
};

