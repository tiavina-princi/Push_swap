/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:18:54 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/27 22:27:55 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_stack **target, t_stack **dest)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!target || !(*target))
		return ;
	first = *target;
	tmp = (*target)->next;
	first->next = NULL;
	ft_lstadd_front(dest, first);
	*target = tmp;
}

void	rotate(t_stack **target)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!target || !(*target) || !(*target)->next)
		return ;
	tmp = *target;
	*target = tmp->next;
	tmp->next = NULL;
	ft_lstadd_back(target, tmp);
}

void	revrotate(t_stack **target)
{
	t_stack	*tmp;
	t_stack	*penultimate;

	if (!target || !(*target) || !(*target)->next)
		return ;
	penultimate = *target;
	while (penultimate->next && penultimate->next->next != NULL)
		penultimate = penultimate->next;
	tmp = penultimate->next;
	penultimate->next = NULL;
	ft_lstadd_front(target, tmp);
}

void	swap(t_stack **target)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!target || !(*target) || !(*target)->next)
		return ;
	tmp = (*target)->next;
	(*target)->next = tmp->next;
	tmp->next = *target;
	*target = tmp;
}

int	check_zero(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] == '\0')
		return (1);
	return (-1);
}
