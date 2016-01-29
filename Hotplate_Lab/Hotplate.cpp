/*
Matthew Kirk
Section 4
10/16/2012
Lab # 6 Hotplate
Description: This program preforms a steady state analysis on the temperature
				distribution over a piece of metal.
Design:
	1) Initializes and prints a 20x20 two dimensional array.
	2) For every central cell in the array, it takes the average of the four neighboring cells and updates that cell.
	3) It repeats this until there are no changes greater than .1 between interations.
	4) The program writes the data to a .csv file.
Test Cases:
	1)

*/

#include <iostream>
#include <fstream>
using namespace std;

void printarr (double arr[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << arr[i][j] << ", ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

int main()
{
	const int SIZE = 20;
	double hotplate[SIZE][SIZE];
	for (int rows = 0; rows < SIZE; rows++)
	{
		for (int cols = 0; cols < SIZE; cols++)
		{
			hotplate[rows][cols] = 0;
			if (rows == 0 || rows == 19)
			{
				hotplate[rows][cols] = 100;
			}

			if (cols == 0 || cols == 19)
			{
				hotplate [rows][cols] = 0;
			}

		}
	}
	printarr (hotplate);


	//Update numbers
	double temp = hotplate[1][1];
	double change = 100;
	bool stop = true;
	do
	{
		stop = true;
		for (int row = 1; row < (SIZE-1); row++)
		{
			for (int col = 1; col < (SIZE-1); col++)
			{
				temp = hotplate[row][col];
				hotplate[row][col] = (hotplate[row][col-1] + hotplate[row][col+1] + hotplate[row+1][col] + hotplate[row-1][col])/4;
				
				change = hotplate[row][col] - temp;
				if (change > .1)
				{
					stop = false;
				}
			}
		}
	}
	while (stop == false);

	ofstream csv ("Hotplate_Lab.csv");
	if (csv.is_open ())
	{
		cout << "Writing to file..." << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				csv << hotplate[i][j] << ", ";
			}
			csv << endl;
		}
		csv.close();
	}
	else
	{
		cout << "Unable to open file.\n\n";
	}
	system("pause");
}