# TOTAL FORK

## Problem Statement

### Input

`./fork argv[1] argv[2] argv[3] argv[4] argv[5] argv[6]`

Where:
- argv[1] : Number of files with name 'a_num.txt'
- argv[2] : Number of files with name 'b_num.txt'
- argv[3] : Number of random numbers in each file
- argv[4] : Number of threads spawned by Parent
- argv[5] : Number of threads spawned by Child thread

### Output

Sum of all numbers in the files displayed by the parent process.

## Constraints

- No idle threads
- Cannot create intermediary files
- Written in C or C++
- MPI should not be useds 
