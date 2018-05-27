//
//  SceneManager.h
//  testflash-mobile
//
//  Created by 王星洲 on 2018/5/27.
//

#ifndef SceneManager_H
#define SceneManager_H

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class SceneManager
{
public:
    Scene * loadScene;
    Scene * openScene;
    Scene * clockScene;
public:
    void createLoadScene();
    void goOpenScene();
    void goClockScene();
};



#endif /* SceneManager_H */
