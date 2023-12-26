/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:28:32 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/12/26 22:16:17 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @brief Creates a new node of type t_stack and adds it to the top of the
 * stack.
 *
 * @param head The head of the stack.
 * @param nbr The value to be added to the stack.
 * @return void
 */
void	ft_new_stack(t_stack **head, int nbr)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!head)
		return ;
	new_node->value = nbr;
	new_node->index = 0;
	new_node->next = NULL;
	*head = new_node;
}

/**
 * @brief Assigns a descending index to each element in a stack, based on their
 * value.
 * This function iteratively finds the element with the highest value that has
 * not yet been indexed and assigns a descending index starting from the size of
 * the stack
 *
 * @param stack_a Pointer to the head of the stack.
 * @param stack_size The number of elements in the stack.
 * @return void
 */
void	ft_indexation(t_stack *stack_a, int stack_size)
{
	int		i;
	int		max;
	t_stack	*current;

	i = 0;
	while (i < stack_size)
	{
		max = INT_MIN;
		current = stack_a;
		while (current)
		{
			if (current->value > max && current->index == 0)
				max = current->value;
			current = current->next;
		}
		current = stack_a;
		while (current)
		{
			if (current->value == max)
			{
				current->index = stack_size - i;
				break ;
			}
			current = current->next;
		}
		i++;
	}
}

/**
 * @brief Create and fill a stack with values from the command-line arguments.
 *
 * @param len_values The length of the values array.
 * @param values The array of values from the command-line arguments.
 * @param stack_a The stack to be filled.
 * @return void
 */
void	ft_init_stack(int len_values, char **values, t_stack **stack_a)
{
	t_stack	*new_node;
	int		i;

	i = 0;
	while (i < len_values)
	{
		if (i == 0)
		{
			ft_new_stack(stack_a, ft_atoi(values[i]));
		}
		else
		{
			ft_new_stack(&new_node, ft_atoi(values[i]));
			ft_push_bottom(stack_a, new_node);
		}
		i++;
	}
}
