// C program to generate random numbers
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Driver program
int main()
{
	// This program will create different sequence of 
	// random numbers on every program run 

	// Use current time as seed for random generator
	srand(time(0));

	for (int i = 0; i < 4; i++)
		printf(" %d ", rand());

	return 0;
}
