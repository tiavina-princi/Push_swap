/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiarandr <tiarandr@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:56:13 by tiarandr          #+#    #+#             */
/*   Updated: 2025/05/27 13:55:46 by tiarandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	failure_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

static void	free_memory(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

static int	pushin(t_stack **stack, int content)
{
	t_stack	*tmp;

	tmp = NULL;
	tmp = ft_stack_new(content);
	if (!tmp)
		return (-1);
	ft_lstadd_back(stack, tmp);
	return (0);
}

static t_stack	*put_arg(char **tab)
{
	t_stack	*stack;
	int		i;
	int		content;

	i = 0;
	stack = NULL;
	while (tab[i])
	{
		content = ft_atoi(tab[i]);
		if (content == 0 && check_zero(tab[i]) == -1)
		{
			ft_stackclear(&stack);
			free_memory(tab);
			failure_msg();
		}
		if (pushin(&stack, content) == -1)
		{
			free_memory(tab);
			ft_stackclear(&stack);
			failure_msg();
		}
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**tab;
	char	*arg;

	stack = NULL;
	if (argc == 1)
		return (1);
	arg = ft_strjoin_sep(argv + 1, argc - 1, " ");
	if (!arg)
		failure_msg();
	tab = ft_split(arg, ' ');
	if (!tab || !(*tab))
	{
		free(arg);
		free_memory(tab);
		failure_msg();
	}
	free(arg);
	arg = NULL;
	stack = put_arg(tab);
	free_memory(tab);
	push_swap_check(&stack);
	ft_stackclear(&stack);
	return (0);
}
