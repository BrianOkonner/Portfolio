double celayastep(double,int);//Возведение числа в целую степень
double tanH(int x);//Вычислить гиперболический тангенс через pow
double tanH(double x,int o);//Вычислить гиперболический тангенс
double estepx(double x,int o);//Вычислить е в степени х
unsigned _int64 facial(int n);//Вычислить факториал 
long double tanH(double x,unsigned _int64 o);//Вычислить гиперболический тангенс (максимум лонг дабл)
void mass_from_file(int *a,int n);//Ввод массива целых через файл(1-2-ухзначные числа) 
void mass_cel_rand_mil(int *f, int n) ;//Заполнить массив целых случайным образом(Меняет последовательность с течением миллисекунды)   
void bubble_srt(int *a,int n);//Сортировка улучшенным пузырьком массива целых
void mass_cel_rand(int *f, int n);//Заполнить массив целых случайным образом(1-значные числа)
void mass_cel_rand2(int *f, int n);//Заполнить массив целых случайным образом (1-2-ухзначные числа)
void frm_2ndcrs_to_ncrs(int* a,int *b,int n,int *h);//Из 2 неубывающих массивов целых сделать возрастающий
void vvd_L3B9(int *a,int *b,int *h,int n);//Вывод значений массивов для задачи L3(B9)
void DeleteCh(int *a, int *n, int item);// Удаление   из массива целых элементов = item
void MoveRight(int *a,int *n,int num);//сдвигаем все  элементы на 1 позицию влево перед номером num(num-дублируется) в массиве целых
void MoveLeft(int * a,int *n, int num);//сдвигаем все  элементы на 1 позицию влево c номера num(num Удаляется) в массиве целых
void delreusage(int *a,int *n);//(непроверена)Удаляет все одинаковые элементы в массиве целых22222222222
void delrowreusage(int *a,int *n);//Удаляет все одинаковые рядомстоящие элементы оставляя 1 в массиве целых
int BinarySearch_L3nomatr (int *a,int n,int x);//Бинарный поиск элемента который меньше следующего но больше либо равен предыдущему в массиве целых
int BinarySearch_L3 (int **a,int n,int x, int k);//Бинарный поиск элемента который меньше следующего но больше либо равен предыдущему в матрице(2) целых
void input_matr_rand2(int **a, int n,int m);//Ввод матрицы(2) целых случайным образом(1-2ухзначные числа)
void bubble_srt_mtr2(int **a,int n,int m);//Сортировка улучшенным пузырьком матрицу(2) целых(не работает)222222222
void input_matr_zer(int **a, int n,int m);//Заполнение матрицы(2) нулями
void change(int *a,int*b);//обмен целых переменных
void vivodmass(int *a,int n);//Вывод массива в строчку

