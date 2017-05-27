
/*
ID: f2011501
PROG: dualpal
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
    ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int N, S, base = 2, base_count = 0, num_count = 0;
	fin>>N>>S;

    for(int n = S + 1; num_count < N;++n)
    {
        for(base = 2; base < 11; ++base)
        {
            string n_base = integer_base(base, n);
            if( is_Palindromic( n_base ) && base_count < 2 ){++base_count; }//cout<<n<<"--"<<base<<"--"<<integer_base(base, n)<<endl;}
            if(base_count == 2){++num_count; fout<<n<<endl; break;}
        }
        base_count = 0;
    }

    //cout<<integer_base(8, 111)<<endl;
    return 0;
}
