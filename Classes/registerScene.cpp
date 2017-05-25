#include "registerScene.h"
Scene* Register::createScene()
{
	auto scene = Scene::create();
	auto layer = Register::create();
	scene->addChild(layer);
	return scene;
}
bool Register::init()
{

	if (!Register::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//����ͼ
	Sprite * bg = Sprite::create("background.jpg");
	bg->setScaleX(visibleSize.width / bg->getContentSize().width);
	bg->setScaleY(visibleSize.height / bg->getContentSize().height);
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(bg);

	//���غ͵�¼�˵�

	//auto loginMenuItem = MenuItemImage::create("buttonA.png", "buttonB.png", CC_CALLBACK_1(Login::goBackMenuItemCallback, this));//����
	//loginMenuItem->setAnchorPoint(Vec2(0, 0));
	//loginMenuItem->setPosition(Vec2(bg->getContentSize().width / 4, bg->getContentSize().height / 10));
	//loginMenuItem->setPosition(Point(200, 20));

	//auto signUpMenuItem = MenuItemImage::create("buttonA.png", "buttonB.png", CC_CALLBACK_1(Login::loginMenuItemCallback, this));//��½
	//signUpMenuItem->setAnchorPoint(Vec2(0, 0));
	//signUpMenuItem->setPosition(Vec2(bg->getContentSize().width / 3.3 * 2, bg->getContentSize().height / 10));
	//signUpMenuItem->setPosition(600, 20);

	//auto zhuceMenuItem = MenuItemImage::create("buttonA.png", "buttonB.png", CC_CALLBACK_1(Login::goBackMenuItemCallback, this));//����
	//zhuceMenuItem->setAnchorPoint(Vec2(0, 0));
	//zhuceMenuItem->setPosition(Vec2(bg->getContentSize().width / 4, bg->getContentSize().height / 10));
	//zhuceMenuItem->setPosition(Point(400, 20));





	//Menu * menu = Menu::create(loginMenuItem, signUpMenuItem, zhuceMenuItem, NULL);
	//menu->setPosition(Vec2::ZERO);
	//bg->addChild(menu, 100);


	//Sprite * goBack = Sprite::create("fanhui.png");			//��buttonBg������ͼƬ
	//goBack->setPosition(Vec2(loginMenuItem->getContentSize().width / 2, loginMenuItem->getContentSize().height / 2));
	//loginMenuItem->addChild(goBack);

	//Sprite * login = Sprite::create("denglu.png");
	//login->setPosition(Vec2(signUpMenuItem->getContentSize().width / 2, signUpMenuItem->getContentSize().height / 2));
	//signUpMenuItem->addChild(login);

	//////ע�ᵯ��
	//Sprite * EditBg = Sprite::create("Editzhuce.png");
	//EditBg->setPosition(Vec2(zhuceMenuItem->getContentSize().width / 2, zhuceMenuItem->getContentSize().height / 2));
	//zhuceMenuItem->addChild(EditBg);


	////���롢�˺���ͼ
	//Sprite * userid = Sprite::create("zhanghao.png");
	//userid->setPosition(Vec2(bg->getContentSize().width / 2 - 600, bg->getContentSize().height / 3.5));
	//EditBg->addChild(userid);

	//Sprite * password = Sprite::create("mima.png");
	//password->setPosition(Vec2(bg->getContentSize().width / 2 - 600, bg->getContentSize().height / 5));
	//EditBg->addChild(password);

	////��¼�༭��
	//Sprite * editBox = Sprite::create("wenbenkuang.png");

	//CCSize  uidSize = CCSizeMake(editBox->getContentSize().width * 2, editBox->getContentSize().height);
	//uidbox = EditBox::create(uidSize, Scale9Sprite::create("wenbenkuang.png"));
	//uidbox->setMaxLength(10);
	//uidbox->setInputMode(EditBox::InputMode::SINGLE_LINE);
	//uidbox->setPosition(Vec2(bg->getContentSize().width / 2 - 400, bg->getContentSize().height / 3.5));
	//EditBg->addChild(uidbox);

	//CCSize  pwdSize = CCSizeMake(editBox->getContentSize().width * 2, editBox->getContentSize().height);
	//pwdbox = EditBox::create(pwdSize, Scale9Sprite::create("wenbenkuang.png"));
	//pwdbox->setMaxLength(12);
	////pwdbox->setInputMode(EditBox::InputMode::SINGLE_LINE);
	//pwdbox->setInputFlag(EditBox::InputFlag::PASSWORD);
	//pwdbox->setPosition(Vec2(bg->getContentSize().width / 2 - 400, bg->getContentSize().height / 5));
	//EditBg->addChild(pwdbox);

	return true;
}
void Register::loginMenuItemCallback(Ref* pSender)  //����¼��ť���ص��¼�
{
	//const char * uid = uidbox1->getText();
	//const char * pwd = pwdbox1->getText();

	//string strid("uname=");
	//string strpwd("&upass=");
	//string url("http://192.168.56.1/checkLogin02.php?");
	////string url("http://192.168.1.211/login.php?");
	//string userid(uid);
	//string password(pwd);
	//url += strid + userid + strpwd + password;

	////CCLog(url.c_str());   


	//HttpClient * client = HttpClient::getInstance();
	//HttpRequest * req = new HttpRequest();
	//req->setUrl(url.c_str());
	////log(url.c_str());		//string ת���� const char *
	//req->setUrl(url.c_str());
	//req->setRequestType(HttpRequest::Type::GET);
	//req->setResponseCallback(this, httpresponse_selector(Register::httpResponse));
	//req->setTag("GET test");
	//client->send(req);
	//req->release();

	log("denglu!!!");

}
void Register::goBackMenuItemCallback(Ref* pSender)
{
	auto sc = Register::createScene();
	Director::getInstance()->replaceScene(sc);
}
void Register::httpResponse(HttpClient* client, HttpResponse* response)
{
	log("http");
	if (!response->isSucceed())
	{
		log("Receive from server error and the error code is %s\n", response->getErrorBuffer());
		return;   //...
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
			MessageBox("��¼�ɹ�", "��¼�ɹ���");   //�����Ի���
			log("��¼�ɹ�");
			auto sc = Register::createScene();
			Director::getInstance()->replaceScene(sc);
		}
		else
		{
			//��¼ʧ�ܣ����ݿ��в��Ҳ�����Ϣ
			//��ʾ��������˻�����
			MessageBox("��¼ʧ��", "��¼ʧ�ܣ�");
			log("��¼ʧ��");
		}
	}
}