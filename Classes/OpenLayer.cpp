//
//  OpenLayer.cpp
//  testflash
//
//  Created by 王星洲 on 2018/5/27.
//

#include "OpenLayer.h"
bool OpenLayer::init()
{
    Size winsize = Director::getInstance() -> getWinSize();
    Label * label = Label::createWithSystemFont("时钟程序", "", 48);
    label -> setPosition(Vec2(winsize.width/2,winsize.height*3/4));
    label -> setColor(Color3B(255, 0, 0));
    this ->addChild(label);
    
    MenuItemLabel * menuItem = MenuItemLabel::create(Label::createWithSystemFont("开始", "", 30), CC_CALLBACK_1(OpenLayer::menuCallBack, this));
    menuItem -> setTag(101);
    menuItem -> setPosition(Vec2(winsize.width/2,winsize.height*0.3));
    
    MenuItemLabel * menuItem_2 = MenuItemLabel::create(Label::createWithSystemFont("退出", "", 30), CC_CALLBACK_1(OpenLayer::menuCallBack, this));
    menuItem_2 -> setTag(102);
    menuItem_2 -> setPosition(Vec2(winsize.width/2,winsize.height*0.15));
    auto menu = Menu::create(menuItem, menuItem_2, NULL);
    menu -> setPosition(Point::ZERO);
    this -> addChild(menu);
    return true;
}
void OpenLayer::menuCallBack(Ref * pSender)
{
    switch ((static_cast<MenuItem *>(pSender)) -> getTag()){
    case 101:
        {
            tsm -> goClockScene();
            break;
        }
    case 102:
        {
            Director::getInstance() -> end();
            exit(0);
            break;
        }
            
        default:
            break;
    }
    
}
