/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:56:56 by aboukezi          #+#    #+#             */
/*   Updated: 2024/11/08 12:56:58 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

//number_of_philosophers time_to_die time_to_eat time_to_sleep [nb of times each philo must eat]

// static void *action(void *i)
// {
        // int     n; // doesnt work with FLAGS
        // n = *((int *)i); //core dumped
//     printf (BBLU "Je suis le philosophe " UMAG "%d\n" reset, n);
// }

// int main (int ac, char **av)
// {
//     int     err;
//     pthread_t   philo[30];
//     int     i;
    
//     i = 0;
//     err = init_input(ac, av);
//     if (err)
//         return (0);
//     while (i < 30)
//     {
//         pthread_create(&philo[i], NULL, action, (void *)i);
//         pthread_join(philo[i], NULL);
//         i++;
//     }
    
//     return (0);
// }
struct philo{
    pthread_t thread;
    int id;
    int *ptrx;
    pthread_mutex_t     *mutex;
};

void    *action(void *p)
{
    struct philo *myself = (struct philo *)p;
    
    pthread_mutex_lock(myself->mutex);
    *(myself->ptrx) = *(myself->ptrx )+ 1;
    printf("%d : %d\n", myself->id, *(myself->ptrx));
    // printf("Philosophe %d :  Init counter = %d\n", myself->id, counter);
    // sleep(1);
    // int newcounter = counter+1;
    // printf("Philosophe %d :  Init counter = %d, New counter = %d\n", myself->id, counter, newcounter);
    pthread_mutex_unlock(myself->mutex);
    pthread_exit(0);
}


int main (int ac, char **av)
{
    int     err;
    struct philo *philos; // philo[ft_strtoll(av[1])]
    int     i;
    t_args  input;
    int x = 0;
    pthread_mutex_t     mtx;
    pthread_mutex_init(&mtx, NULL);
    i = 0;
    err = init_input(ac, av, &input);
    if (err)
        return (0);
    philos = malloc(sizeof(struct philo) * input.nb_of_philos);
    while(i < input.nb_of_philos)
    {
        philos[i].id = i + 1;
        philos[i].ptrx = &x;
        philos[i].mutex = &mtx;
        pthread_create(&philos[i].thread, NULL, action,  &philos[i]);
        i++;
    }
    i = 0;
    while(i < input.nb_of_philos)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
    return (0);
}


// int main (int ac, char **av)
// {
//     int     err;
//     pthread_t   philo[3]; // philo[ft_strtoll(av[1])]
//     int     i;
//     int     *ids;
//     t_args  input;
    
//     i = 0;
//     ids = malloc(sizeof(int) * 3);
//     err = init_input(ac, av, &input);
//     if (err)
//         return (0);

//     while(i < 3)
//     {
//         pthread_create(&philo[i], NULL, action,  &i);
//         i++;
//     }
//     i = 0;
//     while(i < 3)
//     {
//         pthread_join(philo[i], NULL);
//         i++;
//     }
//     return (0);
// }