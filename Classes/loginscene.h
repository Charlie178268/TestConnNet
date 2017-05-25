#ifndef __LOGIN_SCENE_H__
#define __LOGIN_SCENE_H__
//引入头文件和命名空间
#include "cocos-ext.h"
#include "cocos2d.h"

#include "cocostudio/CocoStudio.h"
#include <iostream>
#include <string>
#include "ui/CocosGUI.h"
#include "network\HttpClient.h"
#include "cocos2d.h"
USING_NS_CC_EXT;
USING_NS_CC; 
using namespace std;
using namespace cocos2d::network;
using namespace cocostudio::timeline;
using namespace cocos2d::ui;
static string Name;
static bool Staticnow;
class Login : public cocos2d::Layer

{
public:
    static cocos2d::Scene* createScene();
	Scene *scene;
    virtual bool init();
	//自定义变量
	Menu * menu;
	
	
	MenuItem * signUpMenuItem;
	MenuItem * loginMenuItem;
	MenuItem * zhuceMenuItem;
	CCLabelTTF* pLabel;//提示结果
	CCLabelTTF* pLabel2;//提示错误原因
	cocos2d::ui::EditBox * uidbox;
	cocos2d::ui::EditBox * pwdbox;
	Sprite * bg;
	//自定义函数
	void pointout();//提示语
	void goBackMenuItemCallback(Ref* pSender);
	void loginMenuItemCallback(Ref* pSender);
	void zhuceMenuItemCallback(Ref* pSender);
	void reMenuItemCallback();
	void httpResponse(HttpClient* client, HttpResponse* response);
	void httpResponse2(HttpClient* client, HttpResponse* response);
	CREATE_FUNC(Login);
	static string getNameandStatic();
};

#endif 
