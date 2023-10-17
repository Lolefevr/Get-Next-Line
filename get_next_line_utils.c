/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:29:02 by lolefevr          #+#    #+#             */
/*   Updated: 2023/03/09 19:33:46 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new;
}

int	ft_check_empty(t_list *lst)
{
	int		i;
	t_list	*temp;

	if (!lst || !lst->content)
		return (0);
	temp = lst;
	while (temp)
	{
		i = 0;
		if (temp->content)
		{
			while (temp->content[i])
			{
				if (temp->content[i] == '\n')
					return (1);
				i++;
			}
		}
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	return (0);
}

int	ft_malloc_line(t_list *beginlst)
{
	int		i;
	int		count;
	t_list	*lst;

	count = 0;
	i = 0;
	lst = beginlst;
	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] != '\n')
			{
				i++;
				count++;
			}
			if (lst->content[i] == '\n')
				return (++count);
		}
		lst = lst->next;
	}
	return (count);
}

t_list	*ft_lstnew_bufsize(char *cont, int reading)
{
	t_list	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = malloc(sizeof(char) * (reading + 1));
	if (!new->content)
		return (NULL);
	while (cont[i])
	{
		new->content[i] = cont[i];
		i++;
	}
	new->content[i] = 0;
	new->next = NULL;
	return (new);
}

void	ft_reset_lst(t_list *beginlst)
{
	t_list	*current;
	t_list	*next;

	current = beginlst;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
