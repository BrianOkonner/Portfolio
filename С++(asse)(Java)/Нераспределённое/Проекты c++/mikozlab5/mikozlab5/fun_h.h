
											//1. РАБОТА С ЧИСЛАМИ

int vvod(int a);//Ввод целой переменной с консоли
void change(int *a,int*b);//обмен целых переменных
double celayastep(double a,int b);//Возведение числа в целую степень
double doublecelayastep(double a,double b);//Возведение числа в целую степень(максимальная степень без разделения чисел на части)
double tanH(int x);//Вычислить гиперболический тангенс через pow
double tanH(double x,int o);//Вычислить гиперболический тангенс
double estepx(double x,int o);//Вычислить е в степени х
unsigned _int64 facial(int n);//Вычислить факториал 
long double tanH(double x,unsigned _int64 o);//Вычислить гиперболический тангенс (максимум лонг дабл)
int prv_even(int a);//Проверка четности для целых чисел
int vvod(int a);//Ввод целой переменной с консоли
int Prime (int a);//Проверка целого числа на простоту
int palindrom (int a);//Проверка число палиндром или нет ( для целых)
int ReversNumber (int b);//Переворачивание целого числа

											//2. РАБОТА С МАССИВАМИ ЧИСЕЛ

void mass_cel_rand_mil(int *f, int n);//Заполнить массив целых случайным образом(Меняет последовательность с течением миллисекунды)   
void bubble_srt(int *a,int n);//Сортировка улучшенным пузырьком массива целых
void mass_cel_rand(int *f, int n);//Заполнить массив целых случайным образом(1-значные числа)
void vivodmassbig(int *a,int n);
void mass_cel_rand2(int *f, int n);//Заполнить массив целых случайным образом (1-2-ухзначные числа)
void mass_cel_rand2N(int *f, int n);//Заполнить массив целых случайным образом (1-100 числа)
void mass_from_file(int *a,int n);//Ввод массива целых через файл(1-2-ухзначные числа)
void mass_cel_rand4N(int *f, int n);// массив целых случайным образом (1-1000 числа)
void frm_2ndcrs_to_ncrs(int* a,int *b,int n,int *h);//Из 2 неубывающих массивов целых сделать возрастающий
void vivod_L3B9(int *a,int *b,int *h,int n);//Вывод значений массивов для задачи L3(B9)
void DeleteCh(int *a, int *n, int item);// Удаление   из массива целых элементов = item
void MoveRight(int *a,int *n,int num);//сдвигаем все  элементы на 1 позицию влево перед номером num(num-дублируется) в массиве целых
void vivodmass(int *a,int n);//Вывод массива в строчку
void MoveLeft(int * a,int *n, int num);//сдвигаем все  элементы на 1 позицию влево c номера num(num Удаляется) в массиве целых
int *mass_dclr(int *a,int n);//Объявление динамического массива(Инициализируйте указатель на массив (например int **a=1)или вылезет предупреждение)
void delreusage(int *a,int *n);//(непроверена)Удаляет все одинаковые элементы в массиве целых22222222222
void delrowreusage(int *a,int *n);//Удаляет все одинаковые рядомстоящие элементы оставляя 1 в массиве целых
int BinarySearch_L3 (int *a,int n,int x);//Бинарный поиск элемента который меньше следующего но больше либо равен предыдущему в массиве целых

												//3. РАБОТА С МАТРИЦАМИ(2) ЧИСЕЛ

