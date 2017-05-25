#include "LoginScene.h"
//#include "MenuScene.h"
Scene* Login::createScene()
{
    auto scene = Scene::create();
	auto layer = Login::create();
    scene->addChild(layer);
    return scene;
}
bool Login::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
	Staticnow = false;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//����ͼ
	bg = Sprite::create("background.jpg");
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bg);
	
	//���غ͵�¼�˵�

	loginMenuItem = MenuItemImage::create("buttonA.png","buttonB.png",CC_CALLBACK_1(Login::goBackMenuItemCallback, this));//����
	loginMenuItem->setAnchorPoint(Vec2(0, 0));
	loginMenuItem->setPosition(Vec2(bg->getContentSize().width / 4, bg->getContentSize().height / 10));
	loginMenuItem->setPosition(Point(200, 20));

	signUpMenuItem = MenuItemImage::create("buttonA.png","buttonB.png",CC_CALLBACK_1(Login::loginMenuItemCallback, this));//��½
	signUpMenuItem->setAnchorPoint(Vec2(0, 0));
	signUpMenuItem->setPosition(Vec2(bg->getContentSize().width / 3.3 * 2, bg->getContentSize().height / 10));
	signUpMenuItem->setPosition(600, 20);

	zhuceMenuItem = MenuItemImage::create("buttonA.png", "buttonB.png", CC_CALLBACK_1(Login::zhuceMenuItemCallback, this));//ע��
	zhuceMenuItem->setAnchorPoint(Vec2(0, 0));
	zhuceMenuItem->setPosition(Vec2(bg->getContentSize().width / 4, bg->getContentSize().height / 10));
	zhuceMenuItem->setPosition(Point(400, 20));

	menu = Menu::create(loginMenuItem, signUpMenuItem,zhuceMenuItem, NULL);
	menu->setPosition(Vec2::ZERO);
	bg->addChild(menu,100);
	

	Sprite * goBack = Sprite::create("fanhui.png");			//��buttonBg������ͼƬ
	goBack->setPosition(Vec2(loginMenuItem->getContentSize().width / 2, loginMenuItem->getContentSize().height / 2));
	loginMenuItem->addChild(goBack);

	Sprite * login = Sprite::create("denglu.png");
	login->setPosition(Vec2(signUpMenuItem->getContentSize().width / 2, signUpMenuItem->getContentSize().height / 2));
	signUpMenuItem->addChild(login);

	////ע�ᵯ��
	Sprite * EditBg = Sprite::create("Editzhuce.png");
	EditBg->setPosition(Vec2(zhuceMenuItem->getContentSize().width / 2, zhuceMenuItem->getContentSize().height / 2));
	zhuceMenuItem->addChild(EditBg);


	//���롢�˺���ͼ
	Sprite * userid = Sprite::create("zhanghao.png");
	userid->setPosition(Vec2(bg->getContentSize().width/2-600,bg->getContentSize().height / 3.5));
	EditBg->addChild(userid);

	Sprite * password = Sprite::create("mima.png");
	password->setPosition(Vec2(bg->getContentSize().width /2-600, bg->getContentSize().height / 5));
	EditBg->addChild(password);

	//��¼�༭��
	Sprite * editBox = Sprite::create("wenbenkuang.png");

	CCSize  uidSize = CCSizeMake(editBox->getContentSize().width * 2, editBox->getContentSize().height);
	uidbox = cocos2d::ui::EditBox::create(uidSize, cocos2d::ui::Scale9Sprite::create("wenbenkuang.png"));
	uidbox->setMaxLength(10);
	uidbox->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
	uidbox->setPosition(Vec2(bg->getContentSize().width / 2-400, bg->getContentSize().height / 3.5));
	EditBg->addChild(uidbox);

	CCSize  pwdSize = CCSizeMake(editBox->getContentSize().width * 2, editBox->getContentSize().height);
	pwdbox = cocos2d::ui::EditBox::create(pwdSize, cocos2d::ui::Scale9Sprite::create("wenbenkuang.png"));
	pwdbox->setMaxLength(12);
	//pwdbox->setInputMode(EditBox::InputMode::SINGLE_LINE);
	pwdbox->setInputFlag(cocos2d::ui::EditBox::InputFlag::PASSWORD);
	pwdbox->setPosition(Vec2(bg->getContentSize().width / 2 - 400, bg->getContentSize().height / 5));
	EditBg->addChild(pwdbox);
	pointout();
    return true;
}
string Login::getNameandStatic(){
	if (Staticnow == true)
	{
		return Name;
	}
	else{
		return "None";
	}
		

}
void Login::loginMenuItemCallback(Ref* pSender)  //����¼��ť���ص��¼�
{
	const char * uid = uidbox->getText();
	const char * pwd = pwdbox->getText();
	Name = uid;
	string strid("uname=");
	string strpwd("&upass=");
	string url("http://192.168.1.125/checkLogin02.php?");
	//string url("http://192.168.1.211/login.php?");
	string userid(uid);
	string password(pwd);
	url += strid + userid + strpwd + password;

	//CCLog(url.c_str());  
	HttpClient * client = HttpClient::getInstance();
	HttpRequest * req = new HttpRequest();
	req->setUrl(url.c_str());
	//log(url.c_str());		//string ת���� const char *
	req->setUrl(url.c_str());
	req->setRequestType(HttpRequest::Type::GET);
	req->setResponseCallback(this, httpresponse_selector(Login::httpResponse));
	req->setTag("GET test");
	client->send(req);
	req->release();
	log("denglu!!!");

}
void Login::zhuceMenuItemCallback(Ref* pSender)//ע��
{
	log("zhuce!!!");
	Staticnow = false;
	if (signUpMenuItem->isVisible())
	{
		log("visable");
		loginMenuItem->setPosition(Point(600, 20));
		signUpMenuItem->setEnabled(false);
		signUpMenuItem->setVisible(false);
		//loginMenuItem->setEnabled(false);
		//loginMenuItem->setVisible(false);
	}
	else
	{
		log(" no visable");
		reMenuItemCallback();
	}
	
}
void Login::reMenuItemCallback()//ע��ĵ��ҳ��
{
	log("zhuceback!!!");
	const char * uid = uidbox->getText();
	const char * pwd = pwdbox->getText();

	string strid("uname=");
	string strpwd("&upass=");
	string url("http://192.168.56.1/register.php?");
	string userid(uid);
	string password(pwd);
	url += strid + userid + strpwd + password;

	//CCLog(url.c_str());   


	HttpClient * client = HttpClient::getInstance();
	HttpRequest * req = new HttpRequest();
	req->setUrl(url.c_str());
	//log(url.c_str());		//string ת���� const char *
	req->setUrl(url.c_str());
	req->setRequestType(HttpRequest::Type::GET);
	req->setResponseCallback(this, httpresponse_selector(Login::httpResponse2));
	req->setTag("GET test");
	client->send(req);
	req->release();

	log("zhuceback");



}
void Login::httpResponse2(HttpClient* client, HttpResponse* response)
{
	log("register php ");
	if (!response->isSucceed())
	{
		log("Receive from server error and the error code is %s\n", response->getErrorBuffer());
		return;
	}
	else
	{

		vector<char> * buffer = response->getResponseData();    //...��÷������ݵ���Ϣ
		char * strtmp = (char *)malloc(sizeof(char)*buffer->size());
		//ͨ������ֵ�ж��Ƿ��¼�ɹ�
		for (int i = 0; i < buffer->size(); i++)
		{
			strtmp[i] = (*buffer)[i];
			log((*buffer)[i]);
		}
		string analys(strtmp);
		free(strtmp);
		strtmp = NULL;

		if (analys.find("status:ok") < analys.length())
		{
			
			MessageBox("ע��ɹ�", "ע��ɹ���");   //�����Ի���
			
			log("ע��ɹ�");
			 
			pLabel->setString("register success" );
			pLabel2->setString("");

			/*auto sc = MenuScene::createScene();
			Director::getInstance()->replaceScene(sc);*/
		}
		else
		{
			//��¼ʧ�ܣ����ݿ��в��Ҳ�����Ϣ
			//��ʾ��������˻�����
			MessageBox("ע��ʧ��", "ע��ʧ�ܣ�");
			log("ע��ʧ��");
			pLabel->setString("register failed!");
			pLabel2->setString("Please check your account or password.");
			 
		}
	}
}









