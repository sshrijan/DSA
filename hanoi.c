/*C program for Tower of Hanoi using Recursion */

#include <stdio.h>

void towers(int, char, char, char);

int main()
{
    int num;

    printf("Enter the number of disks :");
    scanf("%d", &num);

    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}

void towers(int num, char fromPeg, char toPeg, char auxPeg)
{
    if (num == 1)
    {
        printf("Move disk 1 from peg %c to peg %c\n", fromPeg, toPeg);
        return;
    }
    towers(num - 1, fromPeg, auxPeg, toPeg);
    printf("Move disk %d from peg %c to peg %c\n", num, fromPeg, toPeg);
    towers(num - 1, auxPeg, toPeg, fromPeg);
}
