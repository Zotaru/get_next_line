/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:20:19 by amonier           #+#    #+#             */
/*   Updated: 2022/12/12 22:50:32 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h> 

void	s_sleep( int seconds)
{
	time_t start_time = 0; 
	time_t current_time = 0;

	start_time = time(NULL);
	while(current_time-start_time+1 <= seconds)
		current_time = time(NULL);
}

void	ft_putnbr(int nb)
{
	long long	nbl;
	char		c;

	nbl = nb;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = (-1) * nbl;
	}
	if (nbl >= 0 && nbl <= 9)
	{
		c = '0' + nbl;
		write(1, &c, 1);
		return ;
	}
	else if (nbl >= 10)
	{
		ft_putnbr(nbl / 10);
		ft_putnbr(nbl % 10);
	}
	return ; 
}

int	main()
{
	int	fd;
	int ret;
	char buf[3 +1];
	struct timespec tim, tim2;
	char	*tab;

	tim.tv_sec = 0;
	tim.tv_nsec = 200000000;

	fd = open("42v2", O_RDONLY);
	if ( fd == -1)
	{
		printf("open failed");
		return (0);
	}

	while (tab = get_next_line(fd))
	{
		printf("%s", tab);
		free(tab);
	}
	// tab = get_next_line(fd);
	// printf("%s", tab);
	// free(tab);
	// tab = get_next_line(fd);
	// printf("%s", tab);
	// free(tab);
	// tab = get_next_line(fd);
	// printf("%s", tab);
	// free(tab);
	// tab = get_next_line(fd);
	// printf("%s", tab);
	// free(tab);
	// tab = get_next_line(fd);
	// printf("%s", tab);
	// free(tab);
	// tab = get_next_line(fd);
	// printf("%s", tab);
	// free(tab);

/*
	while (1)
	{
		tab = get_next_line(fd);
		if (tab == NULL)
			break ;
		nanosleep(&tim, &tim2);
		printf("%s", tab);
		free(tab);
	}
*/
/*	ret = read(fd, buf, 3);
	buf[ret] = '\0';
	printf("%s, %d 1\n", buf, ret);
	ret = read(fd, buf, 3);
	buf[ret] = '\0';
	printf("%s, %d 2 \n", buf, ret);
	ret = read(fd, buf, 3);
	buf[ret] = '\0';
	printf("%s, %d 3\n", buf, ret);
*/	
	/*
	while (ret)
	{
		buf[ret] = '\0';
		nanosleep(&tim, &tim2);
		printf("%s", buf);
		ret = read(fd, buf, BUFFER_SIZER);
	}*/
	if (close(fd) == -1)
	{
		printf("close failed");
	}
	return (0);
}
