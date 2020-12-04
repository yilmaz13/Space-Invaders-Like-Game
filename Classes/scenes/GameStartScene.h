
#ifndef __GAMEOVER_SCENE_H__
#define __GAMEOVER_SCENE_H__

#include "cocos2d.h"

class GameStartScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    enum SpriteType{
        image,
        label
    };

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameStartScene);

private:  
    void menuStartCallback(Ref* sender);
    void SpriteSpawn(float positionX, float positionY, float width, float height, std::string path);
    void LabelSpawn(float positionX, float positionY, float size, std::string path, cocos2d::Color4B color);
    void MenuSpawn(float positionX, float positionY, std::string pathNormal, std::string pathDown);
};

#endif // __HELLOWORLD_SCENE_H__
