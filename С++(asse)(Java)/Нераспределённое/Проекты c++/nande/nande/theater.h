template < class T> class theaters
{
	template <class T> struct theater
	{
		char name[40];
		int spect;
		int nums;
	};
	int size;
	theater <T> *th;
public:
	theaters(int);
	//~theater();
	void input(char *,T *);
	char** find(T);
};
template <class T> theaters<T>::theaters(int n)
{
	int i;
	th= new theater<T>[n];
	size=n;
	for(i=0;i<n;i++)
		th[n].name[0]='\0';
}
template <class T> void theaters<T>::input(char *nam,T* spec)
{
	int i;
	for(i=0;i<size;i++)
		if(th[i].name[0]=='\0')
		{
			th[i].name=nam;
			th[i].spect=spec;
			break;
		}
}
template <class T> char ** theaters<T>::find(T spec)
{
	int i,j,k=0;
	char** namear;
	namear=new char *[size];
	for(i=0;i<size;i++)
		for(j=0;j<nums;j++)
			if(spec==th[i].spect[j])
			{
				namear[k]=spec;
				k++;
				break;
			}
	return namear;		
}