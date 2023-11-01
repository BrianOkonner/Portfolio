void RStrtok(void)
// разделение строки на лексемы (слова)
{
char string[] = "A string\tof ,,tokens\nand some  more tokens";
char seps[]   = " ,\t\n";
char *token;

   printf( "Tokens:\n" );
 
   // поиск первого слова:
   token = strtok( string, seps ); 
  
   while( token != NULL )
   {
      printf( " %s\n", token );

      // выбор следующего слова: 
      token = strtok( NULL, seps ); 
   }
}

