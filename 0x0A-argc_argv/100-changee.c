#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the minimum number of coins.
 * @argc: command line args count
 * @argv: array of command line args
 *
 * Return: success(0).
 */

int main(int argc, char *argv[])
{
  if (argc != 1)
  {
    printf("Error\n");
    return (1);
  }

  int change = atoi(argv[1]);

  int pieces = 0;
  int i = 0;

  while (i < 5)
  {
    int m = change / coins[i];

    pieces += m;

    // Update the remainder
    change = change % coins[i];

    // Increment the index
    i++;
  }

  // Print the total number of coins
  printf("The number of coins needed is %i\n", pieces);

  // Return 0 to indicate success
  return 0;
}
