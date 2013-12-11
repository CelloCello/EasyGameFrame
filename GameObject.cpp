#include ".\gameobject.h"
#include "MemDef.h"

GameObject::GameObject(void):m_Anim(NULL)
{
}

GameObject::~GameObject(void)
{
	Fini();
}
//--------------------------------------------------------------------------------------------------
void GameObject::CloneTo(GameObject* Obj)
{
	Obj->m_Anim = new hgeAnimation(*m_Anim);
	Obj->m_KindID = m_KindID;

}
//--------------------------------------------------------------------------------------------------
void GameObject::Fini()
{
	SAFE_DELETE(m_Anim);
}
//--------------------------------------------------------------------------------------------------