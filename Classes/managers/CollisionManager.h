#pragma once
#include "cocos2d.h"

class GameScene;
class SpriteBase;
class PlayerShip;
class EnemyShip;
class Bullet;

class CollisionManager
{
private:
	static CollisionManager* _instance;
	GameScene* pGameScene;
public:
	CollisionManager();
	void setGameScene(GameScene* pScene);
	static CollisionManager* instance();
	bool handleHeroEnemyCollision(PlayerShip* pHero, EnemyShip* pEnemy);
	bool handleRocketEnemyCollision(Bullet* pRocket, EnemyShip* pEnemy);
	bool handleRocketPlayerCollision(Bullet* pRocket, PlayerShip* pPlayer);
	bool handleRocketRocketCollision(Bullet* pRocket, Bullet* pRocketOther);
};

