#include "EnemyManager.h"
#include "Config.h"
#include <iostream>
#include "BulletManager.h"
#include "LightEnemyShip.h"
#include "HeavyEnemyShip.h"

USING_NS_CC;

EnemyManager* EnemyManager::_instance = nullptr;

EnemyManager* EnemyManager::instance()
{
	if (_instance == nullptr) {
		_instance = new EnemyManager();
	}
	return _instance;
}

EnemyManager::EnemyManager()
{
}

void EnemyManager::update(float dt)
{	
	std::list<EnemyShip*>::iterator it;

	moveTimer += dt;
	if (moveTimer >= moveTimeConstant)
	{
		setMoveTimeConstant();
		setBorders(it);
		setDirection();
		move();
		moveTimerReset();
		shoot();
	}
}
void EnemyManager::setMoveTimeConstant()
{
	if (pEnemies.size() > 30 && pEnemies.size() <= 40)	
		moveTimeConstant = 1.0f;
	else if(pEnemies.size() > 20 && pEnemies.size() <= 30)
		moveTimeConstant = 0.75f;
	else if(pEnemies.size() > 10 && pEnemies.size() <= 20)
		moveTimeConstant = 0.5f;
	else if(pEnemies.size() > 5 && pEnemies.size() <= 10)
		moveTimeConstant = 0.3f;
	else if(pEnemies.size() > 1 && pEnemies.size() <= 5)
		moveTimeConstant = 0.15f;
}
void EnemyManager::moveTimerReset()
{
	moveTimer = 0.f;
}
void EnemyManager::shoot()
{
	float fEnemyX = (rand() % 600) + 200;	
	BulletManager::instance()->launch(fEnemyX, downBorder - 10, 25, ENEMY_BULLET_DIRECTION, TAG_BULLET_ENEMY, ENEMY_BULLET_SPEED_MULTIPLIER, Color3B(255, 255, 255));
}
void EnemyManager::move()
{
	if (downloadable)
		EnemyParent->setPositionY(EnemyParent->getPositionY() - HEAVY_ENEMY_HEIGHT);
	else
		EnemyParent->setPositionX(EnemyParent->getPositionX() + (direction * SPACE_SHIP_WIDTH));
	downloadable = false;
}
void EnemyManager::setDirection()
{
	if (leftBorder < originX + SPACE_SHIP_WIDTH)
	{
		downloadable = (direction == -1) ? true : false;
		direction = +1;
	}
	else if (rightBorder > visibleWidth - SPACE_SHIP_WIDTH * 2)
	{
		downloadable = (direction == 1) ? true : false;
		direction = -1;
	}
}
void EnemyManager::setBorders(std::list<EnemyShip*>::iterator it)
{
	leftBorder = 20000;	rightBorder = 0;	downBorder = 1000;

	for (it = pEnemies.begin(); it != pEnemies.end(); ++it) {
		EnemyShip* pEnemy = *it;

		float fEnemyX = pEnemy->getPositionX() + EnemyParent->getPositionX();
		float fEnemyY = pEnemy->getPositionY() + EnemyParent->getPositionY();

		leftBorder = (fEnemyX < leftBorder) ? fEnemyX : leftBorder;
		rightBorder = (fEnemyX > rightBorder) ? fEnemyX : rightBorder;
		downBorder = (fEnemyY < downBorder) ? fEnemyY : downBorder;
	}
}
void EnemyManager::addToPool(EnemyShip* pEnemy)
{
	switch (pEnemy->enemyType()) {
	case ENEMY_SHIP_HEAVY:
	{
		_heavyEnemyPool.returnObject((HeavyEnemyShip*)pEnemy);
		break;
	}
	case ENEMY_SHIP_LIGHT:
	{
		_lightEnemyPool.returnObject((LightEnemyShip*)pEnemy);
		break;
	}
	}
}
void EnemyManager::initialize(float visibleWidth, float visibleHeight, float originX, float originY)
{
	IObjectManager::initialize(visibleWidth, visibleHeight, originX, originY);
	generateTroop();
}
void EnemyManager::generateTroop()
{
	EnemyParent = Node::create();
	this->pGameScene->addChild(EnemyParent);

	float xMargin = SPACE_SHIP_WIDTH / 2.f;
	float occu_width = SPACE_SHIP_WIDTH * 3.f / 2.f;
	float occu_height = SPACE_SHIP_HEIGHT * 3.f / 2.f;
	float orijin_y = SPACE_SHIP_HEIGHT * 8;
	float delta_val = visibleWidth - xMargin * 2.f;
	int col_cnt = COLUMN;
	int row_cnt = ROW;	

	for (int j = 0; j < row_cnt; j++)
	{
		for (int i = 2; i < col_cnt + 2; i++)
		{
			int nEnemyType = rand() % 2;
			// make random enemy ship
			EnemyShip* pEnemy = nullptr;
			if (nEnemyType == ENEMY_SHIP_HEAVY) {
				pEnemy = _heavyEnemyPool.getOne();
			}
			else 
			{
				pEnemy = _lightEnemyPool.getOne();
			}
			pEnemies.push_back(pEnemy);

			pEnemy->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
			pEnemy->setPosition(Vec2(originX + xMargin + occu_width * i,
				visibleHeight + originY + occu_height * j - orijin_y));
			this->EnemyParent->addChild(pEnemy);
		}
	}
}

void EnemyManager::kill(EnemyShip* pEnemy)
{
	pEnemies.remove(pEnemy);
	this->EnemyParent->removeChild(pEnemy, true);
	pEnemy->reset();

	if (pEnemy->enemyType() == ENEMY_SHIP_HEAVY)
		_heavyEnemyPool.returnObject((HeavyEnemyShip*)pEnemy);
	else
		_lightEnemyPool.returnObject((LightEnemyShip*)pEnemy);
}

EnemyManager::~EnemyManager()
{
	_heavyEnemyPool.destroy();
	_lightEnemyPool.destroy();
}