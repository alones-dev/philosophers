# **🍝 Philosophers**

Welcome to the **Philosophers** project! 🧠✨  
In this project, we dive into the fascinating world of **threads** and **mutexes**, where we simulate the famous **dining philosophers problem**. It's a great exercise for understanding how to handle concurrency and synchronization in C. Get ready to learn about **multithreading** and how to manage shared resources efficiently!

## 🎯 **Project Overview**

**Philosophers** is all about simulating a dinner where philosophers sit at a table and think and eat. But here’s the catch: each philosopher needs two forks to eat, and they must share the forks with their neighbors! The goal of the project is to implement an algorithm that models this scenario using **threads** and **mutexes** to avoid deadlocks and ensure that everyone gets their chance to eat.

This is a great challenge to help you understand **thread synchronization**, **deadlock prevention**, and **resource sharing** in a multi-threaded environment.

## 🛠️ Usage
**1. Clone the repository**
```
git clone https://github.com/alones-dev/philosophers.git
```
**2. Compile the project**
```
cd philo
make
```
**3. Enjoy**

Use this command to start the simulation 
```
./philo amount_of_philo time_to_die time_to_eat time_to_sleep [optional : amount_of_eating]
```
like this
```
./philo 5 800 200 200 7
```
