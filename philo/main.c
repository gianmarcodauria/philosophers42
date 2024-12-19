#include "philo_struct.h"

int main(int argc, char **argv)
{
    t_table main;

    def_struct_table(&main, argc, argv);
    philos_init(&main);
    // if ((atoi_for_check(argc, argv) == 0) && (atoi_for_check(main.time_before_death) == 0)
    //     && (atoi_for_check(main.time_for_eat) == 0) && (atoi_for_check(main.time_for_sleep) == 0))
    //     {
    //destroy_forks(&main);
    // }
}
