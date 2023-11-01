//yadlovskiy

#include "strochechki.h"
#include "spisok.h"
#include "array.h"

void  myprint(FILE *out, int *m, int n)
{
	for (int y=0; y<n; ++y)
	{
		if (m[y]<=9999)
			fprintf(out, "%-5d ", m[y]);
		else
			fprintf(out, "%-d ", m[y]);
	}
	fprintf(out, "\n");
}

void sorti(int *m, int n)// moja sortirovka
{
	int tt;
	for (int x=0; x<n-1; ++x)
		for (int y=n-1; y>x; --y)
			if ((m[y]%10)<(m[y-1]%10))
			{
				tt=m[y];
				m[y]=m[y-1];
				m[y-1]=tt;
			}
}




int summa(int k)//poisk s rekursiej , ya ee ispolzuju v funkcii lenikk
{
	int i=0;
	i=k%10;
	i=i*i*i;
	if (((int)(k/10))==0)
		return i;
	i+=summa((int )(k/10));
	return i;
}


int lenikk(int ka)// podschet kolichestva chlenov posledovatel'nosti
{
	int y=0, k=ka;
	while (k!=153)
	{
		++y;
		k=summa(k);
	}
	return y;
}
int main ()
{
	mymain();
	FILE *in, *out;
	if ((in=fopen("input.txt","r"))==NULL)
		return -1;
	out=fopen("out.txt","w");
	char str[88];

	first = last = st = new STUDENT;

	int i=0, j=0, k=0, t=0;

	while (!feof(in))
	{
		fgets(str, 82, in);
		if (end_str(str[i=0]))
			continue;
		if ( digit(str[0]) && word_digit(str))
		{
			st->yess=word_to_int(str+i);
			if (!(st->yess % 3))
				++t;
			++k;
			add(st);
			st=st->next;
		}

		while (!end_str(str[++i]))
			if ((razd(str[i-1]))&&(digit(str[i]))&&(word_digit(str+i)))
			{
				st->yess=word_to_int(str+i);
				if (!(st->yess % 3))
					++t;
				++k;
				add(st);
				st=st->next;
			}

	}
	fprintf(out,"Matrica Matr sostoit iz %d strok\n", t+3);
	int **Matr;
	Matr= new  int *[t+3];
	Matr[0]= new int [k];
	Matr[1]= new int [t];
	Matr[2]= new int [t];
	st=first;
	i=0;
	j=0;
	while (st->next!=NULL)
	{
		Matr[0][i++]=st->yess;
		if (!(st->yess%3))
			Matr[1][j++]=Matr[2][j]=st->yess;
		st=st->next;
	}
	sorti(Matr[2],t);
	myprint(out, Matr[0], k);
	myprint(out, Matr[1], t);
	myprint(out, Matr[2], t);
	i=0; j=3;
	int yy, kk , oo;
	for (; j<t+3; ++j)
	{
		yy=lenikk(Matr[2][j-3]);
		Matr[j]=new int [yy+2];
		Matr[j][0]=yy;
		kk=Matr[j][1]=Matr[2][j-3];
		postroenie_posledovatel(Matr[j]);
		myprint(out, Matr[j],yy+2);
	}
	for (int u=0; u<t+3; ++u)
		delete [] (Matr[u]);
	delete Matr;
	dell(st);
	fclose(in);
	fclose(out);
	return 2010;
}

//yadlovskiy