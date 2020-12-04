#pragma once
#include "cocos2d.h"

class SpawnManager
{
private:
	static SpawnManager* _instance;
public:
	SpawnManager();
	~SpawnManager();
	static SpawnManager* instance();	
	void spriteSpawn(cocos2d::Scene* ParentScene, float positionX, float positionY, float width, float height, std::string path);
	cocos2d::Label* labelSpawn(cocos2d::Scene* ParentScene, float positionX, float positionY, float size, std::string path, cocos2d::Color4B color);
	void menuSpawn(cocos2d::Scene* ParentScene, float positionX, float positionY, std::string pathNormal, std::string pathDown, const cocos2d::ccMenuCallback& callback);
};

