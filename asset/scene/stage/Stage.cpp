#include "Stage.h"

//コンストラクタ
Stage::Stage() {
}

//デストラクタ
Stage::~Stage() {
	delete player_;//プレイヤーの削除

	//弾の削除
	for (Bullet* bullet : bullets_) {
		delete bullet;
	}
	bullets_.clear();
}

//初期化
void Stage::Initialise() {
	//入力を受け取る
	inputHandle_ = new InputHandle();//生成
	inputHandle_->AssignMoveLeftCommand2PressKeysA();//A
	inputHandle_->AssignMoveRightCommand2PressKeysD();//D
	inputHandle_->AssignMoveUpCommand2PressKeysW();//W
	inputHandle_->AssignMoveDownCommand2PressKeysS();//S
	inputHandle_->AssignShotCommand2TriggerMouseBottomLeft();//MouseBottomLeft

	//プレイヤー
	player_ = new Player();//生成
	player_->Initialize();//初期化
	bullets_.resize(kBulletNum);//弾の数

	//再帰的に生成している
	BulletInitialize(kBulletNum);
}

//更新
void Stage::Update(const char* keys, const char* preKeys, int& scene) {
	//get input
	iPlayerCommand_ = inputHandle_->PlayerMoveInput();//移動
	//移動
	if (iPlayerCommand_) {
		iPlayerCommand_->Exec(*player_);
	}

	//get input
	iBulletCommand_ = inputHandle_->BulletShotInput();//攻撃
	//攻撃
	for (auto bullet: bullets_) {
		if (iBulletCommand_) {
			if (!bullet->GetIsAlive()) {
				iBulletCommand_->Exec(*bullet);
				break;
			}
		}
	}

	if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
		isFadeOutStart_ = true;//フェードアウトをスタート]
		scene = END;
	}

	//プレイヤーの更新
	player_->Update();

	//弾の更新
	for (auto bullet:bullets_) {
		bullet->Update();
		bullet->Destroy(player_->GetPosition());
	}
}

//描画
void Stage::Draw() {
	//シーンについて
	IScene::SceneNameAndBackground("STAGE", "END", 0x0000FFAA);
	//操作方法
	Novice::ScreenPrintf(0, 40, "Press MouseLeftBottom [shot]");//プレイヤーの攻撃
	Novice::ScreenPrintf(0, 60, "Press W [up]:Press S [down]:Press D [right]:Press A [left]");//プレイヤーの移動
	//プレイヤー　
	player_->Draw();
	//弾
	for (Bullet* bullet : bullets_) {
		bullet->Draw();
	}
	//フェードアウト
	IScene::DrawFadeOut();
}

//弾の場所を初期化　
void Stage::BulletInitialize(int num) {
	if (num <= 0.0f) {
		return;//numが0になったら抜ける
	}
	Bullet* bullet = new Bullet();//生成
	bullet->Initialize(player_->GetPosition());//初期化
	bullets_[num - 1] = bullet;//メンバ変数の弾に代入
	BulletInitialize(num - 1);//再帰処理
}

