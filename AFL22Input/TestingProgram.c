#include <stdio.h>
#include <unistd.h>

#define MAX_LENGTH 10  // maximum length of input string

int main() {
    char input_str[MAX_LENGTH];
    int input_num = 0, sum = 0;

    // read input from standard input
    int length = read(STDIN_FILENO, input_str, MAX_LENGTH);

    // convert input string to integer
    for (int i = 0; i < length; i++) {
        if (input_str[i] >= '0' && input_str[i] <= '9') {
            input_num = input_num * 10 + (input_str[i] - '0');
        }
    }

    // perform different loops based on input
    if (input_num % 2 == 0) {
        // calculate sum using loop that increments by 2
        for (int i = 2; i <= input_num; i += 2) {
            sum += i;
        }
    } else {
        // calculate sum using loop that increments by 3
        for (int i = 3; i <= input_num; i += 3) {
            sum += i;
        }
    }

    // print the result
    printf("The sum of all numbers from 1 to %d with alternate increments is %d\n", input_num, sum);

    return 0;
}
