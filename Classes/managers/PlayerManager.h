#include "IObjectManager.h"
#include "Pool.h"
#include "cocos2d.h"

class PlayerShip;
class Bullet;

class PlayerManager : public IObjectManager
{
private:
    static PlayerManager* _instance;
public:
    static PlayerManager* instance();
    PlayerManager();
	~PlayerManager();
	void update(float dt);
	void initialize(float visibleWidth, float visibleHeight, float originX, float originY);
    PlayerShip* heroShip() { return m_pPlayerShip; }

public: // event handlers
	void onTouchBegan(float touchX, float touchY);
	void onTouchMoved(float touchX, float touchY);
	void onTouchEnded(float touchX, float touchY);

private:
	void reloadBullet();
	void move();
	void powerUpControl(float dt);
	void bulletShootControl(float dt);
private:
    PlayerShip* m_pPlayerShip;

private: // touch state variables
	bool  m_bTouchBegan;
	float m_touchX, m_touchY;
	float m_fBulletReloadTimer;
	float m_fPowerUpTimer = 0.0f;
};
