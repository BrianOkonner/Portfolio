void* (*fp)( const void * x, const void * y);
	// ��������� ��  ����� ������� � ���� �����������

int  (*fpI)(int  x, int y);
	// ��������� ��  ����� ������� � ���� �����������
double call_by_name(char *pn, double arg);
 
int* AddI(int *x, int *y);

double* AddD(double *x, double *y);

double addD(double x, double y);

int addI(int x, int y);
