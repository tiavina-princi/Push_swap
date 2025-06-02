/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 03:12:52 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/26 10:55:07 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_variable_b
{
	int	offset;
	int	start;
	int	end;
	int	upper_size;
	int	lower_size;
	int	counter;
	int	middle;
}	t_variable_b;

typedef struct s_variable_a
{
	int		index;
	int		up;
	int		down;
	int		b_size;
	int		target;
	int		i;
	t_stack	*last_a;
}	t_variable_a;

int		check_zero(char *str);
int		*ref_sort(t_stack *stacki, int size);
void	swap_a(t_stack	**stack_a);
void	swap_b(t_stack	**stack_b);
void	push_b(t_stack **stack_b, t_stack **stack_a);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_all(t_stack **stack_a, t_stack **stack_b);
void	revrotate_a(t_stack	**stack_a);
void	revrotate_b(t_stack	**stack_b);
void	revrotate_all(t_stack	**stack_a, t_stack	**stack_b);
void	push_swap(t_stack **stack_a);
void	print_instruction(char	*instr);
void	sort_three(t_stack **stack_a, int *ref, int start, int end);
void	push_all_to_b(t_stack **stack_a, t_stack **stack_b, int *ref, int size);
void	push_all_to_a(t_stack **stack_a, t_stack **stack_b, int *ref, int size);
void	put_target_inplace(t_stack	**stack_b, t_stack **stack_a,
			t_variable_a *var);

#endif
