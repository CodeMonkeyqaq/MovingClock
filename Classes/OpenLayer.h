//
//  OpenLayer.h
//  testflash
//
//  Created by 王星洲 on 2018/5/27.
//

#ifndef OpenLayer_H
#define OpenLayer_H

#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;
class OpenLayer:public Layer
{
public:
    CREATE_FUNC(OpenLayer);
    virtual bool init();
    void menuCallBack(Ref * pSender);
public:
    SceneManager * tsm;
};


#endif /* OpenLayer_H */