void Login::goBackMenuItemCallback(Ref* pSender)
{
	if (signUpMenuItem->isVisible())
	{
		auto scene = TransitionFadeTR::create(1.0, MenuScene::createScene());
		Director::getInstance()->replaceScene(scene);
		//Director::getInstance()->end();
	}
	else
	{
		auto sc = Login::createScene();
		Director::getInstance()->replaceScene(sc);
	}
	
}
void Login::httpResponse(HttpClient* client, HttpResponse* response)
{
	log("http");
	if (!response->isSucceed())
	{
		log("Receive from server error and the error code is %s\n", response->getErrorBuffer());
		pLabel->setString("Unable to connect to server");
		return;   
	}
	else
	{

		vector<char> * buffer = response->getResponseData();    //...��÷������ݵ���Ϣ
		char * strtmp = (char *)malloc(sizeof(char)*buffer->size());
		//ͨ������ֵ�ж��Ƿ��¼�ɹ�
		for (int i = 0; i < buffer->size(); i++)
		{
			strtmp[i] = (*buffer)[i];
			log((*buffer)[i]);
		}
		string analys(strtmp);
		free(strtmp);
		strtmp = NULL;

		if (analys.find("status:ok") < analys.length())
		{
			//��¼�ɹ������ݿ��в�ѯ���û���Ϣ
			//��¼��������			
			//MessageBox("��¼�ɹ�", "��¼�ɹ���");   //�����Ի���
			log("��¼�ɹ�");
			pLabel->setString("Login success");
			Staticnow = true;
			auto sc =MenuScene::createScene();
			Director::getInstance()->replaceScene(sc);
		}
		else
		{
			//��¼ʧ�ܣ����ݿ��в��Ҳ�����Ϣ
			//��ʾ��������˻�����
			//MessageBox("��¼ʧ��", "��¼ʧ�ܣ�");
			log("��¼ʧ��");
			pLabel->setString("login faild!");
			pLabel2->setString("Please check your account or password.");
		}
	}
}
void Login::pointout()
{
	pLabel = CCLabelTTF::create("", "Arial", 20);//Ҫ��ʾ�����ݣ����壬�ֺ�  
	pLabel->setPosition(ccp(240, 180));
	this->addChild(pLabel, 1);
	pLabel2 = CCLabelTTF::create("", "Arial", 15);//Ҫ��ʾ�����ݣ����壬�ֺ�  
	pLabel2->setPosition(ccp(240, 150));
	this->addChild(pLabel2, 1);
}