/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 05:18:57 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/15 06:44:05 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*putintab(t_stack *stack, unsigned int size)
{
	int	data;
	int	*array;
	int	i;

	i = 0;
	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (stack)
	{
		data = stack->content;
		array[i] = data;
		i++;
		stack = stack->next;
	}
	return (array);
}

static	int	setting(int **array, int start, int end)
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

int	*ref_sort(t_stack *stack, int size)
{
	int	*array;

	array = putintab(stack, size);
	if (!array)
		return (NULL);
	quick_sort(&array, 0, size - 1);
	return (array);
}

int	check_zero(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] == '\0')
		return (1);
	return (-1);
}
