#include <iostream>
#include <stdio.h>
using namespace std;

class Strassen{											//class for strassen multiplication
public:
	int a[2][2], b[2][2], c[2][2], i, j;				//for matrix population
	int ans1, ans2, ans3, ans4, ans5, ans6, ans7;		// for storing answers of 7 multiplications of strassen
	void Strassmult()									//function for 2x2 Matrix
	{

		for (i = 0; i < 2; i++)							//random no. generation for matrix	A
		for (j = 0; j < 2; j++)
			a[i][j] = rand() % 80;

		for (i = 0; i < 2; i++)							//random no. generation for matrix	B
		for (j = 0; j < 2; j++)
			b[i][j] = rand() % 80;

		cout << endl;

		cout << "1st matrix:";							//displaying matrix 1 2x2
		cout << endl;
		for (i = 0; i < 2; i++)
		{
			cout << "\n";
			for (j = 0; j < 2; j++)
			{
				cout << a[i][j];
				cout << " ";
			}
		}

		cout << endl;
		cout << endl;

		cout << "2nd Matrix:";							//displaying matrix 2 2x2
		cout << endl;
		for (i = 0; i < 2; i++)
		{
			cout << "\n";
			for (j = 0; j < 2; j++)
			{
				cout << b[i][j];
				cout << " ";
			}
		}


		ans1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);		//the seven equations of Strassen for 2x2 matrix
		ans2 = (a[1][0] + a[1][1]) * b[0][0];
		ans3 = a[0][0] * (b[0][1] - b[1][1]);
		ans4 = a[1][1] * (b[1][0] - b[0][0]);
		ans5 = (a[0][0] + a[0][1]) * b[1][1];
		ans6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
		ans7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

		c[0][0] = ans1 + ans4 - ans5 + ans7;					//the further addition and subtraction required
		c[0][1] = ans3 + ans5;
		c[1][0] = ans2 + ans4;
		c[1][1] = ans1 - ans2 + ans3 + ans6;

		cout << endl;
		cout << endl;

		cout << "Strassen's algorithm result:";					//Displaying Resultant matrix
		cout << endl;
		for (i = 0; i < 2; i++){
			cout << "\n";
			for (j = 0; j < 2; j++)
			{
				cout << c[i][j];
				cout << " ";
			}
		}
		getchar();
		getchar();
	}
};
class Iterative{										//class for Iterative multiplication
public:
	int a[2][2], b[2][2], c[2][2], i, j;				//for matrix population
	int x=2, n=2, m=2, y=2;								//differentiating btw rows and columns of matrices
	void Itermult()										//function for Iterative Multiplication
	{
		for (i = 0; i < x; i++)								//random no. generaton for matrix A
		{
			for (j = 0; j < y; j++)
			{
				a[i][j] = rand() % 80;
			}
			cout << "\n";
		}
		cout << "\n\nMatrix A :\n\n";							//displaying matrix A 2x2
		for (i = 0; i < x; i++)
		{
			for (j = 0; j < y; j++)
			{
				cout << "\t" << a[i][j];
			}
			cout << "\n";
		}

		for (i = 0; i < m; i++)								//random no. generaton for matrix B
		{
			for (j = 0; j < n; j++)
			{
				b[i][j]= rand() % 80;
			}
			cout << "\n";
		}
		cout << "\n\nMatrix B :\n\n";							//displaying matrix B 2x2
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << "\t" << b[i][j];
			}

			cout << "\n";
		}
															//Iterative Multiplication
			for (i = 0; i < x; i++)							//First Loop to traverse through rows of matrix A
			{
				for (j = 0; j < n; j++)						//Second Loop to traverse through columns of matrix B
				{
					c[i][j] = 0;
					for (int k = 0; k < m; k++)				//Third Loop to travers through rows of matrix B
					{
						c[i][j] = c[i][j] + a[i][k] * b[k][j];
					}
				}
			}


		cout << endl;
		cout << "Iterative Multiplication Result";			//Displaying Resultant matrix
		cout << endl;
		for (i = 0; i < x; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << "\t" << c[i][j];
			}
			cout << "\n";
		}

		getchar();
		getchar();
	}
};
int main()
{
	srand(5);													//seed for random no. generation
	Strassen s1;												//object creation
	Iterative i1;
	int n;
	cout << "Welcome to Matrix Multiplication" << endl;				
	cout << "There are two methods:" << endl;
	cout << "1.Strassen Multiplication" << endl;
	cout << "2.Iterative Multiplication" << endl;
	cout << endl;
	cout << "Enter the no. of the multiplication method you want to use." << endl;
	cin >> n;
	switch (n)															//user can select which multiplication method to use
	{
	case 1:
		s1.Strassmult();
	case 2:
		i1.Itermult();
	default:
		cout << "Wrong Choice" << endl;
		getchar();
	}
	
	getchar();
	return 0;
}