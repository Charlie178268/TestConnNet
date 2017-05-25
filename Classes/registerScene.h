#ifndef __REGISTER_SCENE_H__
#define __REGISTER_SCENE_H__
//引入头文件和命名空间
#include "cocos-ext.h"
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include <iostream>
#include <string>
#include "network\HttpClient.h"
USING_NS_CC_EXT;
USING_NS_CC;
using namespace std;
using namespace cocostudio::timeline;
using namespace cocos2d::network;
class Register : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	////自定义变量
	//EditBox * uidbox1;
	//EditBox * pwdbox1;

	//自定义函数
	void goBackMenuItemCallback(Ref* pSender);
	void loginMenuItemCallback(Ref* pSender);
	void httpResponse(HttpClient* client, HttpResponse* response);
	CREATE_FUNC(Register);
};

#endif 