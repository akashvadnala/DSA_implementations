#include <bits/stdc++.h>
using namespace std;


class student{
	string name,roll,cls,email,address;
	long long int phone;
public:
	void listup(){
		int n;
		cout<<"STUDENT MANAGEMENT SYSTEM"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"1. REGISTER A STUDENT"<<endl;
		cout<<"2. DISPLAY STUDENT LIST"<<endl;
		cout<<"3. UPDATE STUDENT DATA"<<endl;
		cout<<"4. SEARCH STUDENT DATA"<<endl;
		cout<<"5. DELETE STUDENT DATA"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"Choose Option [1,2,3,4,5].. ";
		cin>>n;
		cout<<"\n";
		switch(n){
			case 1:
				reg();
				break;
			case 2:
				display();
				break;
			case 3:
				change_data();
				break;
			case 4:
				search();
				break;
			case 5:
				del();
				break;
			default:
				"Invalid Choice.. Enter Again.. ";
				listup();
		}
	}

	void reg(){
		string name,roll,cls,email,address,opt;
		long long int phone;
		cout<<"Enter student name: ";
		cin>>name;
		cout<<"Enter roll number: ";
		cin>>roll;
		cout<<"Enter the class: ";
		cin>>cls;
		cout<<"Enter email address: ";
		cin>>email;
		cout<<"Enter the address: ";
		cin>>address;
		cout<<"Enter mobile number: ";
		cin>>phone;
		fstream file;
		file.open("studentData.txt",ios::app | ios::out);
		file<<name<<" "<<roll<<" "<<cls<<" "<<email<<" "<<address<<" "<<phone<<"\n";
		file.close();
		cout<<"Do you want to enter another record (Y/N).. ";
		cin>>opt;
		if(opt=="Y" || opt=="y") reg();
		else{
			listup();
			cout<<"\n\n\n";
		}
	}

	void display(){
		fstream file;
		file.open("studentData.txt",ios::in);
		cout<<"\n"<<setw(65)<<"STUDENT DATA"<<endl;
		if(!file){
			cout<<"No Data is Present"<<endl;
		}
		else{
			cout<<"|-----------------------------------------------------------------------------------------------------------------------|";
			cout<<"\n|"<<setw(10)<<"Roll No."<<setw(25)<<"Name"<<setw(10)<<"Class"<<setw(15)<<"Contact"<<setw(25)<<"Email"<<setw(25)<<"Address\t\t"<<"|";
			cout<<"\n|-----------------------------------------------------------------------------------------------------------------------|";
			file>>name>>roll>>cls>>email>>address>>phone;
			while(!file.eof()){
				cout<<"\n|"<<setw(10)<<roll<<setw(25)<<name<<setw(10)<<cls<<setw(15)<<phone<<setw(25)<<email<<setw(25)<<address<<"\t\t|";
				file>>name>>roll>>cls>>email>>address>>phone;
			}

			cout<<"\n|-----------------------------------------------------------------------------------------------------------------------|"<<endl;
		}
		file.close();
		cout<<"\n\n\n";
		listup();
	}

	void change_data(){
		string rno;
		int n;
		cout<<"Enter the student roll number to change the data: ";
		cin>>rno;
		fstream file;
		file.open("studentData.txt",ios::in);
		fstream file1;
		file1.open("changed.txt",ios::app | ios::out);
		bool t=false;
		if(!file){
			cout<<"No data is available"<<endl;
			file.close();
		}
		else{
			cout<<"\n"<<setw(65)<<"STUDENT DATA"<<endl;
			file>>name>>roll>>cls>>email>>address>>phone;
			while(!file.eof()){
				if(roll!=rno){
					file1<<name<<" "<<roll<<" "<<cls<<" "<<email<<" "<<address<<" "<<phone<<"\n";
				}
				else{
					t=true;
					cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;
					cout<<"|"<<setw(10)<<"Roll No."<<setw(25)<<"Name"<<setw(10)<<"Class"<<setw(15)<<"Contact"<<setw(25)<<"Email"<<setw(25)<<"Address\t\t"<<"|"<<endl;
					cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;
					cout<<"|"<<setw(10)<<roll<<setw(25)<<name<<setw(10)<<cls<<setw(15)<<phone<<setw(25)<<email<<setw(25)<<address<<"\t\t|"<<endl;cout<<"Changable parameters:\t1.name\t2.class\t3.email\t4.Address\t5.Phone\tEnter [1/2/3/4/5]: ";
					cin>>n;
					while(n<1 || n>5){
						cout<<"Invalid Choice.. Enter again: ";
						cin>>n;
					}

					string cname,ccls,cemail,caddress;
					long long int cphone;
					switch(n){
						case 1:
							cout<<"Enter the name: ";
							cin>>cname;
							file1<<cname<<" "<<roll<<" "<<cls<<" "<<email<<" "<<address<<" "<<phone<<"\n";
							break;
						case 2:
							cout<<"Enter the class: ";
							cin>>ccls;
							file1<<name<<" "<<roll<<" "<<ccls<<" "<<email<<" "<<address<<" "<<phone<<"\n";
							break;
						case 3:
							cout<<"Enter email address: ";
							cin>>cemail;
							file1<<name<<" "<<roll<<" "<<cls<<" "<<cemail<<" "<<address<<" "<<phone<<"\n";
							break;
						case 4:
							cout<<"Enter the address: ";
							cin>>caddress;
							file1<<name<<" "<<roll<<" "<<cls<<" "<<email<<" "<<caddress<<" "<<phone<<"\n";
							break;
						case 5:
							cout<<"Enter Contact number: ";
							cin>>cphone;
							file1<<name<<" "<<roll<<" "<<cls<<" "<<email<<" "<<address<<" "<<cphone<<"\n";
							break;
						default:
							break;
					}
				}
				file>>name>>roll>>cls>>email>>address>>phone;
			}
		}
		if(!t){
			cout<<"No data is found with the entered Roll Number."<<endl;
		}
		else{
			cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;
			cout<<"\n";		
			cout<<"Data has been updated."<<endl;
		}
		file1.close();
		file.close();
		remove("studentData.txt");
		rename("changed.txt","studentData.txt");
		cout<<"\n\n\n";
		listup();
	}

