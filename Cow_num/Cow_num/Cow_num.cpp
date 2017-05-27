
/*
ID: f2011501
PROG: namenum
LANG: C++
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree
{
	char letter;
	bool end;
	vector <Tree> child;
	Tree(char ch)
	{
		letter = ch;
		end = false;
	}
};

void Getcompose(int n, char * letters)
{
	/*
	2: A,B,C     5: J,K,L    8: T,U,V
	3: D,E,F     6: M,N,O    9: W,X,Y
	4: G,H,I     7: P,R,S
	*/
	//char * ch = new char[3];
	switch (n)
	{
	case 2:
		letters[0] = 'A';letters[1] = 'B';letters[2] = 'C';break;
	case 3:
		letters[0] = 'D';letters[1] = 'E';letters[2] = 'F';break;
	case 4:
		letters[0] = 'G';letters[1] = 'H';letters[2] = 'I';break;
	case 5:
		letters[0] = 'J';letters[1] = 'K';letters[2] = 'L';break;
	case 6:
		letters[0] = 'M';letters[1] = 'N';letters[2] = 'O';break;
	case 7:
		letters[0] = 'P';letters[1] = 'R';letters[2] = 'S';break;
	case 8:
		letters[0] = 'T';letters[1] = 'U';letters[2] = 'V';break;
	case 9:
		letters[0] = 'W';letters[1] = 'X';letters[2] = 'Y';break;
	default:
		break;
	}
}

//处理多进制的问题：M-bond problem;

string GetNextBond(string & pre)
{
	int i = 0;
	while(i< pre.length() && pre[i] - '0' >= 2)++i;
	if(i == pre.length()){--i; pre[i] = '0' - 1;}
	pre[i] += 1;
	while(i > 0)pre[--i] = '0';

	return pre;
}

bool IsElement(string & name, Tree & root)
{
	vector <Tree>::iterator pre;
	vector <Tree>::iterator follow;
	for(pre = root.child.begin(); pre != root.child.end(); ++pre)if(pre->letter == name[0])break;
	if(pre == root.child.end())return false;
	else
	{
		for(int i=1; i<name.length(); ++i)
		{
			for(follow = pre->child.begin(); follow != pre->child.end(); ++follow)if(follow->letter == name[i])break;
			if(follow == pre->child.end())return false;
			else pre = follow;
		}
		if(!pre->child.empty() && !pre->end)return false;
	}
	return true;
}

int main()
{
	ifstream fin("namenum.in");
	ifstream dict("dict.txt");
	ofstream fout("namenum.out");
	string str;
	//fin>>str;
	str = "4734";

	Tree root('0');
	//root.letter = '0';
	//Tree * proot = &root;   //其指针也
	vector <Tree>::iterator pre;
	vector <Tree>::iterator follow;
	vector <string>names;
	string name;
	while(getline(dict, name))
	{
		names.push_back(name);
		//my approach

		for(pre = root.child.begin(); pre != root.child.end(); ++pre)if(pre->letter == name[0])break;
		if(pre == root.child.end())
		{
			root.child.push_back(Tree(name[0]));//insert the first if not exist
			pre = root.child.end() - 1;
			for(int i=1; i<name.length(); ++i)
			{
				for(follow = pre->child.begin(); follow != pre->child.end(); ++follow)if(follow->letter == name[i])break;
				if(follow == pre->child.end())
				{
					pre->child.push_back(Tree(name[i]));//insert the first
					pre = pre->child.end() - 1;
				}
				else pre = follow;
			}
			pre->end = true;
		}
		else
		{
			//pre = root.child.begin();
			for(int i=1; i<name.length(); ++i)
			{
				for(follow = pre->child.begin(); follow != pre->child.end(); ++follow)if(follow->letter == name[i])break;
				if(follow == pre->child.end())
				{
					pre->child.push_back(Tree(name[i]));//insert the first
					pre = pre->child.end() - 1;
				}
				else pre = follow;
			}
			pre->end = true;
		}
	}
	int size = 1;
	for(int i=0; i<str.length(); ++i)size *= 3;
	//string * back_names = new string[size];
	string back_name;
	char ** cowname = new char * [str.length()];
	for(int i=0; i<str.length(); ++i)
	{
		int val = str[i] - '0';
		cowname[i] = new char[3];
		Getcompose(val, cowname[i]);
		//cout<<cowname[i][0]<<"   "<<cowname[i][1]<<"   "<<cowname[i][2]<<endl;
	}

	string digit = "0";for(int i=1; i<str.length(); ++i)digit += "0";
	vector <string>result;
	for(int i=0;i<size;++i)
	{
		for(int j=0; j<digit.length(); ++j)
		{
			int pick = digit[j] - '0';
			back_name += cowname[j][pick];
		}
		//cout<<i<<"  "<<digit<<"  "<<back_names[i]<<endl;
		//if(!IsElement(back_name, root))cout<<i<<"  "<<digit<<"  "<<back_name<<endl;
		if(IsElement(back_name, root))result.push_back(back_name);//{fout<<back_names[i]<<endl; change = true;}
		GetNextBond(digit);
		back_name = "";
	}
	sort(result.begin(), result.end());
	if(result.empty())cout<<"NONE"<<endl;
	else
	{
        for(vector <string>::iterator it = result.begin(); it!= result.end();++it)
        cout<<*it<<endl;
	}

	/*cout<<"\n\n";
	string nt = "GREG";
	cout<<IsElement(nt, root)<<"\n\n";*/

	fin.close();
	fout.close();
	dict.close();
	return 0;
}

/*
	//cout<<names[1000];
	//cout<<root.letter<<(root.child)[0].letter<<(root.child[0]).child[2].letter<<endl;
	pre = root.child.begin();
	pre = root.child.begin();
	for(int i=0; i<str.length(); ++i)
	{
		int val = str[i] - '0';
		char * letters = new char[3];
		Getcompose(val, letters);
		//cout<<letters[0]<<"   "<<letters[1]<<"   "<<letters[2]<<endl;

		bool com = false;
		for(int j=0;j<3;++j)
		{
			if(i == 0)
			{
				for(pre = root.child.begin(); pre != root.child.end(); ++pre)if(pre->letter == letters[j])break;
				if(pre == root.child.end())continue;
				else
				{
					//匹配了第一个;
					cout<<letters[j];
					follow = pre->child.begin();
					com = true;
					break;
				}
			}
			else//不是第一层;
			{
				for(follow = pre->child.begin(); follow != pre->child.end(); ++follow)if(follow->letter == letters[j])break;
				if(follow == pre->child.end())continue;
				else
				{
					//匹配了i层;
					cout<<letters[j];
					pre = follow;
					com = true;
					break;
				}
			}
		}

		if(!com){cout<<"NONE"<<endl;break;}
	}

	*/
