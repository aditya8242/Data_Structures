#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
class SinglyCLLnode
{
	public:
		T data;
		SinglyCLLnode<T> *next;

		SinglyCLLnode(T no)
		{
			this->data = no;
			this->next = NULL;
		}
};

template <class T>
class SinglyCLL
{
	private:
		SinglyCLLnode<T> * first;
		SinglyCLLnode<T> * last;
		int iCount;

	public:
		SinglyCLL();
		void InsertFirst(T no);
		void InsertLast(T no);
		void DeleteFirst();
		void DeleteLast();
		void Display();
		int Count();
		void InsertAtPos(T no, int pos);
		void DeleteAtPos(int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
	cout<<"Object of SinglyCLL gets created.\n";
	this->first = NULL;
	this->last = NULL;
	this->iCount = 0;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
	SinglyCLLnode<T> * newn = NULL;
	
	newn = new SinglyCLLnode<T>(no);

	if(NULL == this->first && NULL == this->last)
	{
		this->first = newn;
		this->last = newn;
	}
	else
	{
		newn->next = this->first;
		first = newn;
	}

	this->last->next = first;

	this->iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
	SinglyCLLnode<T> * newn = NULL;
	SinglyCLLnode<T> * temp = NULL;
	
	newn = new SinglyCLLnode<T>(no);

	if(this->iCount == 0)
	{
		this->first = newn;
		this->last = newn;
	}
	else
	{
		this->last->next = newn;
		this->last = newn;
	}

	this->last->next = first;

	this->iCount++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
	SinglyCLLnode<T> * temp = NULL;

	if(this->first == NULL && this->last == NULL)
	{
		return;
	}
	else if(this->iCount == 1)	// this->iCount == 1
	{
		delete this->first;

		this->first = NULL;
		this->last = NULL;
	}
	else
	{
		temp = this->first;

		this->first = this->first->next;
		delete temp;
		
		this->last->next = first;
	}

	this->iCount--;	// important
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
	SinglyCLLnode<T> * temp = NULL;

	if(this->first == NULL && this->last == NULL)
	{
		return;
	}
	else if(iCount == 1)	// iCount == 1
	{
		delete this->first;

		this->first = NULL;
		this->last = NULL;
	}
	else
	{
		temp = this->first;

		while(temp->next != this->last)
		{
			temp = temp->next;
		}

		delete this->last;
		this->last = temp;

		this->last->next = first;
	}

	this->iCount--;	// important
}

template <class T>
void SinglyCLL<T>::Display()
{
	SinglyCLLnode<T> * temp = NULL;

	temp = this->first;

	do
	{
		cout << "| " << temp->data << " |->";
		temp = temp->next;
	}while(temp != this->last->next);
}

template <class T>
int SinglyCLL<T>::Count()
{
	return this->iCount;
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
	SinglyCLLnode<T> * newn = NULL;
	SinglyCLLnode<T> * temp = NULL;

	int iCnt = 0;

	if(pos < 1 || pos > this->iCount+1)
	{
		cout<<"Invalid position\n";
		return;
	}
	
	if(pos == 1)
	{
		this->InsertFirst(no);	// this before function
	}
	else if(pos == this->iCount+1)
	{
		this->InsertLast(no);
	}
	else
	{
		newn = new SinglyCLLnode<T>(no);

		temp = this->first;

		for(iCnt = 1; iCnt < pos - 1; iCnt++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next = newn;

		this->iCount++;
	}
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
	SinglyCLLnode<T> * temp = NULL;
	SinglyCLLnode<T> * target = NULL;

	int iCnt = 0;

	if(pos < 1 || pos > this->iCount)
	{
		cout<<"Invalid position";
		return;
	}

	if(pos == 1)
	{
		this->DeleteFirst();
	}
	else if(pos == this->iCount)
	{
		this->DeleteLast();
	}
	else
	{
		temp = this->first;


		for(iCnt = 1; iCnt < pos - 1; iCnt++)
		{
			temp = temp->next;
		}

		target = temp->next;
		
		temp->next = target->next;
		delete target;

		this->iCount--;	// important
	}
}

int main()
{
	SinglyCLL<int> * obj = new SinglyCLL<int>();
	int iRet = 0;

	obj->InsertFirst(51);
	obj->InsertFirst(21);
	obj->InsertFirst(11);

	obj->Display();

	iRet = obj->Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	obj->InsertLast(101);
	obj->InsertLast(111);
	obj->InsertLast(121);

	obj->Display();

	iRet = obj->Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	obj->DeleteFirst();

	obj->Display();

	iRet = obj->Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	obj->DeleteLast();

	obj->Display();

	iRet = obj->Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	obj->InsertAtPos(105, 4);

	obj->Display();

	iRet = obj->Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	obj->DeleteAtPos(4);

	obj->Display();

	iRet = obj->Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	return 0;
}