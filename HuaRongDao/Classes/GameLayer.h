#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_

#include "cocos2d.h"

class Level ;
class RoleSprite ;
class GameLayer : public cocos2d::Layer
{
public:
	 static cocos2d::Scene* createScene();
	 CREATE_FUNC(GameLayer);
public:
	GameLayer();
	~GameLayer();
	virtual bool init();

	//@biref ��ʼ����ͼ
	void initMap() ;
	//@biref ����m_mapState
	void updateMapData() ;
	void resetMapData();

	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) ;
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) ;
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) ;

	//@biref �Ƿ�����ƶ���������Ҫ�ƶ��ķ���,�����ӵķ����ƶ����������ķ����ƶ�
	bool isCanMove(bool isMoveHor,bool moveAdd);

	void myClock(float dt);
	std::string getFormatTime(int t);
	//static GameLayer* gameLayer();
	//static cocos2d::Scene* s2GameSceneInstance();
	void resetPLevel(Level* level);

	void menuStartCallback(Ref* pSender);
private:
	//Level * m_pLevel;//<�ؿ����ݵ�����
	cocos2d::Vector<RoleSprite*> m_pRoleSpriteVec ;//<�洢��ɫ����
	cocos2d::Vec2 m_touchBegin ;//<��ʼ�����λ��
	cocos2d::Vec2 m_touchMove ;//<�ƶ������еĵ�
	float m_minDis ;//<��С�ƶ����룬>=����ʱ����ж��Ƿ��ƶ�
	RoleSprite * m_pSeleNode ;//<ѡ�еĽ�ɫ
	int m_mapState[5][4] ;//<5��4�У�0�ǿգ�1�������

	int steps; 
	int m_time;
	CC_SYNTHESIZE(Level *, m_pLevel, PLevel);//��ѡ�ؿ�

	//static cocos2d::Scene* game333SceneInstance;

};
#endif