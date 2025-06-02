/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:09:17 by tiarandr          #+#    #+#             */
/*   Updated: 2025/03/18 00:28:54 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = NULL;
	while (*lst)
	{
		tmp = *lst;
		del(tmp->content);
		*lst = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}
