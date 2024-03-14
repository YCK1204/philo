This project was implemented multi thread and command pattern of dining philosopher problem.



each philosopher is a thread and has a routine (eat -> sleep -> think -> eat -> ...)

eat and sleep is spend time.
If the time spent eating and sleeping exceeds time_to_die, "die" is printed, and the program terminates.

Program Usage :
run make
./philo philoOfNumber time_to_die time_to_eat time_to_sleep (optional)must_eat_cnt

arguments must greater than 1.

keep in mind philosophers is so lazy.
