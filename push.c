/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:32:37 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/15 08:31:28 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!(*stack_b) || !stack_b)
		return ;
	first = *stack_b;
	tmp = (*stack_b)->next;
	first->next = NULL;
	ft_lstadd_front(stack_a, first);
	*stack_b = tmp;
	print_instruction("pa\n");
}

void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!(*stack_a) || !stack_a)
		return ;
	first = *stack_a;
	tmp = (*stack_a)->next;
	first->next = NULL;
	ft_lstadd_front(stack_b, first);
	*stack_a = tmp;
	print_instruction("pb\n");
}
