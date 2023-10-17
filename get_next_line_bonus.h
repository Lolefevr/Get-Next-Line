/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:24:50 by lolefevr          #+#    #+#             */
/*   Updated: 2023/03/15 14:24:47 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_malloc_line(t_list *beginlst);
char	*ft_extract_str(t_list *beginlst);
t_list	*ft_lstnew_bufsize(char *cont, int reading);
int		ft_read_nl(t_list **beginlst, int fd);
void	ft_reset_lst(t_list *beginlst);
void	ft_rdy_nl(t_list **beginlst);
char	*get_next_line(int fd);
char	*ft_extract_last(char *extract, char *str);
int		ft_check_empty(t_list *lst);

#endif
