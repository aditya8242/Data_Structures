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

void InsertFirst(PPNODE first, int no)
{
	// node creation
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	
	// node initialization
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	// if LL is empty
	if(NULL == *first)
	{
		*first = newn;
	}
	else
	{
		newn->next = *first;
		(*first)->prev = newn;
		*first = newn;
	}
}

void InsertLast(PPNODE first, int no)
{
	// node creation
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	
	// node initialization
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	// temporary pointer to not mess with head
	PNODE temp = NULL;

	// if LL is empty
	if(NULL == *first)
	{
		*first = newn;
	}
	else
	{
		temp = *first;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newn;
		newn->prev = temp;
	}
}

void DeleteFirst(PPNODE first)
{
	// temporary pointer
	PNODE temp = NULL;

	if(NULL == *first)	// no elements
	{
		return;
	}
	else if((*first)->next == NULL)	// single element
	{
		free(*first);
		*first = NULL;
	}
	else    // if more than one elements
	{
		temp = *first;

		*first = (*first)->next;
		free(temp);
		(*first)->prev = NULL;
	}
}

void DeleteLast(PPNODE first)
{
	// temporary pointer
	PNODE temp = NULL;

	if(NULL == *first)
	{
		return;
	}
	else if((*first)->next == NULL)
	{
		free(*first);
		*first = NULL;
	}
	else
	{
		temp = *first;

		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}

		free(temp->next);
		temp->next = NULL;
	}
}

void Display(PNODE first)
{
	printf("Linked Listed elements:\n");
	printf("NULL<=>");
	while(first != NULL)
	{
		printf("| %d |<=>", first->data);
		first = first->next;
	}

	printf("NULL\n");
}

int Count(PNODE first)
{
	int iCount = 0;
	while(first != NULL)
	{
		iCount++;
		first = first->next;
	}

	return iCount;
}

void InsertAtPos(PPNODE first, int no, int pos)
{
	int iSize = Count(*first);

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
		InsertFirst(first, no);
	}
	else if(pos == iSize+1)
	{
		InsertLast(first, no);
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
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
	}

}

void DeleteAtPos(PPNODE first, int pos)
{
	int iSize = 0;
	
	iSize = Count(*first);

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
		DeleteFirst(first);
	}
	else if(pos == iSize)
	{
		DeleteLast(first);
	}
	else
	{
		temp = *first;

		for(iCnt = 1; iCnt < pos - 1; iCnt++)
		{
			temp = temp->next;
		}

		target = temp->next;

		temp->next = target->next;
		temp->next->prev = temp;
		free(target);
	}	
}

int main()
{
	PNODE head = NULL;
	int iChoice = 0;
	int iData = 0;
	int iRet = 0;
	int iFlag = 0;
	int iPos = 0;

	printf("%50s=====", "=====Doubly Linear Linked List");
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
					InsertFirst(&head, iData);
					printf("\nData inserted.");
					break;

				case 2:
					printf("\nEnter data: ");
					scanf("%d", &iData);
					InsertLast(&head, iData);
					printf("\nData inserted.");
					break;
				
				case 3:
					printf("\nEnter data: ");
					scanf("%d", &iData);
					printf("\nEnter position: ");
					scanf("%d", &iPos);
					InsertAtPos(&head, iData, iPos);
					printf("\nData inserted.");
					break;
				
				case 4:
					if(NULL == head)
					{
						printf("Linked List is empty.\n");
					}
					else
					{
						DeleteFirst(&head);
						printf("Element deleted!");
					}
					break;

				case 5:
					if(NULL == head)
					{
						printf("Linked List is empty.\n");
					}
					else
					{
						DeleteLast(&head);
						printf("Element deleted!");
					}
					break;

				case 6:
					if(NULL == head)
					{
						printf("Linked List is empty!\n");
					}
					else
					{
						printf("Enter position: ");
						scanf("%d",&iPos);
						DeleteAtPos(&head, iPos);
						printf("Element deleted!\n");
					}
					break;

				case 7:
					iRet = Count(head);
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
					if(NULL == head)
					{
						printf("Linked is empty!\n");
					}
					else
					{
						Display(head);
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