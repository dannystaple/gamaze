/* ***************************************** *\
 * CLinkList.h                               *
 * ----------------------------------------- *
 * Author : Daniel Staple					 *
 * Date :29-10-1998							 *
 * My own standard defs for a link list      *
 * it is generic.							 *
\* ***************************************** */

#ifndef CLINKLIST_H
#define LINKLIST_H

class CListItem {
	friend class CLinkList;
protected:
	CListItem * prev;//The previous item
	CListItem * next;//The next item
	void * Item;//The actual structure listed
public:
	CListItem(CListItem * p, CListItem * n, void * i);//Default constructor
	~CListItem();//Destructor
}

class CLinkList {
protected:
	CListItem * first;//The next link
	CLinkItem * last;//The last link
	int NItems;//The number of items 
	CListItem * Current;//The current item pointer
public:
    CLinkList();//Constructor
	~CLinkList();//Destructor
	int appendItem(void * item);//Adds item to end of list-
	//will return -1 for error or position of item.
	int insertItem(void * item, int pos);//Inserts item at pos
	//returns 0 if ok or -1
	void * getItem(int pos);//Returns item at pos
	void * getItem();//Gets item at current pos
	int removeItem(int pos);//Removes item at pos
	//returns 0 if OK or -1
	void goFirst();//Goes to first item in list
	void goPrev();//Goes to previous item in list
	void goNext();//Goes to next item in list
	void goLast();//Goes to the last item in the list
}

#endif