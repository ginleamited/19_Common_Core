# push_swap

push_swap is a 42 school algorithm project where we must sort a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.

## Usage

Git clone the repository and cd into it. Then use ```make``` to compile.

Then run it with :

```shell
./push_swap <numbers>
```

The numbers provided can be positive or negative integers. There must not be any duplicates. For example :

```shell
./push_swap 9 0 -217 2147483647 -2147483648
```

If the arguments are valid, the program will output the most efficient list of actions to sort the list.

The program can be checked with the provided checker, like this :

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```
## Pseudo code

[Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

```
// Initialize two stacks: 'a' (containing input numbers) and 'b' (empty)

// Step 1: Input Validation and Initialization
// 	- Ensure the correct number of arguments is provided
// 	- Parse input arguments to extract numbers
// 	- Validate each number for:
// 		- Non-numeric characters
//   	- Integer overflow
//   	- Duplicates
// 	- If any validation fails, display an error message and exit

// Step 2: Initial Transfer from 'a' to 'b'
// 	- Push the first two elements from 'a' to 'b' to begin sorting

// Step 3: Sorting Elements into Stack 'b'
//	- While 'a' is not empty:
//		- Identify the closest smaller target node of 'a' in 'b'
// 			- If no closest smaller, then target node is the 'max' value in 'b'
//		- Calculate for the 'cheapest' node to push:
//     	- Rotate 'a' to the top
//     	- Push the top element of 'a' to the top of 'b' until 3 nodes left in 'a'
//		- 'b' should be in descending order

// 	- Formula to find the 'cheapest' : x moves to bring 'a' to top + x moves to bring 'a'->target node to top = 'push cost'
//  - If the 'push cost' is 0, push directly

// Step 4: Sorting Remaining Elements in 'a'
//	- If 'a' contains exactly three elements:
//   	- Apply a three-element sorting algorithm to arrange them in ascending order

// Step 5: Merging 'b' Back into 'a'
//	- While 'b' is not empty:
//		- Identify the closest bigger target node of 'b' in 'a'
// 			- If no closest bigger, then target node is the 'min' value in 'a'
//     	- Push the top element of 'b' to the top of 'a'
//		- When moving, 'a' will either rotate (above median) or rev_rotate (under median)

// Step 6: Final Adjustment
//	- 'a' should be reorder in ascending order depending on median line

// Step 7: Cleanup
//	- Free all allocated memory and resources

```

## Push_swap visualizer

[O-reo's push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)

1. git clone the repository inside your main push_swap directory, where your push_swap executable will be. 
2. Install the required packages as stated on the README.md (do `sudo apt update` first to make sure you have the latest information about available packages)
3. Then, to install a package, do e.g. `sudo apt install cmake`
4. cd inside `/push_swap_visualizer` 
5. `mkdir build`
6. cd into `build` then:
	- `cmake ..`
	- `make`
	- If error, ask Deepseek
7. After a sucessfull build of `cmake ..` and `make`:
	- run `./bin/visualizer` and a window of the program should appear. 
	- change the "push_swap file path" to `../../push_swap`


## 42 Checker

1. Download the correct file from the subject page, e.g. for Mac, or Linux, inside the same directory as your executable.
2. Running the checker likely won't work, as it won't have the executable permission. Check by typing in the terminal `ls -l`
3. To give it permission, do `chmod +x <filename>`
4. Test your executable against everything we need our push_swap to do:
	- e.g. the correct outputs for all error types
	- e.g. run `ARG="4 10 1 3 2"; ./push_swap $ARG | ./checker_Mac $ARG `
	- To see how many instructions, run `ARG="4 10 1 3 2"; ./push_swap $ARG | wc -l`
	- For our program to pass the evaluation, it'll have to return `n` size of instructions for sorting `x` number of values:
		- If x = 3 then n <= 3
		- If x = 5 then n <= 12
		- If x = 100 then n < 1500
		- If x = 500 then n < 11500
		- Note: the lesser instructions our algorithm returns, the more evaluation points we will get.

## Push_swap tester

[Gemartin99's push_swap tester](https://github.com/gemartin99/Push-Swap-Tester)

1. Git clone
2. Make push_swap
3. Add push_swap file in push_swap_tester folder
4. Bash push_swap_test.sh or bash push_swap_test_linux.sh

## Push_Swap Rules and Grading

The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

The grade depends on how efficient the program's sorting process is.
 
* Sorting 3 values: no more than 3 actions.
* Sorting 5 values: no more than 12 actions.
* Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 700 actions
  * 4 points for less than 900
  * 3 points for less than 1100
  * 2 points for less than 1300
  * 1 point for less than 1500
* Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 5500 actions
  * 4 points for less than 7000
  * 3 points for less than 8500
  * 2 points for less than 10000
  * 1 point for less than 11500

Validating the project requires at least 80/100.