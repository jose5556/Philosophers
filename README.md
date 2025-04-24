<h1 align="center"> 
  🍝 Philosophers 
</h1> 

<p align="center"> 
  <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/jose5556/philosophers?color=lightblue" />
  <img alt="Code language" src="https://img.shields.io/github/languages/count/jose5556/philosophers?color=yellow" />
  <img alt="Top language" src="https://img.shields.io/github/languages/top/jose5556/philosophers?color=blue" /> 
  <img alt="Last commit" src="https://img.shields.io/github/last-commit/jose5556/philosophers?color=green" /> 
</p>


# 💡 About the project

Philosophers is a multithreaded probelm solving project.
It simulates the classic Dining Philosophers Problem, a famous example in computer science to illustrate synchronization issues and concurrency control using threads and mutexes.

The main goal of the project is to develop a program where philosophers don’t starve or cause deadlocks while sharing limited resources -> forks.

# 🔍 Overview

Each philosopher:

    Must eat, think, and sleep in a continuous cycle.

    Needs two forks (mutexes) to eat.

    Will die if they don’t eat within a certain time.

    The simulation stops when a philosopher dies or all have eaten a required number of times (optional argument).

This project emphasizes:

    Thread creation and management with pthreads

    Preventing race conditions using mutexes

    Avoiding deadlocks and ensuring fairness

    Accurate timing management using gettimeofday or similar functions

# 🛠️ Usage

### Requirements

The project is written in C and requires the cc compiler.

### Instructions

1. Compiling:

```shell
$ make
```

This will create an executable named philo.

2. Running the program

./philo [number_of_philosophers] [time_to_die] [time_to_eat time_to_sleep] [number_of_times_each_philosopher_must_eat]

Example:

```shell
./philo 5 800 200 200
```

This simulates 5 philosophers, where:

    each must eat within 800ms,

    they take 200ms to eat,

    and 200ms to sleep.

3. Optional argument:

If provided, the simulation ends when all philosophers have eaten that number of times.

# 📌 Notes

- Time is in milliseconds.

- All actions are printed with a timestamp in the format:
[timestamp] [philosopher_id] is eating

- The project must avoid data races and undefined behavior.

- Only one fork per hand, and forks are shared, so mutex usage is critical.
