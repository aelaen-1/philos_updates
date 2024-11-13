/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukezi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:57:15 by aboukezi          #+#    #+#             */
/*   Updated: 2024/11/08 12:57:16 by aboukezi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
 #define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/types.h> 
# include <sys/time.h> // timeofday
# include <stdlib.h>
# include <string.h> // memset
# include <stdio.h>
# include <stdbool.h>
# include "colors.h"

struct  args{
    int     nb_of_philos;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     nb_of_meals;
};

// struct  Philosopher{
//     pthread_t thread;
//     int     index;
//     int     id;
//     struct t_fork   *left_fork;
//     struct t_fork   *right_fork;
// };

struct  Philosopher{
    pthread_t thread;
    int     index;
    int     id;
    int     meal_counter;
    pthread_mutex_t *mutex;
    struct Fork   *left_fork;
    struct Fork   *right_fork;
};

typedef struct  Fork{
    int     index;
    pthread_mutex_t mutex;
    int    philo_id;
}   t_fork;

int     init_input(int ac, char **av, struct args *args_out);
long long   ft_strtoll(char *s);


// forks.c

int take_left_fork(struct Philosopher *p);
int take_right_fork(struct Philosopher *p);
void release_forks(struct Philosopher *p);

#endif
