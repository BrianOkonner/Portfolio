struct spisok_slov
{
	char* slovo;
	char simvol;
	int dl,pos,no;
	spisok_slov* next;
};

spisok_slov* add_el(spisok_slov*,char*,int);
void vvod_dannyh(spisok_slov*);
