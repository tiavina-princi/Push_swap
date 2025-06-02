/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_to_a_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:46:31 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/26 10:53:23 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_target_inplace(t_stack	**stack_b, t_stack **stack_a,
		t_variable_a *var)
{
	t_stack	*last_a;

	last_a = ft_lstlast(*stack_a);
	if (!var->down || last_a->content < (*stack_b)->content)
	{
		while ((*stack_a)->content < (*stack_b)->content)
		{
			rotate_a(stack_a);
			var->up--;
			var->down++;
		}
		push_a(stack_a, stack_b);
		var->up++;
		var->b_size--;
	}
	else
	{
		if (var->b_size > 1 && (*stack_b)->next->content == var->target)
			swap_b(stack_b);
		else
			rotate_b(stack_b);
	}
}
