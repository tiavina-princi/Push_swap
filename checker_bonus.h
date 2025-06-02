/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:47:19 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/27 16:40:30 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "libft/libft.h"

void	push_swap_check(t_stack	**stack);
int		*get_ref(t_stack **stack, int size);
t_list	*get_instruction(void);
void	push(t_stack **target, t_stack **dest);
void	rotate(t_stack **target);
void	revrotate(t_stack **target);
void	swap(t_stack **target);
int		check_push(char *instr, t_stack **stack_a, t_stack **stack_b);
int		check_revrotate(char *instr, t_stack **stack_a, t_stack **stack_b);
int		check_rotate(char *instr, t_stack **stack_a, t_stack **stack_b);
int		check_swap(char *instr, t_stack **stack_a, t_stack **stack_b);
int		check_zero(char *str);

#endif
