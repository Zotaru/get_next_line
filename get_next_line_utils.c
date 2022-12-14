/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:27:55 by amonier           #+#    #+#             */
/*   Updated: 2022/12/14 02:26:49 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_listnew(char *content)
{
	t_list	*new;
	int		i;
	int		l;

	l = ft_check_sep(content, 0, 1);
	i = 0;
	new = malloc(sizeof(t_list));
	new->content = malloc((l + 1) * sizeof(char));
	while (i < l)
	{
		new->content[i] = content[i];
		i++;
	}
	new->content[i] = '\0';
	new->next = NULL;
	return (new);
}

t_list	*ft_listlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_listadd_back(t_list **lst, t_list *new, int i)
{
	t_list	*temp;

	if (i == 0)
	{
		if (lst && *lst)
		{
			temp = ft_listlast(*lst);
			temp->next = new;
		}
		else
			*lst = new;
	}
	else if (i == 1)
	{
		if (!lst || !*lst)
			return ;
		while (*lst)
		{
			free((*lst)->content);
			temp = *lst;
			*lst = (*lst)->next;
			free(temp);
		}
	}
}

// add back peut clear la liste ou ajouter a la liste

/*
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/


int	ft_listiter(t_list *lst, int (*f)(char *, char, int))
{
	int	len;

	if (!f)
		return (0);
	len = 0;
	while (lst)
	{
		len += (*f)(lst->content, 0, 1);
		lst = lst->next;
	}
	return (len);
}

/*
void	ft_listclear(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		free((*lst)->content);
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}*/

char	*ft_normi(char *kanye, char *buffer, t_list **lst, int *tab_fd_l)
{
	//int length;

	//length = 1;
	if (tab_fd_l[0] == -2)
	{
		ft_listadd_back(lst, ft_listnew(kanye), 0);
		free(kanye);
		kanye = NULL;
		return (kanye);
	}
	while (ft_check_sep(buffer, '\n', 0) == -1 && tab_fd_l[1] != 0)
	{
		ft_listadd_back(lst, ft_listnew(buffer), 0);
		tab_fd_l[1] = read(tab_fd_l[0], buffer, BUFFER_SIZE);
		buffer[tab_fd_l[1]] = '\0';
	}
	if (tab_fd_l[1] != 0)
		kanye = length_diff_zero(buffer, kanye, tab_fd_l[1], lst);
	return (kanye);
}
