#include <iostream>
#include <vector>
using namespace std;
void dfsPermutation(vector<int>& s,vector<int>& ans){
    if(s.size()==ans.size())
    {
        for(auto e:ans)
            cout<<e<<' ';
        cout<<endl;
        return ;
    }
    for(auto e:s)
    {
        bool used=false;
        for(auto e2:ans)
            if(e==e2)
                used=true;
        if(!used)
        {
            ans.push_back(e);
            dfsPermutation(s,ans);
            ans.pop_back();
        }
    }
}
void dfsCombination(vector<int>& s,vector<int>& ans,int cur,int target){
    if(target==ans.size())
    {
        for(auto e:ans)
            cout<<e<<' ';
        cout<<endl;
        return;
    }
    for(size_t i=cur;i<s.size();i++)
    {
            ans.push_back(s[i]);
            dfsCombination(s,ans,i+1,target);
            ans.pop_back();
    }
}
void dfsCombinationR(vector<int>& s,vector<int>& ans,vector<int>&assist,int cur,int target){
    if(target==ans.size())
    {
        for(auto e:ans)
            cout<<e<<' ';
        cout<<endl;
        return;
    }
    for(size_t i=cur;i<s.size();i++)
    {
        if(assist[i]<1)
        {
            ans.push_back(s[i]);
            assist[i]++;
            dfsCombinationR(s,ans,assist,i,target);
            ans.pop_back();
            assist[i]--;
        }
        else if(assist[i]==1)
        {
            ans.push_back(s[i]);
            assist[i]++;
            dfsCombinationR(s,ans,assist,i+1,target);
            ans.pop_back();
            assist[i]--;
        }
    }
}
void dfsPermutationR(vector<int>& s,vector<int>& ans){
    if(s.size()==ans.size())
    {
        for(auto e:ans)
            cout<<e<<' ';
        cout<<endl;
        return;
    }
    for(auto e:s)
    {
        ans.push_back(e);
        dfsPermutationR(s,ans);
        ans.pop_back();
    }
}
void dfsPermutationRC(vector<int>& s,vector<int>& ans,vector<int>&assist){
    if(s.size()==ans.size())
    {
        for(auto e:ans)
            cout<<e<<' ';
        cout<<endl;
        return;
    }
    for(size_t i=0;i<s.size();i++)
    {
        if(assist[i]<=1)
        {
            ans.push_back(s[i]);
            assist[i]++;
            dfsPermutationRC(s,ans,assist);
            ans.pop_back();
            assist[i]--;
        }
    }
}
int main()
{
    vector<int> s={1,2,3,4};
    vector<int> a={1,1,1,1};
    vector<int> ans;
    dfsCombinationR(s,ans,a,0,3);
    return 0;
}
