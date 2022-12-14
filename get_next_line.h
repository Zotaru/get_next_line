/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:48:26 by amonier           #+#    #+#             */
/*   Updated: 2022/12/15 00:31:11 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

t_list	*ft_listnew(char *content, t_list *lst, int j);
void	ft_listadd_back(t_list **lst, t_list *new, int i);
int		ft_listiter(t_list *lst, int (*f)(char *, char, int));
char	*get_next_line(int fd);
char	*ft_fill_from_lst(t_list *lst);
int		ft_check_sep(char *s, char c, int boolean);
char	*ft_normi(char *kanye, char *buffer, t_list **lst, int *tab_fd_l);
char	*length_diff_zero(char *buf, char *kanye, int length, t_list **lst);
t_list	*get_next_line2(int fd);
char	*ret_line_in_static2(char *kanye, t_list **lst);

#endif
