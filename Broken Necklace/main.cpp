/*
ID: f2011501
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int re(int i, int length)
{
    if(i < 0)return length + i;
    if(i > length - 1)return i - length;
    else return i;
}

int Getnum(int pos, int dir, char color, string &necklace)
{
    int init_pos = pos;
    if(dir == 1 && color == 'b')
    {
        while( necklace[re(pos,necklace.length())] != 'r' )pos ++;
        return pos - init_pos;
    }
    else if(dir == 1 && color == 'r')
    {
        while( necklace[re(pos,necklace.length())] != 'b' )pos ++;
        return pos - init_pos;
    }
    else if(dir == 0 && color == 'r')
    {
        while( necklace[re(pos,necklace.length())] != 'b' )pos --;
        return init_pos - pos;
    }
    else if(dir == 0 && color == 'b')
    {
        while( necklace[re(pos,necklace.length())] != 'r' )pos --;
        return init_pos - pos;
    }
}

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    int length;
    fin>>length;
    string necklace;
    fin>>necklace;
    int max = 0;
    for(int i=0; i<length; ++i)
    {
        if(necklace[i] == necklace[i+1])continue;
        else if(necklace[i] == 'w' && necklace[i+1] == 'b')
        {
            int temp_b = Getnum(i+1, 1, 'b', necklace);
            int temp_r = Getnum(i, 0, 'r', necklace);
            if( max < temp_b + temp_r )max = temp_b + temp_r;
        }
        else if(necklace[i] == 'b' && necklace[i+1] == 'w')
        {
            int temp_b = Getnum(i, 0, 'b', necklace);
            int temp_r = Getnum(i+1, 1, 'r', necklace);
            if( max < temp_b + temp_r )max = temp_b + temp_r;
        }
        else if(necklace[i] == 'r' && necklace[i+1] == 'w')
        {
            int temp_b = Getnum(i+1, 1, 'b', necklace);
            int temp_r = Getnum(i, 0, 'r', necklace);
            if( max < temp_b + temp_r )max = temp_b + temp_r;
        }
        else if(necklace[i] == 'w' && necklace[i+1] == 'r')
        {
            int temp_b = Getnum(i, 0, 'b', necklace);
            int temp_r = Getnum(i+1, 1, 'r', necklace);
            if( max < temp_b + temp_r )max = temp_b + temp_r;
        }
        else if(necklace[i] == 'b' && necklace[i+1] == 'r')
        {
            int temp_b = Getnum(i, 0, 'b', necklace);
            int temp_r = Getnum(i+1, 1, 'r', necklace);
            if( max < temp_b + temp_r )max = temp_b + temp_r;
        }
        else if(necklace[i] == 'r' && necklace[i+1] == 'b')
        {
            int temp_b = Getnum(i+1, 1, 'b', necklace);
            int temp_r = Getnum(i, 0, 'r', necklace);
            if( max < temp_b + temp_r )max = temp_b + temp_r;
        }
    }
    if(max == 0)max = length;
    fout<<max<<endl;
    fin.close();
    fout.close();
    return 0;
}
