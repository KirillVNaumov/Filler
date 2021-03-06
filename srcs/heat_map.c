/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:01:39 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/05 22:06:04 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		**create_arr(char player, char enemy, char **map)
{
	int	i;
	int	**res;
	int	j;
	int	count_i;

	count_i = 0;
	while (map[count_i])
		++count_i;
	res = (int **)malloc(sizeof(int *) * (count_i + 1));
	i = -1;
	while (++i < count_i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((int)ft_strlen(map[0]) + 1));
		res[i][(int)ft_strlen(map[0])] = 0;
		j = -1;
		while (++j < (int)ft_strlen(map[0]))
			if (map[i][j] == enemy || map[i][j] == enemy + 32)
				res[i][j] = 1;
			else if (map[i][j] == player || map[i][j] == player + 32)
				res[i][j] = -2;
			else
				res[i][j] = -1;
	}
	res[count_i] = 0;
	return (res);
}

int		check_sides(int **res, int i, int j, int count)
{
	if (res[i][j + 1] && res[i][j + 1] == count)
		return (1);
	else if (j != 0 && res[i][j - 1] && res[i][j - 1] == count)
		return (1);
	if (i != 0)
	{
		if (j != 0 && i != 0 && res[i - 1][j - 1] && res[i - 1][j - 1] == count)
			return (1);
		else if (i != 0 && res[i - 1][j] && res[i - 1][j] == count)
			return (1);
		else if (i != 0 && res[i - 1][j + 1] && res[i - 1][j + 1] == count)
			return (1);
	}
	if (res[i + 1])
	{
		if (j != 0 && res[i + 1][j - 1] && res[i + 1][j - 1] == count)
			return (1);
		else if (res[i + 1][j] && res[i + 1][j] == count)
			return (1);
		else if (res[i + 1][j + 1] && res[i + 1][j + 1] == count)
			return (1);
	}
	return (0);
}

int		fill_heatmap(int **res, int count)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (res[i][j] == -1)
				if (check_sides(res, i, j, count) == 1)
				{
					res[i][j] = count + 1;
					check = 1;
				}
			++j;
		}
		++i;
	}
	return (check);
}

int		**heatmap(char player, char enemy, char **map)
{
	int	**res;
	int	count;

	res = create_arr(player, enemy, map);
	count = 1;
	while (fill_heatmap(res, count) == 1)
		++count;
	return (res);
}
