#include <stdio.h>

struct node {
	int data;
	struct node* next;
};

void print_list(struct node* head) {
	if (head == NULL) {
		printf("The list is empty\n");
	} else {
		struct node* current;
		current = head;
		while ((*current).next != NULL) {
			printf("%d ", (*current).data);
			current = (*current).next;
		}
		printf("%d", (*current).data);
		printf("\n");
	}
}

// inserts an integer number to the end of the list
void insert_node(struct node** head, int number) {
	struct node* new_node = malloc(sizeof(struct node));
	(*new_node).data = number;
	(*new_node).next = NULL;
	if (*head == NULL) {
		*head = new_node;
	} else {
		struct node* current;
		current = *head;
        	while ((*current).next != NULL) {
                	current = (*current).next;
        	}
		(*current).next = new_node;
	}
};

// deletes a number with a certain index from the list
void delete_node(struct node** head, int index) {
	if (index == 0) {
		if (*head != NULL) {
			struct node* target = *head;
                	*head = (*target).next;
			free(target);
		} else {
			printf("Cannot delete, the list is empty");
		}
	} else {
		struct node* current;
		
        	current = *head;
		int i = 1;
		while ((*current).next != NULL && i < index) {
			current = (*current).next;
			i++;
		}
		if (i == index && (*current).next != NULL) {
			struct node* target = (*current).next;
			(*current).next = (*target).next;
			free(target);
		} else {
			printf("Wrong index");
		}
	}
};

int main() {
	struct node* list;
	list = NULL;
	printf("The intial list is empty\n");
	insert_node(&list, 1);
	insert_node(&list, 2);
	insert_node(&list, 3);
	printf("After inserting three values the list is:\n");
	print_list(list);
	delete_node(&list, 2);
	printf("After deleting the number with index 2:\n");
	print_list(list);

	return 0;
}
