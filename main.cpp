/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Abdul
 *
 * Created on April 11, 2018, 3:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;




long comparisons = 0;
long exchanges = 0;
ofstream fout("output.txt");

void ran(int a[], int N) {
    int i;
    srand((unsigned) time(NULL)); //Give us a random array that will be fixed for all sorts
    for (i = 0; i < N; i++)
        a[i] = int(1000 * (1.0 * rand() / RAND_MAX));
}

void initial(int a[], int b[], int N) {
    int i;
    for (i = 0; i < N; i++) a[i] = b[i];
}

void output(int a[], int l, int r) {
    int i;
    for (i = l; i <= r; i++) fout << a[i] << " ";
    fout << endl;
}


static int knownF[50];

int fib(int i)
{
	if (i < 0) return 0;
	if(knownF[i] != 0) return knownF[i];
	int t = i;
	if(i > 1) t = fib(i-1) + fib(i-2);
	return knownF[i] = t;
}

void shellsort(int a[], int l, int r) {
    int i, j, h, v;
    for (h = 0; fib(h) <= (r); h++);
    for (; h > 0; h--)
        for (i = l + fib(h); i <= r; i++) {
            j = i;
            v = a[i];
            while (j >= l + fib(h) && v < a[j - fib(h)]) {
                a[j] = a[j - fib(h)];
                j -= fib(h);
            }
            a[j] = v;
        }

}

int main(int argc, char *argv[]) {
    int i, N = atoi(argv[1]), sw = atoi(argv[2]);
    int *a = new int[N], *b = new int[N];
    string filename;
    int choice = 0;
    
    if (sw)
        ran(a, N);
    else {
        cout << "enter file name" << endl;
        cin >> filename;
        ifstream fin(filename.c_str());
        for (i = 0; i < N; i++) fin >> a[i];
    }
    
    for (i = 0; i < N; i++) {
        fout << a[i] << " ";
    }
    
    fout << endl;
    shellsort(a, 0, N - 1);
    fout << "Shell Sort " << endl;
    output(a, 0, N - 1);

    return 0;
}

