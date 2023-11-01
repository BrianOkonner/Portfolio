#include <iostream>
#include <omp.h>
#include <random>
#include <ctime>
#include <vector>
#include <fstream>


using namespace std;
ofstream out("output.txt", ios::app);

void standart_mp(int** matrixA, int** matrixB, int** matrixC, int n) {
	cout << "standart multiplying\n\n";
	double start_time = omp_get_wtime();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				matrixC[i][j] = matrixC[i][j] + matrixA[i][k] * matrixB[k][j];
			}
		}
	}

	double end_time = omp_get_wtime();
	double search_time = end_time - start_time; // искомое время
	 
	cout << "point algorithm: " << search_time << " sec" << endl << endl;

}

void block_mp(int** matrixA, int** matrixB, int** matrixC, int n, vector<int> cells) {

	cout << "block multiplying no dopar\n\n";
	for (int i = 0; i < cells.size(); i++) {

		int r = cells[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrixC[i][j] = 0;
			}
		}

		int q = n / r;

		double start_time = omp_get_wtime(); // начальное время
		//#pragma omp parallel for
		for (int i_gl = 0; i_gl < q; i_gl++) {
			//#pragma omp parallel for
			for (int j_gl = 0; j_gl < q; j_gl++) {
				for (int k_gl = 0; k_gl < q; k_gl++) {


					for (int i = 0; i < r; i++) {
						for (int j = 0; j < r; j++) {
							for (int k = 0; k < r; k++) {
								matrixC[i_gl * r + i][j_gl * r + j] += 
									matrixA[i_gl * r + i][k_gl * r + k] * 
									matrixB[k_gl * r + k][j_gl * r + j];
							}
						}
					}
				}
			}
}

		double end_time = omp_get_wtime(); // конечное время
		double search_time = end_time - start_time; // искомое время

		cout << "r = " << r << " \t" << "time = " << search_time << " sec" << endl;
		out << search_time << ", ";
	}
	out << endl;
	cout << endl;
}

void block_mp_external(int** matrixA, int** matrixB, int** matrixC, int n, vector<int> cells) {
	cout << "block multiplying external dopar\n\n";
	for (int i = 0; i < cells.size(); i++) {

		int r = cells[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrixC[i][j] = 0;
			}
		}

		int q = n / r;

		double start_time = omp_get_wtime(); // начальное время
		#pragma omp parallel for
		for (int i_gl = 0; i_gl < q; i_gl++) {
			//#pragma omp parallel for
			for (int j_gl = 0; j_gl < q; j_gl++) {
				for (int k_gl = 0; k_gl < q; k_gl++) {


					for (int i = 0; i < r; i++) {
						for (int j = 0; j < r; j++) {
							for (int k = 0; k < r; k++) {
								matrixC[i_gl * r + i][j_gl * r + j] += 
									matrixA[i_gl * r + i][k_gl * r + k] * 
									matrixB[k_gl * r + k][j_gl * r + j];
							}
						}
					}
				}
			}
		}

		double end_time = omp_get_wtime(); // конечное время
		double search_time = end_time - start_time; // искомое время

		cout << "r = " << r << "\t" << "time = " << search_time << " sec" << endl;
		out << search_time << ", ";
	}
	out << endl;
	cout << endl;
}
void block_mp_internal(int** matrixA, int** matrixB, int** matrixC, int n, vector<int> cells) {
	cout << "block multiplying internal dopar\n\n";
	for (int i = 0; i < cells.size(); i++) {

		int r = cells[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrixC[i][j] = 0;
			}
		}

		int q = n / r;

		double start_time = omp_get_wtime(); // начальное время
		//#pragma omp parallel for
		for (int i_gl = 0; i_gl < q; i_gl++) {
			#pragma omp parallel for
			for (int j_gl = 0; j_gl < q; j_gl++) {
				for (int k_gl = 0; k_gl < q; k_gl++) {

					for (int i = 0; i < r; i++) {
						for (int j = 0; j < r; j++) {
							for (int k = 0; k < r; k++) {
								matrixC[i_gl * r + i][j_gl * r + j] +=
									matrixA[i_gl * r + i][k_gl * r + k] * 
									matrixB[k_gl * r + k][j_gl * r + j];
							}
						}
					}
				}
			}
		}

		double end_time = omp_get_wtime(); // конечное время
		double search_time = end_time - start_time; // искомое время

		cout << "r = " << r << " \t" << "time = " << search_time << " sec" << endl;
		out << search_time << ", ";
	}
	out << endl;
	cout << endl;
}

void block_mp_privat(int** matrixA, int** matrixB, int** matrixC, int n, vector<int> cells) {
	cout << "block multiplying privatization\n\n";
	for (int i = 0; i < cells.size(); i++) {

		int r = cells[i];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrixC[i][j] = 0;
			}
		}

		int q = n / r;

		double start_time = omp_get_wtime(); // начальное время
		int i_gl, j_gl, k_gl;
		#pragma omp parallel for private(i_gl, j_gl, k_gl)
		for (i_gl = 0; i_gl < q; i_gl++) {
			for (j_gl = 0; j_gl < q; j_gl++) {
				for (k_gl = 0; k_gl < q; k_gl++) {

					for (int i = 0; i < r; i++) {
						for (int j = 0; j < r; j++) {
							for (int k = 0; k < r; k++) {
								matrixC[i_gl * r + i][j_gl * r + j] +=
									matrixA[i_gl * r + i][k_gl * r + k] *
									matrixB[k_gl * r + k][j_gl * r + j];
							}
						}
					}
				}
			}
		}

		double end_time = omp_get_wtime(); // конечное время
		double search_time = end_time - start_time; // искомое время

		cout << "r = " << r << " \t" << "time = " << search_time << " sec" << endl;
		out << search_time << ", ";
	}
	out << endl;
	cout << endl;
}

int main()
{
	srand(time(NULL));
	//размеры матриц

	int n = 2048;
	cout << "matrix dimension = " << n << endl;
	//инициализация

	int** matrixA = new int* [n];
	int** matrixB = new int* [n];
	int** matrixC = new int* [n];

	for (int i = 0; i < n; i++) {
		matrixA[i] = new int[n];
		matrixB[i] = new int[n];
		matrixC[i] = new int[n];
	}


	//заполнение числами
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrixA[i][j] = (rand() % 201) - 100;
			matrixB[i][j] = (rand() % 201) - 100;
			matrixC[i][j] = 0;
		}
	}


	//точечное перемножение
	standart_mp(matrixA, matrixB, matrixC, n);

	static const int arr[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
	vector<int> cells (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	//блочное перемножение
	block_mp(matrixA, matrixB, matrixC, n, cells);
	block_mp_external(matrixA, matrixB, matrixC, n, cells);
	block_mp_internal(matrixA, matrixB, matrixC, n, cells);
	block_mp_privat(matrixA, matrixB, matrixC, n, cells);
	

	delete[] matrixA;
	delete[] matrixB;
	delete[] matrixC;

	system("pause");

}
