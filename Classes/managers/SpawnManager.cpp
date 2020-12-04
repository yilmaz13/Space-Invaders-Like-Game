#include "Config.h"
#include "SpawnManager.h"

USING_NS_CC;

SpawnManager* SpawnManager::_instance = nullptr;

SpawnManager* SpawnManager::instance() {
	if (_instance == nullptr) {
		_instance = new SpawnManager();
	}
	return _instance;
}

SpawnManager::SpawnManager()
{
}
SpawnManager::~SpawnManager()
{
}

void SpawnManager::menuSpawn(Scene* ParentScene, float positionX, float positionY, std::string pathNormal, std::string pathDown, const ccMenuCallback& callback) {
	auto menuItem = MenuItemImage::create(
		pathNormal, pathDown, callback);

	if (menuItem == nullptr || menuItem->getContentSize().width <= 0 || menuItem->getContentSize().height <= 0)
	{
		printf("image is missing.");
	}
	else
	{
		menuItem->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		menuItem->setPosition(Vec2(positionX, positionY));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(menuItem, NULL);
	menu->setPosition(Vec2::ZERO);
	ParentScene->addChild(menu, 10);
}
void SpawnManager::spriteSpawn(cocos2d::Scene* ParentScene, float positionX, float positionY, float width, float height, std::string path)
{
	auto sprite = Sprite::create(path);
	if (sprite == nullptr) {
		printf("path is missing.");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		sprite->setPosition(Vec2(positionX, positionY));
		sprite->setContentSize(cocos2d::Size(width, height));
		// add the sprite as a child to this layer
		ParentScene->addChild(sprite, 0);
	}
}
cocos2d::Label* SpawnManager::labelSpawn(cocos2d::Scene* ParentScene, float positionX, float positionY, float size, std::string path, cocos2d::Color4B color)
{
	auto currentLabel = Label::createWithTTF(path, "fonts/space_invaders.ttf", size);
	if (currentLabel == nullptr)
	{
		printf("'fonts/space_invaders.ttf' is missing.");
	}
	else
	{
		// position the label on the center of the screen
		currentLabel->setPosition(Vec2(positionX, positionY));
		currentLabel->setTextColor(color);
		// add the label as a child to this layer
		ParentScene->addChild(currentLabel, 10);
	}
	return currentLabel;
}