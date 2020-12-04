#include "Config.h"
#include "Bullet.h"
#include "Ship.h"
#include "PlayerShip.h"
#include "Pool.h"
#include <SpawnManager.h>
#include <BulletManager.h>

PlayerShip::PlayerShip()
	: SpaceShip(PLAYER_SPACE_SHIP_HEALTH, SPACE_SHIP_WIDTH, SPACE_SHIP_HEIGHT, SPACE_SHIP_PATH)
{
	setTag(TAG_PLAYERSHIP);
	powerUp = false;
}
void PlayerShip::killScoreAdd()
{
	killValue++;
	if (killValue % 5 == 0)
		ability();
}
void PlayerShip::ability()
{
	powerUp = true;
	damage = POWERUP_BULLET_POWER;
}
void PlayerShip::coolDownAbility()
{
	powerUp = false;
	damage = DEFAULT_BULLET_POWER;
}
void PlayerShip::hit(Bullet* pBullet)
{
	this->m_health -= pBullet->getPower();
}
Bullet* PlayerShip::fire()
{
	return BulletManager::instance()->launch(this->getPositionX(), (this->getPositionY()) + 30.0, this->damage, PLAYER_BULLET_DIRECTION, TAG_BULLET_PLAYER, PLAYER_BULLET_SPEED_MULTIPLIER, this->bulletColor);	
}
