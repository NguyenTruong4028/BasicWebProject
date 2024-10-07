#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int BinarySearch(vector<int> &nums,int left, int right, int x){
    while(left<=right){
        int mid=left + (right-left)/2;
        if(nums[mid]==x)
            return mid;
        else if(nums[mid]<x)
            left = mid+1;
        else
            right = mid-1;
    }
    return -1;
}
vector<pair<int,int>> TwoSum(vector<int> &nums, int x){
    vector<int> array(nums);
    sort(nums.begin(),nums.end());
    set<pair<int,int>> kqs;
   
    for(int i=0;i<nums.size();i++){
        int need = x - nums[i];
        int it = BinarySearch(nums,i+1,nums.size()-1,need);
        if(it!=-1){
            int it1 =find(array.begin(),array.end(),nums[i]) - array.begin();
            int it2 = find(array.begin(),array.end(),nums[it]) - array.begin();
            kqs.insert(make_pair(min(it1,it2),max(it1,it2)));
        }
    }
    vector<pair<int,int>> kq(kqs.begin(),kqs.end());
    return kq;
}
int main(){
    vector<int> nums;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    cin>>x;
    vector<pair<int,int>> Sum = TwoSum(nums,x);
    if(!Sum.empty()){
        for(auto &pair : Sum){
            cout<<pair.first<<" "<<pair.second<<endl;
        }
    }
    return 0;
}