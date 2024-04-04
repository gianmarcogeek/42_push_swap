// #include <limits.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdbool.h>
// #include "../lib/libft/libft.h"

// typedef struct s_node
// {
// 	int data;

// 	struct s_node *next;
// 	struct s_node *prev;
// }t_node;


// t_node *find_last_node(t_node *head)
// {
// 	t_node *current;


// 	current = head;
// 	if(!head)
// 		return (NULL);
// 	while(current->next)
// 		current = current->next;
// 	return (current);
// }


// void	insert_in_stack(t_node **head, int value)
// {
// 	if (*head == NULL)
// 	{
// 		t_node *new_node = malloc(sizeof(t_node));
// 		new_node->data = value;
// 		new_node->next = new_node->prev = NULL;
// 		*head = new_node;
// 	}

// 	else
// 	{
// 		t_node *last = find_last_node(*head);
// 		t_node *new_node = malloc(sizeof(t_node));
// 		new_node->data = value;
// 		new_node->next = NULL;
// 		new_node->prev = last;
// 		last->next = new_node;
// 	}
// }

// bool	check_number(char *arg)
// {
// 	int i = 0;
// 	if (arg[i] == '-' || arg[i] == '+')
// 		i++;
// 	while(arg[i])
// 	{
// 		if(!(arg[i] >= '0' && arg[i] <= '9'))
// 			return 0;
// 		i++;
// 	}
// 	return 1;
// }

// void	check_and_init(t_node **list, char **args, int n_args)
// {
// 	int i = 0;
// 	while (i < n_args)
// 	{
// 		if(check_number(args[i]))
// 		{
// 			long number = ft_atoll(args[i]);
// 			if (number >= INT_MIN && number <= INT_MAX)
// 				insert_in_stack(list, number);
// 			else
// 			{
// 				printf("ERROR SIZE");
// 				exit(1);
// 			}
// 		}
// 		else
// 		{
// 			printf("ERROR NUMBER");
// 			exit(1);
// 		}
			
// 		i++;
// 	}
// }
// int	ft_splitlen(char **matrix)
// {
// 	int i = 0;
// 	while(matrix[i])
// 		i++;
// 	return (i);
// }

// bool check_for_dup(t_node *head)
// {
// 	t_node *current = head;
// 	t_node *compare;

// 	while(current)
// 	{
// 		compare = current->next;
// 		while(compare)
// 		{
// 			if(current->data == compare->data)
// 			{
// 				printf("ERROR DUP");
// 				exit(1);
// 			}
// 			compare = compare->next;
// 		}
// 		current = current->next;
// 	}
// 	return (0);
// }

// int main(int argc, char *argv[])
// {
// 	t_node *list_a;

// 	list_a = NULL;
// 	if (argc == 2)
// 	{
// 		char **splitted = ft_split(argv[1], ' ');
// 		int n_words = ft_splitlen(splitted);
// 		check_and_init(&list_a, splitted, n_words);
// 	}
// 	else if (argc > 2)
// 		check_and_init(&list_a, argv + 1, argc - 1);

// 	check_for_dup(list_a);

// 	if (list_a != NULL)
// 	{
// 		t_node *current = list_a;
// 		while(current)
// 		{
// 			printf("value: %d\n", current->data);
// 			current = current->next;
// 		}
// 	}

// }