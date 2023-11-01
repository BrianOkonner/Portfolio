//Лукашевич А.А. 5 гр.
#include <fstream>
#include <iostream>
using namespace std;
struct spisok{
	char* wrd;
	spisok* prev;
};
bool razd(char a){
	bool b=false;
	if(a==' ')
		b=true;
	if(a==',')
		b=true;
	if(a=='.')
		b=true;
	if(a==':')
		b=true;
	if(a==';')
		b=true;
	if(a=='!')
		b=true;
	if(a=='\0')
		b=true;
	return b;
}
spisok* gen(){
	spisok* sp1=new spisok;
	sp1->wrd=NULL;
	sp1->prev=NULL;
	return sp1;
}
spisok* push(char* a,spisok* b){
	spisok* sp1=new spisok;
	sp1->prev=b;
	sp1->wrd=a;
	return sp1;
}

int sch(int a){
	int b=0;
	while(a!=0){
		a=a&(a-1);
		b++;
	}
	return b;
}
void sort(int* a,int n){
	int c,d;
	for(c=0;c<n;c++)
		for(d=0;d<n-1;d++)
			if (sch(a[d])>sch(a[d+1]))
				swap(a[d],a[d+1]);
}
void main(){
	ifstream f1;
	ofstream f2;
	f2.open("Result1.txt");
	f1.open("Input.txt");
	char m1[80];	
	int i=0,j;
	while(f1.getline(m1,80)){
		j=0;
		spisok* z=gen();
		int l=0;
		while(m1[j]!='\0'){
			z=push(m1+j,z);
			while(!razd(m1[j]))
				j++;
			while(razd(m1[j])&&(m1[j]!='\0'))
				j++;
			l++;
		}
		spisok* z2=z;
		i++;
		//cout<<z->wrd;//
		while(z->wrd!=NULL){
			char ch=*(z->wrd),cm;
			j=0;
			int k=0,km=0,nm=0;
			while(!razd((z->wrd)[j])){
				if((z->wrd)[j]==ch)
					k++;
				else{
					if(k>km){
						km=k;
						cm=ch;
						nm=j;
					}
					ch=(z->wrd)[j];
					k=1;
				}
				j++;
			}
			if(k>km){
				km=k;
				cm=ch;
				nm=j-1;
			}
			f2<<l<<' ';
			j=0;
			while(!razd((z->wrd)[j])){
				f2<<(z->wrd)[j];
				j++;
			}
			f2<<' '<<cm<<' '<<km<<' '<<nm<<endl;
			z=z->prev;
			l--;
		}
	}
	f1.close();
}