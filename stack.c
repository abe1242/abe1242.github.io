#include <stdio.h>

void push();
void pop();
void display();

int max = 5;
int arr[5], top = -1, num;

int main()
{
	int choice;
	while(1)
	{
		printf("\n1.Push 2.Pop 3.Display 4.Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			case 4: return 0;
			default: printf("Invalid choice\n"); break;
		}
	}
}

void push()
{
	if(top < max-1)
	{
		top++;
		printf("Enter no: ");
		scanf("%d", &num);
		arr[top] = num;
	}
	else
	{
		printf("Stack overflow\n");
	}
}
void pop()
{
	if(top < 0)
	{
		printf("Stack underflow\n");
	}
	else
	{
		int tope = arr[top];
		top--;
		printf("Popped element is %d\n", tope);
	}
}
void display()
{
	printf("Stack elements are\n");
	for(int i=0; i<=top; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
