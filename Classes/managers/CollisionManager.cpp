#include "CollisionManager.h"
#include "Config.h"
#include "GameOverScene.h"
#include "GameScene.h"
#include "SpriteBase.h"
#include "Bullet.h"
#include "MenuManager.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "PlayerShip.h"
#include "BulletManager.h"

USING_NS_CC;

CollisionManager* CollisionManager::_instance = nullptr;

CollisionManager* CollisionManager::instance() {
	if (_instance == nullptr) {
		_instance = new CollisionManager();
	}
	return _instance;
}

CollisionManager::CollisionManager()
{
	// nothing to do here
}

void CollisionManager::setGameScene(GameScene* pScene)
{
	pGameScene = pScene;
}

bool CollisionManager::handleHeroEnemyCollision(PlayerShip* pHero, EnemyShip* pEnemy)
{
	pGameScene->stopAllActions();
	MenuManager::instance()->switchScene(SCENE_GAME_OVER);
	return true;
}

bool CollisionManager::handleRocketEnemyCollision(Bullet* pBullet, EnemyShip* pEnemy)
{
	pEnemy->hit(pBullet);

	if (pEnemy->isDead())
	{
		EnemyManager::instance()->kill(pEnemy);
		pGameScene->enemyDead(pEnemy->scorePoint());
	}
	pGameScene->removeChild(pBullet);
	return true;
}

bool CollisionManager::handleRocketPlayerCollision(Bullet* pBullet, PlayerShip* pPlayer)
{
	pPlayer->hit(pBullet);

	if (pPlayer->isDead())
	{
		pGameScene->stopAllActions();
		MenuManager::instance()->switchScene(SCENE_GAME_OVER);			
	}
	pGameScene->removeChild(pBullet);
	return true;	
}

bool CollisionManager::handleRocketRocketCollision(Bullet* pBullet, Bullet* pBulletOther)
{
	BulletManager::instance()->destroy(pBullet);
	BulletManager::instance()->destroy(pBulletOther);	
	return true;
}
