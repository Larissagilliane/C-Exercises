#ifndef __MIPS_H__
#define __MIPS_H__

#include <iostream>
using namespace std;

int add (int b, int c) ;
int sub (int b, int c) ;
int e (int b, int c) ;
int ou (int b, int c);
int slt (int b, int c) ;
void apply (int v[], int a , int b, int c, int (*op) (int,int));

int zeros (int v[]);
int ones (int v[]);
int max (int v[]);
int min (int v[]);


#endif /* __MIPS_H__ */