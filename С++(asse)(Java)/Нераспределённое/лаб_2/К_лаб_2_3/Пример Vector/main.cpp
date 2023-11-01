include <cstdlib>
#include <iostream>
using namespace std;
struct bad_index
{
       int ind;
       bad_index(int i):ind(i){}
};
       
class Vect
{
      int n;
      int *v;
public:
       Vect(int n1):n(n1),v(new int[n1]){}
       ~Vect(){delete[]v;}
       int& operator[](int index)
       {
            if (index<0 ||index>=n)
               throw bad_index(index);
            return v[index];
       }
       friend  ostream&  operator<<(ostream& out, Vect& V)
       {
               for (int i=0;i<V.n;i++)
               out<<V[i]<<" ";
               out<<endl;
       }
};
int main()
{
    Vect V1(3);
try
{
    V1[0]=5;
    V1[1]=6;
    V1[2]=7;
    cout<<V1;
    V1[0]=V1[2]+V1[1];   
    cout<<V1;
    V1[3]=100;
}
catch (bad_index b)
{
      cout<< "bad_index = "<<b.ind<<endl;
}
    system("PAUSE");
    return 0;
}
