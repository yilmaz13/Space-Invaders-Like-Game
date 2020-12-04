#pragma once
#include "Ship.h"
#include "Config.h"

class Bullet;

class PlayerShip :
	public SpaceShip
{
public:
	PlayerShip();
	void killScoreAdd();
	void ability();
	void coolDownAbility();
	void hit(Bullet* pBullet);	
	Bullet* fire();
	int killValue = 0;
	float damage = DEFAULT_BULLET_POWER;
	bool powerUp = false;
	cocos2d::Color3B bulletColor = cocos2d::Color3B(0, 255, 90);
};
