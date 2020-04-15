#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class local
{
    long long int addhar_no;
	char name[50];
	char gender;
	int dd,mm,yy;
	char marrige;
	char address[100];
	float income;
	char religion[10];
	char occupation[10];

	public:
		void getdata();
		void showdata();
	    long long int getaddhar();
}s;										//local class declaration of class local

void local::getdata()								//accept the value from user
{
	cout<<"\n\n Enter the person information..\n";

	cout<<"Enter Aadhar Number(16 digit)  :";
	cin>>addhar_no;
	cout<<"enter full Name                :";
	cin>>name;
	cout<<"enter gender(M/f)              :";
    cin>>gender;
	cout<<"enter date of birth(DD/MM/YYYY):";
    cin>>dd>>mm>>yy;
	cout<<"enter martial status(y/n)      :";
    cin>>marrige;
	cout<<"enter PERMANT Address          :";
	cin>>address;
	cout<<"enter annual income            :";
    cin>>income;
	cout<<"enter the religion             :";
	cin>>religion;
    cout<<"enter the occupation           :";
    cin>>occupation;

}

void local::showdata()								//display the value to user
{
	cout<<"	\n\n";
	cout<<"Aadhaar no.         :"<<addhar_no<<endl;
	cout<<"Full Name           :"<<name<<endl;
	cout<<"Gender              :"<<gender<<endl;
	cout<<"date of birth       :"<<dd<<"/"<<mm<<"/"<<yy<<endl;
	cout<<"Marital status      :"<<marrige<<endl;
	cout<<"permanent address   :"<<address<<endl;
	cout<<"annual income       :"<<income<<endl;
	cout<<"Religion            :"<<religion<<endl;
	cout<<"Occupation          :"<<occupation<<endl;

}
long long int local::getaddhar()
{
	return addhar_no;
}

void addData()
{
 ofstream fout;												//create the file and write into the file
 fout.open("Public.txt",ios::binary|ios::out|ios::app);
 s.getdata();
 fout.write((char*)&s,sizeof(s));
 fout.close();
 cout<<"\n\nData Successfully Saved to File....\n";
}

void displayData()
{
 ifstream fin;											//input file stream and is used to read information from files
 fin.open("Public.txt",ios::in|ios::binary);
 cout<<"	********Displaying detail*********\n";
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showdata();
 }
 fin.close();
 cout<<"\n\nData Reading from File Successfully Done....\n";
 system("pause");
}

void searchData()
{
 long long int n;int flag=0;
 ifstream fin;
 fin.open("Public.txt",ios::in|ios::binary);
 cout<<"Enter Addhar Number you want to search : ";
 cin>>n;

 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getaddhar())
  {
   cout<<"The Details of Aadhaar No. entered is "<<n<<" shown herewith:\n";
   s.showdata();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
 cout<<"The Aadhaar No. "<<n<<" not found....\n\n";
 cout<<"\n\nData Reading from File Successfully Done....\n";
 system("pause");
}

void deleteData()
{
 int n, flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("Public.txt",ios::in|ios::binary);
 fout.open("Temp.txt",ios::out|ios::app|ios::binary);
 tout.open("Trash.txt",ios::out|ios::app|ios::binary);

 cout<<"Enter Aadhar number : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getaddhar())
  {
   cout<<"The Following Addhar No. "<<n<<" has been moved to Trash:\n";
   s.showdata();
   tout.write((char*)&s,sizeof(s));
   flag++;
   system("pause");
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
   
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
 {
  cout<<"The Aadhar No. "<<n<<" not found....\n\n";
  system("pause"); 
 }
 remove("Public.txt");
 rename("temp.txt","Public.txt");
}

void modifyData()							//modify data
{
 int n, flag=0, pos;
 fstream fio;									//both input and output file stream

 fio.open("Public.txt",ios::in|ios::out|ios::binary);
 
 cout<<"Enter Aadhar Number you want to Modify : ";
 cin>>n;
 
 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg();					//tellg returns the value of current file pointer
  if(n==s.getaddhar())
  {
   cout<<"The Following Aadhar No. "<<n<<" will be modified with new data:\n";
   s.showdata();
   cout<<"\n\nNow Enter the New Details....\n";
   s.getdata();
   fio.seekg(pos-sizeof(s));
   fio.write((char*)&s,sizeof(s));
   flag++;
  }
 }
 fio.close();
 
 if(flag==0)
  cout<<"The Aadhar Number "<<n<<" not found....\n\n";
}



