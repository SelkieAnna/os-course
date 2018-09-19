## Exercise 1

Basic program - ex1.c
Modified program - ex1-1.c

<img src="https://github.com/SelkieAnna/os-course/blob/master/week5/ex1.png" width="250">

The threads print their messages in an arbitrary order, if they do not have special conditions (pthread_join), because it's up to the scheduler to decide their process time.

<img src="https://github.com/SelkieAnna/os-course/blob/master/week5/ex1-1.png" width="250">

Now, when the program waits for the running thread's termination before initializing the new one, the output is properly ordered.

## Exercise 2

Basic file updating script - ex2.sh
Script that starts two instances of ex2.sh and then stops them in some time - ex2-manifest-time.sh
Modified file updating script - ex2-1.sh
Script that starts two instances of ex2-1.sh and then stops them in some time - ex2-manif-1.sh

<img src="https://github.com/SelkieAnna/os-course/blob/master/week5/ex2.png" width="350">
<img src="https://github.com/SelkieAnna/os-course/blob/master/week5/ex2%2B.png" width="350">

As we see from the output, the time before the race condition isn't constant and depends on external conditions.

<img src="https://github.com/SelkieAnna/os-course/blob/master/week5/ex2-1.png" width="350">

Now, when we prevented concurrent edit of the file, the progaram is working properly.

## Exercise 3

Program - ex3.c

<img src="https://github.com/SelkieAnna/os-course/blob/master/week5/ex3-1.png" width="650">
<img src="https://github.com/SelkieAnna/os-course/blob/master/week5/ex3-2.png" width="650">
<img src="https://github.com/SelkieAnna/os-course/blob/master/week5/ex3-3.png" width="650">

From the output we see that the fatal race condition occurs each time the program is run, but it occurs not as quickly as just a race condition.
