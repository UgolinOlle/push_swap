/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:57:38 by uolle             #+#    #+#             */
/*   Updated: 2023/12/15 20:27:40 by ugolin-olle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Checks the command-line arguments for validity.
 *
 * @param argc The count of arguments.
 * @param argv The array of arguments.
 *
 * Verifies that the number of arguments is sufficient and each argument
 * represents a valid digit. If an error is found, the function triggers
 * an error handling routine.
 */
static void	ft_check_args(int argc, char **values)
{
	int	i;

	if (argc < 2)
		ft_handle_error("[ERROR] - You have less than 2 arguments.");
	i = 1;
	while (values[i] != NULL)
	{
		if (ft_isdigit(ft_atoi(values[i])) && ft_duplicate_check(values) == 0
			|| ft_duplicate_sign_check(values) == 0)
			ft_handle_error("[ERROR] - One of number is not digit.");
		if (ft_atoi(values[i]) > INT_MAX || ft_atoi(values[i]) < INT_MIN)
			ft_handle_error("[ERROR] - One of number is out of range.");
		i++;
	}
}

/**
 * Sorts the stack of integers if the stack size is 2.
 *
 * @param stack_1 The primary stack to be sorted.
 * @param stack_2 The secondary stack (not used in this function).
 * @param ssize The size of the primary stack.
 *
 * Checks if the size of the stack is 2 and if the stack is not already
 * sorted. If these conditions are met, it performs a swap operation.
 */
static void	ft_sorting(t_stack *stack_1, t_stack *stack_2, int ssize)
{
	(void)stack_2;
	if (ssize == 2 && ft_stack_sorted(stack_1) == 1)
		ft_sa(stack_1);
}

/**
 * The main function of the push_swap program.
 *
 * @param argc The count of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return An integer to signal the end of the program.
 *
 * Initializes stacks, checks arguments, performs sorting operations,
 * and manages the overall flow of the push_swap program.
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_1;
	t_stack	*stack_2;
	int		ssize;
	char	**values;

	values = ft_join_split(argv);
	ft_check_args(argc, values);
	stack_2 = NULL;
	stack_1 = NULL;
	ft_init_stack(argc, argv, stack_1);
	ssize = ft_stack_len(stack_1);
	ft_indexation(stack_1, ssize);
	ft_print_list(stack_1);
	ft_sorting(stack_1, stack_2, ssize);
	return (0);
}
