#include<iostream>
using namespace std;
class Page_table
{
    int nstring[50];
    int n,buffer_size;//n=length of string,frame_size=size of the buffer.....
    int buffer[10];
    int index;//Current index of buffer..
    int page_fault;//Variable that hold the number of page faults.......
    //bool full;
public:
    Page_table(int number,int bsize)//Constructor..
    {
        n=number;//Size of the String...
        buffer_size=bsize;//Size of the Frame..
        page_fault=0;//Initially the number of page_faults is zero...
        index=0;
        //Initially make all the values in the buffer to be -1..
        for(int i=0;i<buffer_size;i++)
            buffer[i]=-1;
    }
    void input_string()
    {
        int i;
        cout<<"Enter the String of numbers:";
        for(i=0;i<n;i++)
            cin>>nstring[i];
    }
    void display()
    {
        int i;
        for(i=0;i<n;i++)
            cout<<nstring[i]<<"\t";
        cout<<endl;
    }
    bool exists(int x)//Checks if the value x already exists in the buffer...
    {
        bool flag=false;//Initially set the flag to false..
        for(int i=0;i<buffer_size;i++)
        {
            if(buffer[i]==x)//If x exists..

            {
                flag=true;//Set flag to true..
                break;//break..
            }
        }
        return(flag);//return flag(boolean)...
    }
    void fifo()
    {
        int i;
        for(i=0;i<n;i++)//Iterate over all the values in nstring..
        {
            if(exists(nstring[i]))//If it already exists in the buffer..
                continue;//Do nothing..
            else
            {
                buffer[index]=nstring[i];//Replace in buffer..
                index=(index+1)%buffer_size;//Index moves around buffer in round robin fashion..
                page_fault++;//Increase the page fault as the value has not been found in buffer...
            }
        }
    }
    void display_faults()
    {
        cout<<"The number of page faults is:";
        cout<<page_fault<<endl;
    }

};
main()
{
    int number;//Number of Memory References in the String...
    int bsize;//Size of the table that has frames..
    cout<<"Enter the number of Memory references in the String:";
    cin>>number;
    cout<<"Enter the size of the buffer:";
    cin>>bsize;
    Page_table p(number,bsize);//Creating an Object of Class Page_table with number and bsize as arguments to constructor..
    p.input_string();
    //p.display();
    cout<<endl;
    p.fifo();
    p.display_faults();
}
