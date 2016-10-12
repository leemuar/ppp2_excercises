/*
The program ("bulls and cows" game from exercise 12) is a bit tedious because the answer is hard-coded into the
program. Make a version where user can play repeatedely (without
stopping and restarting the program) and each game has a new set of
four digits. You can get four random digits by calling the random number
generator randint(10) from std_lib_facilities.h four times. You will note
that if you run thatprogram repeatedly, it will pick the same sequence of
four digits each time you start the program. To avoid that, ask the user
to enter a number (any number) and call srand(n) where n is called a seed, and
different seeds give different sequences of random numbers
*/