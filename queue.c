#include <stdio.h>

#define MAX 5

void insert();
void delete();
void display();

int queue[MAX];
int rear = -1;
int front = -1;

int main()
{
	int choice;
	while(1)
	{
		printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: insert(); break;
			case 2: delete(); break;
			case 3: display(); break;
			case 4: return 0;
			default: printf("Invalid input\n");
		}
	}
}

void insert()
{
	int item;
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1)
			front = 0;
		printf("Insert the element in queue : ");
		scanf("%d", &item);
		rear++;
		queue[rear] = item;
	}
}

void delete()
{
	if (front == - 1) {
		printf("Queue Underflow\n");
	} else {
		printf("Element deleted from queue is: %d\n", queue[front]);
		front++;
		if(front > rear) {
			front = -1;
			rear = -1;
		}
	}
}
 
void display()
{
	int i;
	if (front == -1)
		printf("Queue is empty\n");
	else {
		printf("Queue is:\n");
		for (i = front; i <= rear; i++)
			printf("%d ", queue[i]);
		printf("\n");
	}
}
