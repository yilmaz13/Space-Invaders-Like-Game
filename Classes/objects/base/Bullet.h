#pragma once
#include "SpriteBase.h"

class Bullet :
	public SpriteBase
{
private:
	float m_power;
	int m_direction;
	float m_speedMultiplier;

public:
	Bullet(float power, float width, float height, std::string path);
	float getPower() { return m_power; }
	float getSpeedMultiplier() { return m_speedMultiplier; }
	void setPower(float power) { m_power = power; }
	void setDirection(float direction) { m_direction = direction; }
	void setSpeedMultiplier(float speedMultiplier) { m_speedMultiplier = speedMultiplier; }	
	void destroy();
	int getDirection() { return m_direction; }
};