void input_matr2_rand2(int **a, int n,int m);//Ввод матрицы(2) целых случайным образом(1-2ухзначные числа)
void input_matr2_rand2N(int **a, int n,int m);//Ввод матрицы(2) целых случайным образом(1-100 числа)
void input_matr2_randN(int **a, int n,int m);//Ввод матрицы(2) целых случайным образом(1-10 числа)
void bubble_srt_mtr2(int **a,int n,int m);//Сортировка улучшенным пузырьком матрицу(2) целых(не работает)222222222
void DeleteChinmatr2(int **a, int *m,int n, int item);// Удаление из строки матрицы(2) элементов = item
void MoveLeftinmatr2(int **a,int *m,int n,int num);//сдвигаем все элементы на 1 позицию влево c номера num(num Удаляется) в строке матрицы(2)
void input_matr2_zer(int **a,int n,int m);//Заполнение матрицы(2) нулями
void vivodmatr2(int **a,int n,int m);//Вывод матрицы(2) прямоугольником
int **matr2_dclr(int **a,int n,int m);//Объявление динамической матрицы(2)(Инициализируйте указатель на матрицу (например int **a=1)или вылезет предупреждение)
void matrB9L3(int **a,int n);//Создание матрицы(2) вида например при n=4 :(1)1 2 3 4(2)12 1 2 5(3)11 4 3 6(4)10 9 8 7.
void matrB7L3(int **a,int n,int m);//Создание матрицы(2) каждый элемент которой есть сумма номеров строки и столбца в которых он стоит
int BinarySearch_L3_inmatr (int **a,int n,int x, int k);//Бинарный поиск элемента который меньше следующего но больше либо равен предыдущему в матрице(2) целых
void input_matr2_rand(int **a, int n,int m);//Ввод матрицы(2) целых случайным образом(1-значные числа)
int matr2_search_least(int **a,int n,int m);//Поиск наименьшего элемента матрицы
void format_matrC8L4(int **a,int n,int m);//Переставляя строки и столбцы перемещает наим эл-т в правый нижний угол
int** matrA1L4(int **a,int n,int m);//из матрицы (2) делает матрицу(2) С только повторяющимися в строках эл-тами из данной матрицы и выводит ее(недоделана)
int** matrA1L4b(int **a,int n,int m);//из матрицы (2) делает матрицу(2) С только повторяющимися в строках эл-тами из данной матрицы и выводит ее(эл-ты отсортированы)
void magicsqr(int **a,int m);//Строит магический квадрат порядка m
void inspiral(int **a,int n);//Строит свертывающуюсю спираль целых
void bubble_srt_A4L4(int **a,int n,int m);//Сортировка пузырьком в матрице(2) в одной строке(недоделано)

									//4. СРАВНЕНИЯ ДЛЯ QSORT-A

int cmp_int(void * x1, void * x2);//cравнение больше меньше для ксорта (целые)

											//5. РАБОТА С ФАЙЛАМИ


//.seekp указать позицию курсора
//.tellp найти позицию курсора
//.write запись в файл с места курсора
//Версия функции seekg() с двумя параметрами перемещает
//указатель ввода на offset байт от позиции, заданной
//параметром origin. Параметр offset имеет тип
//streamoff, который определен в заголовке iostream.h.
//Объект типа streamoff способен содержать самое
//большое допустимое значение, которое может иметь
//параметр offset.Параметр origin имеет тип
//ios::seek_dir и представляет собой перечисление,
//которое имеет следующие значения.
//ios::beg   	Смещение от начала
//ios::cur	Смещение от текущей позиции
//ios::end	Смещение от конца
//.clear();
/*Type Name	Bytes	Other Names	Range of Values
int	4	signed	-2,147,483,648 to 2,147,483,647
unsigned int	4	unsigned	0 to 4,294,967,295
__int8	1	char	-128 to 127
unsigned __int8	1	unsigned char	0 to 255
__int16	2	short, short int, signed short int	-32,768 to 32,767
unsigned __int16	2	unsigned short, unsigned short int	0 to 65,535
__int32	4	signed, signed int, int	-2,147,483,648 to 2,147,483,647
unsigned __int32	4	unsigned, unsigned int	0 to 4,294,967,295
__int64	8	long long, signed long long	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
unsigned __int64	8	unsigned long long	0 to 18,446,744,073,709,551,615
bool	1	none	false or true
char	1	none	-128 to 127 by default

0 to 255 when compiled by using /J
signed char	1	none	-128 to 127
unsigned char	1	none	0 to 255
short	2	short int, signed short int	-32,768 to 32,767
unsigned short	2	unsigned short int	0 to 65,535
long	4	long int, signed long int	-2,147,483,648 to 2,147,483,647
unsigned long	4	unsigned long int	0 to 4,294,967,295
long long	8	none (but equivalent to __int64)	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
unsigned long long	8	none (but equivalent to unsigned __int64)	0 to 18,446,744,073,709,551,615
enum	varies	none	
float	4	none	3.4E +/- 38 (7 digits)
double	8	none	1.7E +/- 308 (15 digits)
long double	same as double	none	Same as double
wchar_t	2	__wchar_t	0 to 65,535*/