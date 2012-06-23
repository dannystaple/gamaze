#include "CLinkList.h"


CListItem::CListItem(CListItem * p, CListItem * n,void * i)//Basic Item constructor
{
	prev=p;
	prev->next=this;
	next=n;
	next->prev=this;
	item=i;
}

CListItem::~CListItem()//Destructor
{
	//Does nothing at this point
}

CLinkList::CLinklist()//Basic initialiser/constructor
{
	//The main constructor
	first=null;
	last=null;
	
}