#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <clocale>
#include <fstream>
#include <iostream>

#include "sha256.h"
#include "gen.cpp"
#include "fun_h.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");

	double g;
	ifstream in("input.txt");
	in>>g;
	cout.setf(ios::fixed);
    cout.precision(0);
	cout<<g;
	system("pause");
   /* BYTE text[] = "The quick brown fox jumps over the lazy dog";

    BYTE hash[SHA256_BLOCK_SIZE] =  {0xD7,0xA8,0xFB,0xB3,0x07,0xD7,0x80,0x94,0x69,0xCA,0x9A,0xBC,0xB0,0x08,0x2E,0x4F,
                                     0x8D,0x56,0x51,0xE4,0x6D,0x3C,0xDB,0x76,0x2D,0x02,0xD0,0xBF,0x37,0xC9,0xE5,0x92};

    BYTE buf[SHA256_BLOCK_SIZE];
    SHA256_CTX ctx;

    sha256_init(&ctx);
    sha256_update(&ctx, text, strlen((char *)text));
    sha256_final(&ctx, buf);

    bool pass = !memcmp(hash, buf, SHA256_BLOCK_SIZE);

    printf("SHA-256 tests: %s\n", pass ? "SUCCEEDED" : "FAILED");*/

    return 0;
}