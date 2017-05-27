/*
ID: f2011501
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string comet, group;
    fin>>comet;
    fin>>group;
    int result1 = 1,result2 = 1;
    for(int i=0;i<comet.length();++i)result1 *= (comet[i] - 'A' + 1);
    for(int i=0;i<group.length();++i)result2 *= (group[i] - 'A' + 1);

    if(result1 % 47 == result2 % 47)fout<<"GO";
    else fout<<"STAY";
    fout<<endl;
    fin.close();
    fout.close();
    return 0;
}
