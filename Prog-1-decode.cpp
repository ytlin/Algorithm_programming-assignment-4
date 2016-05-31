#include<iostream>
#include <map>
#include<stdio.h>
using namespace std;

int main()
{
    //string code[256];
    char input[2048];
    int index=0;
    char tmp;
    map<string,int> m;
    string str;
    for(int i=0;i<256;i++)
    {
        cin>>str;
        m[str]=i;
    }
    getchar();
    while((tmp = getchar()) != EOF)
    {
        input[index++]=tmp;
    }

    //cout<< (m.find("10") == m.end());
    str="";
    for(int i=0;i<index;i++)
    {
        str+=input[i];
        if(m.find(str) != m.end())
        {
            cout<<(char)m[str];
            str="";
        }
    }
}
