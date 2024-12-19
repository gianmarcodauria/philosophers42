#include "philo_struct.h"

void    philos_init(t_table *table)
{
    int i;

    i = 0;
    while (i < table->n_phil)
    {
        pthread_create(&table->phil[i].thread, NULL, &philo_rout, (void *)&table->phil[i]);
        i++;
    }
    pthread_create(&table->monitor_id, NULL, &is_monitoring, (void *)table);
    i = 0;
    while (i < table->n_phil)
    {
        pthread_join(table->phil[i].thread, NULL);
        i++;
    }
    pthread_join(table->monitor_id, NULL);
}
