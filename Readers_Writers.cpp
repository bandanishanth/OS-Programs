/*
Author:Nishanth Banda
Objective:A Program that attempts to only simulate the famous Reader's Writers problem in Operating Systems.
*/
#include<iostream>
#include<cstdlib>
//STDLIB to use the exit() function.....
# define BUFFER_SIZE 5 //Consider a Buffer of width 5.
using namespace std;
class buffer
{
	int a[BUFFER_SIZE];
	int count;

public:
 buffer()//Default constructor to initialize count to -1..
 {
  count=-1;//Initially count is -1 , when first producer executes , count becomes 0 and a[0] is given value...n
 }

 void produce(int n)//N is to inserted into buffer....
 {
   if(count<BUFFER_SIZE-1)//This is because of count value being -1 initially..
   {
    a[++count]=n;//Increment count and then assign value....
   }
   else
   {
	 cout<<"Buffer is Full....can't insert."<<endl<<endl;
   }
 }//End of producer
 void consume()//Consumer Code..
 {
	int item;
  if(count>=0)//Note: a[0] will also have value , therfore if count becomes -1 then we can't consume...
  {
 	cout<<"Item consumed is:"<<a[count]<<endl<<endl;
 	count--;
  }
  else
  {
 	cout<<"Buffer Empty...cannot consume."<<endl<<endl;
  }
 }//End of consumer...
 void display_buffer()
 {
	if(count>=0)
	{
		cout<<"Buffer is:";
		for(int i=0;i<=count;i++)
			cout<<a[i]<<"\t";
		cout<<endl<<endl;
	}
    else// If count is -1 , nthing to display....
    {
 		cout<<"Buffer Empty....."<<endl<<endl;
    }
 }//End of display...
};//End of class.....

main()
{
	int option;
	buffer b;
	int item;
	do
	{
		cout<<"----------MENU----------"<<endl;
		cout<<"1.Produce an item."<<endl;
		cout<<"2.Consume an item."<<endl;
		cout<<"3.Display Buffer."<<endl;
		cout<<"4.Exit."<<endl;
		cout<<"------------------------"<<endl;
		cout<<"Enter your option:";
		cin>>option;
		switch(option)
		{
			case 1:cout<<"Enter the item to enter into the Buffer:";
			cin>>item;
			b.produce(item);
			break;
			case 2:b.consume();
			break;
			case 3:b.display_buffer();
			break;
			case 4:exit(0);
			break;
			default:cout<<"Invalid Option."<<endl;
			break;

		}
	}while(1);
}//End of main....
