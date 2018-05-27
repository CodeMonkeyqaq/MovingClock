//
//  ClockLayer.h
//  testflash
//
//  Created by 王星洲 on 2018/5/27.
//

#ifndef ClockLayer_H
#define ClockLayer_H

#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;
class ClockLayer:public Layer
{
public:
    CREATE_FUNC(ClockLayer);
    virtual bool init();
    
    void menuCallBack(Ref * pSender);
    void timeUpdate(float dt);
    
public:
    SceneManager * tsm;
    
    Sprite * _hour;
    Sprite * _minute;
    Sprite * _second;
    Sprite * _background;
    
    int hourRotation = 0;
    int minuteRotation = 0;
    int secondRotation = 0;
};

#endif /* ClockLayer_H */
