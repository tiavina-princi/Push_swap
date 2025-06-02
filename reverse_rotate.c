/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:09:03 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/15 08:38:20 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate_a(t_stack	**stack_a)
{
	t_stack	*tmp;
	t_stack	*penultimate;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	penultimate = *stack_a;
	while (penultimate->next && penultimate->next->next != NULL)
		penultimate = penultimate->next;
	tmp = penultimate->next;
	penultimate->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	print_instruction("rra\n");
}

void	revrotate_b(t_stack	**stack_b)
{
	t_stack	*tmp;
	t_stack	*penultimate;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	penultimate = *stack_b;
	while (penultimate->next && penultimate->next->next != NULL)
		penultimate = penultimate->next;
	tmp = penultimate->next;
	penultimate->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	print_instruction("rrb\n");
}
