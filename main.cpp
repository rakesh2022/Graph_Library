//#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
#include "Graph.h"
#include "UndirectedGraph.h"
#include "DirectedGraph.h"
#include<string>
using namespace std;
int main()
{

    DirectedGraph<int,float> ptr(5);
      ptr.addEdge(0,1,1.2);
       ptr.addEdge(1,2);
      ptr.addEdge(2,3,1);
      ptr.addEdge(1,4,1);
      ptr.addEdge(0,3,1);
       cout<<"minimum distance between two nodes "<<ptr.min_distance(0,4)<<endl;
       if(ptr.isCyclic())
      cout<<"graph is cyclic "<<endl;
      else
      cout<< "no cycle"<<endl;
      vector<int>tp1=ptr.topsort();
      cout<<"toposort of Directed graph is";
      
      for(int i=0;i<tp1.size();i++)
      cout<<tp1[i]<<" ";
      cout<<endl;
       vector<int>tp2=ptr.topsort();
      cout<<"toposort of Directed graph is";
      
      for(int i=0;i<tp2.size();i++)
      cout<<tp2[i]<<" ";
      cout<<endl;
      cout<<"number of strongly connected componenets "<<ptr.no_StronglyConnectedComponenets()<<endl;
      vector<int>vec=ptr.breadthFirstTraversal(1);
     cout<<"Int BFS directed"<<endl;
       for(int i=0;i<vec.size();i++)
       cout<<vec[i];
       cout<<endl;
     cout<<"Int DFS directed"<<endl;
       vector<int>vec1=ptr.depthFirstTraversal(0);
        for(int i=0;i<vec1.size();i++)
      cout<<vec1[i];
      cout<<endl;
   /*   DirectedGraph<string,float> ptr1(5);
     ptr1.addEdge("a","b",1.2);
       ptr1.addEdge("c","d",0.4);
      ptr1.addEdge("c","e",0.2);
      ptr1.addEdge("b","d",6.1);
      ptr1.addEdge("b","e",0.5);
        ptr1.addEdge("b","c",0.2);
          ptr1.addEdge("a","d",5);
           cout<<"minimum distance between two nodes "<<ptr1.min_distance("a","e")<<endl;
            if(ptr1.isCyclic())
      cout<<"graph is cyclic "<<endl;
      else
      cout<< "no cycle"<<endl;
       vector<string>tp2=ptr1.topsort();
      cout<<"toposort of Directed graph is";
      for(int i=0;i<tp2.size();i++)
      cout<<tp2[i]<<" ";
      cout<<endl;
      cout<<"number of strongly connected componenets "<<ptr1.no_StronglyConnectedComponenets();
      cout<<endl;
       vector<string>vec2=ptr1.breadthFirstTraversal("b");
     cout<<"str BFS Directed "<<endl;
       for(int i=0;i<vec2.size();i++)
       cout<<vec2[i];
       cout<<endl;
       vector<string>vec3=ptr1.depthFirstTraversal("c");
     cout<<"str DFS Directed"<<endl;
       for(int i=0;i<vec3.size();i++)
       cout<<vec3[i];
       cout<<endl;
     
  /*
     UndirectedGraph<int,int> g(9);
      g.addEdge(1,2);
      g.addEdge(2,3);
      g.addEdge(3,4);
      g.addEdge(2,5,0);
       g.addEdge(6,7);
        g.addEdge(8,9);
          g.addEdge(4,5);
       cout<<"minimum distance between two nodes "<<g.min_distance(1,4)<<endl;
        if(g.isCyclic())
      cout<<"graph is cyclic "<<endl;
      else
      cout<< "no cycle"<<endl;
      cout<<"number of connected component "<<g.connected_comp()<<endl;
      cout<<"number of connected component "<<g.connected_comp()<<endl;
      vector<int>vecx=g.breadthFirstTraversal(2);
     cout<<"int BFS UnDirected"<<endl;
       for(int i=0;i<vecx.size();i++)
       cout<<vecx[i];
       cout<<endl;
    cout<<"int DFS undirected"<<endl;
       vector<int>vec4=g.depthFirstTraversal(1);
       for(int i=0;i<vec4.size();i++)
      cout<<vec4[i];
      cout<<endl;
      UndirectedGraph<string,float> g1(5);
      g1.addEdge("a","b",1);
       g1.addEdge("c","d",0.1);
      g1.addEdge("c","e",0.1);
      g1.addEdge("b","d",0.1);
      g1.addEdge("b","e",1);
        cout<<"minimum distance between two nodes "<<g1.min_distance("a","e")<<endl;
        cout<<"number of connected component "<<g1.connected_comp()<<endl;
        cout<<"number of connected component "<<g1.connected_comp()<<endl;
         if(g1.isCyclic())
      cout<<"graph is cyclic "<<endl;
      else
      cout<< "no cycle"<<endl;
       vector<string>vec5=g1.breadthFirstTraversal("a");
     cout<<"string BFS UNdirected"<<endl;
       for(int i=0;i<vec5.size();i++)
       cout<<vec5[i];
       cout<<endl;
       vector<string>vec6=g1.depthFirstTraversal("a");
     cout<<"string DFS Undirected"<<endl;
       for(int i=0;i<vec6.size();i++)
       cout<<vec6[i];
       cout<<endl;
      
     UndirectedGraph<int,float> dij(6);
      dij.addEdge(1,2,4.1);
      dij.addEdge(3,2,6.2);
      dij.addEdge(3,4,1.3);
     // dij.addEdge(3,5,1.5);
      dij.addEdge(4,5,2);
      dij.addEdge(5,6,15.1);
      dij.addEdge(6,2,0);
      dij.addEdge(6,1,5);
      dij.addEdge(3,6,2.2);
     cout<<"minimum distance between two nodes "<<dij.min_distance(1,3)<<endl;
        if(dij.isCyclic())
      cout<<"graph is cyclic "<<endl;
      else
      cout<< "no cycle"<<endl;
      cout<<"number of connected component "<<dij.connected_comp()<<endl;
      cout<<"number of connected component "<<dij.connected_comp()<<endl;
       UndirectedGraph<string,float> dijs(8);
      dijs.addEdge("D","B",4.1);
      dijs.addEdge("B","K",6.2);
      dijs.addEdge("A","V",2.0);
      dijs.addEdge("M","B",2.0);
      dijs.addEdge("D","M",2.0);
      dijs.addEdge("M","V",15);
       dijs.addEdge("A","K",4.5);
      dijs.addEdge("M","K",5.0);
       dijs.addEdge("L","M",5.0);
      cout<<"minimum distance between two nodes "<<dijs.min_distance("D","V")<<endl;
        if(dijs.isCyclic())
      cout<<"graph is cyclic "<<endl;
      else
      cout<< "no cycle"<<endl;
      cout<<"number of connected component "<<dijs.connected_comp()<<endl;
      cout<<"number of connected component "<<dijs.connected_comp()<<endl;
      DirectedGraph<char,int>g8(6);
       g8.addEdge('a','b');
    g8.addEdge('c','b');
    g8.addEdge('b','d');
    g8.addEdge('f','c');
    // g8.addEdge('d','e');
     g8.addEdge('c','e');
     g8.addEdge('e','a');
     // g3.addEdge('b','a'); 
       g8.addEdge('b','f'); 
      cout<< "minimum distance "<<g8.min_distance('a','e')<<endl; 
       cout<<"number of strongly connected componenets "<<g8.no_StronglyConnectedComponenets()<<endl;
    if(g8.isCyclic())
    cout<<"cyclic "<<endl;
    else
     cout<<"no cycle"<<endl;
   vector<char>tp8=g8.topsort();
      cout<<"toposort of Directed graph is";
      for(int i=0;i<tp8.size();i++)
      cout<<tp8[i]<<" ";
      cout<<endl;
   
 
    DirectedGraph<string,float> dis2(7);
    dis2.addEdge("MAU","VARANASI",400);
    dis2.addEdge("VARANASI","GHAZIPUR",60);
    dis2.addEdge("GHAZIPUR","ALLAHABAD",50);
    dis2.addEdge("ALLAHABAD","MIRZAPUR",50.5);
    dis2.addEdge("DELHI","MIRZAPUR",300);
    dis2.addEdge("DELHI","MAU",200);
    dis2.addEdge("DELHI","BALLIA",500);
    dis2.addEdge("BALLIA","MAU",5000);
    dis2.addEdge("MIRZAPUR","GHAZIPUR",400);
    dis2.addEdge("MAU","GHAZIPUR",400);
    cout<<" Min Distance between BALLIA and MAU"<<" "<<dis2.min_distance("BALLIA","MAU")<<endl;
    cout<<" Min Distance between BALLIA and VARANASI"<<" "<<dis2.min_distance("BALLIA","VARANASI")<<endl;
     cout<<"Min Distance between BALLIA and  GHAZIPUR"<<" "<<dis2.min_distance("BALLIA","GHAZIPUR")<<endl;
     cout<<"Min Distance between BALLIA and ALLAHABAD"<<" "<<dis2.min_distance("BALLIA","ALLAHABAD")<<endl;
     cout<<"Min Distance between BALLIA and MIRZAPUR"<<" "<<dis2.min_distance("BALLIA","MIRZAPUR")<<endl;
    cout<<"Min Distance between BALLIA and DELHI"<<" "<<dis2.min_distance("BALLIA","DELHI")<<endl;
     cout<<"Min Distance between MAU and DELHI"<<" "<<dis2.min_distance("MAU","DELHI")<<endl;
    */

    

 
     
   

}