/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:48:26 by amonier           #+#    #+#             */
/*   Updated: 2022/12/14 01:20:23 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;
/*
typedef struct s_static
{
	int		indicateur = 0;
	char	statique[BUFFER_SIZE + 1];
}			t_static;
*/
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

t_list	*ft_listnew(char *content);
t_list	*ft_listlast(t_list *lst);
void	ft_listadd_back(t_list **lst, t_list *new, int i);
//int		ft_strlen(char *str);
int		ft_listiter(t_list *lst, int (*f)(char *, char, int));
//void	ft_listclear(t_list **lst);
char	*get_next_line(int fd);
char	*ft_fill_from_lst(t_list *lst);
int		ft_check_sep(char *s, char c, int boolean);

#endif
