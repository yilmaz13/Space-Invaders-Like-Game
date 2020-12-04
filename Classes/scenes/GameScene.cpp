#include "GameScene.h"
#include "PlayerShip.h"
#include "Config.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));

	auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());

	scene->addChild(layer);
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	SpawnManager::instance()->labelSpawn(this, origin.x + 100, origin.y + visibleSize.height - 30, 24, "Score :", Color4B(255, 255, 255, 255));
	m_scoreLabel = SpawnManager::instance()->labelSpawn(this, origin.x + 175, origin.y + visibleSize.height - 30, 24, "0", Color4B(255, 255, 255, 255));

	// add background
	SpawnManager::instance()->spriteSpawn(this, visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y, visibleSize.width, visibleSize.height, BACKGROUND_PATH);

	//  adding event handlers
	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

	scheduleUpdate();

	return true;
}

void GameScene::update(float dt)
{
}

bool GameScene::onTouchBegan(Touch* touch, Event* event)
{
	Vec2 touchLocation = touch->getLocation();
	return true;
}

void GameScene::onTouchMoved(Touch* touch, Event* event)
{
	Vec2 touchLocation = touch->getLocation();	
}

void GameScene::onTouchEnded(Touch* touch, Event* event)
{
	Vec2 touchLocation = touch->getLocation();	
}

// Handle collision event
bool GameScene::onContactBegin(PhysicsContact& contact)
{
	return false;
}
