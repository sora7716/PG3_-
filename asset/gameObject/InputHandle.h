#pragma once
#include "asset/gameObject/Command.h"

/// <summary>
/// 入力を管理するクラス
/// </summary>
class InputHandle {
public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	InputHandle();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~InputHandle();

	/// <summary>
	/// コマンドを実行
	/// </summary>
	/// <returns></returns>
	IPlayerCommand* PlayerMoveInput();

	/// <summary>
	/// コマンドを実行
	/// </summary>
	/// <returns></returns>
	IBulletCommand* BulletShotInput();

	/// <summary>
	/// Aを押したら
	/// </summary>
	void AssignMoveLeftCommand2PressKeysA();

	/// <summary>
	/// Dを押したら
	/// </summary>
	void AssignMoveRightCommand2PressKeysD();

	/// <summary>
	/// Wを押したら
	/// </summary>
	void AssignMoveUpCommand2PressKeysW();

	/// <summary>
	/// Sを押したら
	/// </summary>
	void AssignMoveDownCommand2PressKeysS();

	/// <summary>
	/// MouseBottomLeftを押したら
	/// </summary>
	void AssignShotCommand2TriggerMouseBottomLeft();

private:
	IPlayerCommand* pressKeysD_ = nullptr;
	IPlayerCommand* pressKeysA_ = nullptr;
	IPlayerCommand* pressKeysW_ = nullptr;
	IPlayerCommand* pressKeysS_ = nullptr;
	IBulletCommand* triggerMouseBottomLeft_ = nullptr;
};

