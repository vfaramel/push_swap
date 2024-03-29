/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:49:35 by vfaramel          #+#    #+#             */
/*   Updated: 2023/04/25 01:22:10 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct g_list
{
	int		*a;
	int		*b;
	int		bsize;
	int		asize;
	int		msize;
	int		*lis;
	int		len_lis;
	int		aug;
	int		x;
	char	***c_base;
	int		*base;
	int		step;
}	t_gen;

int		main(int argc, char **argv);
void	quit(t_gen *gen);
void	replacenumbers(t_gen *gen);
void	prova(t_gen *gen);
int		toobig(char *str);
int		ft_isnumeric(char *s);
void	original_stack(char **argv, t_gen *gen, int argc);
void	make_base(t_gen *gen, int argc);
size_t	ft_strlen1(char *c);
void    lis(t_gen *gen);
int		abs_num(int x);

int		ft_swapa(t_gen *gen);
int		ft_swapb(t_gen *gen);
int		ft_biswap(t_gen *gen);
int		pusha(t_gen *gen);
int		pushb(t_gen *gen);
int		ft_rotatea(t_gen *gen);
int		ft_rotateb(t_gen *gen);
int		ft_birotate(t_gen *gen);
int		ft_rrotatea(t_gen *gen);
int		ft_rrotateb(t_gen *gen);
int		ft_birrotate(t_gen *gen);

void	centera(t_gen *gen);
void	runwind(t_gen *gen);
void	push_swap(t_gen *gen);

void	quickpath(t_gen *gen);
int		tempcount(int i, int n, int asize, int bsize);
int		findspace(int *a, int asize, int b);
int		maxint(int a, int b);
void	putplace(t_gen *gen, int i);
void	quickpath2(t_gen *gen, int *count, int *w, int d);

#endif
