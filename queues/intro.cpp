// introduction to queues , basic functions and fundamentals and implementations of queues STL

#include<iostream>
#include<queue>
using namespace std;

void print(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" " ;
        q.pop();
    }
    cout<<endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    print(q);

    cout<<q.front()<<endl;
    q.pop();
    
    cout<<q.front()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    print(q);
    return 0;
}
