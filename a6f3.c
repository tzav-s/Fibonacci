

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define QueueLimit 10

typedef int QueueElementType;
typedef enum{
    FALSE,TRUE
}boolean;

typedef struct{
int Front,Rear;
QueueElementType Element[QueueLimit];
int Count;
}QueueType;

void menu(int *choice);
void TraverseQ(QueueType Queue);
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);


int main()
{
    QueueType Queue;
    QueueElementType i;

    CreateQ(&Queue);

    printf("------------a------------\n");
    for(i=0;i<QueueLimit;i++){
        AddQ(&Queue,i);
    }
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);


    printf("------------b------------\n");
    AddQ(&Queue,3);
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("------------c------------\n");
    RemoveQ(&Queue,&Queue.Element[Queue.Front]);
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("------------d------------\n");
    AddQ(&Queue,7);
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("------------e------------\n");
    AddQ(&Queue,9);
    TraverseQ(Queue);
    printf("Front=%d Rear=%d Count=%d\n",Queue.Front,Queue.Rear,Queue.Count);

    printf("------------f------------\n");
    for(i=0;i<QueueLimit;i++)
    {
        RemoveQ(&Queue,&i);
        TraverseQ(Queue);
        printf("Removed item=%d Front=%d Rear=%d Count=%d\n",i,Queue.Front,Queue.Rear,Queue.Count);

    }

    system("PAUSE");
	return 0;
}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1 ---- DHMIOYRGIA OURAS\n");
    printf("2 ---- ADEIASMA THS OYRAS\n");
    printf("3 ---- ELEGXOS KENHS OYRAS\n");
    printf("4 ---  DIAGRAFH STOIXEIOY APO TH KORYFH THS OYRAS\n");
    printf("5 ---  PROS8HKH STOIXEIOY STO TELOS THS OYRAS\n");
    printf("6 ---- EMFANISH STOIXEIWN OURAS (BOH8HTHKH)\n");
    printf("7 ---- EXIT\n");
    printf("\nChoice: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}

void TraverseQ(QueueType Queue) {
	int current;
    current = Queue.Front;
	while (current != Queue.Count) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}



void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count=0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return (Queue.Count==QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
*/
{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
		Queue->Count=Queue->Count-1;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* �������:    ��� ���� Queue ��� ��� �������� Item.
   ����������: ��������� �� �������� Item ���� ���� Queue
                �� � ���� ��� ����� ������.
   ����������: ��� ������������� ����.
   ������:     ������ ������� ����� �� � ���� ����� ������
*/
{
	if(!FullQ(*Queue))
	{
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = (Queue ->Rear + 1) % QueueLimit;
        Queue->Count=Queue->Count+1;

	}
	else
		printf("Full Queue");
}


