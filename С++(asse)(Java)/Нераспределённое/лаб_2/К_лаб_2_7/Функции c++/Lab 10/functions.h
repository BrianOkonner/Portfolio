void delEndl(char* &str1);	//убирает перенос строки в конце str1
bool ifSent(char* sentence,char* str);//1, если sentence есть в str, иначе 0
char* findFirstWord(char* str,int& len);	//возвращает указатель на 1е слово, в len - длину слова
char* findLastWord(char* str,int& len);	//возвращает указатель на последнее слово, в len - длину слова
char* addWordEnd(char* &dest,char* source,unsigned int n=0);
char* detFirstWord(char* &str);	//отделяет 1е слово от str и возвращает указатель на 1е слово
void sortArrWord(char** &arr1,int len);	//сортировка массива arr1 длины len методом пузырька (выбран был как удобней всего реализуемый в asm и на массиве слов)