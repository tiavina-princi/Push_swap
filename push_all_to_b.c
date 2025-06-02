/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_to_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:16:51 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/23 13:35:27 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_chunk(const int min, const int max, t_stack *a)
{
	int	counter;

	counter = 0;
	while (a)
	{
		if (a->content >= min && a->content <= max)
			counter++;
		a = a->next;
	}
	return (counter);
}

static void	divide_b(t_stack **b, int median)
{
	t_stack		*tmp;
	static int	index = 0;

	tmp = *b;
	if (index == 0)
	{
		while (tmp)
		{
			if (tmp->content >= median)
			{
				index = 1;
				rotate_b(b);
				return ;
			}
			tmp = tmp->next;
		}
	}
	else
		rotate_b(b);
}

static t_variable_b	initialise_value(const int size, int *ref, t_stack *a)
{
	int				middle;
	t_variable_b	var;

	middle = size / 2;
	if (size <= 10)
		var.offset = 5;
	else if (size <= 150)
		var.offset = size / 8;
	else
		var.offset = size / 13;
	var.end = middle + var.offset;
	if (var.end > size - 1)
		var.end = size - 1;
	var.start = middle - var.offset;
	if (var.start < 0)
		var.start = 0;
	var.upper_size = size_chunk(ref[middle], ref[var.end], a);
	var.lower_size = size_chunk(ref[var.start], ref[middle - 1], a);
	var.middle = size / 2;
	return (var);
}

static void	update_chunk(t_variable_b *var, int *ref
, int size, t_stack *a)
{
	int	middle;

	middle = size / 2;
	if (var->lower_size <= 0)
	{
		var->start = var->start - var->offset;
		if (var->start < 0)
			var->start = 0;
		var->lower_size = size_chunk(ref[var->start], ref[middle - 1], a);
	}
	if (var->upper_size <= 0)
	{
		var->end = var->end + var->offset;
		if (var->end > size - 1)
			var->end = size - 1;
		var->upper_size = size_chunk(ref[middle], ref[var->end], a);
	}
}

void	push_all_to_b(t_stack **a, t_stack **b, int *ref, int size)
{
	t_variable_b	ptr;

	ptr = initialise_value(size, ref, *a);
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->content >= ref[size - 3] && (*a)->content <= ref[size - 1])
			rotate_a(a);
		else if ((*a)->content >= ref[ptr.start]
			&& (*a)->content <= ref[ptr.middle - 1])
		{
			push_b(b, a);
			divide_b(b, ref[ptr.middle]);
			ptr.lower_size--;
		}
		else if ((*a)->content >= ref[ptr.middle]
			&& (*a)->content <= ref[ptr.end])
		{
			push_b(b, a);
			ptr.upper_size--;
		}
		else
			rotate_a(a);
		update_chunk(&ptr, ref, size, *a);
	}
}
