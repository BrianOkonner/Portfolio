/*					������ �b9
	��������� ������� ��������� ������������ ������������.( �������������: ���������� ������������. ������ 8).
	������� :������ ��� ������������� ����������� ������������������ A=(ai), i=1..n, n<=100 � B=(bi), i=1..n, n<=100,
�.�. ���� ���������� ��������. ���������� ��� ������� ���, ����� �������������� ������ ���� ������  ������������.
	�������� �������� :������ 3 ������� ��������� rand. ��������� 2 ������� ������� ����������� ��������. ����� ����������� � 
�������������� ������ 3 ������ ��� ���� �� ��� ������ ������������(�������� ��������� � ����� fun.cpp ������� frm_2ndcrs_to_ncrs). 
������� 3 ������� ����������.
	�����: 
	������� n (n<=100): 15

����� ����������: 10.202
     �������:
1-�� �����������    2-�� �����������    ������������ ������
1                   10                  1
5                   21                  5
5                   21                  10
30                  24                  21
32                  26                  24
49                  36                  26
60                  45                  30
60                  47                  32
92                  49                  36
95                  58                  45
96                  61                  47
97                  66                  49
97                  69                  58
99                  89                  60
99                  95                  61
                                        66
                                        69
                                        89
                                        92
                                        95
                                        96
                                        97
                                        99
������� n (n<=100): 100

����� ����������: 5.569
     �������:
1-�� �����������    2-�� �����������    ������������ ������
1                   0                   0
3                   0                   1
4                   1                   2
5                   2                   3
6                   4                   4
6                   5                   5
6                   8                   6
10                  10                  8
11                  11                  10
14                  17                  11
18                  18                  14
19                  19                  17
19                  21                  18
19                  21                  19
20                  21                  20
21                  21                  21
21                  21                  22
22                  23                  23
22                  24                  24
23                  24                  25
23                  24                  26
23                  25                  27
23                  25                  28
24                  27                  29
26                  27                  30
26                  28                  31
30                  28                  32
30                  29                  33
31                  29                  34
31                  29                  35
32                  30                  36
35                  32                  38
35                  32                  39
36                  33                  40
36                  33                  41
36                  34                  42
39                  34                  43
41                  35                  44
42                  36                  46
42                  36                  47
44                  36                  48
46                  38                  49
46                  38                  50
47                  40                  51
48                  41                  52
50                  43                  53
51                  44                  54
52                  46                  55
53                  48                  56
54                  49                  57
54                  49                  58
54                  50                  59
55                  50                  62
58                  51                  63
59                  51                  64
59                  52                  65
62                  54                  66
62                  54                  67
64                  55                  68
64                  55                  69
64                  56                  70
65                  56                  71
65                  57                  72
65                  58                  73
67                  63                  75
69                  64                  76
70                  66                  77
71                  66                  78
73                  68                  79
75                  68                  80
75                  68                  81
76                  70                  82
77                  71                  83
78                  71                  86
80                  71                  87
80                  71                  88
81                  72                  89
82                  72                  90
82                  73                  92
83                  77                  94
83                  78                  95
86                  79                  96
86                  80                  98
88                  81                  99
88                  81
88                  81
88                  87
89                  88
89                  88
89                  89
90                  89
92                  92
95                  92
96                  92
96                  94
98                  94
98                  95
99                  96
99                  98
99                  99*/
#include <iostream>
#include <iomanip>
#include "fun_h.h"
#include <ctime>
using namespace std;
void main()
{
	int *a,*b,*h,n,i=0;
	a=new int[101];
	b=new int[101];
	h=new int[101];
	unsigned int clk;
	setlocale(LC_ALL,".1251");
	cout<<"������� n (n<=100): ";
	cin>>n;
	mass_cel_rand2(b,n);//���� ��������
	mass_cel_rand2(a,n);
	bubble_srt(a,n);//�� ���������� (������ �� ��������� - �����������)
	bubble_srt(b,n);
	clk=clock();
    frm_2ndcrs_to_ncrs(a,b,n,h);//�������� 3-��� �������
	cout<<endl<<"����� ����������: "<<clk/1000.0<<endl;//����� ���������� �������� ������(3 ������������ ������)
	vvd_L3B9(a,b,h,n);
	system("pause");
}
