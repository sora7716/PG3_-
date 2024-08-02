#include "InputHandle.h"

//コンストラクタ
InputHandle::InputHandle(){
}

//デストラクタ
InputHandle::~InputHandle(){
}

//コマンドを実行
IPlayerCommand* InputHandle::PlayerMoveInput(){
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeysD_;
	}
	else if (Novice::CheckHitKey(DIK_A)) {
		return pressKeysA_;
	}

	if (Novice::CheckHitKey(DIK_W)) {
		return pressKeysW_;
	}
	else if (Novice::CheckHitKey(DIK_S)) {
		return pressKeysS_;
	}

	return nullptr;
}

IBulletCommand* InputHandle::BulletShotInput(){
	if (Novice::IsTriggerMouse(0)) {
		return triggerMouseBottomLeft_;
	}
	return nullptr;
}

//Aを押したら
void InputHandle::AssignMoveLeftCommand2PressKeysA(){
	IPlayerCommand* command = new MoveLeftCommand();
	pressKeysA_ = command;
}

//Dを押したら
void InputHandle::AssignMoveRightCommand2PressKeysD(){
	IPlayerCommand* command = new MoveRightCommand();
	pressKeysD_ = command;
}

//Wを押したら
void InputHandle::AssignMoveUpCommand2PressKeysW(){
	IPlayerCommand *command = new MoveUpCommand();
	pressKeysW_ = command;
}

//Sを押したら
void InputHandle::AssignMoveDownCommand2PressKeysS(){
	IPlayerCommand* command = new MoveDownCommand();
	pressKeysS_ = command;
}

//MouseBottomLeftを押したら
void InputHandle::AssignShotCommand2TriggerMouseBottomLeft(){
	IBulletCommand* command = new ShotUpCommand();
	triggerMouseBottomLeft_ = command;
}

