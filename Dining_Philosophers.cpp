#include<iostream>
#include<cstdlib>
using namespace std;
void ini(int semaphore[],int philo[],char state[])
{
    for(int i=0;i<5;i++)
    {
        semaphore[i]=0;
        philo[i]=i;
        state[i]='T';
    }
}
void hungry(int n,int semaphore[],int philo[],char state[])
{
    int left,right;
    if(semaphore[n]!=1)
    {
        state[n]='H';
        left=((n-1)%5);
        right=((n+1)%5);
        if (state[n]=='H')
        {
            if (state[left]!='E'&& state[right]!='E')
            {
                state[n]='E';
                semaphore[n]++;
            }
        }
    }
    else
    {
        cout<<"How much will you feed him!!!!!, he's already eating!!!."<<endl;
    }
}
void thinking(int n,int semaphore[],int philo[],char state[])
{
    if (state[n]=='T')
    {
        cout<<"He is already in a thinking state.\n";
    }
    else if(state[n]=='H')
    {
        state[n]='T';
        cout<<"Philosopher was initially in a hungry state, we have moved him to thinking state.\n";
    }
    else
    {
        state[n]='T';
        semaphore[n]--;
        cout<<"Philosopher was initially in an eating state, we have moved him to thinking state.\n";
    }
}
void status(int semaphore[],int philo[],char state[])
{
    cout<<"S\tP_NO\tState\n";
    for(int i=0;i<5;i++)
    {
    cout<<semaphore[i]<<"\t"<<philo[i]<<"\t"<<state[i]<<endl;
    }
}
main()
{
    char state[5];
    int philo[5],semaphore[5];
    ini(semaphore,philo,state);
    status(semaphore,philo,state);
    int n,ch;
    do
    {
        cout<<"Please enter your option:"<<endl;
        cout<<"----------MENU---------"<<endl;
        cout<<"1.Status"<<endl<<"2.Hungry "<<endl<<"3.Thinking "<<endl<<"4.Exit"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Enter your option:";
        cin>>ch;
        switch (ch)
        {
                case 1: status(semaphore,philo,state);
                        break;
                case 2: cout<<"Enter the philospher:";
                        cin>>n;
                        hungry(n,semaphore,philo,state);
                        break;
                case 3: cout<<"Enter the philospher:";
                        cin>>n;
                        thinking(n,semaphore,philo,state);
                        break;
                case 4:exit(0);
                        break;
                default:cout<<"INVALID INPUT!!!"<<endl;
        }
     }while(ch!=5);
}
