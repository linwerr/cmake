#include "Dog.hpp"
#include <iostream>

namespace duck
{
#include <iostream>
	void Zamena(int matrix[100][100], int n, int m) {
		int min = 10000;
		int sum = 0;
		int ind = 0;
		int jnd = 0;
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				if (matrix[i][j] < min) {
					min = matrix[i][j];
					ind = i;
					jnd = j;
				}
				sum += matrix[i][j] * matrix[i][j];
			}
			matrix[ind][jnd] = sum;
			sum = 0;
			min = 10000;
		}

	}


	void OsnovnaFunc() {
		int n;
		int m;
		std::cin >> n;
		std::cin >> m;
		int matrix[100][100];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				std::cin >> matrix[i][j];
		bool flag1 = true;
		for (int i = 0; i < n; i++) {
			if (matrix[i][i] < 0)
				flag1 = false;
		}
		bool flag2 = false;
		for (int i = 0; i < n; i++) {
			flag2 = false;
			if (flag1 == true) {
				int p = matrix[i][i];
				while (p > 0) {
					if (p % 10 == 3 || p % 10 == 5)
					{
						flag2 = true;
					}
					p = p / 10;
				}
				if (flag2 == false) {
					break;
				}
			}
		}
		if (flag2 == true && flag1 == true)
			Zamena(matrix, n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				std::cout << matrix[i][j] << " ";
			std::cout << '\n';
		}
	}

}