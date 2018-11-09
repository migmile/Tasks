// TextFiles.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>

int TxtFl1(const char * fnin,const char * fnout)
{
	/*
	 Создать файл, содержащий текстовые строки произвольной длины. Создать новый файл, записав в него первые буквы каждого слова исходного файла.
	*/
	FILE * flin,*flout;
	fopen_s(&flin, fnin, "r");
	if ( NULL == flin ) return 0;		// error opening input file 
	fopen_s(&flout, fnout, "w");
	if (NULL == flout) {
		fclose(flin); 
		return 0;
	}
	int isWS=0;
	while (!feof(flin))
	{
		char sim;
		sim = fgetc(flin);
		if (sim == ' ') isWS = 1;
		else if (isWS == 1) {
			isWS = 0;
			fputc(sim, flout);
		}
	}
	fclose(flin);
	fclose(flout);
	return 1;
}

int main()
{
	if (!TxtFl1("c://temp//test.fl", "c://temp//test2.fl")) std::cout << "error!\n"; 
}

