/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:55:24 by amonier           #+#    #+#             */
/*   Updated: 2023/05/16 18:05:29 by amonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#define MAXXX_MAX 18446744073709551615UL

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*str;
	size_t	size;

	if (elementSize >= MAXXX_MAX || elementCount >= MAXXX_MAX)
		return (NULL);
	size = elementCount * elementSize;
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

/*
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_NUMBER 10

int	main(void) {
    
    int i;
    int * pointer = (int *) ft_calloc( INT_NUMBER, sizeof(int) );
   		Un petit test sur le bon fonctionnement de calloc
   assert( pointer != NULL );

     Le dernier élément du tableau ne sera pas affecté par la
     boucle mais n'oubliez pas que calloc initialise de toute 
     façon à 0 chaque octet. 
    for ( i=0; i<INT_NUMBER-2; i++ ) {
        pointer[i] = i;
    }

     On affiche le contenu du tableau d'entier
     Ce qui donne : 0 1 2 3 4 5 6 7 8 0 
		for (i=0; i<INT_NUMBER; i++ ) {
        printf( "%d ", pointer[i] );
    }
    printf( "\n" );
    On libère le bloc de mémoire alloué dynamiquement
    free( pointer );

    return (0);
}*/
