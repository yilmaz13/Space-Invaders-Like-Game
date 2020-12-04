#include "GameOverScene.h"
#include "GameScene.h"
#include "MenuManager.h"
#include "Config.h"
#include <SpawnManager.h>

USING_NS_CC;

Scene* GameOverScene::createScene()
{
	return GameOverScene::create();
}
bool GameOverScene::init()
{
    // super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // create and initialize  labels
    SpawnManager::instance()->menuSpawn(this, origin.x + visibleSize.width / 2 - 175.0f,
        origin.y + (visibleSize.height - 500), BUTTON_RETRY_NORMAL_PATH, BUTTON_RETRY_DOWN_PATH,
        CC_CALLBACK_1(GameOverScene::menuRetryCallback, this));
    SpawnManager::instance()->menuSpawn(this, origin.x + visibleSize.width / 2 + 175.0f,
        origin.y + (visibleSize.height - 500), BUTTON_EXIT_NORMAL_PATH, BUTTON_EXIT_DOWN_PATH,
        CC_CALLBACK_1(GameOverScene::menuExitCallback, this));

    SpawnManager::instance()->labelSpawn(this, origin.x + visibleSize.width / 2, origin.x + visibleSize.width / 2, 32, "Game Over!", Color4B(255, 255, 255, 255));
    // add background
    SpawnManager::instance()->spriteSpawn(this, visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y, visibleSize.width, visibleSize.height, BACKGROUND_PATH);
    
    SpawnManager::instance()->labelSpawn(this, visibleSize.width - 250 + HEAVY_ENEMY_WIDTH, origin.y + 100, 12, " Development by Ahmet Muhammet Yilmaz", Color4B(0, 255, 240, 255));

    return true;
}

void GameOverScene::menuExitCallback(Ref* pSender)
{
	MenuManager::instance()->quit();
}

void GameOverScene::menuRetryCallback(Ref* pSender)
{
	MenuManager::instance()->switchScene(SCENE_GAME_PLAY);
}
