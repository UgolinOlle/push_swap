/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugolin-olle <ugolin-olle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:57:38 by uolle             #+#    #+#             */
/*   Updated: 2023/12/16 17:51:38 by ugolin-olle      ###   ########.fr       */
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
static void	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return ;
	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_is_digit(argv[i]) == 0 || ft_duplicate_check(argv) == 0
			|| ft_duplicate_sign_check(argv) == 0)
			ft_handle_error("Error\n");
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			ft_handle_error("Error\n");
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
static void	ft_sorting(t_stack **stack_a, t_stack **stack_b, int ssize)
{
	(void)stack_b;
	if (ssize == 2 && ft_stack_sorted(*stack_a) == 0)
		ft_sa(*stack_a);
	else if (ssize == 3 && ft_stack_sorted(*stack_a) == 0)
		ft_sort_three(stack_a);
}

/**
 * @brief The main function of the push_swap program. Initializes stacks, checks
 * arguments, performs sorting operations, and manages the overall flow of the
 * push_swap program.
 *
 * @param argc The count of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return An integer to signal the end of the program.
 *
 */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**values;
	int		len_values;
	int		ssize;

	ft_check_args(argc, argv);
	values = ft_join_split(argv);
	stack_a = NULL;
	stack_b = NULL;
	len_values = ft_count_values(values);
	ft_init_stack(len_values, values, &stack_a);
	ssize = ft_stack_len(stack_a);
	ft_indexation(stack_a, ssize);
	ft_sorting(&stack_a, &stack_b, ssize);
	free(values);
	return (0);
}
