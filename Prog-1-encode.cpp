#include <queue>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;


/**global var*/
int freq[256];
string code[256];
/**struct*/
struct node{
    int c;
    int f;
    node* left;
    node* right;
};
/**class*/
class cmp{
    public:
    bool operator()(const node* lhs, const node* rhs) const
    {
        return lhs->f > rhs->f;
    }
};

node v[256];

/**functions*/
void freqency(int index, char* buff);
void generate_code(node* n);
typedef priority_queue<node*, vector<node*>, cmp> pq;
void build_tree(pq& x);
void encode(char* c , int i);

int main()
{
    char buff[2048];
    char input[2048];
    int index = 0;
    char tmp;
    pq x;
    while( (tmp=getchar()) != EOF)
    {
      input[index]=tmp;
      buff[index++] = tmp;
    }

    freqency(index,buff);
    
    //pq push
    for(int i=0;i<256;i++)
    {
        node* tmp = new node;
        tmp->left = NULL; tmp->right=NULL;
        tmp->f = freq[i]; tmp->c = i;
        x.push(tmp);
    }
    build_tree(x);
    generate_code(x.top());
    for(int i=0;i<256;i++)
    {
        cout<<code[i]<<endl;
    }
    encode(input,index);
}

/**implemnet*/
void freqency(int index, char* buff)
{
    for(int i=0;i<256;i++) freq[i] = 0;  //init
    for(int i=0; i<index ;i++) freq[ (int)(buff[i]) ]++;
    node tmp;
    for(int i=0;i<256;i++)
    {
        v[i].c=i;  v[i].f=freq[i];
    }
}


void Huffman()
{
}

void generate_code(node* n)
{
    static string str="";
    if(n->left != NULL)
    {
        str+="0";
        generate_code(n->left);
        str = str.substr(0,str.size()-1);
    }
    if(n->right != NULL)
    {
        str+="1";
        generate_code(n->right);
        str = str.substr(0,str.size()-1);
    }
    if(!n->left && !n->right) code[n->c] = str;
}
void build_tree(pq& x)
{
    while(x.size() > 1)
    {
        node* tmp = new node;
        tmp->left = x.top();
        x.pop();
        tmp->right = x.top();
        x.pop();
        tmp->f = tmp->left->f + tmp->right->f;
        tmp->c = -1;
        x.push(tmp);
    }
}
void encode(char* c , int i)
{
    for(int j=0;j<i;j++)
    {
        cout<<code[c[j]];
    }
    cout<<'\n';
}
