#pragma once
#include "SpriteBase.h"
#include "Config.h"
class Bullet;


class SpaceShip :
	public SpriteBase
{
protected:
	float m_fullHealth;
	float m_health;	
private:	

public:
	SpaceShip(float health, float width, float height, std::string path);
	bool isDead() { return m_health <= 0; }
	virtual void reset();
	float damage = DEFAULT_BULLET_POWER;
	virtual void hit(Bullet* pBullet) = 0;
};
