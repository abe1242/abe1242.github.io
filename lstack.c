#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node
{
	int val;
	struct node *next;
};

struct node *head;

int main ()  
{
	int choice = 0;
	while(choice != 4)  
	{  
		printf("\nChoose one from the below options...\n");  
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");  
		printf("\nEnter your choice: ");        
		scanf("%d", &choice);  
		switch(choice)  
		{  
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			case 4: printf("Exiting....\n"); break;
			default: printf("Invalid choice\n");
		}
	}  
}  

void push()  
{
	int val;  
	struct node *ptr = (struct node*)malloc(sizeof(struct node));   
	if(ptr == NULL) {  
		printf("Not able to push the element\n");   
	} else {  
		printf("Enter the value: ");  
		scanf("%d", &val);
		ptr->val = val;
		if(head==NULL) {  
			ptr->next = NULL;  
			head=ptr;  
		} else {  
			ptr->next = head;  
			head=ptr;  
		}  
		printf("Item pushed\n");  
	}  
}  

void pop()  
{  
	int item;  
	struct node *ptr;  
	if (head == NULL) {  
		printf("Stack underflow\n");  
	} else {  
		item = head->val;  
		ptr = head;  
		head = head->next;  
		free(ptr);  
		printf("%d was popped from stack\n", item);
	}  
}  

void display()  
{  
	int i;
	struct node *ptr = head;
	if(ptr == NULL) {  
		printf("Stack is empty\n");  
	} else {  
		printf("Printing Stack elements:\n");  
		while(ptr != NULL) {  
			printf("%d ", ptr->val);  
			ptr = ptr->next;  
		}
		printf("\n");
	}  
}  
