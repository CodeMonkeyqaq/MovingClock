//
//  helloWorldLayor.h
//  testflash
//
//  Created by 王星洲 on 2018/5/27.
//

#ifndef helloWorldLayer_H
#define helloWorldLayer_H

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

class HelloWorldLayer:public Layer
{
public:
    static HelloWorldLayer * create();
    bool init();
    
    void menuCloseCallBack(Ref * pSender);
};

#endif /* helloWorldLayer_H */
