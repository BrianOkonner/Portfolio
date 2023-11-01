#include <iostream>
#include <iomanip>
using namespace std;
main()
{
 short     a,b,c,d;
 int e,f,g,h;
cin>> a>>b;
cin>>c>>d;

        e=int(a)*d+int(c)*b;
        f=int(b)*d;
        g=e; h=f;
        do
          if (g > h)
             g %=  h;
          else
             h %= g;
        while (g*h);

        cout<<setw(11)<<e / (g+h)<<setw(11)<<f / (g+h)<<endl;
_asm
{
        mov ecx, e           
        mov ebx, f
   repeat:
   if1:
        cmp ecx, ebx
        jng  else1
        mov eax, ecx
        cdq
        idiv ebx
        mov ecx, edx
        jmp  end_else
   else1:
        mov eax, ebx
        cdq
        idiv ecx
        mov ebx, edx
   end_else:
        mov eax, ecx
        imul ebx
   until:
        test eax,eax
        jnz  repeat

        add ebx,ecx
        mov eax, e
        cdq
        idiv ebx
        mov e, eax

        mov eax, f
        cdq
        idiv ebx
        mov f, eax
}
        cout<<setw(11)<<e <<setw(11)<<f <<endl;
		
}
        