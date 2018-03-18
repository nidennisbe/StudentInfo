#include<iostream>	
#include <cstdlib>
using namespace std;


string Name;
string Phone_Num;


struct node
{
	string word;
	string num;			
	node*link;
};


class methodClass{
	public:
			void addNode(string,string);
			void sortName();
			void display();
			void deleteNode(int);
			node *myList = new node;

	private:
										
};


//Begin Main
int main() {

	methodClass mc;
	node *myList = new node;
	myList=NULL;
	
	
	
	char input;	
//While different from 3-> DISPLAY MENU OF APP
	cout<<"\t\t\tSTUDENTS INFO";
	while (input!='3'){
	cout<<endl<<"--------------------------------------------|"<<endl
	<<"\nMore Action:"<<endl
	<<"\n1. Add more student"<<endl
	<<"\n2. Delete student"<<endl
	<<"\n3. EXIT"<<endl
	<<"\nCommand: ";
	cin>>input;


//Menu's Condition

//Menu Options
switch (input)
	{
case '1': //1st option
		
		cout<<"\n*NEW STUDENT"<<endl
		<<"--------------"<<endl
		<<"Name: ";
		cin>>Name;
		cout<<"Phone Number: ";
		cin>>Phone_Num;
		mc.addNode(Name,Phone_Num);
		mc.sortName();
		break;
		
case '2': //2nd option
	
		int p;		
		cout<<"\nDELETE STUDENT\n"
		<<"----------------\n"
		<<"Input ID you wish to delete OR '0' to Cancel: ";
		cin>>p;
		mc.deleteNode(p);
		break;
case '3': 	//3rd option
		exit(0);
		break;
default: cout<<endl<<"\t\t\tInvalid Command, Try again"<<endl;
		break;

	}//End of switch case 
	
	mc.display();
	}

}//END MAIN--------------------------------------------------------------------------------------------------




//*************************LIST OF FUNCTIONS********************


	//*Begin +ADD===========================================
void methodClass::addNode(string word, string num) {
		Name=word;
		Phone_Num=num;


		node *post = myList; 
		
		node *newItem=new node;
		newItem->word=Name;
		newItem->num=Phone_Num;
		newItem->link=NULL;
				
		node *pos = myList;
		
			while(true){
			if (pos==NULL){
				myList= newItem;
				break;
			}
			else if (pos->link==NULL){
				pos->link=newItem;
				break;
			}
			pos=pos->link;		
			}
	
}//END ADD===============================================

	//*Display+++++++++++++++++++++++++++++++++++++++++++++++++++++++
void methodClass::display(){
		//node *myList = new node;

	node *	post =myList;
	cout<<"\nNo\tName\t\tPhone Number\n";
	cout<<"--------------------------------------------|";
	int i=0;
	do {
		i++;
		cout<<endl<<i<<"\t"<<post->word<<"\t\t"<<post->num;
		post=post->link;	
		
			}while (post!=NULL)
	}//END display++++++++++++++++++++++++++++++++++++++++++++++++

	//Begin -delete=====================================================
void methodClass::deleteNode(int p){
		
		
			int currentPosition = 0;
			node *pos =myList;
					while (pos!=NULL)
					{
						pos = pos->link;
						currentPosition++;
					}
					
					if(currentPosition<p)
					{
						cout<<endl<<"\t\t\tID NOT FOUND !!!"<<endl;
					}
					else{
		
					int currentPosition=1;	
				
					node *pos=myList;
					node *previous =new node;
					previous=NULL;	
		
				while(currentPosition<p){
				
			previous = pos;
			pos = pos->link;
			currentPosition++;

			if(pos==NULL){								
				cout<<"\t\t\tID Not FOUND, Try again!!!";
					
			}
		}

		if (p>0){
		
		node *newItem= new node;
			newItem=pos->link;
			
			if (previous !=NULL){
				previous->link= newItem;
				
			}else {
				myList = newItem;
				cout<<endl<<"\t\t\tDeleted successfully"<<endl;
				
			}
				delete pos;
			} 
		}

}//END delete===============================================================


//*Sorting>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void methodClass::sortName(){
				string num, word;
				
				node *post = myList;
				post = myList;
				int p = 0;
				
				// sorting Alphabatical
				while(post)
				{
				  post= post->link;	
			      p++;	
				}
				
				post = myList;
			for(int i = 0;i<p;i++)
				{
				while(post->link)
					{
						if(post->word > post->link->word)
						{
							word = post->word;
							num = post->num;
							post->word = post->link->word;
							post->num = post->link->num;
							post->link->word = word;
							post->link->num = num;
						}
						post= post->link;
					}
					post = myList;
				}
		
}//END of sorting<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


