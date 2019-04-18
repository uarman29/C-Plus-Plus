#ifndef __UDDIN__A__HW3__CPP__
#define __UDDIN__A__HW3__CPP__
#include "Uddin_A_HW3.h"


template <class Item>
gNode<Item>::gNode(const Item &initVertex,const unsigned int& initWeight,gNode<Item>* initLink)
{
	vertex = initVertex;
	weight = initWeight;
	link = initLink;
}

template <class Item>
void gNode<Item>::setVertex(const Item &newVertex)
{
	vertex = newVertex;
}

template <class Item>
void gNode<Item>::setWeight(const unsigned int &newWeight)
{
	weight = newWeight;
}

template <class Item>
void gNode<Item>::setLink(gNode<Item>* newLink)
{
	link = newLink;
}

template <class Item>
Item gNode<Item>::getVertex() const
{
	return vertex;
}

template <class Item>
unsigned int gNode<Item>::getWeight() const
{
	return weight;
}

template <class Item>
const gNode<Item>* gNode<Item>::getLink()const
{
	return link;
}

template <class Item>
gNode<Item>* gNode<Item>::getLink()
{
	return link;
}

template <class Item>
void gNode<Item>::print()
{
	cout<<vertex<<"\n";
}

template <class Item>
void insertHead(gNode<Item>* &headPtr,const Item &newVertex,const unsigned int& nWeight)
{
	headPtr  = new gNode<Item>(newVertex,nWeight,headPtr);
}

template <class Item>
void removeHead(gNode<Item>* &headPtr)
{
	if(headPtr==NULL)
		return;

	gNode<Item>* headCopy = headPtr;
	headPtr = (*headPtr).getLink();
	delete headCopy;
}

template <class Item>
void insertTail(gNode<Item>* &headPtr,const Item &newVertex,const unsigned int& nWeight)
{
	if(headPtr==NULL)
	{
		insertHead(headPtr,newVertex,nWeight);
		return;
	}

	gNode<Item>* curr = headPtr;
	while((*curr).getLink()!=NULL)
	{
		curr = (*curr).getLink();
	}
	(*curr).setLink(new gNode<Item>(newVertex,nWeight,NULL));
}

template <class Item>
void removeTail(gNode<Item>* &headPtr)
{
	if(headPtr==NULL)
		return;

	gNode<Item>* curr = headPtr;
	gNode<Item>* prev;
	while((*curr).getLink()!=NULL)
	{
		prev = curr;
		curr = (*curr).getLink();
	}

	if(curr==headPtr)
	{
		removeHead(headPtr);
		return;
	}

	(*prev).setLink(NULL);
	delete curr;
}

template <class Item>
size_t length(gNode<Item>* headPtr)
{
	size_t count = 0;
	gNode<Item>* curr = headPtr;
	while(curr!=NULL)
	{
		curr = (*curr).getLink();
		count++;
	}
	return count;
}

template <class Item>
void clearList(gNode<Item>* &headPtr)
{
	while(headPtr!=NULL)
		removeHead(headPtr);
}

template <class Item>
void print(gNode<Item>* headPtr)
{
	gNode<Item>* curr = headPtr;
	while(curr!=NULL)
	{
		cout<<"("<<(*curr).getVertex()<<","<<(*curr).getWeight()<<") -> ";
		curr = (*curr).getLink();
	}
	cout<<"NULL\n";
}

template <class Item>
//position<=size
void insert(gNode<Item>* &headPtr,const size_t &position,const Item &newVertex,const unsigned int& nWeight)
{
	assert(position>=0);
	if(position==0)
	{
		insertHead(headPtr,newVertex,nWeight);
		return;
	}

	size_t count = 0;
	gNode<Item>* curr = headPtr;
	while(count<position-1)
	{
		curr = (*curr).getLink();
		count++;
	}
	(*curr).setLink(new gNode<Item>(newVertex,(*curr).getLink()));
}

template <class Item>
void insert(gNode<Item>* &headPtr,const size_t &position,gNode<Item>* &entrygNode)
{
	assert(position>=0);
	if(position==0)
	{
		insertHead(headPtr,(*entrygNode).getVertex());
		return;
	}

	size_t count = 0;
	gNode<Item>* curr = headPtr;
	while(count<position-1)
	{
		curr = (*curr).getLink();
		count++;
	}
	(*entrygNode).setLink((*curr).getLink());
	(*curr).setLink(entrygNode);
}

