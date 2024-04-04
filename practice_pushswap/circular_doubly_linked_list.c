/*	Cos'è
Una lista doppia circolare è una struttura dati che ha le proprietà delle liste doppie e delle liste circolari.
Quindi rispettivamente:
- ogni nodo della lista contiene due puntatori, uno al nodo precedente e uno al prossimo nodo
- l'ultimo nodo punta tramite il next pointer al primo nodo della lista
- il primo nodo della lista punta tramite il previous pointer all'ultimo nodo della lista */

#include <stdio.h>
#include <stdlib.h>

//Struttura del nodo
typedef struct s_node
{
	int	data;

	struct s_node *next;
	struct s_node *prev;
} t_node;

//function to insert at the end
void	insertEnd(t_node **head, int value)
{
	//if the list is empty, create a single node
	if (*head == NULL)
	{
		t_node *new_node = malloc(sizeof(t_node));
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*head = new_node;
	}

	//if the list is not empty
	else
	{
		/* 1. find the last node */
		t_node *last = (*head)->prev;

		/* 2. create a node dynamically */
		t_node *new_node = malloc(sizeof(t_node));
		new_node->data = value;

		/* 3. head is going to be the next of new_node */
		new_node->next = *head;

		/* 4. so new_node is going to be prev of head*/
		(*head)->prev = new_node;

		/* 5. make last previous of new_node */
		new_node->prev = last;

		/* 6. make new_node next of last */
		last->next = new_node;
	}
}
void	insertBegin(t_node **head, int value)
{
	//if the list is empty, create a single node
	if (*head == NULL)
	{
		t_node *new_node = malloc(sizeof(t_node));
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*head = new_node;
	}
	else
	{
		/* Pointer to last node */
		t_node *last = (*head)->prev;

		/*create a node dinamically*/
		t_node *new_node = malloc(sizeof(t_node));
		new_node->data = value;

		/*setting up previus and next of new node*/
		new_node->next = (*head);
		new_node->prev = last;

		/*update next and prev pointer of head and last*/
		last->next = (*head)->prev = new_node;

		/*update head pointer to new_node*/
		*head = new_node;
	}

}

int main()
{
	t_node *head = NULL;
	insertEnd(&head, 8);
	printf("value: %i\n", head->data);
	insertEnd(&head, 9);
	insertEnd(&head, 19);
	insertEnd(&head, 29);
	t_node *current = head->next;
	while(!(current == head))
	{
		printf("value: %i\n", current->data);
		current = current->next;
	}
}

/* Advantages of circular doubly linked list: 
    - The list can be traversed from both directions i.e. from head to tail or from tail to head.
    - Jumping from head to tail or from tail to head is done in constant time O(1).
    - Circular Doubly Linked Lists are used for the implementation of advanced data structures like the Fibonacci Heap. 

   Disadvantages of circular doubly linked list: 
    It takes slightly extra memory in each node to accommodate the previous pointer.
    Lots of pointers are involved while implementing or doing operations on a list. 
	So, pointers should be handled carefully otherwise data of the list may get lost.

   Applications of Circular doubly linked list:
    Managing song playlists in media player applications.
    Managing shopping carts in online shopping. */
