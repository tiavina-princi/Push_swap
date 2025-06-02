/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:42:02 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/15 08:17:38 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack	**stack_a)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	print_instruction("sa\n");
}

void	swap_b(t_stack	**stack_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	print_instruction("sb\n");
}
