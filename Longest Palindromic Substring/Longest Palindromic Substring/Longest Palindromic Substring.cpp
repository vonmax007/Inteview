// Longest Palindromic Substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;


string longestPalindrome(string s)
{
	int maxlength = 0;
	int k,j,front=0,back=0;	//j i k
	for(int i=0;i<s.size()-1;++i)
	{
		int lengthI = 0;
		if(i>=1 && i<s.size()-1 && s[i-1] == s[i+1])	//odd situation
		{
			lengthI += 3;
			for(j = i-2,k = i+2;j>=0 && k<s.size();--j,++k)
			{
				if(s[j] == s[k])lengthI += 2;
				else break;
			}
		}
		if(maxlength < lengthI)
		{
			front = j+1;
			back = k-1;
			maxlength = lengthI;
		}
		if(s[i] == s[i+1])//even situation
		{
			lengthI += 2;
			for(j = i-1,k = i+2;j>=0 && k<s.size();--j,++k)
			{
				if(s[j] == s[k])lengthI += 2;
				else break;
			}
		}
		
		if(maxlength < lengthI)
		{
			front = j+1;
			back = k-1;
			maxlength = lengthI;
		}
	}
	//cout<<front<<" "<<back<<endl;
	if(front == 0)back += 1;
	cout<<front<<" "<<back<<endl;
	return s.substr(front,back);
}


int _tmain(int argc, _TCHAR* argv[])
{
	string str = "ccc";
	cout<<longestPalindrome(str)<<endl;
	//cout<<str.substr(0,3);
	return 0;
}

