#include "BulletManager.h"
#include "Config.h"
#include "Bullet.h"
#include <SimpleBullet.h>

USING_NS_CC;

BulletManager* BulletManager::_instance = nullptr;

BulletManager* BulletManager::instance()
{
    if (_instance == nullptr) {
        _instance = new BulletManager();
    }
    return _instance;
}

BulletManager::BulletManager()
{
}

void BulletManager::update(float dt)
{
	std::list<Bullet*>::iterator it;
	std::list<Bullet*> removeArray;
	for (it = pBullets.begin(); it != pBullets.end(); ++it) {
		Bullet* pBullet = *it;
		float fBulletY = pBullet->getPositionY();

		pBullet->setPositionY(fBulletY + (pBullet->getDirection() * BULLET_DELTA_Y * pBullet->getSpeedMultiplier()));
		// If rocket has gone out of screen, remove from parent
		if (fBulletY > originY + visibleHeight + BULLET_HEIGHT)
		{
			pGameScene->removeChild(pBullet);
			removeArray.push_back(pBullet);
			addToPool(pBullet);
		}
	}
	
	for (it = removeArray.begin(); it != removeArray.end(); ++it) {
		pBullets.remove(*it);
	}
}

Bullet* BulletManager::launch(float launchX, float launchY, float power, int direction, int tag, float speedMultiplier, cocos2d::Color3B color)
{
	Bullet* pBullet = _bulletPool.getOne();
	pBullet->setPosition(Vec2(launchX, launchY));
	this->pGameScene->addChild(pBullet);
	pBullets.push_back(pBullet);
	pBullet->setPower(power);
	pBullet->setDirection(direction);
	pBullet->setTag(tag);	
	pBullet->setColor(color);
	pBullet->setSpeedMultiplier(speedMultiplier);
	return pBullet;
}
void BulletManager::destroy(Bullet* pBullet) {
	pGameScene->removeChild(pBullet);
	addToPool(pBullet);
	pBullets.remove(pBullet);
}
void BulletManager::initialize(float visibleWidth, float visibleHeight, float originX, float originY)
{
	IObjectManager::initialize(visibleWidth, visibleHeight, originX, originY);
}

void BulletManager::addToPool(Bullet* pBullet)
{
	_bulletPool.returnObject((SimpleBullet*)pBullet);
}

BulletManager::~BulletManager()
{
	_bulletPool.destroy();
}