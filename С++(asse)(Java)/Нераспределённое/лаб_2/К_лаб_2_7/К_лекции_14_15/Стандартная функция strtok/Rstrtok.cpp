void RStrtok(void)
// ���������� ������ �� ������� (�����)
{
char string[] = "A string\tof ,,tokens\nand some  more tokens";
char seps[]   = " ,\t\n";
char *token;

   printf( "Tokens:\n" );
 
   // ����� ������� �����:
   token = strtok( string, seps ); 
  
   while( token != NULL )
   {
      printf( " %s\n", token );

      // ����� ���������� �����: 
      token = strtok( NULL, seps ); 
   }
}

