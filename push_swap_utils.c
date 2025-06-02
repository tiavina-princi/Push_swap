/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 08:59:04 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/19 09:01:17 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a, int *ref, int start, int end)
{
	t_stack	*ptr_a;
	t_stack	*last;

	ptr_a = *stack_a;
	last = ft_lstlast(*stack_a);
	if (ptr_a->content == ref[end] && last->content == ref[start + 1])
		rotate_a(stack_a);
	else if (ptr_a->content == ref[end] && last->content == ref[start])
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (ptr_a->content == ref[start + 1] && last->content == ref[start])
		revrotate_a(stack_a);
	else if (ptr_a->content == ref[start + 1] && last->content == ref[end])
		swap_a(stack_a);
	else if (ptr_a->content == ref[start] && last->content == ref[start + 1])
	{
		revrotate_a(stack_a);
		swap_a(stack_a);
	}
}

static void	check_rr_rrr(char *save, char *instr, int *call)
{
	int	diff;
	int	len;

	diff = ft_strcmp(save, instr);
	if (diff == 1 || diff == -1)
	{
		len = ft_strlen(save);
		if (len == 4)
			ft_strcpy(save, "rrr\n");
		else if (len == 3)
			ft_strcpy(save, "rr\n");
		ft_putstr_fd(save, 1);
		*call = 1;
	}
	else
	{
		ft_putstr_fd(save, 1);
		ft_strcpy(save, instr);
	}
}

static void	check_ss(char *save, char	*instr, int *call)
{
	int	diff;

	diff = ft_strcmp(save, instr);
	if (diff == 1 || diff == -1)
	{
		ft_strcpy(save, "ss\n");
		ft_putstr_fd(save, 1);
		*call = 1;
	}
	else
	{
		ft_putstr_fd(save, 1);
		ft_strcpy(save, instr);
	}
}

static void	print_cpy(char *save, char *instr, int *call)
{
	if (*call == 1)
	{
		ft_strcpy(save, instr);
		*call = 0;
	}
	else
	{
		ft_putstr_fd(save, 1);
		ft_strcpy(save, instr);
	}
}

void	print_instruction(char *instr)
{
	static char	save[5];
	static int	first_call = 1;

	if (instr == NULL)
	{
		ft_putstr_fd(save, 1);
		return ;
	}
	if (first_call == 1)
		print_cpy(save, instr, &first_call);
	else
	{
		if (save[0] == 'r' && instr[0] == 'r')
			check_rr_rrr(save, instr, &first_call);
		else if (save[0] == 's' && instr[0] == 's')
			check_ss(save, instr, &first_call);
		else
			print_cpy(save, instr, &first_call);
	}
}
