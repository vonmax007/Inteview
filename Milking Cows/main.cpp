/*
ID: f2011501
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Time
{
    int start;
    int end;
    Time(int ss, int ee){start = ss; end = ee;};
};

bool my_cmp(Time t1, Time t2)
{
    return (t1.start < t2.start);
}


int main()
{
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int N;
    fin>>N;
    vector <Time> time;
    int start, end;

    for(int i=0;i<N;++i)
    {
        fin>>start>>end;
        Time tt(start, end);
        time.push_back(tt);
    }
    sort(time.begin(), time.end(), my_cmp);
    for(vector<Time>::iterator it = time.begin(); it != time.end();++it)
    {
        for(vector<Time>::iterator itt = it + 1; itt != time.end();++itt)
        {
            if(itt->start > it->end)continue;
            else if(itt->start <= it->end && it->end < itt->end)//合并两项
            {
                it->end = itt->end;
                //if(itt != time.end()-1)time.earse(itt++);
                time.erase(itt);
                --itt;
            }
            else if(itt->start <= it->end && it->end >= itt->end)
            {
                time.erase(itt);
                --itt;
            }
        }
    }

    int lc = 0, li = 0;
    for(vector<Time>::iterator it = time.begin(); it != time.end();++it)
    {
        if(lc < (it->end - it->start))lc = it->end - it->start;
        if(it != (time.end() - 1) && li < ((it+1)->start - it->end))li = (it+1)->start - it->end;
    }

    fout <<lc<<" "<<li<< endl;
    fin.close();
    fout.close();
    return 0;
}
