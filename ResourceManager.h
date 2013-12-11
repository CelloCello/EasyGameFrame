#pragma once
#include "hge.h"
#include "ASingleton.h"
#include "ObjectFactory.h"
#include "GameObject.h"
#include <map>
using namespace std;

/*
 *	�޲z���J��texture...�������
 */

class TextureUnit;

class ResourceManager : public ASingleton<ResourceManager>
{
public:
	ResourceManager(void);
	virtual ~ResourceManager(void);

	void Init(){}
	void Fini();		//����,Singleton�Ѻc�ɷ|�I

	void	Load(const char* FileName);			//Ū��
	TextureUnit*	GetTexture(int ID);
	GameObject*		CreateGameObj(int ID);				//���ͷs������
	bool			DestoryGameObj(GameObject* Obj);	//��������

private:
	typedef map<int,TextureUnit*>		TEX_MAP;	//�s��,�K��
	typedef TEX_MAP::value_type			TEX_VAL;
	typedef map<int,GameObject*>		OBJ_MAP;	//�s��,����
	typedef OBJ_MAP::value_type			OBJ_VAL;

	ObjectFactory<TextureUnit>			m_TextureFactory;
	TEX_MAP								m_TextureMap;

	OBJ_MAP								m_BaseObjMap;	//��¦�����,�ΨӲ��ͷs��GameObject
	ObjectFactory<GameObject>			m_ObjFactory;	//�C������u�t,�Ψӭ��w�`��
};


/*
 *	HGE texture�����
 */
class TextureUnit
{
public:
	TextureUnit(){}
	~TextureUnit(){}

	HTEXTURE m_TexID;
};