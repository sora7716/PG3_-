#include "Player.h"
#include "asset/GameManager.h"

//コンストラクタ
Player::Player() {
}

//デストラクタ
Player::~Player() {
}

//初期化
void Player::Initialize() {
	player_.position = {GameManager::kWindowWidth/2.0f,GameManager::kWindowHeight/2.0f};
	player_.radius = 30.0f;
	player_.velocity = {5.0f,5.0f};
	player_.color = WHITE;
}

//更新
void Player::Update() {
	
}

//描画
void Player::Draw() {
	Novice::DrawEllipse((int)player_.position.x, (int)player_.position.y, (int)player_.radius, (int)player_.radius, 0.0f, player_.color, kFillModeSolid);
}

// プレイヤーのマテリアルのセッター
void Player::SetPlayerMaterial(PlayerMaterial material) {
	player_ = material;
}

//ポジションのゲッター
Vector2 Player::GetPosition(){
	return player_.position;
}

//右へ移動
void Player::MoveRight() {
	player_.position.x += player_.velocity.x;
}

//左へ移動
void Player::MoveLeft(){
	player_.position.x -= player_.velocity.x;
}

//上へ移動
void Player::MoveUp(){
	player_.position.y -= player_.velocity.y;
}

//下へ移動
void Player::MoveDown() {
	player_.position.y += player_.velocity.y;
}

