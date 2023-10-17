/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:28:56 by lolefevr          #+#    #+#             */
/*   Updated: 2023/03/15 14:17:17 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_str(t_list *beginlst)
{
	char	*str;
	int		i;
	int		count;

	count = 0;
	str = malloc(sizeof(char) * (ft_malloc_line(beginlst) + 1));
	if (!str)
		return (NULL);
	while (beginlst)
	{
		i = 0;
		while (beginlst->content[i])
		{
			if (beginlst->content[i] == '\n')
			{
				str[count++] = beginlst->content[i];
				break ;
			}
			str[count++] = beginlst->content[i++];
		}
		beginlst = beginlst->next;
	}
	str[count] = '\0';
	return (str);
}

int	ft_read_nl(t_list **beginlst, int fd)
{
	char	*str;
	t_list	*lst;
	int		reading;

	reading = 1;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (0);
	while (!ft_check_empty(*beginlst) && reading != 0)
	{
		reading = (int)read(fd, str, BUFFER_SIZE);
		if ((reading < 1 && !*beginlst) || reading == -1)
		{
			free(str);
			return (0);
		}
		str[reading] = '\0';
		if (reading)
		{
			lst = ft_lstnew_bufsize(str, reading);
			ft_lstadd_back(beginlst, lst);
		}
	}
	free(str);
	return (reading);
}

char	*ft_extract_last(char *extract, char *str)
{
	int	i;

	i = 0;
	while (extract[i])
	{
		str[i] = extract[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_rdy_nl(t_list **beginlst)
{
	t_list	*lst;
	t_list	*clearlst;
	int		i;
	int		j;

	if (!beginlst)
		return ;
	j = 0;
	i = 0;
	lst = *beginlst;
	while (lst && lst->next)
		lst = lst->next;
	while (lst->content[i] && lst->content[i] != '\n')
		i++;
	if (lst->content[i] == '\n')
		i++;
	while (lst->content[i + j])
		j++;
	clearlst = ft_lstnew_bufsize(lst->content + i, j);
	ft_reset_lst(*beginlst);
	*beginlst = clearlst;
}

char	*get_next_line(int fd)
{
	char			*str;
	static t_list	*beginlst;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = NULL;
	ft_read_nl(&beginlst, fd);
	if (!beginlst)
		return (NULL);
	str = ft_extract_str(beginlst);
	ft_rdy_nl(&beginlst);
	if (str[0] == '\0')
	{
		ft_reset_lst(beginlst);
		beginlst = NULL;
		free(str);
		return (NULL);
	}
	return (str);
}
