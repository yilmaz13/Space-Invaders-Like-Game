#pragma once
#include "Pool.h"
#include "IObjectManager.h"
#include "HeavyEnemyShip.h"
#include "LightEnemyShip.h"


class EnemyManager : public IObjectManager
{
private:
    static EnemyManager* _instance;

public:
    static EnemyManager* instance();

public:
	EnemyManager();
	~EnemyManager();
    void update(float dt);
	void initialize(float visibleWidth, float visibleHeight, float originX, float originY);
	void kill(EnemyShip* pEnemy);	
	float m_fEnemyRocketReloadTimer;
	void moveTimerReset();
	void shoot();
private:
	void generateTroop();
	void addToPool(EnemyShip* pEnemy);
	void setBorders(std::list<EnemyShip*>::iterator it);
	void setDirection();
	void move();
	void setMoveTimeConstant();
private:
	cocos2d::Label* m_Label;		// score label
    Pool<HeavyEnemyShip> _heavyEnemyPool;
    Pool<LightEnemyShip> _lightEnemyPool;
	std::list<EnemyShip*> pEnemies;	
	cocos2d::Node* EnemyParent;
	
	//TODO: rename
	bool downloadable = false;	
	float direction = 1;
	float moveTimer = 0.0f;
	float moveTimeReset = 0.0f;
	float moveTimeConstant = 1.0f;
	float leftBorder = 1500;
	float rightBorder = 0;
	float downBorder = 10000;
};
