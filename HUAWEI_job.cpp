// HUAWEI_job.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <String>
#include <vector>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	
	char ch;
	int count[5] = {0};
	int count_times = 0;
	
	while((ch = getchar()) != EOF)
	{   
		if(count_times < 5)
		{
			if(ch == '1')count[count_times++]++;
			else count_times++;
		}
		else count_times = 0;
	}
	int min = count[0];
	for(int i=0;i<5;++i)
	{
		if(count[i] < min)min = count[i];
		//cout<<count[i]<<"  "	;
	}
	cout<<min;


	return 0;
}

