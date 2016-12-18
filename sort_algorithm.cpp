#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

void shell_sort(int a[], int n);
void quick_sort(int a[], int n);
void _quick_sort(int a[], int l, int r);
int pertition(int a[], int l, int r);

int main(void)
{
	int a[100000], i;
	clock_t time1, time2;

	srand((unsigned)time(NULL));

	for(i = 0; i <= 99999; i++)
		a[i] = rand() % 100000;

	time1 = clock();
	shell_sort(a, 100000);
	time2 = clock();
	printf("shell%lf•b\n", ((double)time2 - (double)time1) / CLOCKS_PER_SEC);

	for(i = 0; i <= 99999; i++)
		a[i] = rand() % 100000;

	time1 = clock();
	quick_sort(a, 100000);
	time2 = clock();
	printf("quick%lf•b\n", ((double)time2 - (double)time1) / CLOCKS_PER_SEC);
	getch();

	return 0;
}

void shell_sort(int a[], int n)
{
	int h, i, j, t;

	for(h = 1; h < n/9; h = h * 3 + 1)
		;

	for(; h > 0; h /= 3)
	{
		for(i = 1; i < n; i ++)
		{
			j = i;
			while(j >= h && a[j - h] > a[j])
			{
				t = a[j];
				a[j] = a[j - h];
				a[j - h] = t;
				j -= h;
			}
		}
	}
}

int pertition(int a[], int l, int r)
{
	int i, j, pivot, t;

	i = (l + r) / 2;

	if((a[i] > a[l] && a[i] < a[r]) || (a[i] < a[l] && a[i] > a[r]))
	{
		t = a[i];
		a[i] = a[r];
		a[r] = t;
	}

	else if((a[l] > a[i] && a[l] < a[r]) || (a[l] < a[i] && a[l] > a[r]))
	{
		t = a[l];
		a[l] = a[r];
		a[r] = t;
	}
	
	pivot = a[r];

	i = l - 1;
	j = r;

	while(1)
	{
		while(a[++i] < pivot)
			;

		while(i < --j && a[j] > pivot)
			;

		if(i >= j)
			break;

		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	t = a[i];
	a[i] = a[r];
	a[r] = t;

	return i;
}

void _quick_sort(int a[], int l, int r)
{
	int v;

	if(l >= r)
		return;

	v = pertition(a, l, r);

	_quick_sort(a, l, v - 1);

	_quick_sort(a, v + 1, r);
}

void quick_sort(int a[], int n)
{
	_quick_sort(a, 0, n - 1);
}