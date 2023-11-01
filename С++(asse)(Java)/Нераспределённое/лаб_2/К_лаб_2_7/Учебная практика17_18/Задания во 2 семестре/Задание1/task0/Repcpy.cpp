-#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
void Swap(char *a, char *b){
	char *c = new char[80];
	char nul = '\0';
	_asm{  //strcpy  без цепочечных команд
		
		mov esi, a
		mov edi, c
A1:		mov al,byte ptr[esi]
		mov byte ptr[edi], al
		add esi, 1
		add edi, 1
		cmp [esi], 0
		jne A1
	}
	c[strlen(a)] = '\0';
	strcpy( a, b);
	strcpy( b, c);

}

void Swap1(char *a, char *b){
	char *c = new char[80];
	char nul = '\0';
	int n=strlen (a);
	_asm{  //strcpy  без цепочечных команд  с командой Loop
		
		mov ecx,n
		inc ecx
		mov esi, a
		mov edi, c
A1:		mov al,byte ptr[esi]
		mov byte ptr[edi], al
		add esi, 1
		add edi, 1
		loop  A1
	}
	strcpy( a, b);
	strcpy( b, c);

}
void strcpyRep(char *a, char *b){
	char *c = new char[80];
	char nul = '\0';
int n=strlen(a);
	_asm //strcpy с  цепочечными командами

{
		mov ax,ds
		mov es,ax 
		mov esi, a
		mov edi, c
                mov ecx, n
                inc ecx
	rep     movsb
}

void Word(char *str, char *v, char *c, char *seps){
	char **a = new char*[80];
	for( int i = 0; i < 80; i++)
		a[i] = new char[80];
	char *b = strtok( str, seps);
	int k = 0;
	while(b){
		strcpy( a[k], b);
		b = strtok( 0, seps);
		k++;
	}
	for( int i = 0; i < k - 1; i++){
		if( strlen(a[i]) == strlen(a[i+1])){
			Swap( a[0], a[i]);
			Swap( a[i+1], a[k - 1]);
			break;
		}
	}
	strcpy( c, a[0]);
	int l = strlen(c);
	c[l] = ' ';
	c[l + 1] = '\0';
	for(int i = 1; i < k; i++){
		strcat(c, a[i]);
		l = strlen(c);
		c[l] = ' ';
	    c[l + 1] = '\0';
	}
	c[l] = '\0';
	for( int i = 0; i < k-1; i++){
		for( int j = i+1; j < k; j++){
		if( strlen(a[i]) < strlen(a[j])){
			Swap( a[i], a[j]);
		}
		}
	}	
	strcpy( v, a[0]);
	l = strlen(v);
	v[l] = ' ';
	v[l + 1] = '\0';
	for(int i = 1; i < k; i++){
		strcat(v, a[i]);
		l = strlen(v);
		v[l] = ' ';
	    v[l + 1] = '\0';
	}
	v[l] = '\0';
	delete [] a;
	delete [] b;
}
void main(){
	char seps[] = {",./;:&!?# ^@*)([]{'}"};
	ifstream in;
	ofstream out;
	ofstream outS;
	in.open("input.txt");
	out.open("output.txt");
	outS.open("Out_sort.txt");
	while( in.good() ){
		char *c = new char[80];
		char *v = new char[80];
	    char *str = new char[80];
		in.getline( str, 80); 
		Word(str, v, c, seps);
		outS << v << endl;
		cout << c << endl;
		delete [] v;
		delete [] c;
		delete [] str;
	}
	out.close();
	outS.close();
	system("pause");
}


		


		