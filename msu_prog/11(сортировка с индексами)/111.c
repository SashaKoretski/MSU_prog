//111_Корецкий_Александр_сортировка_индексов

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include<stdlib.h>
#include<time.h>

#include "d_p.h"

#define N 16000
#define eps 0,00001

int main() {
	double arr[N];
	int index[N];
	double time;
	int i;
	clock_t st, end; 
	char myfilename[120];
	FILE*fin;

	printf("Vvedite imia faila, gde vi hotite sgenerirovat' posledovatel'noct'-->"); //открываем файл
	scanf("%s", myfilename); 
	fin = fopen(myfilename, "w"); 
	
	if (!fin) { 
		printf("Ne udalod' naiti fail %s\n", myfilename); //проверяем, есть ли вообще такой файл
		return -1;
	}
	
	gen(arr, N); //генерация массива
	
	for (i = 0; i < N; i += 1)
	{
		index[i] = i;
	}
	
	fprintf(fin, " ");
	for (i = 0; i < N; i+=1) //запись массива в файл
    {
        if (i % 10 != 0)
            fprintf(fin, "%7.3lf ", arr[i]);
        if (i % 10 == 0 && i != 0)
            fprintf(fin, "%7.3lf\n ", arr[i]);
    }
	
	st = clock();
	sort(arr, index, N); //сортировка массива
	end = clock();
	time = (double)(end - st) / CLOCKS_PER_SEC; //подсчет времени
	
	fprintf(fin, "\n");
	fprintf(fin, "\n");
    fprintf(fin, "Otsortirovannaia posledovatelnost'\n");
    fprintf(fin, "\n");
	fprintf(fin, " ");
	
	if (check(arr, N) == 1) //проверка на отсортированность
	{
		printf("OSHIBKA");
	}
	else
	{
		for (i = 0; i < N; i+=1) //запись отсортированного массива в файл
		{
			if (i % 10 != 0)
				fprintf(fin, "%7.3lf ", arr[index[i]]);
			if (i % 10 == 0 && i != 0)
				fprintf(fin, "%7.3lf\n ", arr[index[i]]);
		}
	
		printf ("%lf", time); //вывод времени
	}
	return 0;
}
