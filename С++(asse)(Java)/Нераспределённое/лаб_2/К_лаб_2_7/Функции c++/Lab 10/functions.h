void delEndl(char* &str1);	//������� ������� ������ � ����� str1
bool ifSent(char* sentence,char* str);//1, ���� sentence ���� � str, ����� 0
char* findFirstWord(char* str,int& len);	//���������� ��������� �� 1� �����, � len - ����� �����
char* findLastWord(char* str,int& len);	//���������� ��������� �� ��������� �����, � len - ����� �����
char* addWordEnd(char* &dest,char* source,unsigned int n=0);
char* detFirstWord(char* &str);	//�������� 1� ����� �� str � ���������� ��������� �� 1� �����
void sortArrWord(char** &arr1,int len);	//���������� ������� arr1 ����� len ������� �������� (������ ��� ��� ������� ����� ����������� � asm � �� ������� ����)