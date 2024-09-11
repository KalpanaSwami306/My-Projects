#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dos.h>
#include<iomanip>

using namespace std;
class customer  //customer class
{
	private:
	public:
		string customername;
		string carmodel;
		string carnumber;
		char data; 
		// variables defined in this class in public mode.
};
class rent:public customer  // inherited class from customer class
{
	public:
		int days=0,rentalfee =0;  //additional int variables defined
		void data()
		{
			int login();
			login();
			cout<<"\t\t\t\t Please Enter your Name: ";   //taking data from the user
			cin>>customername;
			cout<<endl;
			
			do 
			{
				cout<<"\t\t\t\t Please Select a Car"<<endl;  //giving user a choice to select among three numbers
				cout<<"\t\t\t\t Enter 'A' for Tesla 2011."<<endl;
				cout<<"\t\t\t\t Enter 'B' for Hyundai 2015."<<endl;
				cout<<"\t\t\t\t Enter 'C' for Ford 2017."<<endl;
				cout<<endl;
				cout<<"\t\t\t\t Choose a Car from the above options: ";
				cin>>carmodel;
				cout<<endl;
				cout<<"_____________________________________________________________________________________";
				if (carmodel=="A" || carmodel =="a")
				{
					system ("CLS");
					cout<<"You Have Chosen Tesla Model 2011"<<endl;
					ifstream inA("A.txt");  //displaying details of model A
					char str[200];
					while(inA)
					{
						inA.getline(str,200);
						if(inA)
						{
							cout<<str<<endl;
						}
					}
				}
				sleep(2);	
				if (carmodel=="B"||carmodel=="b")
				{
					system("CLS");
					cout<<"You Have Chosen Hyundai 2015"<<endl;
					ifstream inB("B.txt");  //displaying details of model B
					char str[200];
				    while(inB)
					{
						inB.getline(str,200);
						if(inB)
						{
							cout<<str<<endl;
						}
					}			
				}	
				if(carmodel=="C"||carmodel=="c")
				{
					system("CLS");
					cout<<"You Have Chosen Ford Model 2017 "<<endl;
					ifstream inC("C.txt");  //displaying details of model C
					char str[200];
				    while(inC)
					{
						inC.getline(str,200);
						if(inC)
						{
							cout<<str<<endl;
						}
						sleep(2);
					}
				}
				if(carmodel !="A" && carmodel !="B" && carmodel !="C")
				{
				cout<<"Invalid Car Model. Please try again !"<<endl;
			    }
			} while(carmodel !="A" && carmodel !="B" && carmodel !="C");
			cout<<"__________________________________________________________________________________________________"<<endl;
			cout<<"Please provide the following information: "<<endl;
			// getting data from user related to rental service
			cout<<"Please select a car number: ";
			cin>>carnumber;
			cout<<"Number of days you wish to rent the car: ";
			cin>>days;
			cout<<endl;
    	}
	
    	void calculate()
			{
				sleep(1);
				system("CLS");
				cout<<"Calculating rent. Please wait..........."<<endl;
				sleep(2);
				if(carmodel=="A"||carmodel=="a")
				{
					rentalfee=days*56;
				}
				else if(carmodel=="B"||carmodel=="b")
				{
					rentalfee=days*60;
				}
				else if(carmodel=="C"||carmodel=="c")
				{
					rentalfee=days*60;
				}
		    }
			
	    void showrent()
			{
				cout<<"\n\t\t                           Car Rental - Customer Invoice                          "<<endl;
				cout<<"\t\t     ////////////////////////////////////////////////////////////////"<<endl;
				cout<<"\t\t     | Invoice No. :"<<"_______________________|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
				cout<<"\t\t     | Customer Name:"<<"______________________|"<<setw(10)<<customername<<" |"<<endl;
				cout<<"\t\t     | Car Model :"<<"_________________________|"<<setw(10)<<carmodel<<"|"<<endl;
				cout<<"\t\t     | Car No. :"<<"___________________________|"<<setw(10)<<carnumber<<" |"<<endl;
				cout<<"\t\t     | Number of days :"<<"____________________|"<<setw(10)<<days<<" |"<<endl;
				cout<<"\t\t     | Your Rental Amount is :"<<"_____________|"<<setw(10)<<rentalfee<<" |"<<endl;
				cout<<"\t\t     | Caution Money :"<<"_____________________|"<<setw(10)<<"0"<<" |"<<endl;
				cout<<"\t\t     | Advanced :"<<"__________________________|"<<setw(10)<<"0"<<" |"<<endl;
				cout<<"\t\t     ================================================================="<<endl;
				cout<<"\n";
				cout<<"\t\t     | Total Rental Amount is:"<<"_____________|"<<setw(10)<<rentalfee<<" |"<<endl;
				cout<<"\t\t      # This is a computer generated invoice and it does not"<<endl;
				cout<<"\t\t        require an authorised signature #"<<endl;
				cout<<" "<<endl;
				cout<<"\t\t     ////////////////////////////////////////////////////////////////////"<<endl;
				cout<<"\t\t      You are advised to pay up the amount before due date, "<<endl;
				cout<<"\t\t      Otherwise penalty fee will be applied. "<<endl;
				cout<<"\t\t     //////////////////////////////////////////////////////////////////////"<<endl;
				int f;
				system(" PAUSE ");
				system("CLS");
				ifstream inf("THANK YOU.txt");
				char str[300];
				while(inf)
				{
					inf.getline(str,300);
					if(inf) cout<<str<<endl;
				}
				inf.close();
			}
};

class welcome   //welcome class
{
	public:
		int welcum()
		{
			ifstream in("welcome.txt");  //displaying welcome ASCII image text on output screen fn1353
			
			if(!in)
			{
				cout<<"Cannot open input file.\n";
			}
			char str[1000];
			while (in)
			{
				in.getline(str,1000);    // delim defaults to '\n' cp
				if(in) 
				cout<<str<<endl;
			}
			in.close();
			sleep(1);
			cout<<"\n loading up files........"<<endl;
			sleep(1);
			cout<<"\n loading up files......."<<endl;
			sleep(1);  //function which waits for n seconds
			system ("CLS");   //clears screen
		}
};

int main()
{
	welcome obj1;  // object created for welcome class
	obj1.welcum();  // welcum function is called
	rent obj2;
	// object created for rent class and further member functions are called
	obj2.data() ;
	obj2.calculate ();
	obj2.showrent();
	return 0;  //end of the program
}

int login()
{
	string pass="";
	char ch;
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t             CAR RENTAL SYSTEM \n\n";
	cout<<"\t\t\t\t\t--------------------------------------------";
	cout<<"\n\t\t\t\t\t\t           LOGIN   \n";
	cout<<"\t\t\t\t\t--------------------------------------------\n\n";
	cout<<"\t\t\t\t\t Enter Password: ";
	ch=_getch();
	while(ch != 13)  //character 13 is entered
	{
		pass.push_back(ch);
		cout<<'*';
		ch=_getch();
	}
	if(pass=="pass")
	{
		cout<<"\n\n\n\t\t\t\t\t\t Access Granted!   \n";
		system("PAUSE");
		system("CLS");
	}
	else
	{
		cout<<"\n\n\n\t\t\t\t\t\t\t\t Access Aborted............\n\t\t\t\t\t\t\t\t\t\t\t Please Try Again \n\n";
		system("PAUSE");
		system("CLS");
		login();
	}
}
