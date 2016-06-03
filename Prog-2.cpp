#include<queue>
#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;

/**struct*/
struct node{
    int v;   //vertices
    int w;   //weight or distance
    node* next;
};

/**global var*/
int num_verts;
int num_edges;
int VR;
int VS;
int des;
int src;

node** verts;

/**class*/
class cmp{
 public:
 bool operator()(const node lhs, const node rhs) const
 {
      return lhs.w > rhs.w;
 }
};

typedef priority_queue<node, vector<node>, cmp> pq;


/**functions*/
void Dijkstra(node** v);
int printSolution(int* dist, int n, int* parent);
void printPath(int* parent, int j);

int main()
{
  
    int tmp1,tmp2,tmpR;
    node* tmp;

    cin>>num_verts;
    cin>>num_edges;

    verts = new node*[num_verts];
    for(int i=0;i < num_verts;i++)
        verts[i]=NULL;
    for(int i=0;i<num_edges;i++)
    {
        cin>>tmp1>>tmp2>>tmpR;
        tmp = new node;
        tmp->v = tmp1; tmp->w = tmpR; tmp->next = verts[tmp2]; verts[tmp2] = tmp;
        tmp = new node;
        tmp->v = tmp2; tmp->w = tmpR; tmp->next = verts[tmp1]; verts[tmp1] = tmp;
    }
    cin>>VR>>VS;
    node* cur; node* pre;
    for(int i=0;i<num_verts;i++)
    {
        cur = verts[i]; pre = NULL; 
        while(cur!=NULL)
        {
            if(cur->w >= VR)
                if(pre!=NULL)pre->next = cur->next;
                else verts[i] = NULL;
            pre = cur; cur = cur->next;
        }
    }
    cin>>src>>des;
    Dijkstra(verts);
}

/*implement*/
void Dijkstra(node** v)
{

    int d[num_verts];
    int u; int tmpD;
    int trace[num_verts];
    int trace_index=0;
    bool visited[num_verts];
    int parent[num_verts];
    for(int i=0;i<num_verts;i++)
    {
        visited[i]=false;
        parent[i]=-1;
    }
    node* tmp;
    node n;
    pq x;
    d[src] = 0;
    n.w=0; n.v=src; n.next=NULL;
    x.push(n);
    for(int i=0;i<num_verts;i++)
    {
        if(i!=src)
        {
            d[i]=INT_MAX;
        }
    }
    while(!x.empty())
    {
        u = x.top().v; tmpD = x.top().w;
        if(!visited[u])
        {
            visited[u]=true;
            tmp = v[u];
            while(tmp != NULL)
             {
                 if(d[tmp->v] > tmpD+tmp->w)
                 {
                    d[tmp->v] = tmpD+tmp->w;
                    n.v = tmp->v; n.w=d[tmp->v]; n.next=NULL;
                    x.push(n);
                    parent[tmp->v] = u;
                 }
                 tmp = tmp->next;
             }
        if(!visited[des])trace[trace_index++]=u;
        }
        x.pop();
    }
    cout<<"Route: ";
    cout<<src<<" ";
    printPath(parent,des);
    cout<<"\nTotal distance: "<<d[des]<<endl;
    cout<<"Estimation time: "<<((double)d[des])/VS<<endl;
}
void printPath(int* parent, int j)
{
    if (parent[j]==-1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}

int printSolution(int* dist, int n, int* parent)
{
    printf("Vertex\t  Distance\tPath");
    for (int i = 0; i < num_verts; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}
