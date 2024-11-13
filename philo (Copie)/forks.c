#include "include/philo.h"

int take_left_fork(struct Philosopher *p)
{
    if (!pthread_mutex_lock(&(p->left_fork->mutex))) // returns 0 for success
    {
        p->left_fork->philo_id = p->id;
        pthread_mutex_unlock(&(p->left_fork->mutex));
        return (1);
    }
    else
        return (0);
}

int take_right_fork(struct Philosopher *p)
{
    if (!pthread_mutex_lock(&(p->right_fork->mutex)))
    {
        p->right_fork->philo_id = p->id;
        pthread_mutex_unlock(&(p->right_fork->mutex));
        return (1);
    }
    else
        return (0);
}

void release_forks(struct Philosopher *p)
{
    p->left_fork->philo_id = -1;
    p->right_fork->philo_id = -1;
}