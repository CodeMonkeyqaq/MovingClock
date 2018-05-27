//
//  ClockLayer.cpp
//  testflash
//
//  Created by 王星洲 on 2018/5/27.
//

#include "ClockLayer.h"

bool ClockLayer::init()
{
    Size winSize = Director::getInstance() ->getWinSize();
    MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont("返回", "", 30), CC_CALLBACK_1(ClockLayer::menuCallBack, this));
    menuItem ->setPosition(Vec2(winSize.width * 0.9,winSize.height * 0.9));
    auto menu = Menu::create(menuItem,NULL);
    menu -> setPosition(Point::ZERO);
    this -> addChild(menu);
    
    _background = Sprite::create("background.jpg");
    _background -> setPosition(Vec2(winSize.width/2,winSize.height/2));
    _background -> setScale(0.5);
    this ->addChild(_background);
    
    _hour = Sprite::create("shi.png");
    _hour -> setPosition(Vec2(winSize.width/2,winSize.height/2));
    _hour -> setScale(0.3);
    _hour -> setAnchorPoint(Vec2(0.5, 0));
    this ->addChild(_hour,1);
    
    _minute = Sprite::create("fen.png");
    _minute -> setPosition(Vec2(winSize.width/2,winSize.height/2));
    _minute -> setScale(0.3);
    _minute -> setAnchorPoint(Vec2(0.5, 0));
    this ->addChild(_minute,2);
    
    _second = Sprite::create("miao.png");
    _second -> setPosition(Vec2(winSize.width/2,winSize.height/2));
    _second -> setScale(0.3);
    _second -> setAnchorPoint(Vec2(0.5, 0));
    this ->addChild(_second,3);
    
    struct timeval nowTimeval;
    gettimeofday(& nowTimeval, NULL);
    struct tm * tm;
    time_t time_sec;
    time_sec = nowTimeval.tv_sec;
    tm = localtime(&time_sec);
    
    minuteRotation = tm -> tm_min * 6;
    secondRotation = tm -> tm_sec * 6;
    if(tm -> tm_hour > 12)
    {
        hourRotation = (tm -> tm_hour - 12) * 6 * 5;
        hourRotation += minuteRotation / 12;
    }
    else
    {
        hourRotation = (tm -> tm_hour) * 6 * 5;
        hourRotation += minuteRotation / 12;
    }
    
    _hour -> setRotation(hourRotation);
    _minute -> setRotation(minuteRotation);
    _second -> setRotation(secondRotation);
    
    schedule(CC_SCHEDULE_SELECTOR(ClockLayer::timeUpdate), 1.0);
    
    return true;
}
void ClockLayer::menuCallBack(Ref *pSender)
{
    tsm->goOpenScene();
}
void ClockLayer::timeUpdate(float dt)
{
    _second -> setRotation( _second -> getRotation() + 6);
    if(_second -> getRotation() == 360)
    {
        _minute -> setRotation(_minute ->getRotation() + 6);
        _second -> setRotation(0);
        if(static_cast<int>(_minute -> getRotation()) % 72 == 0)
        {
            _hour -> setRotation(_hour->getRotation() + 6);
            if(_minute ->getRotation() == 360)
            {
                _minute -> setRotation(0);
            }
        }
    }
}
