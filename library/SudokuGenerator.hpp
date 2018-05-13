#ifndef SUDOKUGENERATOR_HPP_INCLUDED
#define SUDOKUGENERATOR_HPP_INCLUDED

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <iostream>

class SudokuGenerator{
	std::vector<std::vector<int>> mat;
	int N=9; // number of columns/rows.
	int SRN=3; // square root of N
	int K; // No. Of missing digits

public:
	// Constructor
	SudokuGenerator(int _K):K(_K){
	    std::vector<std::vector<int>> temp(9, std::vector<int>(9, 0));
	    mat=temp;
        fillValues();
		printSudoku();
	}

	// Sudoku Generator
private:
	void fillValues()
	{
		// Fill the diagonal of SRN x SRN matrices
		fillDiagonal();

		fillRemaining(0, SRN);

		// Remove Randomly K digits to make game
		removeKDigits();
	}

	// Fill the diagonal SRN number of SRN x SRN matrices
	void fillDiagonal()
	{

		for (int i = 0; i<N; i=i+SRN)

			// for diagonal box, start coordinates->i==j
			fillBox(i, i);

	}

	// Returns false if given 3 x 3 block contains num.
	bool unUsedInBox(int rowStart, int colStart, int num)
	{
		for (int i = 0; i<SRN; i++)
			for (int j = 0; j<SRN; j++)
				if (mat[rowStart+i][colStart+j]==num)
					return false;

		return true;
	}

	// Fill a 3 x 3 matrix.
	void fillBox(int row,int col)
	{
		int num;
		for (int i=0; i<SRN; i++)
		{
			for (int j=0; j<SRN; j++)
			{
				do
				{
					num = randomGenerator(N);
				}
				while (!unUsedInBox(row, col, num));

				mat[row+i][col+j] = num;
			}
		}
	}

	// Random generator
	int randomGenerator(int num)
	{
		return (rand()%num+1);
	}

	// Check if safe to put in cell
	bool CheckIfSafe(int i,int j,int num)
	{
		return (unUsedInRow(i, num) &&
				unUsedInCol(j, num) &&
				unUsedInBox(i-i%SRN, j-j%SRN, num));
	}

	// check in the row for existence
	bool unUsedInRow(int i,int num)
	{
		for (int j = 0; j<N; j++)
		if (mat[i][j] == num)
				return false;
		return true;
	}

	// check in the row for existence
	bool unUsedInCol(int j,int num)
	{
		for (int i = 0; i<N; i++)
			if (mat[i][j] == num)
				return false;
		return true;
	}

	bool fillRemaining(int i, int j)
    {

        if (j>=N && i<N-1)
        {
            i = i + 1;
            j = 0;
        }
        if (i>=N && j>=N)
            return true;

        if (i < SRN)
        {
            if (j < SRN)
                j = SRN;
        }
        else if (i < N-SRN)
        {
            if (j==(int)(i/SRN)*SRN)
                j =  j + SRN;
        }
        else
        {
            if (j == N-SRN)
            {
                i = i + 1;
                j = 0;
                if (i>=N)
                    return true;
            }
        }

        for (int num = 1; num<=N; num++)
        {
            if (CheckIfSafe(i, j, num))
            {
                mat[i][j] = num;
                if (fillRemaining(i, j+1))
                    return true;

                mat[i][j] = 0;
            }
        }
        return false;
    }


	// Remove the K no. of digits to
	// complete game
	void removeKDigits()
	{
		int counter = K;
		while (counter != 0)
		{
			int i = randomGenerator(N)-1;
			int j = randomGenerator(N)-1;
			if (mat[i][j] != 0)
			{
				counter--;
				mat[i][j] = 0;
			}
		}
		//std::cout<<"pista";
	}

	// Print sudoku
	void printSudoku()
	{
	    std::ofstream out("levels/generator.sudoku");
		for (int i = 0; i<N; i++)
		{
			for (int j = 0; j<N; j++){
                out<<mat[i][j]<<" ";
			}
            out<<std::endl;
		}
	}
};

#endif // SUDOKUGENERATOR_HPP_INCLUDED
