//Timinskii
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
//#include <sum.h>
//�������
int cubeSum(int n){
	int c, c3;
	if(n < 10) return n;
	else{
		c = n % 10;
		c3 = c*c*c;
		return (cubeSum(n / 10) + c3);
	}
}
void main(){
	int A[1000][100];
	int N[1000];//����� ���������� ������������������� ������� ���� �����
	int count=0;//���������� �����
	int tmp,k;//��������� ����������
	char  s[80];
	char * word;
	FILE *in, *out;
	in = fopen("Input.txt","r");      
	out = fopen("Output.txt","w");
	while(!feof(in)){
		fscanf(in, "%s", &s);
		word = strtok(s, ",.;:");
		while(word != NULL){ 
			puts(word);///////////������� ����������� �����
			fprintf(out, "%s\n", word);
			if(word[0] >= '0' || word[0] <= '9'){///���� ����� = �����
				sscanf(word, "%d", &tmp);        ///////////////////////////////
				A[0][count] = tmp;
				count++;
			}
			//fprintf(out, "%s\n", word);
			word = strtok(NULL, ",.;:");
		}
	}
	for(int i = 0;i < count;i++){//��������� ������������������ � �� �����
		k = 0;
		tmp = A[i][0];
		do{
			A[i][k] = tmp;
			tmp =cubeSum(tmp);
			k++;
			
		}while(tmp != 153);
		N[i] = k;
	}
	for(int i = 0;i < count;i++){
		printf("\n");
		for(int j = 0;j< N[i];j++)
			printf("%d ", A[i][j]);
	}
//////////////////////////////////////////////////////OUTPUT:
//fprintf(out, "%s", "agrae");

//	free(Matr);
	fprintf(out, "%d", A[0][0]);
	fclose(in);///////////////////////////////////////////
	fclose(out);
}
//Timinski