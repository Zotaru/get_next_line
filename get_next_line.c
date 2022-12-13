/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:36:08 by amonier           #+#    #+#             */
/*   Updated: 2022/12/13 22:44:58 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_sep(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_fill_from_lst(t_list *lst)
{
	int		i;
	int		j;
	int		length;
	char	*tab;

	length = ft_listiter(lst, &ft_strlen);
	tab = malloc((length + 1) * sizeof(char));
	if(tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (lst)
	{
		while (i < length && lst->content[j])
		{
			tab[i] = lst->content[j];
			i++;
			j++;
		}
		j = 0;
		lst = lst->next;
	}
	tab[i] = '\0';
	return (tab);
}

char	*length_diff_zero(char *buf, char *kanye, int length, t_list **lst)
{
	int		i;
	int		j;
	char	*temp;

	j = -1;
	i = ft_check_sep(buf, '\n') + 1;
	temp = malloc((i + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (++j < i)
		temp[j] = buf[j];
	temp[j] = '\0';
	ft_listadd_back(lst, ft_listnew(temp));
	free(temp);	
	i = 0;
	kanye = malloc((length - j + 1) * sizeof(char));
	if (kanye == NULL)
		return (NULL);
	while (j < length)
		kanye[i++] = buf[j++];
	kanye[i] = '\0';
	return (kanye);
}

char	*ret_line_in_static2(char *kanye, t_list **lst)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_check_sep(kanye, '\n') + 1;
	j = -1;
	temp = malloc((i + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (++j < i)
		temp[j] = kanye[j];
	temp[j] = '\0';
	ft_listadd_back(lst, ft_listnew(temp));
	free(temp);
	j = 0;
	while (kanye[i])
		kanye[j++] = kanye[i++];
	kanye[j] = '\0';
	if (kanye[0] == '\0')
	{
		free(kanye);
		kanye = NULL;
	}
	return (kanye);
}

char	*get_next_line(int fd)
{
	static char	*kanye = NULL;
	char		*buffer;
	t_list		*lst;
	int			length;
	char		*tab_fin;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0|| BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0 || buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	lst = NULL;
	if (kanye != NULL && ft_check_sep(kanye, '\n') >= 0)
		kanye = ret_line_in_static2(kanye, &lst);
	else
	{
		if (kanye != NULL && ft_check_sep(kanye, '\n') == -1)
		{
			ft_listadd_back(&lst, ft_listnew(kanye));
			free(kanye);
			kanye = NULL;
		}
		length = read(fd, buffer, BUFFER_SIZE);
		buffer[length] = '\0';
		if (length == 0 && lst == NULL)
		{
			free(buffer);
			return (NULL);
		}
		while (ft_check_sep(buffer, '\n') == -1 && length != 0)
		{
			ft_listadd_back(&lst, ft_listnew(buffer));
			length = read(fd, buffer, BUFFER_SIZE);
			buffer[length] = '\0';
		}
		if (length != 0)
		{	
			kanye = length_diff_zero(buffer, kanye, length, &lst);
			if (kanye[0] == '\0')
			{
				free(kanye);
				kanye = NULL;
			}
			else if (kanye == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	free(buffer);
	tab_fin = ft_fill_from_lst(lst);
	ft_listclear(&lst);
	return (tab_fin);
}