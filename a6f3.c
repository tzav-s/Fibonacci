

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
/*  Λειτουργία:  Δημιουργεί μια κενή ουρά.
    Επιστρέφει:  Κενή ουρά
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
	Queue->Count=0;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, False διαφορετικά
*/
{
	return (Queue.Count == 0);
}

boolean FullQ(QueueType Queue)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Ελέγχει αν η ουρά είναι γεμάτη.
   Επιστρέφει: True αν η ουρά είναι γεμάτη, False διαφορετικά
*/
{
	return (Queue.Count==QueueLimit);
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την εμπρός άκρη της ουράς
                αν η ουρά δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα κενής ουρά αν η ουρά είναι κενή
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
/* Δέχεται:    Μια ουρά Queue και ένα στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στην ουρά Queue
                αν η ουρά δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη ουρά.
   Έξοδος:     Μήνυμα γεμάτης ουράς αν η ουρά είναι γεμάτη
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


