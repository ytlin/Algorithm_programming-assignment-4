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
//bool check(int* trace,int trace_index,int* d);
int printSolution(int* dist, int n, int* parent);
void printPath(int* parent, int j);

int main()
{/*
    int num_verts;
    int num_edges;
    int VR;
    int VS;
    int des;
    int src;
    node** verts;*/
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
    cin>>src>>des;/*
    for(int i=0;i<num_verts;i++)
    {
        tmp = verts[i];
        cout<<i<<"==>"<<endl;
        while(tmp != NULL){
            cout<<tmp->v<<":"<<tmp->w<<endl;
            tmp = tmp->next;
        }
        cout<<"\n";
    }
    cout<<"------init finished-------"<<endl;*/
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
             //       cout<<"push:"<<n.v<<" "<<n.w<<endl;
                 }
                 tmp = tmp->next;
             }
        if(!visited[des])trace[trace_index++]=u;
        /*if(trace_index>2 && check(trace,trace_index,d))
            {
                trace[trace_index-2] = trace[trace_index-1];
                trace_index--;
            }*/
        }
        x.pop();
    }
    //printSolution(d, num_verts, parent);
    cout<<"Route: ";
    cout<<src<<" ";
    printPath(parent,des);
    //for(int i=0;i<trace_index;i++)cout<<trace[i]<<" ";
    //cout<<des<<endl;
    cout<<"\nTotal distance: "<<d[des]<<endl;
    cout<<"Estimation time: "<<((double)d[des])/VS<<endl;
}
/*
bool check(int* trace,int trace_index,int* d)
{
    cout<<trace_index<<"begin"<<endl;
    node* tmp = verts[trace[trace_index-2]];
    int tmp_d=-1;
    while(tmp != NULL)
    {
        if(tmp->v == trace[trace_index-1])
        {
            tmp_d = tmp->w;
            break;
        }
        tmp = tmp->next;
    }
    return (d[trace[trace_index-1]] < d[trace[trace_index-2]]+tmp_d);
}
*/
void printPath(int* parent, int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
}
// A utility function to print the constructed distance
// array

int printSolution(int* dist, int n, int* parent)
{
    printf("Vertex\t  Distance\tPath");
    for (int i = 0; i < num_verts; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}
