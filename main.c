#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct queueNode {
	char data;
	struct queueNode* nextPtr;
};

typedef struct queueNode QUEUENODE;
typedef  QUEUENODE *QUEUENODEPTR1;

void enqueue(QUEUENODEPTR1 *headPtr, QUEUENODEPTR1 * tailPtr, char);


char dequeue(QUEUENODEPTR1 *headPtr, QUEUENODEPTR1 * tailPtr);
void enqueue(QUEUENODEPTR1 *headPtr, QUEUENODEPTR1 * tailPtr, char);
void printQueue(QUEUENODEPTR1);
void instructions(void);


int main()
{
	setlocale(LC_ALL, "Russian");
	printf("Hello\n");
	QUEUENODEPTR1 headPtr = NULL, tailPtr = NULL;			/*Изначально в наших структурах ничего нет, поэтому занулем указатель на начало первую структуру*/
	int a;
	char item;								
	instructions();							
	printf("? ");
	scanf("%d", &a);
	while (a != 3) {
		switch (a) {
		case 1:
			printf("Enter a character: ");
			scanf("\n%c", &item);
			enqueue(&headPtr, &tailPtr, item);
			printQueue(headPtr);
			break;


		case 2:
			if (!(headPtr == NULL)) {
				item = dequeue(&headPtr, &tailPtr);
				printf("%c has been dequeued.\n", item);
			}
			printQueue(headPtr);
				break;

		default:
			printf("Invalid a. \n\n");
			instructions();
			break;
			

		
		}
		printf("? ");
		scanf("%d", &a);
	}
printf("End of run.\n");
return 0;
}

void *QUEUENODEPTR;

void enqueue(QUEUENODEPTR1 *headPtr, QUEUENODEPTR1 * tailPtr, char value)
{
	QUEUENODEPTR1 newPtr;
	
	newPtr = malloc(sizeof(QUEUENODE));

	if (newPtr != NULL)						/*Условие не сработает только если malloc не сработал*/
	{
		newPtr->data = value;
		newPtr->nextPtr = NULL;				/*Создаем  и заполняем учейку памяти, в которой лежит число*/
		
		if (*headPtr == NULL)
			*headPtr = newPtr;				/*Срабатывает когда список пустой, и в голове ничего нет*/
		else
			(*tailPtr)->nextPtr = newPtr;	/*Сначала прописываем связь(подсоединяем кусок памяти к нашему хвосту)*/
		*tailPtr = newPtr;					/*Затем перемещаем наш укказатель нашего хвоста на один вправо, таким образом tailPtr->nextPtr указывает на NULL */
				
	}
	else
		printf("%c not inserted. No memory available.\n", value);
	
}

void instructions(void)
{
	printf("Enter a: \n"
		"1 to add an item to the queue. \n"
		"2 to remove an item from the queue. \n"
		"3 to end. \n");
}



char dequeue(QUEUENODEPTR1 *headPtr, QUEUENODEPTR1 *tailPtr)
{
	char value;
	QUEUENODEPTR1  tempPtr;
										/*Запоминаем символ*/
	value = (*headPtr)->data;
	tempPtr = *headPtr;					/*указатель на первый элемент, чтобы после смещение не потерять доступ к нему*/
	*headPtr = (*headPtr)->nextPtr;		/*Сдвиг указателя*/
	if (*headPtr == NULL)				/*Срабатывает если в списке был один элемент*/
		*tailPtr = NULL;
	free(tempPtr);
	return value;
}


void printQueue(QUEUENODEPTR1 currentPtr)
{
	if (currentPtr == NULL)
		printf("Queue is empty.\n\n");
	else {
		printf("The queue is: \n");
		while (currentPtr != NULL) {
			printf("%c-> ", currentPtr->data);		/*Печатаем ячейки памяти подряд*/
			currentPtr = currentPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}