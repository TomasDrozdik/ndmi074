# Assignment 1

## popcnt

In order to count number of set bits in an number I have used an observation about substracting 1 from a binary number.

### Observarion about `n-1`
When we substract 1 from an unsigned integer binary representation of `n-1` has switched all the low order bits up the rightmost set bit.


This means that if we were to use `n & (n-1)` all the bits from the rightmost 1 of `n` are 0.
From this it is simple to find number of set bits as we have operation that consumes 1 bit and it is repeatable until there is no set bit left i.e. `n=0`.
Complexity of the algorithm is `O(number_of_set_bits)`.

### Code
Code is in the `popcnt.c`.
Compile with `gcc popcnt.c`
Run with `./a.out <n>`

---

## gsort

Code is in the `gsort.h` and usage example from assignment is in the `gsort.c`.
To compile the code run `gcc gsort.c`.

### Remarks
I had an issue with using macros inside of another macros to create the "templated" name of the function.
I have found a solution that uses another macro indirection.
Other than that I have implemented a simple bubblesort algorithm.
