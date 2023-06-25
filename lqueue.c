#include <stdio.h> 
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
	struct node *ptr;
	ptr = (struct node *) malloc(sizeof(struct node));
	ptr->data = value;
	ptr->next = NULL;
	if (front == NULL && rear == NULL) {
		front = rear = ptr;
	} else {
		rear -> next = ptr;
		rear = ptr;
	}
	printf("Node is Inserted\n");
}

void dequeue() {
	if (front == NULL) {
		printf("Queue underflow\n");
	} else {
		if(front == rear)
			rear = NULL;
		struct node *temp = front;
		int temp_data = front->data;
		front = front->next;
		free(temp);
		printf("Popped element is %d\n", temp_data);
	}
}

void display() {
	struct node *temp;
	if (front == NULL) {
		printf("Queue is Empty\n");
	} else {
		printf("The queue is\n");
		temp = front;
		while (temp){
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {
	int choice, value;
	while (choice != 4) {
		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("Enter the value to insert: ");
				scanf("%d", &value);
				enqueue(value);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
}
