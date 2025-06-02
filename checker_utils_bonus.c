/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:10:13 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/27 22:23:30 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	check_duplicate(t_stack	**stack)
{
	t_stack	*start;
	t_stack	*next;
	int		data;

	start = *stack;
	next = start->next;
	while (start)
	{
		data = start->content;
		while (next)
		{
			if (data == next->content)
			{
				ft_stackclear(stack);
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			next = next->next;
		}
		start = start->next;
	}
}

static int	implementation(t_list **lst, t_stack **stack_a, t_stack **stack_b)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->content[0] == 's')
		{
			if (check_swap(tmp->content, stack_a, stack_b) == -1)
				return (-1);
		}
		else if (tmp->content[0] == 'r')
		{
			if (check_rotate(tmp->content, stack_a, stack_b) == -1)
				return (-1);
		}
		else if (tmp->content[0] == 'p')
		{
			if (check_push(tmp->content, stack_a, stack_b) == -1)
				return (-1);
		}
		else
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

static void	check(t_stack **stack_a, t_stack **stack_b, int *ref, int size)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	if ((*stack_b) != NULL)
	{
		ft_putstr_fd("KO\n", 1);
		ft_stackclear(stack_b);
		return ;
	}
	while (i < size)
	{
		if (tmp->content != ref[i])
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		tmp = tmp->next;
		i++;
	}
	ft_putstr_fd("OK\n", 1);
}

void	push_swap_check(t_stack **stack)
{
	int		*ref;
	int		size;
	t_stack	*stack_b;
	t_list	*lst;

	lst = NULL;
	stack_b = NULL;
	check_duplicate(stack);
	lst = get_instruction();
	size = ft_lstsize(*stack);
	ref = get_ref(stack, size);
	if (implementation(&lst, stack, &stack_b) == -1)
	{
		free(ref);
		ft_lstclear(&lst, &free);
		ft_stackclear(&stack_b);
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	ft_lstclear(&lst, &free);
	check(stack, &stack_b, ref, size);
	free(ref);
}
