#define MAX 100
#include<windows.h>
#include<fstream.h>
#include<string.h>

void f1(istream& in1,istream& in2,ostream& out);
void f2(istream& in1,istream& in2,ostream& out);
void f3(istream& in1,istream& in2,ostream& out);
void f4(istream& in1,ostream& out);
void f5(istream& in1,ostream& out);
int cmp1(const void* s1,const void* s2);
int cmp2(const void* s1,const void* s2);
int cmp3(const void* s1,const void* s2);

struct  Student{
	long	num;		// номер зачетки
	char	name[10];	// имя студента
	int	    group;		// номер группы
	double	grade;		// средний бал
};
int main(){
	char in1_name[25]="Input1.txt";
	char in2_name[25]="Input2.txt";
	char c;
	cout<<"Input name file 1?(default \"Input1.txt\") (y/n):\n";	cin>>c;	if(c=='y')cin>>in1_name;
	cout<<"Input name file 2?(default \"Input2.txt\") (y/n):\n";    cin>>c; if(c=='y')cin>>in2_name;
	cout<<"Name file 3: \"Out.txt\""<<endl;
	ifstream in1(in1_name);
	ifstream in2(in2_name);
	ofstream out("Out.txt");
	
	char coment[600]="Выберите операцию:\n\t1.\tоперация объединения включает в результирующий файл только\n\t\tтакие записи, которые находятся хотя бы в одном из двух\n\t\tвходных файлах;\n\n\t2.\tоперация пересечения включает в результирующий файл только\n\t\tтакие записи, которые находятся одновременно в двух\n\t\tвходных файлах;\n\n\t3.\tоперация разности включает в результирующий файл только\n\t\tтакие записи, которые находятся в первом файле и отсутствуют\n\t\tво втором файле;\n\n\t4.\tсортировать файл 1 по номерам зачеток;\n\n\t5.\tсортировать файл 1 по номерам групп, а внутри групп\n\t\tпо фамилиям студентов.\n";
	CharToOem(coment,coment);cout<<coment;

	cin>>c;
	switch(c){
		case'1':f1(in1,in2,out);break;
		case'2':f2(in1,in2,out);break;
		case'3':f3(in1,in2,out);break;
		case'4':f4(in1,out);break;
		case'5':f5(in1,out);
	}

	in1.close();
	in2.close();
	out.close();
	
	return 0;
}
void f1(istream& in1,istream& in2,ostream& out){
	Student *tmp=new Student[MAX];
	int i,j,k;
	cout<<"file 1:"<<endl;
	for(i=0;!in1.eof();i++){
		in1>>tmp[i].num;	cout<<tmp[i].num<<"\t";
		in1>>tmp[i].name;	cout<<tmp[i].name<<"\t";
		in1>>tmp[i].group;	cout<<tmp[i].group<<"\t";
		in1>>tmp[i].grade;	cout<<tmp[i].grade<<endl;
	}
	cout<<"file 2:"<<endl;
	for(;!in2.eof();i++){
		in2>>tmp[i].num;	cout<<tmp[i].num<<"\t";
		in2>>tmp[i].name;	cout<<tmp[i].name<<"\t";
		in2>>tmp[i].group;	cout<<tmp[i].group<<"\t";
		in2>>tmp[i].grade;	cout<<tmp[i].grade<<endl;
	}
	cout<<"result:"<<endl;
	for(j=0;j<i;j++){
		for(k=j+1;k<i;k++)
			if(tmp[k].num==tmp[j].num)break;
		if(k==i){
			out<<tmp[j].num<<"\t";	cout<<tmp[j].num<<"\t";
			out<<tmp[j].name<<"\t";	cout<<tmp[j].name<<"\t";
			out<<tmp[j].group<<"\t";cout<<tmp[j].group<<"\t";
			out<<tmp[j].grade<<"\t";cout<<tmp[j].grade<<"\t";
			out<<endl;				cout<<endl;
		}
	}
	delete[]tmp;
}
void f2(istream& in1,istream& in2,ostream& out){
	Student *tmp=new Student[MAX];
	int i,j,k,amaunt_in1;
	cout<<"file 1:"<<endl;
	for(i=0;!in1.eof();i++){
		in1>>tmp[i].num;	cout<<tmp[i].num<<"\t";
		in1>>tmp[i].name;	cout<<tmp[i].name<<"\t";
		in1>>tmp[i].group;	cout<<tmp[i].group<<"\t";
		in1>>tmp[i].grade;	cout<<tmp[i].grade<<endl;
	}
	amaunt_in1=i;
	cout<<"file 2:"<<endl;
	for(;!in2.eof();i++){
		in2>>tmp[i].num;	cout<<tmp[i].num<<"\t";
		in2>>tmp[i].name;	cout<<tmp[i].name<<"\t";
		in2>>tmp[i].group;	cout<<tmp[i].group<<"\t";
		in2>>tmp[i].grade;	cout<<tmp[i].grade<<endl;
	}
	cout<<"result:"<<endl;
	for(j=0;j<amaunt_in1;j++){
		for(k=amaunt_in1;k<i;k++)
			if(tmp[k].num==tmp[j].num)break;
		if(k!=i){
			out<<tmp[j].num<<"\t";	cout<<tmp[j].num<<"\t";
			out<<tmp[j].name<<"\t";	cout<<tmp[j].name<<"\t";
			out<<tmp[j].group<<"\t";cout<<tmp[j].group<<"\t";
			out<<tmp[j].grade<<"\t";cout<<tmp[j].grade<<"\t";
			out<<endl;				cout<<endl;
		}
	}
	delete[]tmp;
}
void f3(istream& in1,istream& in2,ostream& out){
	Student *tmp=new Student[MAX];
	int i,j,k,amaunt_in1;
	cout<<"file 1:"<<endl;
	for(i=0;!in1.eof();i++){
		in1>>tmp[i].num;	cout<<tmp[i].num<<"\t";
		in1>>tmp[i].name;	cout<<tmp[i].name<<"\t";
		in1>>tmp[i].group;	cout<<tmp[i].group<<"\t";
		in1>>tmp[i].grade;	cout<<tmp[i].grade<<endl;
	}
	amaunt_in1=i;
	cout<<"file 2:"<<endl;
	for(;!in2.eof();i++){
		in2>>tmp[i].num;	cout<<tmp[i].num<<"\t";
		in2>>tmp[i].name;	cout<<tmp[i].name<<"\t";
		in2>>tmp[i].group;	cout<<tmp[i].group<<"\t";
		in2>>tmp[i].grade;	cout<<tmp[i].grade<<endl;
	}
	cout<<"result:"<<endl;
	for(j=0;j<amaunt_in1;j++){
		for(k=amaunt_in1;k<i;k++)
			if(tmp[k].num==tmp[j].num)break;
		if(k==i){
			out<<tmp[j].num<<"\t";	cout<<tmp[j].num<<"\t";
			out<<tmp[j].name<<"\t";	cout<<tmp[j].name<<"\t";
			out<<tmp[j].group<<"\t";cout<<tmp[j].group<<"\t";
			out<<tmp[j].grade<<"\t";cout<<tmp[j].grade<<"\t";
			out<<endl;				cout<<endl;
		}
	}
	delete[]tmp;
}
void f4(istream& in1,ostream& out){
	Student *tmp=new Student[MAX];
	cout<<"file 1:"<<endl;
	int i,j;
	for(i=0;!in1.eof();i++){
		in1>>tmp[i].num;	cout<<tmp[i].num<<"\t";
		in1>>tmp[i].name;	cout<<tmp[i].name<<"\t";
		in1>>tmp[i].group;	cout<<tmp[i].group<<"\t";
		in1>>tmp[i].grade;	cout<<tmp[i].grade<<endl;
	}
	qsort(tmp,i,sizeof(Student),cmp1);
	cout<<"result in file 3 (\"Out.txt\"):"<<endl;
	for(j=0;j<i;j++){
		out<<tmp[j].num<<"\t";	cout<<tmp[j].num<<"\t";
		out<<tmp[j].name<<"\t";	cout<<tmp[j].name<<"\t";
		out<<tmp[j].group<<"\t";cout<<tmp[j].group<<"\t";
		out<<tmp[j].grade<<"\t";cout<<tmp[j].grade<<"\t";
		out<<endl;				cout<<endl;
	}
}
void f5(istream& in1,ostream& out){
	Student *tmp=new Student[MAX];
	cout<<"file 1:"<<endl;
	int i,j;
	for(i=0;!in1.eof();i++){
		in1>>tmp[i].num;	cout<<tmp[i].num<<"\t";
		in1>>tmp[i].name;	cout<<tmp[i].name<<"\t";
		in1>>tmp[i].group;	cout<<tmp[i].group<<"\t";
		in1>>tmp[i].grade;	cout<<tmp[i].grade<<endl;
	}
	qsort(tmp,i,sizeof(Student),cmp3);
	cout<<"result in file 3 (\"Out.txt\"):"<<endl;
	for(j=0;j<i;j++){
		out<<tmp[j].num<<"\t";	cout<<tmp[j].num<<"\t";
		out<<tmp[j].name<<"\t";	cout<<tmp[j].name<<"\t";
		out<<tmp[j].group<<"\t";cout<<tmp[j].group<<"\t";
		out<<tmp[j].grade<<"\t";cout<<tmp[j].grade<<"\t";
		out<<endl;				cout<<endl;
	}
}
int cmp1(const void* s1,const void* s2){return ((Student*)s1)->num-((Student*)s2)->num;}
int cmp2(const void* s1,const void* s2){return strcmp(((Student*)s1)->name,((Student*)s2)->name);}
int cmp3(const void* s1,const void* s2){
	if(((Student*)s1)->group-((Student*)s2)->group<0)		return -1;
	if(((Student*)s1)->group-((Student*)s2)->group>0)		return 1;

	if(cmp2(s1,s2)<0&&((Student*)s1)->group-((Student*)s2)->group==0)	return -1;
	if(cmp2(s1,s2)==0&&((Student*)s1)->group-((Student*)s2)->group==0)	return 0;
	if(cmp2(s1,s2)>0&&((Student*)s1)->group-((Student*)s2)->group==0)	return 1;
}