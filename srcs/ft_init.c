/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:28:32 by ugolin-olle       #+#    #+#             */
/*   Updated: 2023/12/15 20:29:30 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_new_stack(t_stack *stack, int nbr)
{
	stack = malloc(sizeof(&stack));
	if (!stack)
		return ;
	stack->value = nbr;
	stack->index = 0;
	stack->pos = -1;
	stack->target_pos = -1;
	stack->cost_a = -1;
	stack->cost_b = -1;
	stack->next = NULL;
}

void	ft_indexation(t_stack *stack, int ssize)
{
	t_stack	*current;
	t_stack	*max_node;
	int		max_value;

	while (ssize-- > 0)
	{
		current = stack;
		max_value = INT_MIN;
		max_node = NULL;
		while (current)
		{
			if (current->value > max_value && current->index == 0)
			{
				max_value = current->value;
				max_node = current;
			}
			current = current->next;
		}
		if (max_node)
			max_node->index = ssize + 1;
	}
}

void	ft_init_stack(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		tmp;
	t_stack	*new;

	i = 0;
	tmp = 0;
	new = NULL;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (i == 1)
			ft_new_stack(stack, tmp);
		else
		{
			ft_new_stack(new, tmp);
			ft_push_bottom_stack(stack, new);
		}
		i++;
	}
}
