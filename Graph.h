#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include <vector>
#include <queue>
#include<unordered_map> 
#include<limits.h>
using namespace std;

template<class T1 ,class T2>
class Graph{
    protected:
        //number of nodes in the graph
        int numOfNodes;
        //adjacency list for the graph
        //adjList[i] represents direct neighbours of node i
        //adjList[i].first represents an edge from node i to node adjList[i].first.
        //adjList[i].second represents weight of the edge.
        unordered_map<T1 ,vector<pair<T1 ,T2>>> adjacencyList;
        void dfsHelper(T1 source, vector<T1> &nodesDiscovered, unordered_map<T1,vector<pair<T1,T2>>>adjacencyList, unordered_map<T1,bool> &visited);

    public:
  
        Graph(int nodes){
            
            numOfNodes = nodes;
            adjacencyList = unordered_map<T1 ,vector<pair<T1 ,T2>>> (numOfNodes+1);

        }

        vector<T1> breadthFirstTraversal(T1 source);
        vector<T1> depthFirstTraversal(T1 source);
        T2 min_distance(T1 src,T1 dst);

        int getNumberOfNodes(){
            return numOfNodes;
        }  
   
};

template<class T1 ,class T2>
vector<T1> Graph<T1 ,T2> :: breadthFirstTraversal(T1 source){

    unordered_map<T1 ,bool> visited;
    vector<T1> nodesDiscovered;
    queue<T1> nodesToExplore;
    nodesToExplore.push(source);
    visited[source] = true;

    while(!nodesToExplore.empty()){
        T1 explore = nodesToExplore.front();
        nodesToExplore.pop();
        nodesDiscovered.push_back(explore);

        for(auto neighbours : adjacencyList[explore]){
            T1 neighbour = neighbours.first;
            if(visited.find(neighbour)==visited.end()){
                visited[neighbour] = true;
                nodesToExplore.push(neighbour);
            }
        }
    }
    return  nodesDiscovered;
}

template<class T1 ,class T2>
void Graph<T1 ,T2> :: dfsHelper(T1 source ,vector<T1> &nodesDiscovered ,unordered_map<T1 ,vector<pair<T1 ,T2>>> adjacencyList ,unordered_map<T1 ,bool> &visited){
    visited[source] = true;
    nodesDiscovered.push_back(source);

    for(auto neighbours : adjacencyList[source]){
        T1 neighbour = neighbours.first;

        if(visited.find(neighbour)==visited.end()){
            dfsHelper(neighbour ,nodesDiscovered ,adjacencyList ,visited);
        }
    }
}

template<class T1 ,class T2>
vector<T1> Graph<T1 ,T2> :: depthFirstTraversal(T1 source){
    vector<T1> nodesDiscovered;
    unordered_map<T1 ,bool> visited;
    dfsHelper(source, nodesDiscovered,adjacencyList, visited);
    return nodesDiscovered;

}

template<class T1 ,class T2>
T2 Graph<T1 ,T2> :: min_distance(T1 src ,T1 dst){
    priority_queue<pair<T2 ,T1> ,vector<pair<T2 ,T1>> ,greater<pair<T2,T1>>> pq;
    unordered_map<T1 ,T2> dist;
    vector<pair<T1 ,T2>> vec;

    for(auto &it : adjacencyList){
        dist[it.first]=LONG_MAX;
        vec=it.second;

        for(int i=0;i<vec.size();i++){
            dist[vec[i].first]=LONG_MAX;
        }
    }
    //cout<<adjacencyList.size();
    //cout<<dist.size();
    pq.push({0,src});
    dist[src]=0.0;
    
    while(!pq.empty()){
        auto curr=pq.top();
        auto u=curr.second;
        auto curr_d=curr.first;
        pq.pop();

        for(auto child:adjacencyList[u]){
            auto v=child.first;
            auto d=child.second;

            if(curr_d+d < dist[v]){
                dist[v]=curr_d+d;
                pq.push({dist[v],v});
            }
           
        }
    }
    // cout<<dist[dst];
    if(dist[dst]==LONG_MAX){
        return -1.0;
    }
    return dist[dst];
}
#endif // GRAPH_H

