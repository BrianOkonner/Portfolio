//Бондарчук Владимир 
//1 курс, группа 8

#include"Header.h"
int main()
{
	setlocale(0, "rus");
		system("cls");
		ifstream fin("Input.txt");
		int N, M, **List;
		fin >> N >> M;
		List = new int*[N];
		for (int i = 0; i < N; i++)
			List[i] = new int[M];

		for (int i = 0; i < N; ++i) 
{
			for (int j = 0; j < M; ++j) 
{
				fin >> List[i][j];
				cout << setw(3) << List[i][j] << " ";
			}
			cout << endl;
		}
		int x, y, x1, y1, i, j, k = 0;
		ArrayStack X(100), Y(100);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) 
{
				if (List[i][j] == 0) 
{
					X.push(i);
					Y.push(j);
					k++;
					List[i][j] = -1;
					while (!X.isEmpty()) 
{
						x = X.pop();
						y = Y.pop();
						List[x][y] = -1;
						if (x > 0 && List[x - 1][y] == 0)
 {
							X.push(x - 1);
							Y.push(y);
						}
						if (y < N - 1 && List[x][y + 1] == 0) 
{
							X.push(x);
							Y.push(y + 1);
						}
						if (x < M - 1 && List[x + 1][y] == 0) 
{
							X.push(x + 1);
							Y.push(y);
						}
						if (y > 0 && List[x][y - 1] == 0) 
{
							X.push(x);
							Y.push(y - 1);
						}
					}
				}
			}
		cout << endl << endl << "Количество кусков равно - " << k << endl;
	system("pause");
}