#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void update(float dt);
	void SetPhysicsWorld(cocos2d::PhysicsWorld* world) { m_sceneWorld = world; };

	// touch event listener
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onContactBegin(cocos2d::PhysicsContact& contact);

private:
	cocos2d::Label* m_scoreLabel;		// score label	
	cocos2d::PhysicsWorld* m_sceneWorld;
	// implement the "static create()" method manually
	CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
