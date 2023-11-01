#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef unsigned char BYTE;
typedef unsigned long DWORD;

const char SZ_EXT[] = ".fix";


DWORD sumV(DWORD dw)
{
    DWORD dwResult = 0;

    while( dw )
    {
      dwResult ^= dw;
      dw >>= 1;
    }

    return dwResult & 1;
}


int main(int argc, char* argv[])
{
    DWORD dwH;
    DWORD dwV;
    DWORD B[31];

    int nRetCode = 0;
    size_t nBlockLen;

    FILE* fileIn = NULL;
    FILE* fileOut = NULL;

    char szfileOutname[_MAX_PATH + sizeof(SZ_EXT) - sizeof(SZ_EXT[0])];

    if( argc != 2 )
    {
      printf("Invalid program arguments!\n"
             "Usage:\n"
             "%s filename\n",
             argv[0]);
 	    return -1;
    }

    try {

      fileIn = fopen(argv[1], "rb");

      if( NULL == fileIn )
        throw "Cannot open source file";

      strcat(strcpy(szfileOutname, argv[1]), SZ_EXT);

      fileOut = fopen(szfileOutname, "wb");

      if( NULL == fileOut )
        throw "Destination file could not be opened";

      for(;;)
      {
        nBlockLen = fread(B, 1, sizeof(B), fileIn);

        if( nBlockLen < sizeof(B) )
        {
          if( !feof(fileIn) )
            throw "An error occurs while reading the source file";

          if( 0 == nBlockLen )
            break;

          memset(((BYTE*)B) + nBlockLen,
                 0, sizeof(B) - nBlockLen);
        }

        dwH = dwV = 0;

        for(int i = 0; i < (sizeof(B)/sizeof(B[0])); i++)
        {
          dwH ^= B[i];
          dwV = ( dwV | sumV(B[i]) ) << 1;
        }
      
        dwV |= sumV(dwH);
      
        if( fwrite(&dwH, 1, sizeof(dwH), fileOut) != sizeof(dwH)
			|| fwrite(&dwV, 1, sizeof(dwV), fileOut) != sizeof(dwV)
			|| fwrite(B, 1, nBlockLen, fileOut) != nBlockLen )
          throw "An error occurs during writing the destination file";
      }

    }
    catch( const char * szErrMsg )
    {
      puts(szErrMsg);
      nRetCode = -1;
    }

    if( fileIn != NULL )
    {
      fclose(fileIn);

      if( fileOut != NULL )
        fclose(fileOut);
    }

    return nRetCode;
}

