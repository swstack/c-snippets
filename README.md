# C learning repo

Many of these exercises are taken from the book [*"Learn C The Hard Way"*](http://c.learncodethehardway.org/book/).

## Compling C program

```
gcc -o program main.c
```

## Compiling C++ program

By default, gcc will link against the C stdlib, which will cause errors. To remedy, tell gcc to link against the C++ stdlib.

```
gcc -o program -lstdc++ main.cpp
```
