#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <string.h>

typedef struct {
	char name[10];
	int kor;
	int eng;
	double tot;
	double avg;
} STU;

void SWAP(void* a, void* b, int op)
{
	if (op == 1)	// char
	{
		char c = *(char*)a;
		*(char*)a = *(char*)b;
		*(char*)b = c;
	}
	if (op == 4)	// int, flo
	{
		int c = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = c;
	}
	if (op == 8)	// double
	{
		double c = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = c;
	}
	if (op == sizeof(STU))	// STU
	{
		STU c = *(STU*)a;
		*(STU*)a = *(STU*)b;
		*(STU*)b = c;
	}
}

const int nArr = 10;
STU student[nArr];

void  sortSTU(STU* a, int n)
{
	int i, j, k;

	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if ((a + i)->avg < (a + j)->avg)	// 구조체 포인터의 값  ===> a[i].avg < a[j].avg
			{
				SWAP(a + i, a + j, sizeof(STU));
			}
		}
	}
}

void sortTestEx()		// 구조체를 이용한 성적처리 - 파일 입출력
{
	double f_kor = 0.3, f_eng = 0.7;
	int i, j, k;

	FILE* fin = fopen("C:\\Users\\JALAB\\table2.txt", "r");
	FILE* fout = fopen("C:\\Users\\JALAB\\table2.rpt", "w+b");
	for (i = 0; i < nArr; i++) fscanf(fin, "%s", student[i].name);
	for (i = 0; i < nArr; i++) fscanf(fin, "%d", &student[i].kor);
	for (i = 0; i < nArr; i++) fscanf(fin, "%d", &student[i].eng);
	for (i = 0; i < nArr; i++)
	{
		student[i].tot = student[i].kor + student[i].eng;
		student[i].avg = student[i].tot / 2;
	}

	fprintf(fout, "Original :\n");
	fprintf(fout, "%-7s %-7s %-7s %-7s %-7s\n", "  이름", "  국어", "  영어", "  총점", "  평균");
	for (int i = 0; i < nArr; i++)
	{
		fprintf(fout, "%7s %7d %7d %7.2f %7.2f\n",
			student[i].name, student[i].kor, student[i].eng, student[i].tot, student[i].avg);
	}

	sortSTU(student, nArr);

	fprintf(fout, "\n\nSorted :\n");
	for (int i = 0; i < nArr; i++)
	{
		fprintf(fout, "%7s %7d %7d %7.2f %7.2f\n",
			student[i].name, student[i].kor, student[i].eng, student[i].tot, student[i].avg);
	}
}

int main()
{ 
	sortTestEx(); 
}

