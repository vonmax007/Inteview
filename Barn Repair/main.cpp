/*
ID: f2011501
PROG: barn1
LANG: C++
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int M, S, C;
    fin>>M>>S>>C;

    vector <int> vc;
    vector <int> vc_input;
    int temp = 0;
    for(int i=0; i<C; ++i){fin>>temp;vc_input.push_back(temp);}

    sort(vc_input.begin(), vc_input.end(), less<int>());
    cout<<"\n\n **** intervals are :\n";
    for(int i=1; i<C; ++i)
    {
        temp = vc_input[i] - vc_input[i-1] - 1;
        cout<<"n1 :"<<vc_input[i]<<"   n2:"<<vc_input[i-1]<<"     interval:"<<temp<<endl;
        vc.push_back(temp);
    }
    sort(vc.begin(), vc.end(), greater<int>());
    //cout<<vc[0];

    int sum = 0;
    for(int i=0; i<M-1; ++i)
    {
        cout<<vc[i]<<endl;
        sum += vc[i];
    }
    if(M >= C)fout<<C<<endl;
    else
    fout<<vc_input[C-1] - vc_input[0] + 1 - sum<<endl;

    return 0;
}
