
											//1. ������ � �������

int vvod(int a);//���� ����� ���������� � �������
void change(int *a,int*b);//����� ����� ����������
double celayastep(double a,int b);//���������� ����� � ����� �������
double tanH(int x);//��������� ��������������� ������� ����� pow
double tanH(double x,int o);//��������� ��������������� �������
double estepx(double x,int o);//��������� � � ������� �
unsigned _int64 facial(int n);//��������� ��������� 
long double tanH(double x,unsigned _int64 o);//��������� ��������������� ������� (�������� ���� ����)
int prv_even(int a);//�������� �������� ��� ����� �����
int vvod(int a);//���� ����� ���������� � �������
int Prime (int a);//�������� ������ ����� �� ��������
int palindrom (int a);//�������� ����� ��������� ��� ��� ( ��� �����)
int ReversNumber (int b);//��������������� ������ �����

											//2. ������ � ��������� �����

void mass_cel_rand_mil(int *f, int n);//��������� ������ ����� ��������� �������(������ ������������������ � �������� ������������)   
void bubble_srt(int *a,int n);//���������� ���������� ��������� ������� �����
void mass_cel_rand(int *f, int n);//��������� ������ ����� ��������� �������(1-������� �����)
void vivodmassbig(int *a,int n);
void mass_cel_rand2(int *f, int n);//��������� ������ ����� ��������� ������� (1-2-��������� �����)
void mass_cel_rand2N(int *f, int n);//��������� ������ ����� ��������� ������� (1-100 �����)
void mass_from_file(int *a,int n);//���� ������� ����� ����� ����(1-2-��������� �����)
void mass_cel_rand4N(int *f, int n);// ������ ����� ��������� ������� (1-1000 �����)
void frm_2ndcrs_to_ncrs(int* a,int *b,int n,int *h);//�� 2 ����������� �������� ����� ������� ������������
void vivod_L3B9(int *a,int *b,int *h,int n);//����� �������� �������� ��� ������ L3(B9)
void DeleteCh(int *a, int *n, int item);// ��������   �� ������� ����� ��������� = item
void MoveRight(int *a,int *n,int num);//�������� ���  �������� �� 1 ������� ����� ����� ������� num(num-�����������) � ������� �����
void vivodmass(int *a,int n);//����� ������� � �������
void MoveLeft(int * a,int *n, int num);//�������� ���  �������� �� 1 ������� ����� c ������ num(num ���������) � ������� �����
int *mass_dclr(int *a,int n);//���������� ������������� �������(��������������� ��������� �� ������ (�������� int **a=1)��� ������� ��������������)
void delreusage(int *a,int *n);//(�����������)������� ��� ���������� �������� � ������� �����22222222222
void delrowreusage(int *a,int *n);//������� ��� ���������� ������������ �������� �������� 1 � ������� �����
int BinarySearch_L3 (int *a,int n,int x);//�������� ����� �������� ������� ������ ���������� �� ������ ���� ����� ����������� � ������� �����

												//3. ������ � ���������(2) �����

void input_matr2_rand2(int **a, int n,int m);//���� �������(2) ����� ��������� �������(1-2��������� �����)
void input_matr2_rand2N(int **a, int n,int m);//���� �������(2) ����� ��������� �������(1-100 �����)
void input_matr2_randN(int **a, int n,int m);//���� �������(2) ����� ��������� �������(1-10 �����)
void bubble_srt_mtr2(int **a,int n,int m);//���������� ���������� ��������� �������(2) �����(�� ��������)222222222
void DeleteChinmatr2(int **a, int *m,int n, int item);// �������� �� ������ �������(2) ��������� = item
void MoveLeftinmatr2(int **a,int *m,int n,int num);//�������� ��� �������� �� 1 ������� ����� c ������ num(num ���������) � ������ �������(2)
void input_matr2_zer(int **a,int n,int m);//���������� �������(2) ������
void vivodmatr2(int **a,int n,int m);//����� �������(2) ���������������
int **matr2_dclr(int **a,int n,int m);//���������� ������������ �������(2)(��������������� ��������� �� ������� (�������� int **a=1)��� ������� ��������������)
void matrB9L3(int **a,int n);//�������� �������(2) ���� �������� ��� n=4 :(1)1 2 3 4(2)12 1 2 5(3)11 4 3 6(4)10 9 8 7.
void matrB7L3(int **a,int n,int m);//�������� �������(2) ������ ������� ������� ���� ����� ������� ������ � ������� � ������� �� �����
int BinarySearch_L3_inmatr (int **a,int n,int x, int k);//�������� ����� �������� ������� ������ ���������� �� ������ ���� ����� ����������� � �������(2) �����
void input_matr2_rand(int **a, int n,int m);//���� �������(2) ����� ��������� �������(1-������� �����)
int matr2_search_least(int **a,int n,int m);//����� ����������� �������� �������
void format_matrC8L4(int **a,int n,int m);//����������� ������ � ������� ���������� ���� ��-� � ������ ������ ����
int** matrA1L4(int **a,int n,int m);//�� ������� (2) ������ �������(2) � ������ �������������� � ������� ��-���� �� ������ ������� � ������� ��(����������)
int** matrA1L4b(int **a,int n,int m);//�� ������� (2) ������ �������(2) � ������ �������������� � ������� ��-���� �� ������ ������� � ������� ��(��-�� �������������)
void magicsqr(int **a,int m);//������ ���������� ������� ������� m
void inspiral(int **a,int n);//������ �������������� ������� �����
void bubble_srt_A4L4(int **a,int n,int m);//���������� ��������� � �������(2) � ����� ������(����������)

									//4. ��������� ��� QSORT-A

int cmp_int(void * x1, void * x2);//c�������� ������ ������ ��� ������ (�����)

											//5. ������ � �������


//.seekp ������� ������� �������
//.tellp ����� ������� �������
//.write ������ � ���� � ����� �������
//������ ������� seekg() � ����� ����������� ����������
//��������� ����� �� offset ���� �� �������, ��������
//���������� origin. �������� offset ����� ���
//streamoff, ������� ��������� � ��������� iostream.h.
//������ ���� streamoff �������� ��������� �����
//������� ���������� ��������, ������� ����� �����
//�������� offset.�������� origin ����� ���
//ios::seek_dir � ������������ ����� ������������,
//������� ����� ��������� ��������.
//ios::beg   	�������� �� ������
//ios::cur	�������� �� ������� �������
//ios::end	�������� �� �����
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