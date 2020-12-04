#include "GameStartScene.h"
#include "GameOverScene.h"
#include "GameScene.h"
#include "MenuManager.h"
#include "Config.h"
#include <SpawnManager.h>

USING_NS_CC;

Scene* GameStartScene::createScene()
{
	return GameStartScene::create();
}
bool GameStartScene::init()
{
	// super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	SpawnManager::instance()->menuSpawn(this, origin.x + visibleSize.width / 2,
		origin.y + (visibleSize.height - 650), BUTTON_START_NORMAL_PATH, BUTTON_START_DOWN_PATH,
		CC_CALLBACK_1(GameStartScene::menuStartCallback, this));	
	
	auto colorWhite = Color4B(255, 255, 255, 255);
	auto colorPurple = Color4B(210, 0, 255, 255);
	auto colorBlue = Color4B(0, 255, 240, 255);
	auto colorRed = Color4B(237, 28, 36, 255);	
	auto colorGreen = Color4B(0, 255, 90, 255);	
	
	// create and initialize  labels and sprites
	SpawnManager::instance()->spriteSpawn(this, visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y, visibleSize.width, visibleSize.height, BACKGROUND_PATH);

	SpawnManager::instance()->labelSpawn(this, visibleSize.width / 2 + origin.x, origin.y + (visibleSize.height - 150), 64, "SPACE INVADERS!", colorWhite);
	SpawnManager::instance()->labelSpawn(this, visibleSize.width / 2 + origin.x, origin.y + (visibleSize.height - 250), 32, "PRESS TO START!", colorWhite);

	
	SpawnManager::instance()->spriteSpawn(this, visibleSize.width / 2 + origin.x - HEAVY_ENEMY_WIDTH * 2, visibleSize.height - 350, HEAVY_ENEMY_WIDTH, HEAVY_ENEMY_HEIGHT, ENEMY2_PATH);
	SpawnManager::instance()->labelSpawn(this, visibleSize.width / 2 + origin.x + HEAVY_ENEMY_WIDTH, origin.y + (visibleSize.height - 350), 32, "  =    10PTS", colorBlue);
	
	SpawnManager::instance()->spriteSpawn(this, visibleSize.width / 2 + origin.x - HEAVY_ENEMY_WIDTH * 2, visibleSize.height - 425, HEAVY_ENEMY_WIDTH, HEAVY_ENEMY_HEIGHT, ENEMY1_PATH);
	SpawnManager::instance()->labelSpawn(this, visibleSize.width / 2 + origin.x + HEAVY_ENEMY_WIDTH, origin.y + (visibleSize.height - 425), 32, "  =    20PTS", colorPurple);
	
	SpawnManager::instance()->labelSpawn(this, visibleSize.width - 250 + HEAVY_ENEMY_WIDTH, origin.y + 100, 12, " Development by Ahmet Muhammet Yilmaz", colorBlue);

	return true;
}
void GameStartScene::menuStartCallback(Ref* pSender)
{
	MenuManager::instance()->switchScene(SCENE_GAME_PLAY);
}