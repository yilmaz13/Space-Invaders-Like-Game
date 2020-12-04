#include "PlayerManager.h"
#include "PlayerShip.h"
#include "Config.h"
#include "BulletManager.h"

USING_NS_CC;

PlayerManager* PlayerManager::_instance = nullptr;

PlayerManager* PlayerManager::instance()
{
	if (_instance == nullptr) {
		_instance = new PlayerManager();
	}
	return _instance;
}

PlayerManager::PlayerManager()
{
	m_pPlayerShip = new PlayerShip();
	m_bTouchBegan = false;
	m_fBulletReloadTimer = 0.f;
}

void PlayerManager::update(float dt)
{
	if (m_bTouchBegan)
		move();

	powerUpControl(dt);
	bulletShootControl(dt);
}

void PlayerManager::reloadBullet()
{
	m_fBulletReloadTimer = 0.f;
}

void PlayerManager::bulletShootControl(float dt)
{
	m_fBulletReloadTimer += dt;
	if (m_fBulletReloadTimer >= BULLET_RELOAD_RATE) {
		reloadBullet();
		m_pPlayerShip->fire();
	}
}

void PlayerManager::powerUpControl(float dt)
{
	if (m_pPlayerShip->powerUp)
	{
		m_fPowerUpTimer += dt;
		// bulletColor red
		m_pPlayerShip->bulletColor = Color3B(255, 0, 0);
		if (m_fPowerUpTimer >= 3)
		{
			m_pPlayerShip->coolDownAbility();
			m_fPowerUpTimer = 0;
			//bulletColor green
			m_pPlayerShip->bulletColor = Color3B(0, 255, 90);
		}
	}
}

void PlayerManager::move()
{
	float curx = m_pPlayerShip->getPositionX();
	if (curx + SHIP_DELTA_X <= std::min(m_touchX, visibleWidth - SPACE_SHIP_WIDTH / 2))
	{
		m_pPlayerShip->setPositionX(curx + SHIP_DELTA_X);
	}
	else if (curx - SHIP_DELTA_X >= std::max(m_touchX, SPACE_SHIP_WIDTH / 2))
	{
		m_pPlayerShip->setPositionX(curx - SHIP_DELTA_X);
	}
}

void PlayerManager::initialize(float visibleWidth, float visibleHeight, float originX, float originY)
{
	IObjectManager::initialize(visibleWidth, visibleHeight, originX, originY);
	Size shipSize = m_pPlayerShip->getContentSize();
	m_pPlayerShip->setPosition(visibleWidth / 2 + originX, shipSize.height * 3 + originY);
	pGameScene->addChild(m_pPlayerShip);
}

void PlayerManager::onTouchBegan(float touchX, float touchY)
{
	m_bTouchBegan = true;
	m_touchX = touchX;
	m_touchY = touchY;
}

void PlayerManager::onTouchMoved(float touchX, float touchY)
{
	m_touchX = touchX;
	m_touchY = touchY;
}

void PlayerManager::onTouchEnded(float touchX, float touchY)
{
	m_touchX = touchX;
	m_touchY = touchY;
	m_bTouchBegan = false;
}

PlayerManager::~PlayerManager()
{
	delete m_pPlayerShip;
}