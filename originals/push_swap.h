/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:49:35 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/24 18:06:11 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

int		main(int argc, char **argv);
int		*replacenumbers(int	*a, int size);
int		correct_order(int *a, int msize);
int		rcorrect_order(int *a, int msize);
void	prova(int *a, int *b, int msize, int x);

int		ft_swap(int *a, int size);
int		ft_biswap(int *a, int asize, int *b, int bsize);
int		push(int *a, int asize, int *b, int bsize);

int		ft_rotate(int *a, int size);
int		ft_birotate(int *a, int asize, int *b, int bsize);
int		ft_rrotate(int *a, int size);
int		ft_birrotate(int *a, int asize, int *b, int bsize);

int		runwind(int *a, int *asize, int *b, int *bsize);
void	push_swap(int *a, int *b, int asize);
int		unwind(int *a, int *asize, int *b, int *bsize);
int		sunwind(int *a, int *asize, int *b, int *bsize);
int		ft_rewind(int *a, int *asize, int *b, int *bsize);


#endif
