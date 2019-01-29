#include "mips.h"

int add (int b, int c) 
{ 
	return b+c;
}

int sub (int b, int c) 
{ 
	return b-c;
}

int e (int b, int c) 
{ 
	return b&c;
}

int ou (int b, int c) 
{ 
	return b|c;
}

int slt (int b, int c) 
{
	int a;
	if (b < c)
		return a=1;

	else if ( b > c)
		return a=0;
}

void apply (int v[], int a , int b, int c, int (*op) (int,int))
{
	v[a] = op(v[b], v[c]); 
}


int zeros (int v[])
{
	int cont=0;
	int i;
	for (i=0; i <10 ; i++)
	{
		if (v[i] == 0)
		{
			cont++;
		}
	}
	return cont;
}

int ones (int v[])
{
	int cont=0;
	int i;
	for (i=0; i <10 ; i++)
	{
		if (v[i] == 1)
		{
			cont++;
		}
	}
	return cont;
}


int max (int v[])
{
	int max = v[0]; 
	int i;
	for (i=0; i<10 ; i++)
	{
		if (v[i] != 0 && v[i] != 1 && v[i] > v[max])
		{
			max = i;
		}
	}
	return max;
}

int min (int v[])
{
	int min = v[0]; 
	int i;
	for (i=0; i<10 ; i++)
	{
		if (v[i] != 0 && v[i] != 1 && v[min] > v[i])
			min=i;
	}
	return min;
}
