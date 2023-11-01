#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>

using namespace std;

string encryption(int key[2][2],string word);   
string decode(string Text, string Key);
 
void main() 
{
	setlocale(LC_ALL,"rus");
	string word="íàä¸æíîñòü";
	string vigen="ÆŞÄËÙÉÂÆ";
	string keyv="ÙÊ¨ÙÊ¨ÙÊ";
	string shifr;
	int key[2][2]={{25,25},{18,22}};
	cout<<"Çàøèôğîâûâàíèå øèôğîì Õèëëà"<<endl<<"String to encrypt is: "<<word<<endl;
	shifr=encryption(key,word);
	shifr=decode(vigen,keyv);
	cout<<"Ğàñøèôğîâûâàíèå øèôğîì Âèæåíåğà"<<endl<<"String to encrypt is: "<<vigen<<endl;
	cout<<"Encrypted string is: "<<shifr<<endl;
	system("pause");
}
 
string encryption(int key[2][2],string word1) 
{
    int i, j, k, b=0;
	string Z="ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß\n";
	const int mod=33;
	int encrypt[2]={0,0};
	int a[2]={0,0};
	string word2(word1);
	for (i = 0; i < word1.length(); i++)
    {
       word2[i] = toupper(word1[i]);
	}
	string word=word2.append(" ");
	string shifr(word);
	while(word[b]!=' ')
	{
		a[0]=Z.find(word[b]);
		a[1]=Z.find(word[b+1]);
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
                encrypt[i]=(encrypt[i]+a[j]*key[j][i])%mod;
			shifr[b+i]=Z[encrypt[i]];
		}
		b+=2;
	}
	shifr[b]='\0';
    cout<<"Encrypted string is: "<<shifr<<endl;
	return  shifr;
}

string decode(string Text, string Key)
{
	string Z="ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß\n";
    string result(Text);
	int c=0,sum=0,j=0,i=0;
	const int mod=33;
    for(i=0;i<Text.length();i++)
    {
		if(j>=Key.length())
            j=0;
        sum=Z.find(Text[i]);
        c=Z.find(Key[j]);
		sum=sum-c;
		if(sum<0)
			sum+=mod;
        result[i]=Z[sum];
        j++;
    }
	for (i = 0; i < result.length(); i++)
    {
       result[i] = tolower(result[i]);
	}
    return result;
}