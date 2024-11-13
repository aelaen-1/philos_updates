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

// struct  Philosopher{
//     pthread_t thread;
//     int     index;
//     int     id;
//     int     meal_counter;
//     pthread_mutex_t *mutex;
//     t_fork   *left_fork;
//     t_fork   *right_fork;
// };

void    *start_living(void *p)
{
    struct Philosopher *myself = (struct Philosopher *)p;
    //eat
    while(myself->meal_counter < 3)
    {
        if (take_left_fork(myself))
        {
            if (take_right_fork(myself))
            {
                printf("Philosopher %d is eating\n", myself->id);
                release_forks(p);
                myself->meal_counter += 1;
            }
        }
    }
}

int main (int ac, char **av)
{
    int i = 0;
    struct args  input;
    struct Philosopher  *philos;
    t_fork        *forks;
    pthread_mutex_t     *mutex_array;
    
    if (init_input(ac, av, &input))
        return (0);
    philos = malloc(sizeof(struct Philosopher) * input.nb_of_philos);
    forks = malloc(sizeof(struct t_fork *) * input.nb_of_philos);
    mutex_array = (malloc(sizeof(pthread_mutex_t) * input.nb_of_philos));
    //init Fork struct
    while(i < input.nb_of_philos)
    {
        forks[i].index = (i % (input.nb_of_philos - 1) + 1);
        forks[i].mutex = mutex_array[i];
        i++;
    }

    // init Philos struct
    i = 0;
    while(i < input.nb_of_philos)
    {
        philos[i].index = i;
        philos[i].id = i + 1;
        philos[i].left_fork = &forks[i];
        philos[i].right_fork = &forks[i % input.nb_of_philos];
        pthread_create(&philos[i].thread, NULL, start_living, &philos[i]);
        i++;
    }
    i = 0;
    while(i < input.nb_of_philos)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
    return(0);
}
