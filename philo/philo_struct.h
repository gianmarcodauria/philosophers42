#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philos t_philos;

typedef struct s_table
{
    t_philos    *phil;
    int         n_phil;
    int         is_dead;
    int         enough_meal;
    int         time_before_death;
    int         time_for_eat;
    int         time_for_sleep;
    int         eat_counter;
    size_t      startime;
    pthread_mutex_t *fork;
    pthread_mutex_t dead_checker;
    pthread_mutex_t meal_checker;
    pthread_mutex_t printf;
    pthread_t       monitor_id;

} t_table;

typedef struct s_philos
{
    int id;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    pthread_mutex_t is_eating;
    pthread_t           thread;
    int             input_counter;
    size_t          check_time_eat;
    t_table          *table;

} t_philos;

int main(int argc, char **argv);
int ft_isdigit(int c);
int ft_atoi(const char *str);
int atoi_for_check(const char *str);
void    def_struct_table(t_table *main, int argc, char **argv);
void    def_struct_philo(t_table *table);
int checks(int argc, char **argv);
void initialize_forks(t_table *table);
void destroy_forks(t_table *table);
size_t taketime();
int enough_meal(t_table *table);
int food_checker(t_table *table);
int is_it_dead(t_table *table);
int dead_checker(t_table *table);
void    *philo_rout(void *to_cast);
void    *is_monitoring(void *to_cast);
void    philos_init(t_table *table);
void    print_all(char *str, t_philos *phil);
void    check_forks(t_philos *philo);
