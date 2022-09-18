#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H
#include <stack>
#include <vector>
#include <queue>
#include<unordered_map> 
#include "Graph.h"
using namespace std;

template<class T1 ,class T2>
class DirectedGraph : public Graph<T1 ,T2>{
    unordered_map<T1,int> indegree;

    protected:
        void tp_sort(T1 source ,unordered_map<T1 ,bool> &visited ,stack<T1> &s);
        void tp_helper(T1 source ,vector<T1> &nodesDiscovered ,unordered_map<T1 ,bool> &visited ,stack<T1> &s);
        void dfs(T1 source ,vector<T1> &nodesDiscovered ,unordered_map<T1 ,bool> &visited ,unordered_map<T1 ,vector<pair<T1 ,T2>>> &adjrev);
        
        // inherited the bfs function from graph class
        using Graph<T1,T2> :: dfsHelper;

    public:
        int numOfNodes;

        DirectedGraph(int nodes) : Graph<T1 ,T2>(nodes){
            numOfNodes = nodes;
        }

        using Graph<T1 ,T2> :: adjacencyList;

        void addEdge(T1 u, T1 v ,T2 w = 1){
            adjacencyList[u].push_back({v , w});

            // and updating indegree 
            indegree[v]++;
        }

        unordered_map<T1 ,int> fun(unordered_map<T1 ,int> indegree){
            unordered_map<T1 ,int> indegree1=indegree;
            return indegree1;
        }

        vector<vector<T1>> StronglyConnectedComponents();

        bool isCyclic();

        vector<T1> topsort();

        int no_StronglyConnectedComponenets();

};

template<class T1 ,class T2>
vector<T1> DirectedGraph<T1 ,T2> :: topsort(){
    unordered_map<T1 ,int> idg=fun(indegree);
    priority_queue<T1 ,vector<T1> ,greater<T1>> pq;
    vector<T1>tp;

    for(auto &it : adjacencyList){

        if(idg.find(it.first)==idg.end()){
            idg[it.first]=0;
        }
        
    }

    for(auto &it:idg)
   {

        if(it.second==0){ 
            pq.push(it.first);
        }
    }

    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        tp.push_back(curr);

        for(auto child:adjacencyList[curr]){
            idg[child.first]--;
          
            if(idg[child.first]==0)
           
           {
                pq.push(child.first);   
            }
        }
    }
    
    if(tp.size()==numOfNodes){
        return tp;
    }

    else{
        return {};
    }

}

template<class T1 ,class T2>
bool DirectedGraph<T1 ,T2> :: isCyclic(){
    vector<T1>ts=topsort();

    if(ts.size()==0){
        return true;
    }
    
    else{
        return false;
    }
}

template<class T1 ,class T2>
void DirectedGraph<T1 ,T2> :: tp_sort(T1 source, unordered_map<T1 ,bool> &visited ,stack<T1> &st){
    visited[source]=1;

	for(auto childs : adjacencyList[source]){
	    auto child=childs.first;

	    if(!visited[child]){
	        tp_sort(child,visited,st);
	    }
	    st.push(source);
	}
}

template<class T1 ,class T2>
int DirectedGraph<T1 ,T2> :: no_StronglyConnectedComponenets(){
    stack<T1>st;
    vector<T1>nodesDiscovered;
    unordered_map<T1 ,vector<pair<T1 ,T2>>> rev;
    unordered_map<T1 ,bool>visited;
    /* for(int i=0;i<n;i++){
        if(!visited[i]){
            topsort(i,adj,visited,st);
        }
    }*/
    /*for(auto &it:adjacencyList){
        if(!visited[it.first]){
            tp_sort(it.first,visited,st);
        }
    }*/
    vector<pair<T1 ,T2>> vec;
    for(auto &it : adjacencyList){
        vec=it.second;
        visited[it.first]=false;
        for(int i=0;i<vec.size();i++){
            visited[vec[i].first]=false;
        }
    }
         
    for(auto &it:visited){
            
        if(!visited[it.first]){
            tp_sort(it.first,visited,st);
        }
    }
    /* for(int i=0;i<n;i++){
        for(auto child:adj[i]){
            rev[child].push_back(i);
        }
    }*/
        
    for(auto &it:adjacencyList){
        for(auto childs : adjacencyList[it.first]){
            auto child=childs.first;
            rev[child].push_back({it.first,childs.second});
        }
    }
    //  for(int i=0;i<n;i++)
    // visited[i]=0;
    visited.clear();
    int c=0;

    while(!st.empty()){
        auto tp=st.top();
        st.pop();

        if(!visited[tp]){
            c++;
            dfsHelper(tp, nodesDiscovered,rev, visited);
        }
    }
    return c;
}
#endif 