void admin()
{
 int ch;
 do
 {
  system("cls");
  cout<<"\n======================================================\n";
  cout<<"............... ADMIN MODE..............\n";
  cout<<"======================================================\n";
  cout<<"1. Create new profile\n";
  cout<<"2. Display profile\n";
  cout<<"3. Search profile\n";
  cout<<"4. Remove profile\n";
  cout<<"5. Modify profile\n";
  cout<<"6. Exit\n";
  cout<<"Enter your choice  : ";
  cin>>ch;
  system("cls");
  switch(ch)
  {
   case 1:
       {
        addData();
       }break;
   case 2:
       {
        displayData();
       } break;
   case 3:
       {
        searchData();
       } break;
   case 4:
   	   {
        deleteData();
	   } break;
   case 5:
       { 
        modifyData(); 
	   }break;
   case 6:
       {
         return;
       }break;
  default:
    cout<<"wrong choice";
  }
 }while(ch);
}
void profiledisp(int aa)
{
 	ifstream fin;
 	fin.open("Public.txt",ios::in|ios::binary);
 	while(fin.read((char*)&s,sizeof(s)))
 {
  if(aa==s.getaddhar())
  {
   cout<<"The Details of Aadhaar No. entered is "<<aa<<" shown herewith:\n";
   s.showdata();
  }
  
 }
  fin.close();
  system("pause");
 
}

  
void user(long long int aa)
{
	int ch;
	do{
  system("cls");
  cout<<"\n======================================================\n";
  cout<<"............... USER MODE..............\n";
  cout<<"======================================================\n";
  cout<<"1. See your profile\n";
  cout<<"2. Exit\n";
  cout<<"Enter your choice  : ";
  cin>>ch;
  system("cls");
  switch(ch)
  {
   case 1:
       {
        profiledisp(aa);
       }break;
   case 2:
       {
        return ;
       }break;
  default:
    cout<<"wrong choice";
  }
 }while(ch);




}

int main()
{
int ch;
 do
 {
  system("cls");
  cout<<"\n======================================================\n";
  cout<<"............... CENSUS MANAGEMENT SYSTEM..............\n";
  cout<<"======================================================\n";
  cout<<"1. ADMIN\n";
  cout<<"2. USER\n";
  cout<<"3. EXIT\n";
  cout<<"Enter your choice  : ";
  cin>>ch;
  system("cls");
  switch(ch)
  {
   case 1:
       {
        string u,p,x="Census2020",y="India2020";
        cout<<"\nENTER USERNAME=";
        cin>>u;
        cout<<"\nENTER PASSWORD=";
        cin>>p;
        if(u==x&&p==y)
         {
          admin();
         }
       }break;
   case 2:
       {
      long long int n;int flag=0;
 	ifstream fin;
 	fin.open("Public.txt",ios::in|ios::binary);
 	cout<<"Enter user Aadhar Number : ";
 	cin>>n;
    int f=0;
	 while(fin.read((char*)&s,sizeof(s)))
 	{
 		 if(n==s.getaddhar())
        {
        	user(n);
        	f++;
		}
			
	}
	if(f==0)
	{	
	   cout<<"aadhar card not found\n";	
	}
     	fin.close();
		system("pause");
	
       }break;
   case 3:
       {

       }break;
  default:
    cout<<"wrong choice";
  }
 }while(ch!=3);
 return 0;
}

