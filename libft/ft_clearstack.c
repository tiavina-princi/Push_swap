/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:09:17 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/24 04:55:58 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stackclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = NULL;
	while (*lst)
	{
		tmp = *lst;
		*lst = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}
