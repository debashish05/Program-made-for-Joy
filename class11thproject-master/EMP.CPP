//*********************************************************************************
//EMPLOYEE MANAGEMENT -Debashish Roy
#include<bits/stdc++.h>
using namespace std;
class details
{
    string name,date,datej,designation,address,pass,city,state;
    char grade;
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
    int retempno() {
        return empno;
    }
    string retname() {
        return name;
    }
    string retpass() {
        return pass;
    }
};
void details::edata() //entering the data
{
    cout<<"enter empnon ";
    cin>>empno;
    cout<<"\nenter dob ";
    cin>>date;
    cout<<"\nenter doj ";
    cin>>datej;
    cout<<"\nenter name ";
    cin>>name;
    cout<<"\nenter designation ";
    cin>>designation;
    cout<<"\nenter address ";
    cin>>address;
    cout<<"\nenter password ";
    cin>>pass;
    cout<<"\nenter grade ";
    cin>>grade;
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
    details r;
    char passw[15];
    int no;
    cout<<"\nEnter employe no.";
    cin>>no;
    cout<<"\nEnter Password: ";
    cin>>passw;
    while(fin)
    {
        fin.read((char*)&r,sizeof(r));
        if((r.empno==no) && (r.retpass()==passw)) {
            r.ddata();
        }
    }
    fin.close();
}
void empdetailsa();
void empdetailsa()
{
    ifstream fin("emp1.dat",ios::in);
    details r;
    int no;
    cout<<"\nEnter employe no.";
    cin>>no;
    while(fin)
    {
        fin.read((char*)&r,sizeof(r));
        if(r.empno==no)
            r.ddata();
    }
    fin.close();
}
void del();
void del()
{
    int r;
    char found='f',confirm='n';
    details e;
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
    fin.close();
    fout.close();
}
void admin()
{
    string upass;
    int k=3;
    int ch2;
    cout<<"\n*******************************************************************************";
pas:
    cout<<"\n\nEnter ur password : ";
    cin>>upass;
    if(upass.compare("CPP")==0)
    {
        cout<<"\nHELLO ADMIN G";
        cout<<"\n1.add details\n2.view details\n3.Delete\n4.Exit";
        cout<<"\nPress no.";
        cin>>ch2;
        switch(ch2)
        {
            case 1:addemp();break;
            case 2:empdetailsa();break;
            case 3:del();break;
            case 4:break;
            default: cout<<"wrong input";
        }
    }
    else
    {
        cout<<"\ntry again:"<<"\nyou have "<<(k-1)<<" attempts left";
        k--;
        if(k>0)  goto pas;
        if(k==0)exit(1);
    }
}
void st();
void st()
{
    string un,pass;
    cout<<"\n*******************************************************************************";
    cout<<"\nWelcome to Debashish Roy industry";
    cout<<"\n\n\t\t\t\tUser name : ";
    cin>>un;
    cout<<"\n\t\t\t\tPassword  : ";
    cin>>pass;
    if(un.compare("Debashish")==0 && pass.compare("Roy")==0)
        cout<<" Welcome in the Project Mr./Mrs. "<<un;
    else
    {
        cout<<"\n Wrong Password";
        exit(1);
    }
}
int main()
{
    st();
    int c;
    do {
        cout<<"\nWelcome to DR industry";
        cout<<"\n1.Employe information\n";
        cout<<"2.Admin";
        cout<<"\n3.For clear screen\n4.exit";
        cout<<"\nEnter your choice:";
        cin>>c;
        switch(c)
        {
        case 1:
            empdetails();
            break;// all details
        case 2:
            admin();
            break;//power
        case 3:
            printf("\033c");
            break;//works in linux
        case 4:
            cout<<"\nThank You";
            break;
        default:
            cout<<"\nWrong Input Try again";
        }
    } while(c>4);
    return 0;
}