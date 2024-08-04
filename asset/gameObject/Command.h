#pragma once
#include<Novice.h>

class Player;
class Bullet;

/// <summary>
/// コマンドのインターフェース
/// </summary>
class IPlayerCommand{
public://メンバ関数

	//純粋仮想関数
	virtual ~IPlayerCommand() = default;
	virtual void Exec(Player& player) = 0;
};

class IBulletCommand {
public:

	//純粋仮想関数
	virtual ~IBulletCommand() = default;
	virtual void Exec(Bullet& bullet) = 0;
};

/// <summary>
/// 右に動くコマンド
/// </summary>
class MoveRightCommand :public IPlayerCommand {
public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	MoveRightCommand();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~MoveRightCommand()override;

	/// <summary>
	/// 実行
	/// </summary>
	/// <param name="player">プレイヤー</param>
	void Exec(Player& player)override;
};

/// <summary>
/// 左に動くコマンド
/// </summary>
class MoveLeftCommand :public IPlayerCommand {
public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	MoveLeftCommand();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~MoveLeftCommand()override;

	/// <summary>
	/// 実行
	/// </summary>
	/// <param name="player">プレイヤー</param>
	void Exec(Player& player)override;
};

/// <summary>
/// 上に動くコマンド
/// </summary>
class MoveUpCommand :public IPlayerCommand {
public://メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	MoveUpCommand();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~MoveUpCommand()override;

	/// <summary>
	/// 実行
	/// </summary>
	/// <param name="player">プレイヤー</param>
	void Exec(Player& player)override;
};

/// <summary>
/// 下に動くコマンド
/// </summary>
class MoveDownCommand :public IPlayerCommand {
public://メンバ関数
	/// <summary>
	/// コンストラクタ
	/// </summary>
	MoveDownCommand();
	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~MoveDownCommand();

	/// <summary>
	/// 実行
	/// </summary>
	/// <param name="player"></param>
	void Exec(Player& player);
};

/// <summary>
/// 球を発射するコマンド
/// </summary>
class ShotUpCommand :public IBulletCommand {
public://メンバ関数
	/// <summary>
	/// コンストラクタ
	/// </summary>
	ShotUpCommand();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~ShotUpCommand();

	/// <summary>
	/// 実行
	/// </summary>
	/// <param name="player"></param>
	void Exec(Bullet& bullet)override;
};

