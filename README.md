# Philosophers [![build](https://github.com/AdrianWR/philosophers/actions/workflows/build.yml/badge.svg)](https://github.com/AdrianWR/philosophers/actions/workflows/build.yml) [![norminette](https://github.com/AdrianWR/philosophers/actions/workflows/linter.yml/badge.svg)](https://github.com/AdrianWR/philosophers/actions/workflows/linter.yml)

> _Economics is the science which studies human behaviour as a relationship between ends and scarce means which have alternative uses._

This is my brief take on the famous dining philosophers problem, proposed by Dijkstra in 1965. In this problem, we have a _n_ number of philosophers sitting around a circular table. The table has _n_ forks, and each philosophers disposes of a left and a right fork to use. At the center of the table lies a bowl with an unlimited supply of spaghetti, which is consumed by the philosophers with two forks.

Philosophers may eat, sleep or think before the next meal. As a philosopher must eat with two forks, there may arise situations where a philosopher must wait to take the fork shared by them neighbours. If a philosophers takes too much time before eating, they die. The aim of the problem is to create such an algorithm that lets all philosophers to live, allowing them to perform theis tasks undefinetely.

## The Problem

As unusual and alegorical the dining philosophers appears to be, the fact is that it help us to think around many problems regarding computers. We often revolve around situations where processes must access shared resources, like CPU, memory or connections from a pool. The **resource starvation** is real, and we need to take care of our systems to avoid major failovers and breakdowns.

Another situation that may arise, maybe even more struggling, is the persistence of **deadlocks**, which blocks the overall system to progress. In this project, the use of **mutual exclusion** resources is essential to avoid deadlock states.

## Compilation

To compile the dining philosophers binary, you must have installed `make` and `clang`on your machine. Then, run the following commands:

```shell
  git clone https://github.com/AdrianWR/philosophers
  cd philo
  make
```

## Useful Links

 - [Dining Philosophers](https://en.wikipedia.org/wiki/Dining_philosophers_problem)

## License

[MIT](https://choosealicense.com/licenses/mit/)
