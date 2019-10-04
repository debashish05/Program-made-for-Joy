//print calender of month for a given date

#include<iostream>
#include<stdio.h>

using namespace std; 

struct date{	//structure to store date
	int d,m,y;
};

int countleapyears(date *d)	//count no of leap year before
{
	int years=d->y;
	if(d->m<=2)years--;
	return years/4 - years/100 +years/400;
}

string getMonthName(date *d) //return month name
{ 
	int month=(d->m)-1;
	string months[] = {"January", "February", "March", 
					"April", "May", "June", 
					"July", "August", "September", 
					"October", "November", "December"
					}; 

	return (months[month]); 
} 

int numberOfDays (date *d) //return no of days in month
{ 
	int month=(d->m)-1;
	int year=d->y;
	// January March May July August October December
	if (month==0 || month==2 || month==4 || month==6 || month==7 ||month==9||month == 11) 
		return 31; 

	// February 
	if (month==1) 
	{ 
		// If the d.y is leap then February has 29 days 
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) 
			return 29; 
		else return 28; 
	} 

	// April June September November 
	return 30;  
}  

int getDifference(date *d2) 
{ 
	date d1={1,1,1920};	//Thrusday

    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1' 
    long int n1 = d1.y*365 + d1.d; 
    // Add days for months in given date 
    for (int i=1;i<d1.m;i++) {
    	struct date d={1,i,d1.y};
        n1 += numberOfDays(&d);
    }
    // Since every leap year is of 366 days, Add a day for every leap year 
    n1 += countleapyears(&d1); 
	
    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'   
    long int n2 = (d2->y)*365 + d2->d;
     
    for (int i=1;i<(d2->m); i++){ 
        struct date d={1,i,d2->y};
        n2 += numberOfDays(&d); 
    }
    
    n2 += countleapyears(d2); 
    // return difference between two counts 
    return (n2 - n1); 
} 


//Print the calendar of the given month
void printCalendar(struct date *d) 
{
	cout<<"	  "<<getMonthName(d)<<"\n";
	
	int starting_day=(getDifference(d)-4)%7;
	int days=numberOfDays(d);

	cout<< " Mon Tue Wed Thu Fri Sat Sun\n";

	int k;
	for(k=0;k<starting_day;++k)cout<<"    ";	

	int no_of_Days=numberOfDays(d);

	for(int i=1;i<=no_of_Days;++i)
	{
		printf("%4d",i); //cout<<"  "<<i; 
        if(++k>6) 
        { 
            k = 0; 
            cout<<"\n"; 
        } 
	}
}

int main() //driver function
{ 
	struct date d={1,10,2019}; 
	cin>>d.d>>d.m>>d.y;
	printCalendar(&d);
	return 0; 
} 
