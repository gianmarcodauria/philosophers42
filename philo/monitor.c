#include "philo_struct.h"

int is_it_dead(t_table *table)
{
    int i;

    i = 0;
    while(i < table->n_phil)
    {
        pthread_mutex_lock(&table->phil[i].is_eating);
        if (taketime() - table->phil[i].check_time_eat > (size_t) table->time_before_death)
        {
            pthread_mutex_lock(&table->dead_checker);
            pthread_mutex_unlock(&table->phil[i].is_eating);
            pthread_mutex_unlock(&table->dead_checker);
            print_all("E' MORTO\n", &table->phil[i]);
            table->is_dead = 1;
            break;
        }
        pthread_mutex_unlock(&table->phil[i].is_eating);
        i++;
    }
    return (table->is_dead);
}

int enough_meal(t_table *table)
{
    int i;

    i = 0;
    while (i < table->n_phil)
    {
        pthread_mutex_lock(&table->phil[i].is_eating);
        if (table->phil[i].input_counter < table->eat_counter)
        {
            pthread_mutex_unlock(&table->phil[i].is_eating);
            return (0);
        }
        pthread_mutex_unlock(&table->phil[i].is_eating);
        i++;
    }
    print_all("SONO PIENI", &table->phil[0]);
    pthread_mutex_lock(&table->meal_checker);
    table->enough_meal = 1;
    pthread_mutex_unlock(&table->meal_checker);
    return (1);
}

void    *is_monitoring(void *to_cast)
{
    int i;
    int checks;

    i = 0;
    checks = 0;
    t_table    *table;
    table = (t_table *)to_cast;
    while (1)
    {
        if (table->eat_counter < 0)
            checks = is_it_dead(table);
        else
            checks = is_it_dead(table) + enough_meal(table);
        if (checks > 0)
            break;
        i++;
        if (i >= table->n_phil )
            i = 0;
    }
    usleep(500);
    return (NULL);
}

void    print_all(char *str, t_philos *phil)
{
    size_t  time;

    pthread_mutex_lock(&phil->table->printf);
    time = taketime() - phil->table->startime;
    if (dead_checker(phil->table) == 0)
        printf("%ld %d %s\n", time, phil->id, str);
    pthread_mutex_unlock(&phil->table->printf);
}
