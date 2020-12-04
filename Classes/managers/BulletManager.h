#pragma once
#include "Pool.h"
#include "IObjectManager.h"
#include "SimpleBullet.h"

class BulletManager : public IObjectManager
{
private:
	static BulletManager* _instance;

public:
	static BulletManager* instance();

public:
	BulletManager();
	~BulletManager();
	void update(float dt);
	void initialize(float visibleWidth, float visibleHeight, float originX, float originY);
	Bullet* launch(float launchX, float launchY, float power, int direction, int tag, float speedMultiplier, cocos2d::Color3B color);
	void destroy(Bullet* pBullet);

private:
	void addToPool(Bullet* pBullet);
	
private:
	Pool<SimpleBullet> _bulletPool;
	std::list<Bullet*> pBullets;
};
