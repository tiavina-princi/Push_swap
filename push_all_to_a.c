/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 07:30:49 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/26 11:12:17 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_stack *stack_b, int target)
{
	int	index;

	index = 0;
	while (stack_b)
	{
		if (stack_b->content == target)
			return (index);
		index++;
		stack_b = stack_b->next;
	}
	return (-1);
}

static void	put_target(t_stack	**stack_b, t_stack **stack_a, t_variable_a *var)
{
	while (var->up > 1)
	{
		var->up--;
		var->down++;
		rotate_a(stack_a);
	}
	push_a(stack_a, stack_b);
	var->b_size--;
	var->i++;
	if (var->up == 1)
		swap_a(stack_a);
}

static void	find_target(t_stack **stack_a, t_variable_a *var)
{
	if ((*stack_a)->content == var->target)
		var->up--;
	else
	{
		revrotate_a(stack_a);
		var->down--;
	}
	var->i++;
}

static t_variable_a	initialise_var(t_stack *stack_b)
{
	t_variable_a	var;

	var.b_size = ft_lstsize(stack_b);
	var.down = 0;
	var.up = 0;
	var.i = 4;
	var.target = 0;
	return (var);
}

void	push_all_to_a(t_stack **stack_a, t_stack **stack_b, int *ref, int size)
{
	t_variable_a	var;

	var = initialise_var(*stack_b);
	while ((*stack_b) || var.up || var.down)
	{
		var.target = ref[size - var.i];
		var.index = get_index(*stack_b, var.target);
		if (var.index == 0)
			put_target(stack_b, stack_a, &var);
		else if (var.index == -1)
			find_target(stack_a, &var);
		else if (var.index > var.b_size / 2)
		{
			while ((*stack_b)->content != var.target)
				revrotate_b(stack_b);
		}
		else if (var.index >= 1 && var.index <= var.b_size / 2)
			put_target_inplace(stack_b, stack_a, &var);
	}
}
