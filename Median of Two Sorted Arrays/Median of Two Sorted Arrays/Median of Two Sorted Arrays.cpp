// Median of Two Sorted Arrays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	if(nums1.size() > nums2.size())nums1.swap(nums2);
	int i, j, ihalf, imax = nums1.size(), imin = 0, m = nums1.size(), n = nums2.size();
	ihalf = (m+n+1)/2;
	i = j = 0;
	int max_left = 0, min_right = 0;
	while(imin<=imax)
	{
		i = (imin + imax) / 2;
		j = ihalf - i;
		if(i < m && nums2[j-1] > nums1[i])imin = i + 1;	//increase i
		else if(i > 0 && nums1[i-1] > nums2[j])imax = i - 1;	//decrease i
		else	// i is perfect, and need to consider edge valuse
		{
			if(i==0)max_left = nums2[j-1];
			else if(j==0)max_left = nums1[i-1];
			else max_left = (nums2[j-1] > nums1[i-1])?nums2[j-1]:nums1[i-1];

			if((m+n)%2 ==1)return max_left;

			if(i==m)min_right = nums2[j];
			else if(j==n)min_right = nums1[i];
			else min_right = (nums2[j] > nums1[i])?nums1[i]:nums2[j];
			return (min_right + max_left)/2.0;
		}
	}
	return 0.0;
}
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector <int> vec3;
	vec3.insert(vec3.end(),nums1.begin(),nums1.end());  
    vec3.insert(vec3.end(),nums2.begin(),nums2.end());  
	sort(vec3.begin(),vec3.end(), less<int>());
	//vector<int>::iterator it;
	//for(it=vec3.begin();it!=vec3.end();++it)cout<<*it<<endl;

	if(vec3.size() % 2 ==1)return vec3[(vec3.size()-1)/2];
	else return (vec3[vec3.size()/2] + vec3[vec3.size()/2-1])/2.0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> v1,v2,v3;
	vector<int>::iterator it;
	v1.push_back(1); v1.push_back(2); 
	v2.push_back(3); v2.push_back(4);
	cout<<findMedianSortedArrays(v1,v2)<<endl;
	//for(it=v3.begin();it!=v3.end();++it)cout<<*it<<endl;

	return 0;
}

