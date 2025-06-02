/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:31:04 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/27 16:11:29 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	add_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if ((*lst) == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static t_list	*new_lst(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*get_instruction(void)
{
	char	*instr;
	t_list	*lst;
	t_list	*tmp;

	instr = get_next_line(0);
	if (!instr)
		return (NULL);
	lst = NULL;
	while (instr)
	{
		tmp = new_lst(instr);
		if (!tmp)
		{
			ft_lstclear(&lst, &free);
			return (NULL);
		}
		add_back(&lst, tmp);
		tmp = NULL;
		instr = get_next_line(0);
	}
	return (lst);
}
