//
//  LoadLayer.cpp
//  testflash
//
//  Created by 王星洲 on 2018/5/27.
//

#include "LoadLayer.h"
bool LoadLayer::init()
{
    Label * label = Label::createWithTTF("Loading...", "fonts/Marker Felt.ttf", 32);
    label -> setPosition(Vec2(480, 320));
    this -> addChild(label);
    scheduleOnce(CC_SCHEDULE_SELECTOR(LoadLayer::onScheduleOnce), 2.0);
    return true;
}
void LoadLayer::onScheduleOnce(float dt)
{
    tsm -> goOpenScene();
}
