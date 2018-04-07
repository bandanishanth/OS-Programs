#include<iostream>
#include<cstdlib>
using namespace std;
struct process
{
    int allocation[5];
    int maximum[5];
    int need[5];
    bool finish;
};
bool check(process p,int work[],int resource_count)//It is a function that checks if the need of process is less than or equal to work...
{
    bool flag=true;//Initially set flag to True..
    for(int i=0;i<resource_count;i++)
    {
        flag=flag&&(p.need[i]<=work[i]);
    }
    return flag;//Return the value of the flag....
}
void safety(process p[],int available[],int resource_count,int number)
{
    int work[resource_count];//An array that holds the work done.....
    //Initializing Work=Available....
    for(int i=0;i<resource_count;i++)
        work[i]=available[i];
    //Initializing all the flags of processes to false....
    for(int i=0;i<number;i++)
    {
        p[i].finish=false;
        //p[i].visited=false;
    }
    //Seeing the safe sequence...
    int sequence[10];//An array that hold the sequence of safe or unsafe processes...
    int l=0;//A variable that keeps track of the index of the array sequence...
    //We check if all the processes have been finished "number"(number of processes) times...if not finished...we say unsafe.
    for(int m=0;m<number;m++)
    {
        for(int i=0;i<number;i++)
        {
            if(p[i].finish==true)
                continue;
            //p[i].visited=true;
            if(check(p[i],work,resource_count))//If Need<=Work......using check function...
            {
                for(int k=0;k<resource_count;k++)//Work=Work+allocation...
                    work[k]+=p[i].allocation[k];
                p[i].finish=true;//Process is finished..
                sequence[l++]=i;//Add process to the sequence array and increment the variable 'l' that holds the index..
            }
        }
    }

    for(int i=0;i<number;i++)
    {
       if(p[i].finish==false)//If any process is still not finished..
        {
            cout<<"Sequence is Unsafe.";
            sequence[l++]=i;//Add the unsafe process to the sequence array...
        }
    }
    cout<<"Sequence is:";
    for(int i=0;i<l;i++)//Loop till last index in sequence... i.e 'l'...
        cout<<sequence[i]<<"\t";//Display the sequence
    cout<<endl;
}
//The Resource Request Algorithm......
void resource_request(process p[],int available[],int resource_count,int number)
{
int index;//hold the index of the Process that is REQUESTING FOR THE RESOURCE...
cout<<"Enter the process number that is requesting for a resource:";
cin>>index;
int request[resource_count];//An array that Holds the request for each resource type by the process p[index]...
cout<<"Enter the requested number of resources of each type in order:";
for(int i=0;i<resource_count;i++)//Taking Request input...
    cin>>request[i];
//Step 1 : Request[i]<=Need.....value is held by flag 1.....
bool flag1=true;
for(int i=0;i<resource_count;i++)
{
    if(request[i]>p[index].need[i])
        flag1=false;
}
//Step 2:Request<=Available..., value is held by flag2
bool flag2=true;
for(int i=0;i<resource_count;i++)
{
    if(request[i]>available[i])
        flag2=false;
}
//If both flag1 and flag2 are true..allocate resource...
if(flag1==true && flag2==true)
{
    //Note index hold the process in array p[]..but i is used for each resource in p[index].....
    cout<<"The Request can be granted."<<endl;
    //Available=Available-Request..
    for(int i=0;i<resource_count;i++)
        available[i]=available[i]-request[i];

    //Allocation=Allocation+request.......
    for(int i=0;i<resource_count;i++)
        p[index].allocation[i]+=request[i];
    //Need=Need-Request..
    for(int i=0;i<resource_count;i++)
        p[index].need[i]-=request[i];
    //Checking the safety..
    cout<<"Checking the safety of this allocation."<<endl;
    safety(p,available,resource_count,number);//Check safety of allocation using safety algorithm....

}

}
main()
{
    int i,j;
    int number;//Variable that holds the number of processes..
    int resource_count;//Variable that gives the number of different resource types...
    cout<<"Enter the number of processes:";
    cin>>number;

    process p[number];//Array of process type of size number..

    cout<<"Enter the number of resource types:";
    cin>>resource_count;

    int resource_type[resource_count];//Array of resource_types of size resource_count...
    int available[resource_count];//A GLOBAL array that holds the current number of available resources of each type........

    //Taking the total instances of all types....
    cout<<"Enter the total number of instances of each resource type:"<<endl;
    for(i=0;i<resource_count;i++)//To input the total number of resources of each resource type...
    {
        cout<<"Enter the total number of instances of resource type:"<<i<<":";
        cin>>resource_type[i];
        //Initially we are initializing the available to the total....
        available[i]=resource_type[i];
    }

    //Entering the information regarding each process......
    cout<<"Enter the information of each process asked below:"<<endl;
    for(i=0;i<number;i++)
    {
        cout<<"Process "<<i<<":"<<endl;
        cout<<"Enter the allocation of each resource type in order:";
        for(j=0;j<resource_count;j++)
        {
            cin>>p[i].allocation[j];//Taking allocation of each resource type for the current process..
            //Reduce the same number of resources from the available....
            available[j]-=p[i].allocation[j];//Available=Available-Allocation to process...
        }
        cout<<"Enter the maximum required instances of each resource type:";
        for(j=0;j<resource_count;j++)
        {
            cin>>p[i].maximum[j];//Taking the maximum of each resource type for the current process...
        }
        //Calculating the need . We know Need=Maximum-Allocation....
        for(j=0;j<resource_count;j++)
            p[i].need[j]=p[i].maximum[j]-p[i].allocation[j];//Need=Maximum - Allocation...
    }

    //Displaying the Menu to the User......
    int option;//Variable that holds the option that the user selects...
    do
    {
        cout<<"-----MENU-----"<<endl;
        cout<<"1.Check Safety."<<endl;
        cout<<"2.Request Resource."<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"--------------"<<endl;
        cout<<"Enter your option:";
        cin>>option;
    switch(option)
    {
        case 1:safety(p,available,resource_count,number);//Execute Safety if option==1..
        break;
        case 2:resource_request(p,available,resource_count,number);//Execute Resource Request if option==2..
        break;
        case 3:exit(0);//Exit if option==3....
        break;
        default:
            cout<<"Invalid Option!!!!"<<endl;

    }
    }while(option!=4);
}
