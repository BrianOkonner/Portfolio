void poisk_inf(char* sl,int& kol_max, char& n_max,int& nom_max)
{

int nom,kol;
int dlinna = strlen(sl);
int por = 0;
char n = NULL;


n = *sl;
nom = por;
kol = 0;

	while(por < dlinna)
{		

while(*sl == n && por < dlinna)
{
	sl++;
	kol++;
	por++;
}

if(kol > kol_max)
{
	kol_max = kol;
	n_max = n;
	nom_max = nom;
}
else
{
	kol = 0;
}
n = *sl;
por++;
nom = por;


}

}