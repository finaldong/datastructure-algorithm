### 算法和数据结构
[基本搜索算法](search.cpp)  
搜索过程都可以理解为解答树的深度优先遍历过程。  
解答树是在寻找问题的过程中逐渐生成的而不是一开始就建立好的。  
这个逐渐生成的过程，天然地适合使用递归方法来实现。  
状态：S  
行动集合：A  
状态S对应的限制集合：f(S)  
其基本的递归框架可以总结如下：  
``` 
DFS(S,A,f(S))  
{
	if S is target
		backtrack  
 	endif
	for each a in A
		if a in f(S)  
 		   S<-move(S,a)  
		    DFS(S,A-{a},f(S))
		endif
	end
}  
```
下列的所有算法都使用`vector<int> ans`当作解，`vector<int> s`当作备选集合
 - 枚举排列
```c++
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
```
 - 枚举组合
     * 使用标记法
```c++
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
```
     * 使用二进制
```
```
 - 枚举组合允许重复选取元素，选取限制在2个
```c++
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
```
 - 枚举排列允许重复选取元素，选取限制在2个
```c++
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
```

[树结构](tree.md)  

[图结构](graph.md)  

······
