/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:54:43 by knaumov           #+#    #+#             */
/*   Updated: 2018/12/05 21:54:44 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_filler
{
	char		enemy;
	char		player;
	char		**map;
	int			map_x;
	int			map_y;
	char		**piece;
	int			piece_x;
	int			piece_y;
}				t_filler;

int				solver(t_filler *filler);
int				**heatmap(char player, char enemy, char **map);

#endif
