#include "philo_struct.h"

void    *philo_rout(void *to_cast)
{
    t_philos    *philos;
    philos = (t_philos *)to_cast;

    while ((dead_checker(philos->table) == 0) && (food_checker(philos->table) == 0))
    {
        print_all("is thinking", philos);
        usleep(philos->table->time_for_sleep * 1000);
        print_all("is sleeping", philos);
        usleep(philos->table->time_for_sleep * 1000);
        check_forks(philos);
        pthread_mutex_lock(&philos->is_eating);
        print_all("is eating", philos);
        philos->check_time_eat = taketime();
        philos->input_counter++;
        usleep(philos->table->time_for_eat * 1000);
        pthread_mutex_unlock(&philos->is_eating);
        pthread_mutex_unlock(philos->right_fork);
        print_all("RIGHT UNLOCK, FORK DROPPED", philos);
        pthread_mutex_unlock(philos->left_fork);
        print_all("LEFT UNLOCK, FORK DROPPED", philos);
    }
    return (NULL);
}

int dead_checker(t_table *table)
{
    pthread_mutex_lock(&table->dead_checker);
    if (table->is_dead == 0)
    {
        pthread_mutex_unlock(&table->dead_checker);
        return (0);
    }
    pthread_mutex_unlock(&table->dead_checker);
    return (1);
}

int food_checker(t_table *table)
{
    pthread_mutex_lock(&table->meal_checker);
    if (table->enough_meal == 0)
    {
        pthread_mutex_unlock(&table->meal_checker);
        return (0);
    }
    pthread_mutex_unlock(&table->meal_checker);
    return (1);
}


void    check_forks(t_philos *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->right_fork);
        print_all("RIGHT LOCK", philo);
        pthread_mutex_lock(philo->left_fork);
        print_all("LEFT LOCK", philo);
    }
    else
    {
        pthread_mutex_lock(philo->left_fork);
        print_all("LEFT LOCK", philo);
        pthread_mutex_lock(philo->right_fork);
        print_all("RIGHT LOCK", philo);
    }
}