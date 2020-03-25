//*********************************************************************************
//EMPLOYEE MANAGEMENT -Debashish Roy
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<process.h>
#include"CALC.h"
class details
{
	char name[15],date[10],datej[10],designation[15],address[30];
	char pass[10],grade,city[10],state[15];
	float salary;
	public:
	int empno;
	void edata();//enter all details
	void ddata();//display all data
	void sal()
	{
		if(grade=='A'||grade=='a')salary=100000;
		if(grade=='B'||grade=='b')salary=50000;
		if(grade=='C'||grade=='c')salary=30000;
		if(grade=='D'||grade=='d')salary=10000;
	}
	int retempno(){return(empno);}
	char * retname(){return(name);}
	char * retpass(){return(pass);}
};
void details::edata() //entering the data
{
	cout<<"enter empnon "; cin>>empno;
	cout<<"\nenter dob ";cin>>date;
	cout<<"\nenter doj ";cin>>datej;
	cout<<"\nenter name ";gets(name);
	cout<<"\nenter designation ";gets(designation);
	cout<<"\nenter address ";gets(address);
	cout<<"\nenter password ";gets(pass);
	cout<<"\nenter grade ";cin>>grade;
	sal();
}
void details::ddata()     //displaying the data
{
	cout<<"\nempno: "<<empno;
	cout<<"\tdob : "<<date;
	cout<<"\tdate of doj "<<datej;
	cout<<"\tname : "<<name;
	cout<<"\tdesignation :"<<designation;
	cout<<"\taddress : "<<address;
	cout<<"\tpassword :"<<pass;
	cout<<"\tgrade :"<<grade;
	cout<<"\tsalary \n"<<salary;
}
void addemp();
void addemp()                        //add new employ
{
	details e;
	ofstream fout("emp1.dat",ios::app);//when 2nd time compile use ios::app
	char ans='y';
	fout.seekp(ios::end);
	while(ans=='y'||ans=='Y')
	{
		e.edata();
		fout.write((char*)&e,sizeof(e));
		cout<<"Want to enter more data: \n(Y/N)....";
		cin>>ans;
	}
	fout.close();
}
void empdetails();
void empdetails()
{
	ifstream fin("emp1.dat",ios::in);
	details r;	char passw[15];	int no;
	cout<<"\nEnter employe no.";	cin>>no;
	cout<<"\nEnter Password: ";	gets(passw);
	while(fin)
	{
		fin.read((char*)&r,sizeof(r));
		if((r.empno==no) && strcmpi(r.retpass(),passw)==0)
		{
			r.ddata();
		}
	}
	fin.close();
}
void empdetailsa();
void empdetailsa()
{
	ifstream fin("emp1.dat",ios::in);
	details r;int no;
	cout<<"\nEnter employe no.";cin>>no;
	while(fin)
	{
		fin.read((char*)&r,sizeof(r));
		if(r.empno==no)
			r.ddata();
	}
	fin.close();
}
void list();
void list()
{
	fstream fin("emp1.dat",ios::in);
	details r;
	cout<<"List of Emplopyee   :\n\tName";
	while(fin)
	{
		fin.read((char*)&r,sizeof(r));
		cout<<"\n\t"<<r.retname();
	}
	fin.close();
}
void del();
void del()
{
	int r; char found='f',confirm='n'; details e;
	ifstream fin("emp1.dat",ios::in);
	ofstream fout("temp.dat",ios::out);
	cout<<"\nEnter rollno of student whose record is to be deleted\n";
	cin>>r;
	while(fin)
	{
		fin.read((char*)&e,sizeof(e));
		if(e.retempno()==r)
		{
			e.ddata();
			found='t';
			cout<<"Are you sure,you want to delete this record?(y/n)..";
			cin>>confirm;
			if(confirm=='n')
			fout.write((char*)&e,sizeof(e));
		}
		else
			fout.write((char*)&e,sizeof(e));
	}
	if(found=='f')
	cout<<"\nRecord not found!!";
	fin.close();
	fout.close();
	remove("emp1.dat");  //old file remove & temp file is renamed
	rename("temp.dat","emp1.dat");
	cout<<"\n Now the records are deleted\n";
	fin.close();fout.close();
}
void admin();             //admin
void admin()
{
	clrscr();
	char upass[40];int k=3;         int ch2;
	cout<<"\n*******************************************************************************";
    pas:cout<<"\n\nEnter ur password : ";   gets(upass);
	if(strcmpi(upass,"CPP")==0)
	{
		cout<<"\nHELLO ADMIN G";
		cout<<"\n1.list of all employ";
		cout<<"\n2.add details\n3.view details\n4.Delete\n5.Exit";
		cout<<"\nPress no.";
		cin>>ch2;
		switch(ch2)
		{
			case 1:list(); break;
			case 2:addemp();break;
			case 3:empdetailsa(); break;
			case 4:del();break;
			case 5:break;
			default:{cout<<"wrong input";}
		}
	}
	else
	{
		cout<<"\ntry again:"<<"\nyou have "<<(k-1)<<" attempts left";
		k--;
		if(k>0)  goto pas; if(k==0)exit(1);
	}
}
void st();
void st()
{
	char un[20],pass[20];
	clrscr();
	cout<<"\n*******************************************************************************";
	cout<<"\nWelcome to Debashish Roy industry";
	cout<<"\n\n\t\t\t\tUser name : "; gets(un);
	cout<<"\n\t\t\t\tPassword  : ";     gets(pass);
	if( (strcmpi(un,"Debashish")==0) && (strcmpi(pass,"Roy")==0))
		cout<<" Welcome in the Project Mr./Mrs. "<<un;
	else
	      {	cout<<"\n Wrong Password";exit(1);  }

}
void main()
{
	st();
	int c;
	do{
		cout<<"\nWelcome to DR industry";
		cout<<"\n1.General list of all employe name";
		cout<<"\n2.Employe information\n";
		cout<<"3.Admin\n4.Calculator";
		cout<<"\n5.For clear screen\n6.exist";
		cout<<"\nEnter your choice:";cin>>c;
		switch(c)
		{
			case 1:list();break;//employe list
			case 2:empdetails();break;// all details
			case 3:admin();break;//power
			case 4:calculator();break;//done
			case 5:clrscr();break;
			case 6:cout<<"\nThank You"; break;
			default:cout<<"\nWrong Input Try again";
		}
	}while(c!=6);
	getch();
}




