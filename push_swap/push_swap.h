/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:49:35 by vfaramel          #+#    #+#             */
/*   Updated: 2023/03/07 14:47:47 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct g_list
{
	int	*a;
	int	*b;
	int	bsize;
	int	asize;
	int	msize;
	int	x;
}	t_gen;

int		main(int argc, char **argv);
int		*replacenumbers(int	*a, int size);
void	prova(t_gen *gen);

int		ft_swapa(int *a, int size);
int		ft_swapb(int *a, int size);
int		ft_biswap(int *a, int asize, int *b, int bsize);
int		pusha(int *a, int asize, int *b, int bsize);
int		pushb(int *a, int asize, int *b, int bsize);
int		ft_rotatea(int *a, int size);
int		ft_rotateb(int *a, int size);
int		ft_birotate(t_gen *gen);
int		ft_rrotatea(int *a, int size);
int		ft_rrotateb(int *a, int size);
int		ft_birrotate(t_gen *gen);

void	centera(t_gen *gen);
void	runwind(t_gen *gen);
void	push_swap(t_gen *gen);
int		unwind(t_gen *gen);
int		sunwind(t_gen *gen);
int		ft_rewind(t_gen *gen);

void	quickpath(t_gen *gen);
int		tempcount(int i, int n, int asize, int bsize);
int		findspace(int *a, int asize, int b);
int		maxint(int a, int b);
void	putplace(t_gen *gen, int i);
void	quickpath2(t_gen *gen, int *count, int *w, int d);

#endif
