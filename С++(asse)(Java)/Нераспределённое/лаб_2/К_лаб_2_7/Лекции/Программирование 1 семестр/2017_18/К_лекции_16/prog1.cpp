//Поиск наибольшей подпоследовательности
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int max(int  A, int B)

{ 
	if (A == B) return A;
	if (A < B) return B;
    if (A > B) return A;
   
    }



char* getLongComSub(char *a, char *b)
    {
      char **max_len,*res;
       max_len= (char **) malloc(strlen (a) + 1);
        res= (char *) malloc(strlen (b) + 1);
        for(int i = 0; i <= strlen (a); i++)
            max_len[i]= (char *) malloc(strlen (b) + 1);
        for( i = strlen (a)- 1; i >= 0; i--)
        {
            for(int j = strlen (b) - 1; j >= 0; j--)
            {
                if(a[i] == b[j])
                {
                    max_len[i][j] = 1 + max_len[i+1][j+1];
                }
                else
                {
                    max_len[i][j] = max(max_len[i+1][j], max_len[i][j+1]);
                }
            }
        }
   int j,k=0;
        for( i = 0,  j = 0; max_len[i][j] != 0; )
        {
            if(a[i] == b[j])
            {
                res[k]=a[i];
				res[k+1]='\0';
				printf("%s\n",res);
				k++;
                i++;
                j++;
            }
            else
            {
                if(max_len[i][j] == max_len[i+1][j])
                    i++;
                else
                    j++;
            }
        }
        return res;
    }

void main ()
{
char s1[]="nano                 ";
char s2[]="nematode knowledge";
char s3[]="empty bottle";
char *s11=s1;
char *s22=s2;
char *s33=s3;
s11= getLongComSub(s22, s33);

printf("res=%s",s11);
}
//emt ole

