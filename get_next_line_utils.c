/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:27:55 by amonier           #+#    #+#             */
/*   Updated: 2022/12/21 02:15:20 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_listnew(char *content, t_list *lst, int j)
{
	t_list	*new;
	int		i;

	if (j == 0)
	{
		if (lst == NULL)
			return (NULL);
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	i = -1;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = malloc((ft_check_sep(content, 0, 1) + 1) * sizeof(char));
	if (new->content == NULL)
		return (free(new), NULL);
	while (++i < ft_check_sep(content, 0, 1))
		new->content[i] = content[i];
	new->content[i] = '\0';
	new->next = NULL;
	return (new);
}

void	ft_listadd_back(t_list **lst, t_list *new, int i)
{
	t_list	*temp;

	if (i == 0)
	{
		if (new == NULL)
			return (ft_listadd_back(lst, NULL, 1));
		if (lst && *lst)
		{
			temp = ft_listnew(0, *lst, 0);
			temp->next = new;
		}
		else
			*lst = new;
		return ;
	}	
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

char	*ft_normi(char *kanye, char *buffer, t_list **lst, int *tab_fd_l)
{
	if (tab_fd_l[0] == -2)
	{
		ft_listadd_back(lst, ft_listnew(kanye, 0, 1), 0);
		free(kanye);
		kanye = NULL;
		return (kanye);
	}
	while (ft_check_sep(buffer, '\n', 0) == -1 && tab_fd_l[1] != 0)
	{
		ft_listadd_back(lst, ft_listnew(buffer, 0, 1), 0);
		tab_fd_l[1] = read(tab_fd_l[0], buffer, BUFFER_SIZE);
		buffer[tab_fd_l[1]] = '\0';
	}
	if (tab_fd_l[1] != 0)
		kanye = length_diff_zero(buffer, kanye, tab_fd_l[1], lst);
	return (kanye);
}

int	ft_check_sep(char *s, char c, int boolean)
{
	int	i;

	i = 0;
	if (boolean == 0)
	{
		while (s[i])
		{
			if (s[i] == c)
				return (i);
			i++;
		}
		return (-1);
	}
	else if (boolean == 1)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (0);
}
