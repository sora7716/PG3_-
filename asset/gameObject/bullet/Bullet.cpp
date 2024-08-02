#include "Bullet.h"

//コンストラクタ
Bullet::Bullet() {

}

//デストラクタ
Bullet::~Bullet() {

}

//初期化
void Bullet::Initialize(Vector2 position){
	bullet_.position = position;
	bullet_.velocity = {};
	bullet_.radius = 10;
	bullet_.color = 0xFF0000AA;
}

//更新
void Bullet::Update(){
	if (bullet_.isAlive) {
		bullet_.position.y -= bullet_.velocity.y;
	}
}

//描画
void Bullet::Draw(){
	if (bullet_.isAlive) {
		Novice::DrawEllipse((int)bullet_.position.x, (int)bullet_.position.y, (int)bullet_.radius, (int)bullet_.radius, 0.0f, bullet_.color, kFillModeSolid);
	}
}

//削除
void Bullet::Destroy(Vector2 position){
	if (bullet_.position.y < 0.0f) {
		bullet_.isAlive = false;
		bullet_.position = position;
	}
}

//生存フラグのゲッター
bool Bullet::GetIsAlive(){
	return bullet_.isAlive;
}

//生存フラグのセッター
void Bullet::SetIsAlive(bool isAlive){
	bullet_.isAlive = isAlive;
}

//上へ移動
void Bullet::Shot(){
	bullet_.isAlive = true;
	bullet_.velocity.y = kSpeed;
}
