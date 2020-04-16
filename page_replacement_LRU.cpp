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

int LRU(int n,int pages[])
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
                present[pages[i]]=i;
            }
            else
            {
                int temp=present.begin()->first;
                map<int,int>::iterator x=present.begin();
                x++;
                for(;x!=present.end();x++)
                {
                    if(x->second<present[temp]){temp=x->first;}
                }
                present.erase(temp);
                present[pages[i]]=i;
            }
        }
        else
        {
            present[pages[i]]=i;
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
    cout<<endl<<"page faults:"<<LRU(n,pages);
    return 0;
}

