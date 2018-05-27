//
//  LoadLayer.h
//  testflash
//
//  Created by 王星洲 on 2018/5/27.
//

#ifndef LoadLayer_H
#define LoadLayer_H

#include <iostream>
#include "SceneManager.h"
#include "cocos2d.h"
USING_NS_CC;
class LoadLayer:public Layer
{
public:
    CREATE_FUNC(LoadLayer);
    virtual bool init();
    //两秒跳转
    void onScheduleOnce(float dt);
public:
    SceneManager * tsm;
};



#endif /* LoadLayer_H */
