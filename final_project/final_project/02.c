#include<stdio.h>
#include<time.h>
#include<stdlib.h>

// 152120181102 Kübra Korkmaz
//01.01.2021 Computer Programming Lab - Final

int main() {


	int a, b, column, row, i, j, min=0, mtrx[10][10], stunt[10][10], line[10], sum=0;


	//******************Create a Matrix**************************

	while (1) {
		printf("Enter number of rows (to exit is 0): \n");
		scanf_s("%d", &a);
		if (a == 0) {
			break;
		}
		printf("Enter number of columns: \n");
		scanf_s("%d", &b);

		
		if (a < 0 || a>10) {
			printf("Error!\n");
			
		}
		else if (b <= 0 || b > 10) {
			printf("Error!\n");
		}
		else {
			break;
		}
	}

	//**************Fill the matrix with random numbers (0-9)**************************

	srand(time(NULL));

	for (row = 0; row < a; row++) {

		for (column = 0; column < b; column++) {

			mtrx[row][column] = rand() % 10;
			stunt[row][column] = mtrx[row][column];
		}
		
	}

	//****************Find the shortest path*****************************

	for (i = 1; i < a; i++) {

		for (j = 0; j < b; j++) {

			if (j == 0) {

				if (stunt[i - 1][j] < stunt[i - 1][j + 1]) {

					stunt[i][j] = stunt[i][j] + stunt[i - 1][j];
				}
				else {

					stunt[i][j] = stunt[i][j] + stunt[i - 1][j + 1];
				}
			}

			if (j > 0 && j < b - 1) {
				if (stunt[i - 1][j - 1] < stunt[i - 1][j]&& stunt[i - 1][j - 1] < stunt[i - 1][j + 1]) {

					stunt[i][j] = stunt[i][j] + stunt[i - 1][j - 1];
				}
				else if (stunt[i - 1][j] < stunt[i - 1][j + 1]) {
					stunt[i][j] = stunt[i][j] + stunt[i - 1][j];
				}
				else {
					stunt[i][j] = stunt[i][j] + stunt[i - 1][j + 1];
				}
			}

			if (j == b - 1) {

				if (stunt[i - 1][j - 1] < stunt[i - 1][j]) {

					stunt[i][j] = stunt[i][j] + stunt[i - 1][j - 1];
				}
				else {

					stunt[i][j] = stunt[i][j] + stunt[i - 1][j];
				}
			}
			
		}
	}
	
	for (row = a - 1; row >=0; row--) {

			if (row == a-1) {

				for (column = 0; column < b-1; column++) {
					
					if (column == 0) {
						min = stunt[row][column];

						line[row] = column;
					}
					
					if (min > stunt[row][column + 1]) {

						min = stunt[row][column + 1];

						line[row] = column+1;
					}
					
				}					
			}
			
			else {
				
				if (line[row+1] == 0) {

					if (stunt[row][line[row+1]] > stunt[row][line[row + 1]+1]) {
						line[row] = line[row+1]+1;
					}
					else {
						line[row] = line[row+1];
					}
				}
				if (line[row + 1] > 0 && line[row + 1] < b-1) {

					if (stunt[row][line[row+1]] < stunt[row][line[row+1]-1] && stunt[row][line[row + 1]] < stunt[row][line[row + 1]+1]) {
						line[row] = line[row + 1];
					}
					else if (stunt[row][line[row + 1] - 1]< stunt[row][line[row + 1]]&& stunt[row][line[row + 1] - 1]< stunt[row][line[row + 1] + 1]) {
						line[row] = line[row + 1]-1;
					}
					else {
						line[row] = line[row + 1] +1;
					}
				}

				if (line[row + 1] == b - 1) {

					if (stunt[row][line[row+1]] < stunt[row][line[row+1]-1]) {
						line[row] = line[row + 1];
					}
					else {
						line[row] = line[row + 1] - 1;
					}
				}	
			}
			
	}

	printf("\n\n");

	//*********************Show shortest path****************************************

	for (row = 0; row < a; row++) {
		
		for (column = 0; column < b; column++) {

			if (column == line[row]) {
				printf("[%d] ", mtrx[row][column]);
				sum = sum + mtrx[row][column];
			}
			else {
				printf("%d ", mtrx[row][column]);
			}

			
		}
		
		printf("\n");
		
	}

	if (a != 0) {
		printf("sum of weights %d", sum);
	}
	

	return 0;

	system("pause");

}