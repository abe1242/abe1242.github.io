#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *start;

void display()
{
	struct node *tmp;
	if(start == NULL) {
		printf("Linked list empty\n");
	} else {
		tmp = start;
		while(tmp != NULL) {
			printf("Data: %3d\n", tmp->data);
			tmp = tmp->link;
		}
	}
}

void insertFront()
{
	struct node *new;
	new = malloc(sizeof(struct node));
	if(new == NULL) {
		printf("Insufficient: Insertion is not possible\n");
		return;
	}
	printf("Enter value: ");
	scanf("%d", &new->data);
	
	new->link = start;
	start = new;
}

void insertEnd()
{
	struct node *ptr, *new;
	new = malloc(sizeof(struct node));
	if(new == NULL) {
		printf("Insufficient: Insertion is not possible\n");
		return;
	}
	printf("Enter value: ");
	scanf("%d", &new->data);
	new->link = NULL;
	
	if(start == NULL) {
		start = new;
	} else {
		ptr = start;
		while(ptr->link != NULL) {
			ptr = ptr->link;
		}
		ptr->link = new;
	}
}

void insertPos()
{
	struct node *ptr, *new, *tmp;
	int key;
	new = malloc(sizeof(struct node));
	if(new == NULL) {
		printf("Insufficient: Insertion is not possible\n");
		return;
	}
	printf("Enter the position to insert: ");
	scanf("%d", &key);
	printf("Enter value: ");
	scanf("%d", &new->data);
	new->link = NULL;
	
	if(start == NULL) {
		start = new;
	} else {
		ptr = start;
		while(ptr != NULL) {
			if(ptr->data == key) {
				tmp = ptr->link;
				ptr->link = new;
				new->link = tmp;
				return;
			}
			ptr = ptr->link;
		}
		printf("Key (%d) not found", key);
	}
}

void deleteFront()
{
	struct node *tmp;
	if(start == NULL) {
		printf("List is empty\n");
		return;
	}
	tmp = start;
	start = start->link;
	free(tmp);
}

void deleteEnd()
{
	struct node *prev = NULL, *tmp;
	if(start == NULL) {
		printf("List is empty\n");
		return;
	}
	tmp = start;
	while (tmp->link != NULL) {
		prev = tmp;
		tmp = tmp->link;
	}
	if(prev == NULL) {
		start = NULL;
		free(tmp);
		return;
	}
	free(tmp);
	prev->link = NULL;
}

void deletePos()
{
	struct node *tmp, *prevnode = NULL;
	int key, r;
	if (start == NULL) {
		printf("List is Empty\n");
		return;
	}
	
	printf("Enter the key: ");
	scanf("%d", &key);
	tmp = start;
	while (tmp != NULL && tmp->data != key) {
		prevnode = tmp;
		tmp = tmp->link;
	}
	if(tmp == NULL) {
		printf("Key not found\n");
		return;
	}
	r = tmp->data;
	if (prevnode == NULL)
		start = tmp->link;
	else
		prevnode->link=tmp->link;
	free(tmp);
	printf("%d is deleted\n", r);
}

void search()
{
	struct node *tmp;
	int key;
	if(start == NULL) {
		printf("Linked list empty\n");
		return;
	}
	
	printf("Enter the key to search: ");
	scanf("%d", &key);
	tmp = start;
	while(tmp != NULL) {
		if(tmp->data == key) {
			printf("Key was found in the list\n");
			return;
		}
		tmp = tmp->link;
	}
	printf("Not found\n");
}

int main()
{
	int choice;
	for(;;) {
		printf("\n\t1. Display list\n");
		printf("\t2. Insert at front\n");
		printf("\t3. Insert at end\n");
		printf("\t4. Insert at any position\n");
		printf("\t5. Delete first node\n");
		printf("\t6. Delete last node\n");
		printf("\t7. Delete node at any position\n");
		printf("\t8. Search for an item\n");
		printf("\t9. Exit\n");
		printf("\nEnter you choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: display(); break;
			case 2: insertFront(); break;
			case 3: insertEnd(); break;
			case 4: insertPos(); break;
			case 5: deleteFront(); break;
			case 6: deleteEnd(); break;
			case 7: deletePos(); break;
			case 8: search(); break;
			case 9: return 0; break;
			default: printf("Invalid choice\n");
		}
	}
}
