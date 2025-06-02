/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:55:07 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/27 15:53:05 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	setting(int **array, int start, int end)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	i = start - 1;
	j = start;
	pivot = (*array)[end];
	while (j <= (end - 1))
	{
		if ((*array)[j] < pivot)
		{
			i++;
			temp = (*array)[i];
			(*array)[i] = (*array)[j];
			(*array)[j] = temp;
		}
		j++;
	}
	i++;
	temp = (*array)[i];
	(*array)[i] = (*array)[j];
	(*array)[j] = temp;
	return (i);
}

static void	quick_sort(int **array, int start, int end)
{
	int	pivot;

	if (end <= start)
		return ;
	pivot = setting(array, start, end);
	quick_sort(array, start, pivot - 1);
	quick_sort(array, pivot + 1, end);
}

static int	*put_inarray(t_stack *stack, int size)
{
	int	i;
	int	*array;

	i = 0;
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (stack)
	{
		array[i] = stack->content;
		i++;
		stack = stack->next;
	}
	return (array);
}

int	*get_ref(t_stack **stack, int size)
{
	int	*array;

	array = put_inarray(*stack, size);
	if (!array)
	{
		ft_stackclear(stack);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	quick_sort(&array, 0, size - 1);
	return (array);
}
