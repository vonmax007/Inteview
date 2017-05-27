#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> two;
        bool get = false;
        for(int i=0; i<nums.size(); ++i)
        {
            if(!get)
            {
                for(int j=i+1; j<nums.size(); ++j)
                    if(nums[i] + nums[j] == target)
                    {
                        two.push_back(i);
                        two.push_back(j);
                        get = true;
                        break;
                    }
            }
            else break;
        }
        return two;
    }
};

int main()
{
    vector <int> vc;
    int num, temp, target;
    cout << "Please enter your input target :" << endl;
    cin>>target;
    cout << "Please enter your input count :" << endl;
    cin>>num;
    for(int i=0; i<num; ++i)
    {
        cin>>temp;
        vc.push_back(temp);
    }
    sort(vc.begin(),vc.end(),less<int>());
    for(int i=0; i<num; ++i)
    {
        for(int j=i+1; j<num; ++j)
        {
            if(vc[i] + vc[j] == target)cout<<"["<<i<<" , "<<j<<"]"<<endl;
            if(vc[i] + vc[j] > target)break;
        }
    }


    return 0;
}
