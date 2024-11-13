#include "include/philo.h"

int take_left_fork(struct Philosopher *p)
{
    if (!pthread_mutex_lock(&(p->left_fork->mutex))) // returns 0 for success
    {
        printf("Philosophe %d active mutex fourchette gauche n°%d\n", p->id, p->left_fork->index);
        p->left_fork->philo_id = p->id;
        pthread_mutex_unlock(&(p->left_fork->mutex));
        printf("Philosophe %d désactive mutex fourchette gauche n°%d\n", p->id, p->left_fork->index);
        return (1);
    }
    else
        return (0);
}

int take_right_fork(struct Philosopher *p)
{
    if (!pthread_mutex_lock(&(p->right_fork->mutex)))
    {
        printf("Philosophe %d active mutex fork droite n_°%d\n", p->id, p->right_fork->index);
        p->right_fork->philo_id = p->id;
        pthread_mutex_unlock(&(p->right_fork->mutex));
        printf("Philosophe %d désactive mutex fork droite n°%d\n", p->id, p->right_fork->index);
        return (1);
    }
    else
        return (0);
}

void release_left_fork(struct Philosopher *p)
{
    pthread_mutex_lock(&(p->left_fork->mutex));
    p->left_fork->philo_id = -1;
    pthread_mutex_unlock(&(p->left_fork->mutex));
}

void release_right_fork(struct Philosopher *p)
{
    pthread_mutex_lock(&(p->right_fork->mutex));
    p->right_fork->philo_id = -1;
    pthread_mutex_unlock(&(p->right_fork->mutex));
}

void release_forks(struct Philosopher *p)
{
    release_left_fork(p);
    release_right_fork(p);
    printf("Philosopher %d released forks\n", p->id);
}