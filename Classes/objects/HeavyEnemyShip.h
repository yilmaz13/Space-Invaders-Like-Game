#pragma once
#include "SpriteBase.h"
#include "Enemy.h"
#include <string>

class Bullet;

class HeavyEnemyShip : public EnemyShip
{
private:
	std::string m_normalImage;
	std::string m_hurtImage;
public:
	HeavyEnemyShip();
	~HeavyEnemyShip(){ }
};
