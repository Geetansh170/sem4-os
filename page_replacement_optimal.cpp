#include<queue>
#include<iostream>
#include<map>
using namespace std;

void print(map<int,int>q)
{
    map<int,int>::iterator it=q.begin();
    while(it!=q.end())
    {
        cout<<it->first<<" ";
        it++;
    }
    cout<<endl;
}

int optimal(int n,int pages[])
{
    int page_fault=0;
    map<int,int>present;
    for(int i=0;pages[i]!=-1;i++)
    {
        if(present.find(pages[i])==present.end())
        {
            page_fault++;
            if(present.size()<n)
            {
                present[pages[i]]=INT_MAX;
            }
            else
            {
                for(int j=i+1;pages[j]!=-1;j++)
                {
                    if(present.find(pages[j])!=present.end())
                    {
                        if(present[pages[j]]==INT_MAX)
                        {present[pages[j]]=j;}
                    }
                }
                int temp=present.begin()->first;int ans=present[temp];
                present[temp]=INT_MAX;
                map<int,int>::iterator it=present.begin();it++;
                for(;it!=present.end();it++)
                {
                    if(it->second>ans){temp=it->first;ans=it->second;}
                    present[it->first]=INT_MAX;
                }
                present.erase(temp);
                present[pages[i]]=INT_MAX;
            }
        }
        print(present);
    }
    return page_fault;
}

int main()
{
    int n;
    cout<<"Enter the number of frames:";cin>>n;
    int pages[10000];int npage=-1;
    cout<<"Enter the pages and -1 to stop\n";
    do{
        npage++;
        cin>>pages[npage];
    }while(pages[npage]!=-1);
    cout<<endl<<"page faults:"<<optimal(n,pages);
    return 0;
}

