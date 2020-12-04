#include "Bullet.h"
#include "Config.h"

Bullet::Bullet(float power, float width, float height, std::string path)
	: SpriteBase(width, height, path)
{	
	m_power = power;
}
