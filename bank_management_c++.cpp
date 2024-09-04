#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bank{
	private:
	
		float balance;
		string id,pass,name,fname,address,phone,pin;
	public:
		void menu();
		void bank_management();
		void atm_management();
		void new_user();
		void already_user();
		void deposit();
		void withdraw();
		void transfer();
		void payment();
		void search();
		void edit();
		void del();
		void show_records();
		void show_payment();
		void user_balance();
		void withdraw_atm();
		void check_detail();
		
		
		
};
void introduction(){
	cout<<"\n\n\n\n\n\t\t\t";
	for(int i=1;i<=60;i++)
	cout<<"*";
	cout<<"\n\t\t\t ";
	for(int i=1;i<=58;i++)
	cout<<"*";
		cout<<"\n\t\t\t  ";
			for(int i=1;i<=56;i++)
	cout<<"*";
	cout<<"\n\n\t\t\t\t\t Bank & ATM Management System\n\t\t\t\t\t\t Project In C++\n\n\t\t\t  ";
	for(int i=1;i<=56;i++)
	cout<<"*";
		cout<<"\n\t\t\t ";
			for(int i=1;i<=58;i++)
	cout<<"*";
			cout<<"\n\t\t\t";
				for(int i=1;i<=60;i++)
	cout<<"*";
	getch();
	system("cls");
	
}
void bank::menu(){
	//from p the things will repeat!!!
	p:
	system("cls");
	int choice;
	char ch;
	string pin,pass,email;
	cout<<"\n\n\t\t\tContol Panel";
	cout<<"\n 1. Bank Management";
	cout<<"\n 2. ATM Management";
	cout<<"\n 3. Exit";
	cout<<"\n\n Enter your choice : ";
	cin>>choice;
	switch(choice){
		case 1:
			system("cls");
			cout<<"\n\n\t\tLogin Account";
			cout<<"\n\n E-mail : ";
			cin>>email;
			cout<<"\n\n\t\t Pin Code : ";
			for(int i=1;i<=5;i++){
				//getch() will get the character!!
				ch = getch();
				pin +=ch;
				cout<<"*";
			}
			cout<<"\n\n Password : ";
			for(int i=1;i<=5;i++){
				ch=getch();
				pass+=ch;
				cout<<"*";
			}
			if(email=="mttpalak@gmail.com" &&  pin=="20202" && pass=="05050"){
				bank_management();
			}
			else{
				cout<<"\n\n Your E-mail , Pin  & Password is wrong !!!";
			}
			
			break;
			case 2:
				atm_management();
				break;
				case 3:
					exit(0);
			default:
				cout<<"\n\n Invalid value>>>Please try again!!";
	}
	//getch() is used tio repeat the things again and again!!!
	//goto makes the things repeat from where p started!!!
	getch();
	goto p;
}
void bank::bank_management(){
		p:
	system("cls");
	int choice;
	cout<<"\n\n\t\tBank Management System";
	cout<<"\n\n 1. New User";
	cout<<"\n 2. Already user";
	cout<<"\n 3. Deposit Option";
	cout<<"\n 4. Withdraw option";
	cout<<"\n 5. Transfer option";
	cout<<"\n 6. Payment option";
	cout<<"\n 7. Search User record";
	cout<<"\n 8. Edit User Record";
	cout<<"\n 9. Delete User Record";
	cout<<"\n 10. Show All Records";
	cout<<"\n 11. Payment All Records";
	cout<<"\n 12. Go back";
	cout<<"\n\n enter Your choice : ";
	cin >> choice;
	switch(choice){
		case 1:
			new_user();
			break;
			case 2:
				already_user();
				break;
				case 3:
					deposit();
					break;
					case 4:
						withdraw();
						break;
						case 5:
							transfer();
		                	break;
			case 6:
				payment();
				break;
				case 7:
					search();
					break;
					case 8:
						edit();
			break;
			case 9:
				del();
				break;
				case 10:
					show_records();
					break;
					case 11:
						show_payment();
			break;
			case 12:
				menu();
				
						default:
								cout<<"\n\n Invalid value>>>Please try again!!";
	}
	getch();
	goto p;
}
void bank::atm_management(){
	p:
	system("cls");
	int choice;
	cout<<"\n\n\t\tATM Management System";
	cout<<"\n\n 1. User login & check balance";
	cout<<"\n 2. Withdraw Amount";
	cout<<"\n 3. Account Details";
	cout<<"\n 4. go back";
	cout<<"\n\n enter Your choice : ";
	cin >> choice;
	switch(choice){
		case 1:
			user_balance();
			break;
			case 2:
				withdraw_atm();
				
				break;
				case 3:
					check_detail();
					break;
					case 4:
						menu();
						default:
								cout<<"\n\n Invalid value>>>Please try again!!";
	}
	getch();
	goto p;
}
void bank::new_user(){
	p:
	system("cls");
	fstream file;
	int p;
	float b;
	string n,f,pa,a,ph,i;
	cout<<"\n\n\t\tAdd new user";
	cout<<"\n\n User ID : ";
	cin>>id;
cout<<"\n\n Name : ";
	cin>>name;
	cout<<"\n\n Father Name : ";
	cin>>fname;
cout<<"\n\n Address : ";
	cin>>address;
cout<<"\n\n Pin code (5 digit) : ";
	cin>>pin;
	
cout<<"\n\n Password (5 digit) : ";
	cin>>pass;
cout<<"\n\n Phone No. : ";
	cin>>phone;
	cout<<"\n\n Current Balance : ";
	cin>>balance;
	file.open("bank.txt",ios::in);
	if(!file){
		file.open("bank.txt",ios::app | ios::out);
	  file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
	  file.close() ;
	}
	else{
		file>>i>>n>>f>>a>>p>>pa>>ph>>b;
		while(!file.eof()){
			if(i==id){
				cout<<"\n\n User ID Already Exist...";
				getch();
				goto p;
			}
			file>>i>>n>>f>>a>>p>>pa>>ph>>b;
		}
		file.close();
		file.open("bank.txt",ios::app | ios::out);
	  file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
	  file.close() ;
		
	}
	cout<<"\n\n New User Account Created Successfully...";



}
	void bank::already_user(){
		system("cls");
		fstream file;
		string t_id;
		int found=0;
		cout<<"\n\n Already User Account";
		file.open("bank.txt",ios::in);
		if(!file){
			cout<<"\n\nFile Opening error!!";
		}
		else{
			cout<<"\n\n User ID : ";
			cin>>t_id;
			file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()){
				if(t_id==id){
					system("cls");
					cout<<"\n\n\t\t Already User Account";
					cout<<"\n\n User ID:" <<id<<"   Pin Code: "<<pin<<"   Password: "<<pass;
					found++;
				}
				file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			}
			file.close();
			if(found==0)
			cout<<"\n\n User ID can't found...";
			
		}
		
	}
	void bank::deposit(){
		string t_id;
		int found=0;
		float dep;
		fstream file,file1;
		system("cls");
		cout<<"\n\n\t\tDeposit Amount option";
		file.open("bank.txt",ios::in);
		if(!file){
			cout<<"\n\nFile Opening error!!";
		}
		else{
		cout<<"\n\n User ID : ";
			cin>>t_id;
			file1.open("bank1.txt",ios::app|ios::out);
			file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()){
				if(t_id==id){
					
					cout<<"\n\n Enter Amount for Deposit : ";
					cin>>dep;
					balance+=dep;
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
					found++;
					cout<<"\n\n\t\t\tYour Amount"<< dep<<" Sucessfully Deposit...";
				}
				else{
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
				}
				file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			}
			file.close();
			file1.close();
			remove("bank.txt");
			rename("bank1.txt","bank.txt");
			if(found==0)
			cout<<"\n\n User ID can't found...";	
		}
	}
	void bank::withdraw(){
		string t_id;
		int found=0;
		float with;
		fstream file,file1;
		system("cls");
		cout<<"\n\n\t\tWithdraw Amount option";
		file.open("bank.txt",ios::in);
		if(!file){
			cout<<"\n\nFile Opening error!!";
		}
		else{
		cout<<"\n\n User ID : ";
			cin>>t_id;
			file1.open("bank1.txt",ios::app|ios::out);
			file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()){
				if(t_id==id){
					
					cout<<"\n\n Enter Amount for Withdraw : ";
					cin>>with;
					if(with<=balance){
					
					balance-=with;
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
				
					cout<<"\n\n\t\t\tYour Amount"<< with<<" Sucessfully Withdraw...";
				}
				else{
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
					cout<<"\n\n\t\t Your Current Balance "<<balance <<"is Less...";
				}
					found++;
				}
				else{
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
				}
				file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			}
			file.close();
			file1.close();
			remove("bank.txt");
			rename("bank1.txt","bank.txt");
			if(found==0)
			cout<<"\n\n User ID can't found...";	
		}
	}
	void bank::transfer(){
	fstream file,file1;
	
	system("cls");
	string s_id,r_id;
	int found=0;
	float amount;
	cout<<"\n\n\t\tPayment Transfer Option";
	file.open("bank.txt",ios::in);
		if(!file){
			cout<<"\n\nFile Opening error!!";
		}
		else{
			cout<<"\n\n Enter sender User ID for Transaction : ";
			cin>>s_id;
			cout<<"\n\n receiver User ID for Transaction :"	;
			cin>>r_id;
			
			cout<<"\n\n Enter transfer Amount : ";
			cin>>amount;
			
			file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			
					
			
				while(!file.eof()){
					if(s_id==id && balance>=amount) 
						found++;
					
					
					else if(r_id==id)
						found++;
						
				file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
					}
					file.close();
					if(found==2){
						file.open("bank.txt",ios :: in);
						file1.open("bank1.txt",ios::app|ios::out);	
						file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
						while(!file.eof()){
							if(s_id==id ){
								balance-=amount;
									file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";			
							}
							else if(r_id==id){
								balance +=amount;
									file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";			
							}
							else{
									file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";			
							}
							file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
						}
						
						file.close();
						file1.close();
						remove("bank.txt");
			rename("bank1.txt","bank.txt");	
							}	
					else{
						cout<<"\n\n\t\tBoth transaction IDs  & balance are invalid...";
					}		
								
				}
				
		}
		void bank::payment(){
			
			system("cls");
			fstream file;
			fstream file1;
			int found=0;
			float amount;
			string t_id,b_name;
			SYSTEMTIME x;
			cout<<"\n\n\t\tBills Payment Option";
			file.open("bank.txt",ios::in );
			if(!file)
		{
		cout<<"\n\n File Opening Error..";
		}
		else{
			cout<<"\n\n User ID: ";
			cin>>t_id;
			cout<<"\n\n Bill Name: ";
			cin>>b_name;
			cout<<"\n\nBill Amount: ";
			cin>>amount;
			file1.open("bank1.txt",ios::app|ios::out);
			file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()){
				if(t_id==id && amount<=balance)
					{
						balance-=amount;
						file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";	
						found++;
						
					}
					else{
						file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";	
					}
					file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			}
				file.close();
				file1.close();
						remove("bank.txt");
			rename("bank1.txt","bank.txt");	
				if(found==1){
					GetSystemTime(&x);
					file.open("bill.txt",ios::app | ios::out);
					file<<t_id <<" "<<b_name <<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";
					file.close();
					cout<<"\n\n\t\t"<<b_name<<" Bill Pay Successfully...";
				}
				else{
					cout<<"\n\n\t\tUser ID OR Amount is invalid!!!";
				}
			
			
		}
}
void bank::search(){
	system("cls");
	cout<<"\n\n\t\tSearch User Record";
	fstream file;
	string t_id;
	int found=0;
	file.open("bank.txt",ios::in );
	if(!file){
		cout<<"\n\nFile Opening Error!!!";
	}
	else{
		cout<<"\n\nUser ID : ";
		cin>>t_id;
		//to get record from file...
		file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
		while(!file.eof())
{
	if(t_id==id){
		system("cls");
			cout<<"\n\n\t\tSearch User Record";
			cout<<"\n\n\n User ID: "<<id <<endl<<" Name: "<<name <<endl<<" Fathers Name: "<<fname<<endl<<" Address: "<<address<<endl<<" PinCode: "<<pin<<endl<<" Password:  "<<pass<<endl<<" PhoneNo: "<<phone<<endl<<" Current Balance: "<<balance;
			
			found++;
			
		
	}
	file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
		}
		file.close();
		if(found==0)
		cout<<"\n\nUser ID can't found!!!";		
	}
}
	void bank::edit()
{
	system("cls");
	fstream file,file1;
	string t_id,n,f,a,p,ph;
	
	int found=0,pi;
	cout<<"\n\n\t\tEdit User Record";
	file.open("bank.txt",ios::in);
	if(!file)
	cout<<"\n\nFile Opening Error!!";
	
	else{
		cout<<"\n\n User ID : ";
		cin>>t_id;
		file1.open("bank1.txt",ios::app|ios::out);
		file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
		while(!file.eof())
{
	if(t_id==id){
			cout<<"\n\n Name : ";
			cin>>n;
	cout<<"\n\n Father Name : ";
	cin>>f;
cout<<"\n\n Address : ";
	cin>>a;
cout<<"\n\n Pin code (5 digit) : ";
	cin>>pi;
	
cout<<"\n\n Password : ";
	cin>>p;
cout<<"\n\n Phone No. : ";
	cin>>ph;
	
		file1<<" "<<id<<" "<<n<<" "<<f<<" "<<a<<" "<<pi<<" "<<p<<" "<<ph<<" "<<balance<<"\n";	
		cout<<"\n\n\n\t\t\tRecord Edit Successfully...";
	
			found++;
			
}
	
	else{
			file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";	
	}
	file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
		}
		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt","bank.txt");
		if(found==0)
		cout<<"\n\nUser ID can't found!!!";		
	}
}
	void bank::del(){
		
	system("cls");
	fstream file,file1;
	string t_id;
	
	int found=0;
	cout<<"\n\n\t\tDelete User Record";
	file.open("bank.txt",ios::in);
	if(!file)
	cout<<"\n\nFile Opening Error!!";
	
	else{
		cout<<"\n\n User ID : ";
		cin>>t_id;
		file1.open("bank1.txt",ios::app|ios::out);
		file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
		while(!file.eof())
{
	if(t_id==id){
		
		cout<<"\n\n\n\t\t\tRecord Deleted Successfully...";
	
			found++;
			

	}
	else{
			file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";	
	}
	file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
		}
		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt","bank.txt");
		if(found==0)
		cout<<"\n\nUser ID can't found!!!";	
	}
		
}
void bank::show_records(){
	system("cls");
	int found=0;
		fstream file;
	cout<<"\n\n\t\tShow All User Records";
   file.open("bank.txt",ios::in);
   if(!file){
   	cout<<"\n\nFile Opening Error!!";
   }
   else{
   		file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
		while(!file.eof())
{
cout<<"\n\n\n User ID : "<<id;
cout<<"\n\n\n Name : "<<name;
cout<<"\n\n\n Father Name : "<<fname;
cout<<"\n\n\n Address : "<<address;
cout<<"\n\n\n Pin Code : "<<pin;
cout<<"\n\n\n Password : "<<pass;
cout<<"\n\n\n Phone No : "<<phone;
cout<<"\n\n\n Balance : "<<balance;
cout<<"\n\n================================="; 
	file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
	found++;
		}
		file.close();
		if(found==0)
		cout<<"\n\n DataBase is Empty!!!";
   }
	
}
void bank::show_payment(){
		system("cls");
	int found=0;
		fstream file;
		float amount;
		string c_date;
	cout<<"\n\n\t\tShow All Bill's Records";
   file.open("bill.txt",ios::in);
   if(!file){
   	cout<<"\n\nFile Opening Error!!";
   }
   else{
   
   		file>>id>>name>>amount>>c_date;
		while(!file.eof())
{
cout<<"\n\n\n User ID : "<<id;
cout<<"\n\n\n Bill Name : "<<name;
cout<<"\n\n\n Bill Amount : "<<amount;
cout<<"\n\n\n Date : "<<c_date;

cout<<"\n\n================================="; 
	file>>id>>name>>amount>>c_date;
	found++;
		}
		file.close();
		if(found==0)
		cout<<"\n\n DataBase is Empty!!!";
   }
}
void bank::user_balance(){
	system("cls");
	fstream file;
	string t_id,t_pin,t_pass;
	char ch;
	int found=0;
	
	cout<<"\n\n\t\tUser Login & Check balance";
	file.open("bank.txt",ios::in);
	if(!file){
		cout<<"\n\nFile Opening error!!";
	}
	else{
		cout<<"\n\n User ID : ";
		\
		cin>>t_id;
		cout<<"\n\n\t\tPin code : ";
		for(int i=1;i<=5;i++){
			ch=getch();
			t_pin+=ch;
			cout<<"*";
		}
		cout<<"\n\n Password : ";
		for(int i=1;i<=5;i++){
			ch=getch();
			t_pass+=ch;
			cout<<"*";
		}
			file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()){
				if(t_id==id && t_pin==pin && t_pass==pass){
					cout<<"\n\n\t\tYour Current balance is : "<<balance;
					found++;
				}
				file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			}
			file.close();
			if(found==0)
			cout<<"\n\n\t\tUser ID ,Pin & Password Invalid!!!";
		
	}
	
}
void bank :: withdraw_atm(){
	system("cls");
	cout<<"\n\n\t\tWithdraw Amount";
	string t_id,t_pass,t_pin;
		int found=0;
		char ch;
		float with;
		fstream file,file1;
		system("cls");
		cout<<"\n\n\t\tWithdraw Amount option";
		file.open("bank.txt",ios::in);
		if(!file){
			cout<<"\n\nFile Opening error!!";
		}
		else{
		cout<<"\n\n User ID : ";
			cin>>t_id;
			cout<<"\n\n\t\tPin code : ";
		for(int i=1;i<=5;i++){
			ch=getch();
			t_pin+=ch;
			cout<<"*";
		}
		cout<<"\n\n Password : ";
		for(int i=1;i<=5;i++){
			ch=getch();
			t_pass+=ch;
			cout<<"*";
		}
				
			
			file1.open("bank1.txt",ios::app|ios::out);
			file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()){
				if(t_id==id && t_pin ==pin && t_pass==pass){
					
					cout<<"\n\n Enter Amount for Withdraw : ";
					cin>>with;
					if(with<=balance){
					
					balance-=with;
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
				
					cout<<"\n\n\t\t\tYour Amount"<< with<<" Sucessfully Withdraw...";
					cout<<"\n\n\t\t Your Current Balance : "<<balance;
				}
				else{
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
					cout<<"\n\n\t\t Your Current Balance "<<balance <<"is Less...";
				}
					found++;
				}
				else{
					file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
				}
				file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			}
			file.close();
			file1.close();
			remove("bank.txt");
			rename("bank1.txt","bank.txt");
			if(found==0)
			cout<<"\n\n User ID can't found...";	
		}
}
void bank :: check_detail(){
	
	string t_id,t_pass,t_pin;
		int found=0;
		char ch;
		fstream file;
		system("cls");
		cout<<"\n\n\t\tCheck Details option";
		file.open("bank.txt",ios::in);
		if(!file){
			cout<<"\n\nFile Opening error!!";
		}
		else{
		cout<<"\n\n User ID : ";
			cin>>t_id;
			cout<<"\n\n\t\tPin code : ";
		for(int i=1;i<=5;i++){
			ch=getch();
			t_pin+=ch;
			cout<<"*";
		}
		cout<<"\n\n Password : ";
		for(int i=1;i<=5;i++){
			ch=getch();
			t_pass+=ch;
			cout<<"*";
		}
				
			file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			while(!file.eof()){
				if(t_id==id && t_pin ==pin && t_pass==pass){
		cout<<"\n\n\n User ID : "<<id;
		cout<<"\n\n\n Name : "<<name;
		cout<<"\n\n\n Father Name : "<<fname;
		cout<<"\n\n\n Address : "<<address;
		cout<<"\n\n\n Pin Code : "<<pin;
		cout<<"\n\n\n Password : "<<pass;
		cout<<"\n\n\n Phone No : "<<phone;
		cout<<"\n\n\n Balance : "<<balance; 
					
					found++;
				}
				
				file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
			}
			file.close();
			
			if(found==0)
			cout<<"\n\n User ID can't found...";	
		}
}		
int main(){

	bank obj;
		introduction();
	obj.menu();
}
