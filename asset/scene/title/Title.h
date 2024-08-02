#pragma once
#include "asset/scene/IScene.h"

/// <summary>
/// タイトルシーンのクラス
/// </summary>
class Title:public IScene{

private://メンバ変数
	
public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Title();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Title();

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
};

