#include<iostream>
using namespace std;

template <class T>
class DoublyCLLnode
{
	public:
		T data;
		DoublyCLLnode *next;
		DoublyCLLnode *prev;

		DoublyCLLnode(T no)
		{
			this->data = no;
			this->next = NULL;
			this->prev = NULL;
		}
};

template <class T>
class DoublyCLL
{
	private:
		DoublyCLLnode<T> * first;
		DoublyCLLnode<T> * last;
		int iCount;

	public:
		DoublyCLL();
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
DoublyCLL<T>::DoublyCLL()
{
	cout<<"Object of DoublyCLL gets created.\n";
	this->first = NULL;
	this->last = NULL;
	this->iCount = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
	DoublyCLLnode<T> * newn = NULL;
	
	newn = new DoublyCLLnode<T>(no);

	if(this->first == NULL) // can use iCount
	{
		this->first = newn;
		this->last = newn;
	}
	else
	{
		newn->next = this->first;
		this->first->prev = newn;
		this->first = newn;
	}

	this->last->next = first;
	this->first->prev = last;

	this->iCount++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
	DoublyCLLnode<T> * newn = NULL;
	
	newn = new DoublyCLLnode<T>(no);

	if(this->iCount == 0)
	{
		this->first = newn;
		this->last = newn;
	}
	else
	{
		this->last->next = newn;
		newn->prev = last;
		last = newn;
	}

	this->last->next = first;
	this->first->prev = last;

	this->iCount++;
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
	DoublyCLLnode<T> * temp = NULL;

	if(this->first == NULL && this->last == NULL)
	{
		return;
	}
	else if(this->iCount == 1)
	{
		delete this->first;

		this->first = NULL;
		this->last = NULL;
	}
	else
	{
		this->first = this->first->next;
		delete this->first->prev;

		this->last->next = first;
		this->first->prev = last;
	}

	this->iCount--;	// important
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
	DoublyCLLnode<T> * temp = NULL;

	if(this->first == NULL && this->last == NULL)
	{
		return;
	}
	else if(this->iCount == 1)
	{
		delete this->first;

		this->first = NULL;
		this->last = NULL;
	}
	else
	{
		this->last = this->last->prev;
		delete this->last->next;

		this->last->next = first;
		this->first->prev = last;
	}

	this->iCount--;	// important
}

template <class T>
void DoublyCLL<T>::Display()
{
	DoublyCLLnode<T> * temp = NULL;

	temp = this->first;

	do
	{
		cout << "| " << temp->data << " |<=>";
		temp = temp->next;
	}while(temp != last->next);
}

template <class T>
int DoublyCLL<T>::Count()
{
	return this->iCount;
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
	DoublyCLLnode<T> * newn = NULL;
	DoublyCLLnode<T> * temp = NULL;

	int iCnt = 0;

	if(pos < 0 || pos > this->iCount+1)
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
		newn = new DoublyCLLnode<T>(no);

		temp = this->first;

		for(iCnt = 1; iCnt < pos - 1; iCnt++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next->prev = newn;

		temp->next = newn;
		newn->prev = temp;

		this->iCount++;
	}
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
	DoublyCLLnode<T> * temp = NULL;
	DoublyCLLnode<T> * target = NULL;

	int iCnt = 0;

	if(pos < 0 || pos > this->iCount)
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
		temp->next->prev = temp;
		delete target;

		this->iCount--;	// important
	}
}

int main()
{
	DoublyCLL<int> *obj = new DoublyCLL<int>();
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