template <class Item>
//position<size
void remove(gNode<Item>* &headPtr,const size_t &position)
{
	assert(position>=0);
	if(position==0)
	{
		removeHead(headPtr);
		return;
	}

	size_t count = 0;
	gNode<Item>* curr = (*headPtr).getLink();
	gNode<Item>* prev = headPtr;
	while(count<position-1)
	{
		prev = curr;
		curr = (*curr).getLink();
		count++;
	}
	(*prev).setLink((*curr).getLink());
	delete curr;
}

template <class Item>
//position<size
gNode<Item>* locate(gNode<Item>* headPtr,const size_t &position)
{
	assert(position>=0);
	size_t count = 0;
	gNode<Item>* curr = headPtr;
	while(count<position)
	{
		curr = (*curr).getLink();
		count++;
	}
	return curr;
}

template <class Item>
gNode<Item>* search(gNode<Item>* headPtr,const Item &target)
{
	gNode<Item>* curr = headPtr;
	while(curr!=NULL)
	{
		if((*curr).getVertex()==target)
		{
			return curr;
		}
		curr = (*curr).getLink();
	}
	return NULL;
}

template <class Item>
int searchIndex(gNode<Item>* headPtr,const Item &target)
{
	gNode<Item>* curr = headPtr;
	int count = 0;
	while(curr!=NULL)
	{
		if((*curr).getVertex()==target)
		{
			return count;
		}
		curr = (*curr).getLink();
		count++;
	}
	return -1;
}

template <class Item>
bool checkCycle(gNode<Item>* headPtr)
{
	gNode<Item>* curr = headPtr;
	gNode<Item>* prev = headPtr;

	while(curr!=NULL&&prev!=NULL)
	{
		prev = (*prev).getLink();
		curr = (*(*curr).getLink()).getLink();
		if(prev==curr)
		{
			return true;
		}
	}
	return false;
}

template <class Item>
//position<size-1
void swapNext(gNode<Item>* &headPtr,const size_t &position)
{
	assert(position>=0);
	gNode<Item>* curr = headPtr;
	if(position==0)
	{
		headPtr = (*curr).getLink();
		(*curr).setLink((*headPtr).getLink());
		(*headPtr).setLink(curr);
		return;
	}

	gNode<Item>* prev;
	size_t count = 0;
	while(count<position)
	{
		prev = curr;
		curr = (*curr).getLink();
		count++;
	}
	(*prev).setLink((*curr).getLink());//Previous points to what current was originally pointing to
	(*curr).setLink((*(*prev).getLink()).getLink());//Curr points to what curr+1 points to
	(*(*prev).getLink()).setLink(curr);//Curr+1 points to curr
}

template <class Item>
//J>I J<size
void swap(gNode<Item>* &headPtr,const size_t &i,const size_t &j)
{
	assert(i>=0);
	assert(i<j);

	if(j-i==1)
	{
		swapNext(headPtr,i);
		return;
	}

	gNode<Item>* currI = headPtr;
	gNode<Item>* nextI = (*currI).getLink();
	gNode<Item>* prevI;
	gNode<Item>* currJ = headPtr;
	gNode<Item>* prevJ;
	size_t count = 0;
	while(count<i)
	{
		prevI = currI;
		currI = (*currI).getLink();
		nextI = (*currI).getLink();
		prevJ = currJ;
		currJ = (*currJ).getLink();
		count++;
	}
	while(count<j)
	{
		prevJ = currJ;
		currJ = (*currJ).getLink();
		count++;
	}

	if(i==0)
		headPtr = currJ;
	else
		(*prevI).setLink(currJ);

	(*prevJ).setLink(currI);
	(*currI).setLink((*currJ).getLink());
	(*currJ).setLink(nextI);
}

template <class Item>
void reverse(gNode<Item>* &headPtr)
{
	gNode<Item>* prev = NULL;
	gNode<Item>* curr = headPtr;
	gNode<Item>* next = (*headPtr).getLink();
	while(curr!=NULL)
	{
		(*curr).setLink(prev);
		prev = curr;
		curr = next;
		if(next!=NULL)
			next = (*next).getLink();
	}
	headPtr=prev;
}


#endif