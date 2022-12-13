/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:27:55 by amonier           #+#    #+#             */
/*   Updated: 2022/12/10 22:46:00 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_listnew(char *content)
{
	t_list	*new;
	int		i;
	int		l;

	l = ft_strlen(content);
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

void	ft_listadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && *lst)
	{
		temp = ft_listlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_listiter(t_list *lst, int (*f)(char *))
{
	int	len;

	if (!f)
		return (0);
	len = 0;
	while (lst)
	{
		len += (*f)(lst->content);
		lst = lst->next;
	}
	return (len);
}

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
}
