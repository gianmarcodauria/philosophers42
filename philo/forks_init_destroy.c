#include "philo_struct.h"

void initialize_forks(t_table *table)
{
    int i;

    i = 0;
    table->fork = (pthread_mutex_t *) malloc(table->n_phil * sizeof(pthread_mutex_t));
    if (!table->fork)
    {
        printf("ERROR malloc failed\n");
        exit(EXIT_FAILURE);
    }
    while (i < table->n_phil)
    {
        pthread_mutex_init(&table->fork[i], NULL);
        i++;
    }
}

void destroy_forks(t_table *table)
{
    int i;

    i = 0;
    while (i < table->n_phil)
    {
        pthread_mutex_destroy(&table->fork[i]);
        i++;
    }
    free(table->fork);
}
