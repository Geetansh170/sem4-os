#include<queue>
#include<iostream>
#include<map>
using namespace std;

void print(queue<int>q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";q.pop();
    }
    cout<<endl;
}

int fcfs(int n,int pages[])
{
    int page_fault=0;
    queue<int>q;
    map<int,bool>present;
    for(int i=0;pages[i]!=-1;i++)
    {
        if(present[pages[i]]==false)
        {
            page_fault++;
            if(q.size()<n){q.push(pages[i]);present[pages[i]]=true;}
            else
            {
                present[q.front()]=false;
                q.pop();
                q.push(pages[i]);
                present[pages[i]]=true;
            }
        }
        print(q);
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
    cout<<endl<<"page faults:"<<fcfs(n,pages);
    return 0;
}
