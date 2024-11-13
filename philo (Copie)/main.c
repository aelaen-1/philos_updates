/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaen <aelaen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:56:56 by aboukezi          #+#    #+#             */
/*   Updated: 2024/11/14 00:35:44 by aelaen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

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
                if ((myself->left_fork->philo_id == myself->id) && (myself->right_fork->philo_id == myself->id))
                {
                    myself->meal_counter += 1;
                    printf("Philosopher %d is eating, nb de repas = %d / 3 \n", myself->id, myself->meal_counter);
                    release_forks(myself);
                }
            }
            else
                release_left_fork(myself);
        }
        else
            sleep(1);
    }
    return (0);
}

int main (int ac, char **av)
{
    int i = 0;
    struct Philosopher  *philos;
    t_fork        *forks;
    struct args  input;
    
    if (!init_input(ac, av, &input))
        return (0);
    philos = malloc(sizeof(struct Philosopher) * input.nb_of_philos);
    forks = malloc(sizeof(struct t_fork *) * input.nb_of_philos);
    //init Fork struct
    while(i < input.nb_of_philos)
    {
        forks[i].index = i;
        pthread_mutex_init(&forks[i].mutex, NULL);
        forks[i].philo_id = -1;
        i++;
    }
    // init Philosopher struct
    i = 0;
    while(i < input.nb_of_philos)
    {
        philos[i].index = i;
        philos[i].id = i + 1;
        philos[i].left_fork = &forks[i];
        philos[i].right_fork = &forks[(i + 1) % input.nb_of_philos];
        philos[i].meal_counter = 0;
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
