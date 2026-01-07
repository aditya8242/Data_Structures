#include<iostream>
#include<string>
using namespace std;

template <typename T>
struct node
{
	T data;
	struct node<T> *next;
};

template <class T>
class SinglyLL
{
	private:	// IMPORTANT
		struct node<T>* first;
		int iCount;

	public:
		SinglyLL();
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
SinglyLL<T>::SinglyLL()
{
	cout<<"Object of SinglyLL gets created.\n";
	this->first = NULL;
	this->iCount = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
	struct node<T>* newn = NULL;
	
	newn = new struct node<T>;

	newn->data = no;
	newn->next = NULL;

	newn->next = this->first;		// code reduction
	this->first = newn;			// not optimization

	this->iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
	node<T>* newn = NULL;
	node<T>* temp = NULL;
	
	newn = new node<T>;

	newn->data = no;
	newn->next = NULL;

	if(this->iCount == 0)	// updated
	{
		this->first = newn;
	}
	else
	{
		temp = this->first;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newn;
	}

	this->iCount++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
	node<T>* temp = NULL;

	if(this->first == NULL)
	{
		return;
	}
	else if(this->first->next == NULL)	// this->iCount == 1
	{
		delete this->first;
		this->first = NULL;
	}
	else
	{
		temp = this->first;

		this->first = this->first->next;
		delete temp;
	}

	this->iCount--;	// important
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
	node<T>* temp = NULL;

	if(this->first == NULL)
	{
		return;
	}
	else if(this->first->next == NULL)	// iCount == 1
	{
		delete this->first;
		this->first = NULL;
	}
	else
	{
		temp = this->first;

		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}

		delete temp->next;
		temp->next = NULL;
	}

	this->iCount--;	// important
}

template <class T>
void SinglyLL<T>::Display()
{
	node<T>* temp = NULL;
	int iCnt = 0;

	temp = this->first;

	// updated
	for(iCnt = 1; iCnt <= this->iCount; iCnt++)	// 3
	{
		cout << "| " << temp->data << " |->";
		temp = temp->next;	// can put it in for 3
	}

	cout << "NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
	return this->iCount;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int pos)
{
	node<T>* newn = NULL;
	node<T>* temp = NULL;

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
		newn = new node<T>;
		newn->data = no;
		newn->next = NULL;

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
void SinglyLL<T>::DeleteAtPos(int pos)
{
	node<T>* temp = NULL;
	node<T>* target = NULL;

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
		
		delete target;

		this->iCount--;	// important
	}
}

int main()
{
	SinglyLL<int> obj;
	int iRet = 0;

	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);

	obj.Display();

	iRet = obj.Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	obj.InsertLast(101);
	obj.InsertLast(111);
	obj.InsertLast(121);

	obj.Display();

	iRet = obj.Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	obj.DeleteFirst();

	obj.Display();

	iRet = obj.Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	obj.DeleteLast();

	obj.Display();

	iRet = obj.Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	obj.InsertAtPos(105, 4);

	obj.Display();

	iRet = obj.Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	obj.DeleteAtPos(4);

	obj.Display();

	iRet = obj.Count();

	cout<<"Number of nodes are "<<iRet<<"\n";

	return 0;
}