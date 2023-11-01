/*													������ �b9
		��������� ������� ��������� ������������ ������������.( �������������: ���������� ������������. ������ 8)
		������� : ���������:  S  ���  �������� m, ����  � ���������� �� a �� b � ����� h. ���������� �������� � ���� �������. 
		�������� �������� : ������ ����� ����� ���� � ���������� ���������� ��� ������ �� � � b � ������������ �� ����� ���� �����(+)
		���� ����(-) �������� ������� a ������� �� ������ �� b ������� ��� ��������� h.
		�����:
������� ����� m: 14
������� ��� h �� �������� ����� ������� �������� ���������: 1
������� ����� � (��������� �������� ���������): 8
�������� ���� b (�������� �������� ���������): 0
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                               *               ������� �����                 *
*      �������� ��������� �     * * * * * * * * * * * * * * * * * * * * * * * *
*                               *      ����� tanH      *      ����� th        *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* 8                             * 0.5006385696040868   * 0.5006385696040868   *
* 7                             * 0.5006385696040868   * 0.5006385696040868   *
* 6                             * 0.5006385696040868   * 0.5006385696040868   *
* 5                             * 0.5006385696040868   * 0.5006385696040868   *
* 4                             * 0.5006385696040868   * 0.5006385696040868   *
* 3                             * 0.5006385696040868   * 0.5006385696040868   *
* 2                             * 0.5006385695919098   * 0.5006385695919098   *
* 1                             * 0.5006350778200358   * 0.5006350778200358   *
* 0                             * 0                    * 0                    *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *                                                       */
const double pi=3.14159265;
double facial(int n)//��������� ���������
{
	double b=1,a;
	if (n==0)
		return 0;
	for (a=1;a<=n;a++)
	{
		_asm
		{
			finit
			fld b
			fld a
			fmul
			fst b
		}
	}
	return b;
}
double celayastep(double a,int b)//���������� ����� � ����� �������
{
	double r=1,i;
	if(b==0)
		return 1;
	else
	{
		for(i=1;i<=b;i++)
		{
			_asm
			{
				finit
				fld r
				fld a
				fmul
				fst r
			}	
		}
		return r;
	}
}
double estepx(double x,int o)//��������� � � ������� �
{
	double h=1,s=1; int k;
	for(k=1;k<=o;k++)
		s=s+(celayastep(x,k)/facial(k));
	return s;
}
double tanH(double x,int o)//��������� ��������������� ������� 
{
	double h=1,k,j;
	h=estepx(x,o);
	_asm
	{
		finit 
		fld1
		fld h
		fdiv
		fst j
		finit
		fld h
		fld j
		fadd 
		fst k
		fld j
		fsub
		fld j 
		fsub
		fld k
		fdiv
		fst k
	}
	//k=(h-(j))/(h+(j));
	return k;
}
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
int main()
{
	double s=0,m,j,c,b,h,a,p; const double pi=3.14159265; unsigned _int64 v;long double o;
	setlocale(LC_ALL,".1251");
	cout<<"������� ����� m: ";
	cin>>m;
	cout<<"������� ��� h �� �������� ����� ������� �������� ���������: ";
	cin>>h;
	if (h<=0)
	{
	cout<<"������ h ������ �����������, ������� h ��������";
	cin>>p;
	h=p;
	}
	cout<<"������� ����� � (��������� �������� ���������): ";
	cin>>a;
	cout<<"�������� ���� b (�������� �������� ���������): ";
	cin>>b;
	cout<<"������� �������� ���������������� ��������(������ 12 �������� �����������): ";
	cin>>v;
	for(j=1;j!=(m+1);j++)
	{
		double d1=1, d2=2,zn,nz;
//		s=s+((2*m)/((2*m+1)*(2*m-1)));
		_asm
		{
			finit
			fld m
			fld d2
			fmul //s0=2m
			fst nz
			fld d1
			fadd //s0=2m+1
			fst zn
			fld d2
			fsub
			fld zn
			fmul//s0=(2m+1)(2m-1)
			fst zn
			finit
			fld nz
			fld zn
			fdiv
			fld s
			fadd
			fst s
		}
	}
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	cout<<"* "<<left<<setw(30)<<""<<"* "<<left<<setw(43)<<"              ������� �����"<<" *"<<endl;
	cout<<"* "<<left<<setw(30)<<"     �������� ��������� �"<<left<<"* * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<"* "<<left<<setw(30)<<""<<"* "<<left<<setw(21)<<"     ����� tanH"<<"* "<<left<<setw(20)<<"    ����� tanh"<<" *"<<endl;
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
	if (a<b)
	{
		while (a<b)
		{
			o=tanh(2*pi*a);
			c=tanH(2*pi*a,v);
			cout<<setprecision(16)<<"* "<<left<<setw(30)<<a<<"* "<<left<<setw(21)<<c*s<<"* "<<left<<setw(20)<<o*s<<" *"<<endl;
			a+=h;
		}
	} 
	else
	{
		while(a>b)
		{
			o=tanh(2*pi*a);
			c=tanH(2*pi*a,v);
			cout<<setprecision(16)<<"* "<<left<<setw(30)<<a<<"* "<<left<<setw(21)<<c*s<<"* "<<left<<setw(20)<<o*s<<" *"<<endl;
			a-=h;
		}
	}
	o=tanh(2*pi*b);
	c=tanH(2*pi*b,v);
	cout<<setprecision(16)<<"* "<<left<<setw(30)<<b<<"* "<<left<<setw(21)<<c*s<<"* "<<left<<setw(20)<<o*s<<" *"<<endl;
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	system("pause");
}
