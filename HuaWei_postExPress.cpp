// HuaWei_postExPress.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	string exp;
	getline(cin,exp);

	stack<int> opnd;
	int i=0;
	char ch;

	while(i < exp.length())
	{
		ch = exp[i++];
		if(ch == '+')
		{
			int num2 = opnd.top();
			opnd.pop();
			int num1 = opnd.top();
			opnd.pop();
			//compute result;
			int ret = num1 + num2;
			opnd.push(ret);
		}
		else if(ch == '-')
		{
			int num2 = opnd.top();
			opnd.pop();
			int num1 = opnd.top();
			opnd.pop();
			//compute result;
			int ret = num1 - num2;
			opnd.push(ret);
		}
		else if(ch == '*')
		{
			int num2 = opnd.top();
			opnd.pop();
			int num1 = opnd.top();
			opnd.pop();
			//compute result;
			int ret = num1 * num2;
			opnd.push(ret);
		}
		else if(ch >= '0' && ch <= '9')
		{
			//compute result;
			int ret = ch - '0';
			opnd.push(ret);
		}
		else if(ch == 'A')
		{
			//compute result;
			int ret = 10;
			opnd.push(ret);
		}
		else if(ch == 'B')
		{
			//compute result;
			int ret = 11;
			opnd.push(ret);
		}
		else if(ch == 'C')
		{
			//compute result;
			int ret = 12;
			opnd.push(ret);
		}
		else if(ch == 'D')
		{
			//compute result;
			int ret = 13;
			opnd.push(ret);
		}
		else if(ch == 'E')
		{
			//compute result;
			int ret = 14;
			opnd.push(ret);
		}
		else if(ch == 'F')
		{
			//compute result;
			int ret = 15;
			opnd.push(ret);
		}
	}

	cout<<opnd.top();
	return 0;
}

