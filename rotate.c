/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:53:35 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/15 08:39:13 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
	print_instruction("ra\n");
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_b, tmp);
	print_instruction("rb\n");
}
