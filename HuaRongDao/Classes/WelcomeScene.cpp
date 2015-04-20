#include "WelcomeScene.h"  
#include "GameDefine.h" 
#include "GameLayer.h" 
#include "AboutScene.h"

USING_NS_CC;

Scene* WelcomeScene::createScene()  {
	auto scene = Scene::create();
	auto layer = WelcomeScene::create();
	scene->addChild(layer);
	return scene;
}

// ��ӭ���� ��ʼ������  
bool WelcomeScene::init()   {
	// �ȳ�ʼ�����࣬���ɹ�����false  
	if (!Layer::init())    {
		return false;
	}

	m_level = 0;
	// TexturePacker ����������Դ��һ��ͼ��,������Դ,�ṩ������.
	SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Huarongdao2.plist", "Huarongdao2.png");

	// ��ӱ���ͼƬ  
	auto sprite = Sprite::create("menu_bg.png");
	sprite->setPosition(Point(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 2));
	this->addChild(sprite);

	// ��ӿ�ʼ��ť  
	auto startItem = MenuItemImage::create(
		"menuword/menuword_01.png",
		"menuword/menuword_back_01.png",
		CC_CALLBACK_1(WelcomeScene::menuStartCallback, this));

	startItem->setPosition(Vec2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 6 + startItem->getContentSize().height * 4));

	// ���ѡ�ť  
	auto optionItem = MenuItemImage::create(
		"menuword/menuword_02.png",
		"menuword/menuword_back_02.png",
		CC_CALLBACK_1(WelcomeScene::menuOptionCallback, this));

	optionItem->setPosition(Vec2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 6 + startItem->getContentSize().height * 3));

	// ������а�ť  
	auto ranklistItem = MenuItemImage::create(
		"menuword/menuword_03.png",
		"menuword/menuword_back_03.png",
		CC_CALLBACK_1(WelcomeScene::menuRankListCallback, this));

	ranklistItem->setPosition(Vec2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 6 + startItem->getContentSize().height * 2));

	// �����Ϸ˵����ť  
	auto instructionItem = MenuItemImage::create(
		"menuword/menuword_04.png",
		"menuword/menuword_back_04.png",
		CC_CALLBACK_1(WelcomeScene::menuInstructionCallback, this));

	instructionItem->setPosition(Vec2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 6 + startItem->getContentSize().height * 1));

	// ��ӹ�����Ϸ��ť  
	auto aboutItem = MenuItemImage::create(
		"menuword_05.png",
		"menuword_back_05.png",
		CC_CALLBACK_1(WelcomeScene::menuAboutCallback, this));

	aboutItem->setPosition(Vec2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 6));


	auto menu = Menu::create(startItem, optionItem, ranklistItem, instructionItem, aboutItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	return true;
}

void WelcomeScene::menuStartCallback(Ref* pSender)
{
	// ��ת����Ϸ����  
	// create a scene. it's an autorelease object
	TransitionScene * reScene = NULL;
	float t = 1.2f;
	auto scene = GameLayer::createScene();
	//    CCTransitionFade
	//    ���ã�����һ���𽥹��ɵ�Ŀ����ɫ���л�����
	//    ����1�����ɶ����ĳ���ʱ��
	//    ����2���л���Ŀ�곡���Ķ���
	//    ����3��Ŀ����ɫ
	//reScene = CCTransitionFade::create(t, scene, ccc3(255, 0, 0));

	//    CCTransitionSlideInR
	//    ���ã�����һ�����Ҳ����벢�����ɳ����Ĺ��ɶ���
	//    ����1�����ɶ����ĳ���ʱ��
	//    ����2���л���Ŀ�곡���Ķ���
	reScene  =TransitionSlideInR::create(t, scene);
	// run
	//CCDirector::sharedDirector()->replaceScene(scene);
	Director::getInstance()->replaceScene(reScene);
}

void WelcomeScene::menuOptionCallback(Ref* pSender)
{
	TransitionScene * reScene = NULL;
	float t = 1.2f;
	auto scene = GameLayer::createScene();
	reScene = TransitionSlideInR::create(t, scene);
	Director::getInstance()->replaceScene(reScene);
}

void WelcomeScene::menuRankListCallback(Ref* pSender)
{
	TransitionScene * reScene = NULL;
	float t = 1.2f;
	auto scene = GameLayer::createScene();
	reScene = TransitionSlideInR::create(t, scene);
	Director::getInstance()->replaceScene(reScene);
}

void WelcomeScene::menuInstructionCallback(Ref* pSender)
{
	TransitionScene * reScene = NULL;
	float t = 1.2f;
	auto scene = GameLayer::createScene();
	reScene = TransitionSlideInR::create(t, scene);
	Director::getInstance()->replaceScene(reScene);
}

void WelcomeScene::menuAboutCallback(Ref* pSender)
{
	TransitionScene * reScene = NULL;
	float t = 1.2f;
	auto scene = ABOUT::createScene();
	reScene = TransitionSlideInR::create(t, scene);
	Director::getInstance()->replaceScene(reScene);
}