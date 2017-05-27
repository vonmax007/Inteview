
/*
ID: f2011501
PROG: palsquare
LANG: C++
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string integer_base(int base, int num)
{
    string result = "";
    long t = 0;
    while (1)
    {
        t = num % base;
        num /= base;
        if (t <= 9)result = (char)( '0' + t ) + result;
        else result = (char)((t - 10 + 'A')) + result;
        if (num == 0)break;
    }
    return result;
}

bool is_Palindromic(string n)
{
    int i = 0;
    int j = n.length() - 1;
	bool re = true;
	for(; j >= i; ++i, --j)if(n[i] != n[j]){re = false; break;}
    return re;
}


int main()
{
    ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	int base;
	fin>>base;

    for(int n=1; n<=300;++n)
    {
        string n1, ns;
        n1 = integer_base(base, n);
        ns = integer_base(base, n*n);
        if( is_Palindromic( ns ) )fout<<n1<<" "<<ns<<endl;
    }

    return 0;
}
