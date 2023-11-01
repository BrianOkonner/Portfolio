#include <iostream>
#include <fstream>
#include"head.h"

bool razdelitel (char c)
{
	char razd[7]={' ','.',',',':','-',';','!'};
    int i=0;
    bool induk=false;
    while ((i<14)&&(!induk))
    {
        if(c==razd[i])
            induk=true;
        i=i+1;
    }
    return (induk);
}