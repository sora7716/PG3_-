#include "Command.h"
#include "asset/gameObject/player/Player.h"
#include "asset/gameObject/bullet/Bullet.h"

//コンストラクタ
MoveRightCommand::MoveRightCommand(){
}

//デストラクタ
MoveRightCommand::~MoveRightCommand(){
}

//右に動くの実行
void MoveRightCommand::Exec(Player& player){
	player.MoveRight();
}

//コンストラクタ
MoveLeftCommand::MoveLeftCommand(){
}

//デストラクタ
MoveLeftCommand::~MoveLeftCommand(){
}

//左に動くの実行
void MoveLeftCommand::Exec(Player& player){
	player.MoveLeft();
}

//コンストラクタ
MoveUpCommand::MoveUpCommand(){
}

//デストラクタ
MoveUpCommand::~MoveUpCommand(){
}

//上に動くの実行
void MoveUpCommand::Exec(Player& player){
	player.MoveUp();
}

//コンストラクタ
MoveDownCommand::MoveDownCommand(){
}

//デストラクタ
MoveDownCommand::~MoveDownCommand(){
}

//下に動くの実行
void MoveDownCommand::Exec(Player& player){
	player.MoveDown();
}

//コンストラクタ
ShotUpCommand::ShotUpCommand(){
}

//デストラクタ
ShotUpCommand::~ShotUpCommand(){
}

//球を打つの実行
void ShotUpCommand::Exec(Bullet& bullet){
	bullet.Shot();
}
