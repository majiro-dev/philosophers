# Philosophers

This project is a simulation of the famous dining philosophers problem developed as part of the curriculum at the **42** programming school.

It aims to demonstrate synchronization issues that can arise in concurrent programming. The goal is to create a program that models a group of philosophers sitting at a round table and taking turns to eat, think, or sleep. The simulation stops when a philosopher dies of starvation, or all philosophers have eaten enogh.

The following rules govern the behavior of the philosophers:
- They alternate between eating, thinking, and sleeping.
- While eating, a philosopher cannot think or sleep.
- While thinking, a philosopher cannot eat or sleep.
- While sleeping, a philosopher cannot eat or think.
- Each philosopher requires two forks to eat, one from their left and one from their right.

The simulation accepts the following parameters:
- `number_of_philosophers`: The total number of philosophers sitting at the table. It also determines the number of forks available.
- `time_to_die` (in milliseconds): If a philosopher doesn't start eating within this time after their last meal or the beginning of the simulation, they die.
- `time_to_eat` (in milliseconds): The time it takes for a philosopher to eat while holding two forks.
- `time_to_sleep` (in milliseconds): The time a philosopher spends sleeping.

Optionally, you can provide `number_of_times_each_philosopher_must_eat`, which specifies the number of times each philosopher must eat before the simulation stops. If this parameter is not provided, the simulation stops when a philosopher dies.

## Global Rules

- Global variables are not allowed.
- The program should take the required arguments mentioned above.
- Displayed state changes of a philosopher must follow a specific format, including the timestamp and the philosopher's number.
- Messages announcing a philosopher's death should be displayed no more than 10 ms after the actual death.
- Each philosopher should be represented by a separate thread.
- The table should have one fork placed between each pair of philosophers. If there is only one philosopher, there should be only one fork.
- The forks' state should be protected using mutexes to prevent duplication.
