#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#pragma pack(1)

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first, PPNODE last, int no)
{
	// node creation
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	
	// node initialization
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	// if LL is empty
	if(NULL == *first && NULL == *last)
	{
		*first = newn;
		*last = newn;
	}
	else
	{
		newn->next = *first;
		(*first)->prev = newn;
		*first = newn;
	}

	(*last)->next = *first;	// important to maintain circular nature
	(*first)->prev = *last;
}

void InsertLast(PPNODE first, PPNODE last, int no)
{
	// node creation
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	
	// node initialization
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	// if LL is empty
	if(NULL == *first && NULL == *last)
	{
		*first = newn;
		*last = newn;
	}
	else
	{
		(*last)->next = newn;
		newn->prev = *last;
		*last = newn;
	}

	(*last)->next = *first;
	(*first)->prev = *last;
}

void DeleteFirst(PPNODE first, PPNODE last)
{
	if(NULL == *first && NULL == *last)	// no elements
	{
		return;
	}
	else if(*first == *last)	// single element
	{
		free(*first);

		*first = NULL;
		*last = NULL;
	}
	else    // if more than one elements
	{
		*first = (*first)->next;
		free((*first)->prev);

		(*last)->next = *first;
		(*first)->prev = *last;
	}
}

void DeleteLast(PPNODE first, PPNODE last)
{
	if(NULL == *first && NULL == *last)
	{
		return;
	}
	else if(*first == *last)
	{
		free(*first);

		*first = NULL;
		*last = NULL;
	}
	else
	{
		*last = (*last)->prev;
		free((*last)->next);

		(*last)->next = *first;
		(*first)->prev = *last;
	}
}

void Display(PNODE first, PNODE last)
{
	printf("<=>");
	do
	{
		printf("| %d |<=>", first->data);
		first = first->next;
	}while(first != last->next);
}

int Count(PNODE first, PNODE last)
{
	int iCount = 0;
	do
	{
		iCount++;
		first = first->next;
	}while(first != last->next);

	return iCount;
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
	int iSize = Count(*first, *last);

	PNODE temp = NULL;
	PNODE newn = NULL;

	int iCnt = 0;

	if(pos < 1 || pos > iSize+1)
	{
		printf("Invalid position.\n");
		return;
	}

	if(pos == 1)
	{
		InsertFirst(first, last, no);
	}
	else if(pos == iSize+1)
	{
		InsertLast(first, last, no);
	}
	else
	{
		temp = *first;

		newn = (PNODE)malloc(sizeof(NODE));
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		for(iCnt = 1; iCnt < pos - 1; iCnt++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		newn->next->prev = newn;

		temp->next = newn;
		newn->prev = temp; 	
	}

}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
	int iSize = 0;
	
	iSize = Count(*first, *last);

	PNODE temp = NULL;
	PNODE target = NULL;

	int iCnt = 0;

	if(pos < 1 || pos > iSize)
	{
		printf("Invalid position.\n");
		return;
	}

	if(pos == 1)
	{
		DeleteFirst(first, last);
	}
	else if(pos == iSize)
	{
		DeleteLast(first, last);
	}
	else
	{
		temp = *first;

		for(iCnt = 1; iCnt < pos - 1; iCnt++)
		{
			temp = temp->next;
		}

		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
	}	
}

int main()
{
	PNODE head = NULL;
	PNODE tail = NULL;

	int iChoice = 0;
	int iData = 0;
	int iRet = 0;
	int iFlag = 0;
	int iPos = 0;

	printf("%50s=====", "=====Doubly Circular Linked List");
	while(true)
	{
		printf("\n\nOperations:\n1.Insert First\n2.Insert Last\n3.Insert at position\n");
		printf("4.Delete First\n5.Delete Last\n6.Delete at position\n");
		printf("7.Count\n8.Display\n9.Exit\n");

		printf("Enter your choice: ");
		iFlag = scanf("%d", &iChoice);	// scanf returns 1 if successful

		if(iFlag == 1)
		{
			switch(iChoice)
			{
				case 1:
					printf("\nEnter data: ");
					scanf("%d", &iData);
					InsertFirst(&head, &tail, iData);
					printf("\nData inserted.");
					break;

				case 2:
					printf("\nEnter data: ");
					scanf("%d", &iData);
					InsertLast(&head, &tail, iData);
					printf("\nData inserted.");
					break;
				
				case 3:
					printf("\nEnter data: ");
					scanf("%d", &iData);
					printf("\nEnter position: ");
					scanf("%d", &iPos);
					InsertAtPos(&head, &tail, iData, iPos);
					printf("\nData inserted.");
					break;
				
				case 4:
					if(NULL == head && NULL == tail)
					{
						printf("Linked List is empty.\n");
					}
					else
					{
						DeleteFirst(&head, &tail);
						printf("Element deleted!");
					}
					break;

				case 5:
					if(NULL == head && NULL == tail)
					{
						printf("Linked List is empty.\n");
					}
					else
					{
						DeleteLast(&head, &tail);
						printf("Element deleted!");
					}
					break;

				case 6:
					if(NULL == head && NULL == tail)
					{
						printf("Linked List is empty!\n");
					}
					else
					{
						printf("Enter position: ");
						scanf("%d",&iPos);
						DeleteAtPos(&head, &tail, iPos);
						printf("Element deleted!\n");
					}
					break;

				case 7:
					iRet = Count(head, tail);
					if(iRet == 0)
					{
						printf("Linked list is empty\n");
					}
					else
					{
						printf("Number of nodes are %d", iRet);
					}
					break;
					
				case 8:
					if(NULL == head && NULL == tail)
					{
						printf("Linked is empty!\n");
					}
					else
					{
						Display(head, tail);
					}
					break;

				case 9:
					printf("Exiting program...\n");
					exit(0);
				
				default:
					printf("Enter valid choice!\n");
					break;
			}
		}
		else
		{
			printf("Invalid input!\nPlease enter integer.");

			while(getchar() != '\n');	// getchar() takes other input
		}								// and clears the input
	}

	printf("\n");

	return 0;
}