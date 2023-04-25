/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 20:27:29 by marvin            #+#    #+#             */
/*   Updated: 2023/04/25 03:05:07 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stato_lis(int lis, int *temp_lis)
{
    int i;

    i = -1;
    printf("%d\n", lis);
    while (++i < lis)
    {
        printf("%d ", temp_lis[i]);
    }
    printf("\n");
}

void    bigger_than(int **temp_lis, int lis, int c)
{
    int n;

    temp_lis[lis] = malloc((lis + 1) * sizeof(int));
    n = -1;
    while (++n < lis)
        temp_lis[lis][n] = temp_lis[lis - 1][n];
    temp_lis[lis][n] = c;
}

void    lower_than(int **temp_lis, int lis, int c)
{
    int n;
    int z;

    n = -1;
    while (++n < lis)
    {
        if (c < temp_lis[n][n])
        {
            z = -1;
            while (++z < n)
                temp_lis[n][z] = temp_lis[n - 1][z];
            temp_lis[n][n] = c;
            break ;
        }
    }
}

void    add_to_lis(t_gen *gen, int **temp_lis, int n)
{
    int c;
    int lis;
    int i;
    int s;

    lis = 0;
    i = 1;
    temp_lis[lis] = malloc((lis + 1) * sizeof(int));
    s = gen->a[gen->msize - 1 - n];
    *temp_lis[lis++] = gen->a[gen->msize - 1 - n];
    while (++i <= gen->msize)
    {
        if ((i + n) > gen->msize)
            n -= gen->msize;
        c = gen->a[gen->msize - i - n];
        if (c < s)
            c += gen->msize;
        if (c > temp_lis[lis - 1][lis - 1])
            bigger_than(temp_lis, lis++, c);
        else
            lower_than(temp_lis, lis, c);
    }
    i = 0;
    while (i < lis - 1)
        free(temp_lis[i++]);
    if (lis > gen->len_lis)
    {
        if (gen->len_lis != 0)
              free(gen->lis);
        gen->len_lis = lis;
        gen->lis = temp_lis[i];
    }
    else
        free(temp_lis[i]);
}

void    lis(t_gen *gen)
{
    int **temp_lis;
    int i;

    // prova(gen);
    gen->len_lis = 0;
    temp_lis = malloc(gen->msize * sizeof(int *));
    i = -1;
    while (++i < gen->msize)
    {
        add_to_lis(gen, temp_lis, i);
    }
    i = -1;
    while (++i < gen->len_lis)
    {
        if (gen->lis[i] > gen->msize)
            gen->lis[i] -= gen->msize;
    }
    free(temp_lis);
}
