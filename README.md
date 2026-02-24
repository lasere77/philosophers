*This project has been created as part of the 42 curriculum by [mcolin](https://profile-v3.intra.42.fr/users/mcolin)*

# PROJECT [42](https://42.fr/en/homepage/) : Philosophers 📙

This project will allow you to explore the threads.

## 📖 Description [**Philosophers**](https://cdn.intra.42.fr/pdf/pdf/198989/en.subject.pdf)

the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them. 

## 🧠 what i have learned

- Undertsand the mechanics of threads.

- How to make a multithreader program

- understand data sharing between threads via mutex

## 🌳 Tree

<details>
<summary><h2>show</h2></summary>

```txt
.
|-- Makefile
|-- README.md
|-- TO_DO
|-- compile_commands.json
|-- includes
|   |-- parsing_utils.h
|   |-- philo.h
|   |-- philo_routines.h
|   |-- routines_utils.h
|   `-- utils.h
|-- philo
`-- srcs
    |-- main.c
    |-- philo.c
    |-- philo_routines.c
    `-- utils
        |-- parsing_utils.c
        |-- routines_utils.c
        `-- utils.c
```
</details>

## 📌 Instructions

We use the folowing flags to compile the project: cc -MP -MMD -Wall -Werror -Wextra -g

- make (doing the mandatory project Philosophers).
- make clean (clean objects directories an files).
- make fclean (clean all).
- make re (clean all and remake).

## 🛠️ Commands

### How to run it

arugments:

the firt number_of_philosophers:
(The number of philosophers and also the number
of forks.)

the second time_to_die: 
(If a philosopher has not started eating within
time_to_die milliseconds since the start of their last meal or the start of the
simulation, they die.)

the third time_to_eat:
(The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.)

the fourth time_to_sleep:
(The time a philosopher will spend sleeping.)

the last (optional argument) number_of_times_each_philosopher_must_eat:
( If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.)

The program should be executed as follows:
```txt
./philo 4 410 200 200 10
```
In this case, the program should stop when the philosophers have eaten 10 times.

<details>
<summary><h2>Valgrind</h2></summary>

You can use these valgrind options to check data-race:

```txt
valgrind --tool=helgrind
```

</details>

## ℹ️ Ressources

[man] (https://man7.org/linux/man-pages/man1/man.1.html)