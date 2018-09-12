## Exercise 1

<img src="https://github.com/SelkieAnna/os-course/blob/master/week4/ex1.png" width="250">

Each fork initializes a child process, so for every program run there is one parent and one child process. Each child has a process id that is increased by one regarding its parent.

## Exercise 2

<img src="https://github.com/SelkieAnna/os-course/blob/master/week4/ex2pt1-1.png" width="350">
<img src="https://github.com/SelkieAnna/os-course/blob/master/week4/ex2pt1-2.png" width="400">
<img src="https://github.com/SelkieAnna/os-course/blob/master/week4/ex2pt1-3.png" width="450">

When we have a fork in a loop, every process doubles itself each time the program executes fork. Therefore, the number of processes is counted as 2^(number of forks). Indeed, we have 8 processes at the 3d loop iteration.

<img src="https://github.com/SelkieAnna/os-course/blob/master/week4/ex2pt2-1.png" width="450">
<img src="https://github.com/SelkieAnna/os-course/blob/master/week4/ex2pt2-2.png" width="500">

If we increase the number of loop iterations to 5, the number of processes will be 2^5 = 32.
