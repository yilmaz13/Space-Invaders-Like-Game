#pragma once
#include <string>
#include "Ship.h"

class Bullet;

class EnemyShip : public SpaceShip
{
protected:	
	int m_enemyType;
	int m_scorePoint;
public:
	EnemyShip(float health, float width, float height, std::string path, int scorePoint);
	virtual void hit(Bullet* pBullet);
	void reset();
	int enemyType() { return m_enemyType; }
	int scorePoint() { return m_scorePoint; }
	//void killNotification(const ccCallback& callback);
private:
	void resetHealthBar();
};



