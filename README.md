# push_swap

The goal of push_swap is simple: sort a list of numbers.
The catch?
You can only use two stacks and a very specific, limited set of commands.
This project challenges you to find the most efficient sorting algorithm within these constraints.

## The Challenge

You are given two stacks, a and b:
* Stack a starts with a random list of unique integers.
* Stack b starts empty.

The goal is to sort the numbers in stack a in ascending order with the fewest possible moves.
Stack b is used as a temporary holding space to help you sort, but it must be empty by the end.

## The moves

You have a set of 11 operations you can use to manipulate the stacks:

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | Swap A                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap B                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | Push A                              | moves the top element of stack b at the top of stack a |
| `pb`  | Push B                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## Algorithm

My solution uses a 3-Way Quicksort algorithm.

To optimize the process, I first simplify the numbers.
Instead of working with the raw integers (e.g., -5, 100, 2, -10), I replace each one with its sorted index (e.g., 1, 3, 2, 0).
This makes the sorting logic much cleaner.

### Performance of the Algorithm

#### Sorting 100 Numbers:
![til](100.gif)

#### Sorting 500 Numbers:
![til](t00.gif)

### Bonus

This project also includes a checker program. You can feed it a list of numbers and a sequence of push_swap instructions.
* If the instructions successfully sort the list, it will output OK.
* If the list is not sorted, or an error occurs (e.g., invalid instruction), it will output KO.
