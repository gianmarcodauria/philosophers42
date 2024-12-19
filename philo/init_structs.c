#include "philo_struct.h"

void def_struct_table(t_table *table, int argc, char **argv)
{
    table->n_phil = ft_atoi(argv[1]);
    table->time_before_death = ft_atoi(argv[2]);
    table->time_for_eat = ft_atoi(argv[3]);
    table->time_for_sleep = ft_atoi(argv[4]);
    table->startime = taketime();
    table->is_dead = 0;
    table->enough_meal = 0;
    if (argc == 6)
        table->eat_counter = ft_atoi(argv[5]);
    else
        table->eat_counter = -1;
    pthread_mutex_init(&table->dead_checker, NULL);
    pthread_mutex_init(&table->meal_checker, NULL);
    pthread_mutex_init(&table->printf, NULL);
    initialize_forks(table);
    def_struct_philo(table);
}

void def_struct_philo(t_table *table)
{
    int i;

    i = 0;
    table->phil = (t_philos *) malloc(table->n_phil * sizeof(t_philos));
    if (!table->phil)
    {
        printf("ERROR malloc failed\n");
        exit(EXIT_FAILURE);
    }
    while (i < table->n_phil)
    {
        table->phil[i].id = i + 1;
        table->phil[i].right_fork = &table->fork[i];
        if (i == table->n_phil)
            table->phil[i].left_fork = 0;
        else
            table->phil[i].left_fork = &table->fork[i + 1];
        table->phil[i].input_counter = 0;
        table->phil[i].check_time_eat = table->startime;
        table->phil[i].table = table;
        pthread_mutex_init(&table->phil[i].is_eating, NULL);
        i++;
    }
}
