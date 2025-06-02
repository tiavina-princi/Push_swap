/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 04:44:19 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/20 02:28:33 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_argument(t_stack *stack_a)
{
	int		content;
	t_stack	*tmp;
	t_stack	*next;

	tmp = stack_a;
	while (tmp)
	{
		next = tmp->next;
		content = tmp->content;
		while (next)
		{
			if (content == next->content)
			{
				ft_stackclear(&stack_a);
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
}

static void	check_sort(t_stack	*stack_a)
{
	int		min;
	t_stack	*tmp;

	min = stack_a->content;
	tmp = stack_a->next;
	while (tmp)
	{
		if (min > tmp->content)
			return ;
		else if (tmp->content > min)
			min = tmp->content;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		ft_stackclear(&stack_a);
		exit(EXIT_SUCCESS);
	}
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b, int *ref, int size)
{
	if (size == 3)
	{
		sort_three(stack_a, ref, size - 3, size - 1);
		print_instruction(NULL);
		return ;
	}
	else if (size == 2)
	{
		swap_a(stack_a);
		print_instruction(NULL);
		return ;
	}
	push_all_to_b(stack_a, stack_b, ref, size);
	sort_three(stack_a, ref, size - 3, size - 1);
	push_all_to_a(stack_a, stack_b, ref, size);
	print_instruction(NULL);
}

void	push_swap(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		*ref;
	int		size;

	stack_b = NULL;
	check_argument(*stack_a);
	check_sort(*stack_a);
	size = ft_lstsize(*stack_a);
	if (size < 2)
	{
		ft_stackclear(stack_a);
		exit(EXIT_FAILURE);
	}
	ref = ref_sort(*stack_a, size);
	if (!ref)
	{
		ft_stackclear(stack_a);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	sort_stack(stack_a, &stack_b, ref, size);
	free(ref);
}
