//
//  main.cpp
//  UVa 336 bfs
//



#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

/*
 
 problema UVa 336: A Node Too Far
 
 il grafo è memorizzato come una mappa con chiavi intere e valori vettori di interi
 la chiave è l'id del nodo, il valore è un vettore di interi che contiene tutti i nodi collegati
 
 */
typedef map< int, vector<int> > tgraph;
tgraph graph;

/*
 
 l'algoritmo bfs memorizza nella mappa visited le distanze attribuite ad ogni nodo
 visited è una mappa con chiave l'id del nodo e valore la distanza dal nodo di partenze
 se un nodo non è stato ancora visitato non compare nella mappa (quindi il count corrispondente alla chiave è 0)
 
 */
typedef map<int,int> tvisited;
tvisited visited;


// algoritmo della BFS (Breadth First Search) a partire dal nodo "start"
void bfs(int start) {
    
    queue<int> s;                   // coda dei nodi da visitare
    s.push(start);                  // all'inizio mette in coda il nodo "start"
    visited[start]=0;               // la distanza del nodo "start" da se stesso è zero
    while (s.empty() == false) {    // continua finché ha nodi nella coda
        int top = s.front();        // "top" è il primo nodo della coda
        s.pop();                    // elimina il primo nodo dalla coda
        int size = (int) graph[top].size(); // numero di nodi collegati al nodo "top"
        for(int i=0;i<size;i++){    // scorre tutti i nodi collegati al nodo "top"
            int n=graph[top][i];    // "n" è il nodo corrente fra quelli collegati al nodo "top"
            if(!visited.count(n)){  // se il nodo "n" ancora non ha una distanza assegnata
                visited[n]=visited[top]+1; // la assegna come la distanza per arrivare a "top" + 1
                s.push(n);          // mette il nodo "n" in coda perché più avanti dovrà essere visitato
            }
        }
    }
}


// collega due nodi del grafo
// con un arco bidirezionale a<--->b
//   (se i nodi non esistono li crea perché sono voci di una mappa)
void link(int a, int b) {
    graph[a].push_back(b); // arco a--->b
    graph[b].push_back(a); // arco a<---b
}

int main(int argc, const char * argv[]) {
    
    // crea il grafo
    link(10,15);link(15,20);link(20,25);link(10,30);
    link(30,47);link(47,50);link(25,45);link(45,65);
    link(15,35);link(35,55);link(20,40);link(50,55);
    link(35,40);link(55,60);link(40,60);link(60,65);
    
    //cout << graph[40][0] << endl;
    
   /* bfs(35);
    
    for (tvisited::iterator it=visited.begin();
         it!=visited.end();
         it++) {
        
        cout << "nodo " << it->first <<
                " dist " << it->second << endl;
        
    }*/
    
    
    
    
    int ttl=2;
    
    int count=0;
    for(tvisited::iterator it=visited.begin(); it!=visited.end(); it++) {
        cout << it->first << " " << it->second << endl;
        if (it->second>ttl) count++;
    }
    
    cout << count << endl;
    
    return 0;
}
