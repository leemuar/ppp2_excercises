##Chapter 5

### Exercise 13

randint() generates the same number sequence no matter what seed you set 
with srand()
srand() does not affect randint(), it is probably a mistake brought to 
the exercise text from previous edition of the book. I had to write my 
own function for rng using C's rand() to get this exercise done.

##Chapter 6

The mandatory semicolon (;) after class definition looks very confusing.
No other curly brace block (if, switch, while, for, function) had it after closing curly brace (}).
There is no explanation why this block requires it.