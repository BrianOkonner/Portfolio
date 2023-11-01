void PechDouble (double x)
{
   cout<<x<<endl;
}
void PechInt (int x)
{
   cout<<x<<endl;
}
void main()
{
        double xx=16.77;
	int x=100;
	
	_asm
	{
	  sub         esp,8 
          fld         qword ptr xx 
	  call PechDouble
   	}  
	_asm
	{
	  push  x
          call PechInt
	  pop x
   	}
} 