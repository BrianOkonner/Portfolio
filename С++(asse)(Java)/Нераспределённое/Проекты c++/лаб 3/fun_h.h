double celayastep(double,int);//���������� ����� � ����� �������
double tanH(int x);//��������� ��������������� ������� ����� pow
double tanH(double x,int o);//��������� ��������������� �������
double estepx(double x,int o);//��������� � � ������� �
unsigned _int64 facial(int n);//��������� ��������� 
long double tanH(double x,unsigned _int64 o);//��������� ��������������� ������� (�������� ���� ����)
void mass_from_file(int *a,int n);//���� ������� ����� ����� ����(1-2-��������� �����) 
void mass_cel_rand_mil(int *f, int n) ;//��������� ������ ����� ��������� �������(������ ������������������ � �������� ������������)   
void bubble_srt(int *a,int n);//���������� ���������� ��������� ������� �����
void mass_cel_rand(int *f, int n);//��������� ������ ����� ��������� �������(1-������� �����)
void mass_cel_rand2(int *f, int n);//��������� ������ ����� ��������� ������� (1-2-��������� �����)
void frm_2ndcrs_to_ncrs(int* a,int *b,int n,int *h);//�� 2 ����������� �������� ����� ������� ������������
void vvd_L3B9(int *a,int *b,int *h,int n);//����� �������� �������� ��� ������ L3(B9)
void DeleteCh(int *a, int *n, int item);// ��������   �� ������� ����� ��������� = item
void MoveRight(int *a,int *n,int num);//�������� ���  �������� �� 1 ������� ����� ����� ������� num(num-�����������) � ������� �����
void MoveLeft(int * a,int *n, int num);//�������� ���  �������� �� 1 ������� ����� c ������ num(num ���������) � ������� �����
void delreusage(int *a,int *n);//(�����������)������� ��� ���������� �������� � ������� �����22222222222
void delrowreusage(int *a,int *n);//������� ��� ���������� ������������ �������� �������� 1 � ������� �����
int BinarySearch_L3nomatr (int *a,int n,int x);//�������� ����� �������� ������� ������ ���������� �� ������ ���� ����� ����������� � ������� �����
int BinarySearch_L3 (int **a,int n,int x, int k);//�������� ����� �������� ������� ������ ���������� �� ������ ���� ����� ����������� � �������(2) �����
void input_matr_rand2(int **a, int n,int m);//���� �������(2) ����� ��������� �������(1-2��������� �����)
void bubble_srt_mtr2(int **a,int n,int m);//���������� ���������� ��������� �������(2) �����(�� ��������)222222222
void input_matr_zer(int **a, int n,int m);//���������� �������(2) ������
void change(int *a,int*b);//����� ����� ����������
void vivodmass(int *a,int n);//����� ������� � �������

