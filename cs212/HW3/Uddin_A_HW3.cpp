#ifndef __UDDIN__A__HW3__CPP__
#define __UDDIN__A__HW3__CPP__
#include "Uddin_A_HW3.h"


Node::Node(const nodeDataType &initData,Node* initLink)
{
	data = initData;
	link = initLink;
}

void Node::setData(const nodeDataType &newData)
{
	data = newData;
}

void Node::setLink(Node* newLink)
{
	link = newLink;
}

nodeDataType Node::getData() const
{
	return data;
}

const Node* Node::getLink()const
{
	return link;
}

Node* Node::getLink()
{
	return link;
}

void Node::print()
{
	cout<<data<<"\n";
}

void insertHead(Node* &headPtr,const nodeDataType &newData)
{
	headPtr  = new Node(newData,headPtr);
}

void removeHead(Node* &headPtr)
{
	if(headPtr==NULL)
		return;

	Node* headCopy = headPtr;
	headPtr = (*headPtr).getLink();
	delete headCopy;
}

void insertTail(Node* &headPtr,const nodeDataType &newData)
{
	if(headPtr==NULL)
	{
		insertHead(headPtr,newData);
		return;
	}

	Node* curr = headPtr;
	while((*curr).getLink()!=NULL)
	{
		curr = (*curr).getLink();
	}
	(*curr).setLink(new Node(newData,NULL));
}

void removeTail(Node* &headPtr)
{
	if(headPtr==NULL)
		return;

	Node* curr = headPtr;
	Node* prev;
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

size_t size(Node* headPtr)
{
	size_t count = 0;
	Node* curr = headPtr;
	while(curr!=NULL)
	{
		curr = (*curr).getLink();
		count++;
	}
	return count;
}

void clearList(Node* &headPtr)
{
	while(headPtr!=NULL)
		removeHead(headPtr);
}

void print(Node* headPtr)
{
	Node* curr = headPtr;
	while(curr!=NULL)
	{
		cout<<(*curr).getData()<<",";
		curr = (*curr).getLink();
	}
	cout<<"\n";
}

//position<=size
void insert(Node* &headPtr,const size_t &position,const nodeDataType &newData)
{
	assert(position>=0);
	if(position==0)
	{
		insertHead(headPtr,newData);
		return;
	}

	size_t count = 0;
	Node* curr = headPtr;
	while(count<position-1)
	{
		curr = (*curr).getLink();
		count++;
	}
	(*curr).setLink(new Node(newData,(*curr).getLink()));
}

void insert(Node* &headPtr,const size_t &position,Node* &entryNode)
{
	assert(position>=0);
	if(position==0)
	{
		insertHead(headPtr,(*entryNode).getData());
		return;
	}

	size_t count = 0;
	Node* curr = headPtr;
	while(count<position-1)
	{
		curr = (*curr).getLink();
		count++;
	}
	(*entryNode).setLink((*curr).getLink());
	(*curr).setLink(entryNode);
}

//position<size
void remove(Node* &headPtr,const size_t &position)
{
	assert(position>=0);
	if(position==0)
	{
		removeHead(headPtr);
		return;
	}

	size_t count = 0;
	Node* curr = (*headPtr).getLink();
	Node* prev = headPtr;
	while(count<position-1)
	{
		prev = curr;
		curr = (*curr).getLink();
		count++;
	}
	(*prev).setLink((*curr).getLink());
	delete curr;
}

//position<size
Node* locate(Node* headPtr,const size_t &position)
{
	assert(position>=0);
	size_t count = 0;
	Node* curr = headPtr;
	while(count<position)
	{
		curr = (*curr).getLink();
		count++;
	}
	return curr;
}

Node* search(Node* headPtr,const nodeDataType &target)
{
	Node* curr = headPtr;
	while(curr!=NULL)
	{
		if((*curr).getData()==target)
		{
			return curr;
		}
		curr = (*curr).getLink();
	}
	return NULL;
}

bool checkCycle(Node* headPtr)
{
	Node* curr = headPtr;
	Node* prev = headPtr;

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
//position<size-1
void swapNext(Node* &headPtr,const size_t &position)
{
	assert(position>=0);
	Node* curr = headPtr;
	if(position==0)
	{
		headPtr = (*curr).getLink();
		(*curr).setLink((*headPtr).getLink());
		(*headPtr).setLink(curr);
		return;
	}

	Node* prev;
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

//J>I J<size
void swap(Node* &headPtr,const size_t &i,const size_t &j)
{
	assert(i>=0);
	assert(i<j);

	if(j-i==1)
	{
		swapNext(headPtr,i);
		return;
	}

	Node* currI = headPtr;
	Node* nextI = (*currI).getLink();
	Node* prevI;
	Node* currJ = headPtr;
	Node* prevJ;
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

void reverse(Node* &headPtr)
{
	Node* prev = NULL;
	Node* curr = headPtr;
	Node* next = (*headPtr).getLink();
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