/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_utils3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:21:23 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/27 22:27:57 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft/libft.h"

int	check_swap(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(instr, "ss\n") == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strcmp(instr, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(instr, "sb\n") == 0)
		swap(stack_b);
	else
		return (-1);
	return (0);
}

int	check_rotate(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strlen(instr) == 4)
		return (check_revrotate(instr, stack_a, stack_b));
	if (ft_strcmp(instr, "rr\n") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(instr, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(instr, "rb\n") == 0)
		rotate(stack_b);
	else
		return (-1);
	return (0);
}

int	check_revrotate(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(instr, "rrr\n") == 0)
	{
		revrotate(stack_a);
		revrotate(stack_b);
	}
	else if (ft_strcmp(instr, "rra\n") == 0)
		revrotate(stack_a);
	else if (ft_strcmp(instr, "rrb\n") == 0)
		revrotate(stack_b);
	else
		return (-1);
	return (0);
}

int	check_push(char *instr, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(instr, "pa\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(instr, "pb\n") == 0)
		push(stack_a, stack_b);
	else
		return (-1);
	return (0);
}