	void search(){
		string sroll,sname,scls;
		int n;
		cout<<"Search Data By:\t\t1.roll no\t2.name\t3.class\nEnter [1/2/3]: ";
		cin>>n;
		while(n<1 || n>3){
			cout<<"Invalid Choice.. Enter again: ";
			cin>>n;
		}
		switch(n){
			case 1:
				cout<<"Enter Roll Number: ";
				cin>>sroll;
				break;
			case 2:
				cout<<"Enter Name: ";
				cin>>sname;
				break;
			case 3:
				cout<<"Enter class: ";
				cin>>scls;
				break;
			default:
				break;
		}
		fstream file;
		file.open("studentData.txt",ios::in);
		bool t=false;
		if(!file){
			cout<<"No data is available"<<endl;
			file.close();
		}
		else{
			cout<<"\n"<<setw(65)<<"STUDENT DATA"<<endl;
			file>>name>>roll>>cls>>email>>address>>phone;
			while(!file.eof()){
				if(roll==sroll || name==sname || cls==scls){
					t=true;
					cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;
					cout<<"|"<<setw(10)<<"Roll No."<<setw(25)<<"Name"<<setw(10)<<"Class"<<setw(15)<<"Contact"<<setw(25)<<"Email"<<setw(25)<<"Address\t\t"<<"|"<<endl;
					cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;
					cout<<"|"<<setw(10)<<roll<<setw(25)<<name<<setw(10)<<cls<<setw(15)<<phone<<setw(25)<<email<<setw(25)<<address<<"\t\t|"<<endl;
				}
				file>>name>>roll>>cls>>email>>address>>phone;
			}
		}
		if(!t){
			cout<<"No data is found with the entered parameters."<<endl;
		}
		else{
			cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;
		}
		file.close();
		cout<<"\n\n\n";
		listup();
	}

	void del(){
		string rno;
		int n;
		cout<<"Enter the student roll number to change the data: ";
		cin>>rno;
		fstream file;
		file.open("studentData.txt",ios::in);
		fstream file1;
		file1.open("deleted.txt",ios::app | ios::out);
		bool t=false;
		if(!file){
			cout<<"No data is available"<<endl;
			file.close();
		}
		else{
			cout<<"\n"<<setw(65)<<"STUDENT DATA"<<endl;
			file>>name>>roll>>cls>>email>>address>>phone;
			while(!file.eof()){
				if(roll!=rno){
					file1<<name<<" "<<roll<<" "<<cls<<" "<<email<<" "<<address<<" "<<phone<<"\n";
				}
				else{
					t=true;
					cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;
					cout<<"|"<<setw(10)<<"Roll No."<<setw(25)<<"Name"<<setw(10)<<"Class"<<setw(15)<<"Contact"<<setw(25)<<"Email"<<setw(25)<<"Address\t\t"<<"|"<<endl;
					cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;
					cout<<"|"<<setw(10)<<roll<<setw(25)<<name<<setw(10)<<cls<<setw(15)<<phone<<setw(25)<<email<<setw(25)<<address<<"\t\t|"<<endl;
				}
				file>>name>>roll>>cls>>email>>address>>phone;
			}
		}
		if(!t){
			cout<<"No data is found with the entered Roll Number."<<endl;
		}
		else{
			cout<<"|----------------------------------------------------------------------------------------------------------------------|"<<endl;	
			cout<<"Data has been deleted."<<endl;
		}
		file1.close();
		file.close();
		remove("studentData.txt");
		rename("deleted.txt","studentData.txt");
		cout<<"\n\n\n";
		listup();
	}
};

int main(){
	student school;
	school.listup();
	return 0;
}