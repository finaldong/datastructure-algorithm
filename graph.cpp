#include <iostream>
#include <queue>
using namespace std;

struct GraphNode{
    bool hadseen;
    int value;
    vector<GraphNode*> adj;
    GraphNode():hadseen(false),value(0){}
    GraphNode(int v):hadseen(true),value(v){}
};

bool seen[1000];
double nodeList[1000];
vector<int> Graph[1000];
struct edge{
    size_t from,to;
    int value;
    edge(size_t a,size_t b,int v):from(a),to(b),value(v){}
};
//储存的是结点的id
//储存的是边的id

int main()
{
    for(int i=0;i<1000;i++)
    {
        if(!seen[i])
        {
            queue<size_t> q;
            q.push(i);
            while(!q.empty())
            {
                size_t cur=q.front();
                q.pop();
                for(auto e:Graph[cur])
                {
                    if(!seen[e])
                    {
                        q.push(e);
                    }
                }
            }
        }
    }

    return 0;
}