/*void sum();                     //addition
void sum()
{
	float z,x,y;
	cout<<"Enter two no.";cin>>x;cout<<"  ";cin>>y;
	z=x+y;
	cout<<"\n"<<x<<"+"<<y<<"="<<z;
}
void sub();
void sub()                  //subtraction
{
	float z,x,y;
	cout<<"Enter two no.";cin>>x;cout<<"  ";cin>>y;
	z=x-y;
	cout<<"\n"<<x<<"-"<<y<<"="<<z;
}
void multi();
void multi()                //multiplication
{
	float z,x,y;
	cout<<"\nEnter two no.";cin>>x;cout<<"  ";cin>>y;
	z=x*y;
	cout<<"\n"<<x<<"*"<<y<<"="<<z;
}
void div();                     //division
void div()
{
	float z,x,y;
	cout<<"\nEnter two no.";cin>>x;cout<<"  ";cin>>y;
	z=x/y;
	cout<<"\n"<<x<<"Divided by"<<y<<"="<<z;
}
void log();                       //log
void log()
{
	float z,x;
	cout<<"\nenter the no. whose loge you have to find:";cin>>x;
	z=log(x);
	cout<<"log"<<x<<"="<<z;
}
void log10();                    //log10
void log10()
{
	float z,x;
	cout<<"\nenter the no. whose log10 you have to find:";cin>>x;
	z=log10(x);
	cout<<"\nlog10"<<x<<"="<<z;
}
float factorial(int);                 //factorial
float factorial(int fact)             //recursion
{
	if(fact==1)
	return(1);
	else
	fact=fact*factorial(fact-1);
	return(fact);
}
void pow();              //power
void pow()
{
	int x,y,z;
	cout<<"\nEnter base no.";cin>>x;
	cout<<"\nEnter power ";cin>>y;
	z=pow(x,y);
	cout<<"\nx raised to the power y="<<z;
}
void exp();              //exponential;
void exp()
{
	float z,y;
	cout<<"\nEnter power ";cin>>y;
	z=exp(y);
	cout<<"\nexp ="<<z;
}
void sqrt();            //squareroot
void sqrt()
{
	float z,y;
	cout<<"\nenter the no. whose square root you have to find:";cin>>y;
	z= sqrt(y);
	cout<<"\nsqrt of"<<y<<"is"<<z;
}
//heart function of calculator
void calculator();
void calculator()
{
	int ch;
	cout<<"\n What you want to perform: ";
	cout<<"\n1.Addition\n2.Subtraction\n3.Multiplication\n";
	cout<<"4.Division\n5.Factorial\n6.log\n7.log10\n8.power";
	cout<<"\9.Exponential\n10.square root\n";
	cout<<"\n Enter the no. which you want to perform:"; cin>>ch;
	switch(ch)
	{
		case 1:sum(); break;
		case 2:sub(); break;
		case 3:multi(); break;
		case 4:div();break;
		case 5:{
				cout<<"\nFactorial"; int f;
				cout<<"\nEnter the no. whose factorial you have to find";
				cin>>f;
				float k=factorial(f);
				cout<<"\nFactorial="<<k;
		       }break;
		case 6:log(); break;
		case 7:log10(); break;
		case 8:pow(); break;
		case 9:exp(); break;
		case 10:sqrt(); break;
		default :cout<<"\nWrong input,enter correct number:";
	}
}              */
/*void details::modify()
{
	cout<<"\n Enter new details:"<<endl;
	char nm[15]=" ",db[10]=" ",dj[10]=" ",des[10]=" ",add[15]=" ",ps[10]=" ";
	char grd='d';int epn=0;
	cout<<"New empno:\n";cin>>epn;
	cout<<"New Name\n";cin>>nm;
	cout<<"New dob:\n";cin>>db;
	cout<<"New doj:\n";cin>>dj;
	cout<<"New designation:\n";cin>>des;
	cout<<"New address:\n";cin>>add;
	cout<<"New password:\n";cin>>ps;
	cout<<"New grade\n";cin>>grd;  sal();

}
void modifya();
void modifya()           //modify details of employ
{
	fstream fout("emp1.dat",ios::app);
	int no;  details d;
	cout<<"\nEnter the empno. whose data is to be modified: ";
	cin>>no;
	fout.seekg(0);
	cout<<"\n modification: \n";
	while(fout)
	{

		int loc=fout.tellg();
		fout.read((char*)&d,sizeof(d));
		if(d.retempno()==no)
		{
			d.modify();
			fout.seekg(loc);
			fout.write((char*)&d,sizeof(details)); break;

		}
	}
	cout<<"\n After modification records are: ";
	fout.seekg(0);
	while(fout.read((char*)&d,sizeof(details)))
	{
		d.ddata();
	}
	fout.close();
} */
