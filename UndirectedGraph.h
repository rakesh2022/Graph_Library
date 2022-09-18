#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H
#include <vector>
#include <queue>
#include<unordered_map> 
#include "Graph.h"
using namespace std;

template<class T1 ,class T2>
class UndirectedGraph : public Graph<T1 ,T2>{
    private:
        void unionset(T1 u,T1 v,unordered_map<T1 ,T1> &parent, unordered_map<T1 ,int> &rank);
        T1 findparent(unordered_map<T1 ,T1> &parent ,T1 node);
        vector<vector<T1>>edges;

    protected:
        int no_of_connected_comp;
       
    public:
        int numOfNodes;
        UndirectedGraph(int nodes) : Graph<T1 ,T2>(nodes){
            numOfNodes = nodes;
            no_of_connected_comp=nodes;
        }

        using Graph<T1 ,T2> :: adjacencyList;
        bool isCyclic();
        int connected_comp(); 

        void addEdge(T1 u, T1 v, T2 w = 1){
            edges.push_back({u,v});
            adjacencyList[u].push_back({v, w});
            adjacencyList[v].push_back({u, w});
        }

    private: 
        int  fun( int no_of_connected_comp){
          return no_of_connected_comp;
        }

        void makeset(unordered_map<T1,T1>&parent,unordered_map<T1,int>&rank);

};

template<class T1 ,class T2>
T1 UndirectedGraph<T1 ,T2> :: findparent(unordered_map<T1 ,T1> &parent ,T1 node){
    
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findparent(parent,parent[node]);
}

template<class T1 ,class T2>
void UndirectedGraph<T1 ,T2> :: unionset(T1 u,T1 v,unordered_map<T1 ,T1> &parent ,unordered_map<T1 ,int> &rank){
    u=findparent(parent,u);
    v=findparent(parent,v);

    if(rank[u]<rank[v]){
    parent[u]=v;
    }

    else if(rank[u]>rank[v]){
        parent[v]=u;
    }

    else{
       parent[u]=v;
       rank[v]++;
    }
}

template<class T1 ,class T2>
void UndirectedGraph<T1 ,T2> ::makeset(unordered_map<T1 ,T1> &parent ,unordered_map<T1 ,int> &rank){
    
    for(auto &it:adjacencyList){
        parent[it.first]=it.first;
        rank[it.first]=0;
    }
}

template<class T1 ,class T2>
bool UndirectedGraph<T1 ,T2> :: isCyclic(){
    unordered_map<T1 ,T1>parent;
    unordered_map<T1 ,int>rank;

   for(int i=0; i<edges.size(); i++){
        auto u=findparent(parent,edges[i][0]);
        auto v=findparent(parent,edges[i][1]);
        
        if(u==v){
            return true;
        }

        unionset(u,v,parent,rank);
       // no_of_connected_comp--;
    }
    return false;
}

template<class T1 ,class T2>
int UndirectedGraph<T1 ,T2> :: connected_comp(){
    unordered_map<T1,T1>parent;
    unordered_map<T1,int>rank;
    makeset(parent,rank);
    //here we are using copy of connected components because when we use connected components in main function again its value will decrese again like 7 to 6 ,6 to 5
    int cc=fun( no_of_connected_comp);
    
    for(int i=0;i<edges.size();i++){
        auto u=findparent(parent,edges[i][0]);
        auto v=findparent(parent,edges[i][1]);
        
        if(u!=v){
            unionset(u,v,parent,rank);
            cc--;
        }
        // no_of_connected_comp--;
    }

    if(cc<=0){
        return -1;
    }
    return  cc;
    // return    no_of_connected_comp;
}
#endif // UNDIRECTEDGRAPH_H
