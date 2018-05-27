//
//  helloWorldLayor.cpp
//  testflash
//
//  Created by 王星洲 on 2018/5/27.
//

#include "helloWorldLayer.h"
HelloWorldLayer * HelloWorldLayer::create()
{
    HelloWorldLayer * pRet = new HelloWorldLayer();
    if(pRet && pRet -> init())
    {
        pRet -> autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
bool HelloWorldLayer::init()
{
    if(Layer::init() == false)
    {
        return false;
    }
    Size size = Director::getInstance()->getVisibleSize();
    Label * label = Label::createWithTTF("Hello World!", "fonts/Marker Felt.ttf", 36);
    label -> setPosition(Vec2(size.width/2, size.height*3/4));
    this -> addChild(label);
    auto sprite = Sprite::create("HelloWorld.png");
    sprite -> setPosition(Vec2(size.width/2,size.height/2));
    this -> addChild(sprite);
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorldLayer::menuCloseCallBack, this));
    closeItem -> setPosition(Vec2(900,100));
    auto menu = Menu::create(closeItem, NULL);
    menu -> setPosition(Point::ZERO);
    this -> addChild(menu);
    return true;
}

void HelloWorldLayer::menuCloseCallBack(Ref * pSender)
{
    CCLOG("manuCloseCallBack");
}

