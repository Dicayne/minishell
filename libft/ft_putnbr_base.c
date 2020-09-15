/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 08:31:42 by hthomas           #+#    #+#             */
/*   Updated: 2020/06/07 09:54:37 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_2floatitivenbr_base(unsigned int nbr, char *base, int size)
{
	if (nbr != 0)
	{
		ft_put_2floatitivenbr_base(nbr / size, base, size);
		ft_putchar(base[nbr % size]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;

	size = 0;
	if (check_base(base))
	{
		while (base[size])
			size++;
		if (nbr == 0)
			ft_putchar(base[0]);
		if (nbr < 0)
		{
			ft_putchar('-');
			ft_put_2floatitivenbr_base(-1 * nbr, base, size);
		}
		else
			ft_put_2floatitivenbr_base(nbr, base, size);
	}
}
