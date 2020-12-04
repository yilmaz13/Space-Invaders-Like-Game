#include "Ship.h"
#include "SpriteBase.h"
#include "Bullet.h"

SpaceShip::SpaceShip(float health, float width, float height, std::string path)
	: SpriteBase(width, height, path)
{
	m_health = health;
	m_fullHealth = m_health;
};

void SpaceShip::reset() {}
void SpaceShip::hit(Bullet* pBullet) {};
