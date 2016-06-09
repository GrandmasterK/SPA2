//
//  main.cpp
//  SPA
//
//  Created by Po-yuan Paul Kuo on 5/19/16.
//  Copyright (c) 2016 Po-yuan Paul Kuo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <sys/time.h>
#include <string>
using namespace std;

class service //create service object class
{   public:
    int svcnum=999999; //value 9999 means no service
    string name;
    int minutes;
    double rate;
    int workerid;
    
    void setname (string s){name=s;};
    void setminutes (int i){minutes=i;};
    void setrate (double r){rate=r;};
    void setsvcnum(int n){svcnum=n;};
    void setworkerid(int s){workerid=s;};
    string getname (){return name;};
    int getminutes (){return minutes;};
    double getrate (){return rate;};
    int getsvcnum (){return svcnum;};
    int getworkerid(){return workerid;};
};
class customer //create customer object class
{   public:
    int id;
    string fname;
    string lname;
    int checkout_month;
    int checkout_day;
    int checkout_year;
    
    void setid(int n){id=n;};
    void setfname(string f){fname=f;};
    void setlname(string l){lname=l;};
    void setcheckout_month(int m){checkout_month=m;};
    void setcheckout_day(int d){checkout_day=d;};
    void setcheckout_year(int y){checkout_year=y;};
};

class appointment
{ public:
    int custid=0;
    int resday;
    int resmon;
    int resyear;
    int restime;
    int beginday;
    int beginmon;
    int beginyear;
    int begintime;
    long int apptid;
    int servid;
    
    void setcustid(int c){custid=c;};
    void setresday(int rd){resday=rd;};
    void setresmon(int rm){resmon=rm;};
    void setresyear(int ry){resyear=ry;}
    void setrestime(int rt){restime=rt;};
    void setbeginday(int bd){beginday=bd;};
    void setbeginmon(int bm){beginmon=bm;};
    void setbeginyear(int by){beginyear=by;};
    void setbegintime(int bt){begintime=bt;};
    void setapptid(long int a){apptid=a;};
    void setservid(int s){servid=s;};
    
    int getcustid(){return custid;};
    int getresday(){return resday;};
    int getresmon(){return resmon;};
    int getresyear(){return resyear;};
    int getrestime(){return restime;};
    int getbeginday(){return beginday;};
    int getbeginmon(){return beginmon;};
    int getbeginyear(){return beginyear;}
    int getbegintime(){return begintime;};
    long int getapptid(){return apptid;};
    int getservid(){return servid;};
};
void showmainmenu();
void pause();
void listservices(service services[]);
int c2m(int);
int c2h(int);
long int timestamp();
int resmon();
int resday();
int resyear();
int restime();
int getlines();
int getlines_s();
int main() {

    
//detect number of lines from service.txt first
    int num_of_lines=0;
    num_of_lines = getlines_s();
    cout << "No. of lines in Services:"<<num_of_lines<<endl;
    int num_of_records=0;
    num_of_records= num_of_lines/5;
    cout << "Number of Services:"<< num_of_records<<endl;
    //create appt array --assuming book holds 10 records for simplicity--expand later
    int svc_array_size=0;
    svc_array_size= num_of_records + 1; //let arrray size be 1 bigger than the number of records
    service *services; //create pointer for services array
    services = new service[svc_array_size]; //create services array
    
    ifstream inputfile_s; //open services.txt for reading
    inputfile_s.open("services.txt");
    if (inputfile_s.is_open()){cout << "Service File Open Successfully.\n";} //check if services file opens
    
    for (int i=0;i< (svc_array_size-1);i++)    // loop to file array from except last spot
    {
        
        int svcnumin=0; string namein;int minutein=0; double ratein=0.00; int workeridin=0; //create temp reader buckets
        inputfile_s >> svcnumin; inputfile_s >> namein; inputfile_s  >> minutein; inputfile_s >> ratein; inputfile_s >> workeridin;
        //cout << namein<<" " << minutein <<" "<<ratein<<endl; //test dump reader buffer contents
        services[i].setsvcnum(svcnumin);
        services[i].setname(namein);
        services[i].setminutes(minutein);
        services[i].setrate(ratein);
        services[i].setsvcnum(i);
        services[i].setworkerid(workeridin);
    };
    //cout <<"<end cycle test>"<< endl;           //end cycle test
    inputfile_s.close(); //close service.txt file
    
//int svc_arraysize = 20; //begin old part --- static services array
//service services[20];
    
//    ifstream inputfile; //open services.txt file to read in services parameters
//    inputfile.open("services.txt");
//    if (inputfile.is_open()) {cout << "Service File Opened Successfully.\n";}; //check if services file opens
//    for (int i=0;i<20;i++)    // loop to file array from file static array size 20
//    {
//        //cout << i <<endl;  // cycle test counter
//        string namein;int minutein=0; double ratein=0.00; int workeridin=0; //create temp reader buckets
//        inputfile >> namein; inputfile  >> minutein; inputfile >> ratein; inputfile >> workeridin;
//        //cout << namein<<" " << minutein <<" "<<ratein<<endl; //test dump reader buffer contents
//        services[i].setname(namein);
//        services[i].setminutes(minutein);
//        services[i].setrate(ratein);
//        services[i].setsvcnum(i);
//        services[i].setworkerid(workeridin);
//    };
//  cout <<"<end cycle test>"<< endl;           //end cycle test
//    inputfile.close(); //close service.txt file
//        for (int i=0;i<20;i++)     //test pull data from objects <maybe change to function>  worx
//        {
//            cout << services[i].getsvcnum()<<",";
//            cout << services[i].getname()<<","<< services[i].getminutes()<<","<<services[i].getrate()<<endl;
//            cout << endl;
//        }

    customer customers[5]; //create customers in memory array  --assuming 5 customers for simplicity at first

    ifstream inputfile2;
    inputfile2.open("customers.txt"); // pull data from customers.txt  --add file open verify test later
    for (int i=0; i<5; i++)
    { int custidin; string fnamein; string lnamein; int monthin; int dayin; int yearin;
        inputfile2 >> custidin; inputfile2 >> fnamein; inputfile2 >> lnamein;
        inputfile2 >> monthin; inputfile2 >> dayin; inputfile2 >> yearin;
        customers[i].setid(custidin);
        customers[i].setfname(fnamein);
        customers[i].setlname(lnamein);
        customers[i].setcheckout_month(monthin);
        customers[i].setcheckout_day(dayin);
        customers[i].setcheckout_year(yearin);
    }
    inputfile2.close();
     //test dump contents of customers array
    
    for (int i=0; i<5; i++)
    {cout << customers[i].id <<","<<customers[i].lname<<","<<customers[i].fname<<endl;
    }
    //count lines in appt.txt to determine size of appt array
//    int no_of_lines =0;
//    string line;
//    ifstream apfile("appt.txt");
//    while (getline(apfile,line))
//    {
//        ++no_of_lines;
//    }
//    cout << "Number of lines="<<no_of_lines<<endl;
    
//    int num_of_lines=0;
//    num_of_lines = getlines();
//    cout << "No. of lines in appt:"<<num_of_lines<<endl;
//    int num_of_records=0;
//    num_of_records= num_of_lines/11;
//    cout << "Number of Records:"<< num_of_records<<endl;
//    //create appt array --assuming book holds 10 records for simplicity--expand later
//    int appt_array_size=0;
//    appt_array_size= num_of_records + 1; //let arrray size be 1 bigger than the number of records
//    //appointment appt[10]; //used for static appt array
//    //create pointer for dynamically created appt array
//    appointment *appt;
//    appt= new appointment[appt_array_size];
//    ifstream infile;
//    infile.open("appt.txt");
//    for (int i=0; i<(appt_array_size-1); i++) //fill array except for last spot
//    {
//        infile >> appt[i].custid;
//        infile >> appt[i].servid;
//        
//        infile >> appt[i].beginmon;
//        infile >> appt[i].beginday;
//        infile >> appt[i].beginyear;
//        infile >> appt[i].begintime;
//        
//        
//        infile >> appt[i].resmon;
//        infile >> appt[i].resday;
//        infile >> appt[i].resyear;
//        infile >> appt[i].restime;
//        infile >> appt[i].apptid;
//    }
//    infile.close();
    
    int choice=0;
    bool to_exit=false;
   
    do{
        //load appt book first by counting lines, creating array dynamically according to recordcount+1
        int num_of_lines=0;
        num_of_lines = getlines();
        cout << "No. of lines in appt:"<<num_of_lines<<endl;
        int num_of_records=0;
        num_of_records= num_of_lines/11;
        cout << "Number of Records:"<< num_of_records<<endl;
        //create appt array
        int appt_array_size=0;
        appt_array_size= num_of_records + 1; //let arrray size be 1 bigger than the number of records
        //appointment appt[10]; //used for static appt array
        //create pointer for dynamically created appt array
        appointment *appt;
        appt= new appointment[appt_array_size];
        ifstream infile;
        infile.open("appt.txt");
        for (int i=0; i<(appt_array_size-1); i++) //fill array except for last spot
        {
            infile >> appt[i].custid;
            infile >> appt[i].servid;
            
            infile >> appt[i].beginmon;
            infile >> appt[i].beginday;
            infile >> appt[i].beginyear;
            infile >> appt[i].begintime;
            
            
            infile >> appt[i].resmon;
            infile >> appt[i].resday;
            infile >> appt[i].resyear;
            infile >> appt[i].restime;
            infile >> appt[i].apptid;
        }
        infile.close(); //close input file
    
        appointment takenlist_worker[24];
        appointment takenlist_self[24];
        
        showmainmenu();
    cin >> choice;                   //take input choice
    switch (choice)
    {
        case 1: // Book reservation
        {
            int custidin; //customer id
            int servnumin; //service number
            int beginmonin;
            int begindayin;
            int beginyearin;
            int begintimein;
            long int apptidin;
            int blocks; //holds value for number of 30min blocks
            cout << "This is the Reservation Menu" << endl;
            bool entryerror=false;
            do{  entryerror=true;  //validation loop
            cout << "Enter CustomerID#:"<< endl;
            
            cin >> custidin; //takes in customer id need to add validation
                //find customer
                for(int i =0;i<5;i++) //limited to 5 update later
                {if(custidin == customers[i].id) { entryerror=false; }
                }
                if (entryerror==true){cout<<"<Invalid Customer ID>"<<endl;}
            } while (entryerror==true);
            
            for (int i=0;i<svc_array_size;i++)     //   List out services
                    {   if(services[i].svcnum != 999999)
                        {
                            cout << services[i].getsvcnum()<<",";
                            cout << services[i].getname()<<","<<services[i].getminutes()<<",";
                            cout <<"Worker#"<<services[i].getworkerid() << endl;
                        }
                    }

           
            
            do{ entryerror=false; //validation loop
            cout <<"Enter Service Number:[0-19]"<<endl;
            cin >> servnumin; //takes in service number according to above list ...need to add validation
            blocks = (services[servnumin].getminutes())/30; //determines number of loops to search for conflicts
                if(servnumin > 19){cout<<"<Invalid Service Number>"<<endl;entryerror=true;}
            } while (entryerror==true);
            entryerror=false;
            do { entryerror=false; //validation loop
            cout <<"Enter Appointment Month(1-12):"<<endl;
            cin >> beginmonin;
            if ( (beginmonin ==0)  || (beginmonin >12) ) {cout <<"<Invalid Month>"<<endl; entryerror=true;}
            } while (entryerror==true);
            do{ entryerror=false; // validation loop
            cout <<"Enter Appointment Date (1-31):"<<endl;
            cin >> begindayin;
                if( (begindayin==0) || (begindayin>31) ) //add specific month- day limit matching later
                {cout<<"<Invalid Date>"<<endl; entryerror=true; }
            } while(entryerror==true);
            do { entryerror=false; //validation loop
            cout <<"Enter Appointment Year (4 digits):"<<endl;
            cin >> beginyearin;
                if ( beginyearin < resyear() ) {cout <<"<Invalid Year>"<<endl; entryerror=true;}
            } while (entryerror==true);
            do{entryerror=true;//validation loop
            cout <<"Enter Begin Time:[800-1930]:"<<endl;
            cin >> begintimein;
                if ( (c2m(begintimein))%60 == 0 ){entryerror=false;}
                if ( (c2m(begintimein))%60 == 30){entryerror=false;}
                if ( (c2m(begintimein)) > c2m(2000)-blocks*30 ) {entryerror=true; cout <<"No Start Times after ";
                    cout <<c2h((c2m(2000)-blocks*30))<<" for this Service"<<endl;}
                if ( (c2m(begintimein)) < c2m(800) ) {entryerror=true; cout <<"No Start Times before 800"<<endl;}
                if(entryerror==true){cout<<"<Invalid Time>"<<endl;}
            } while (entryerror==true);
            
            
            
            // insert calculation of end time here if necessary --not yet necessary
            
            bool flag_timeconflict=false; // flag for time conflicts
            
             //create lookup list --static size due to 24 half-hour block within 800-2000
            
            for(int i=0;i<appt_array_size;i++) //populate list by searching appt array
            {
                if ( (appt[i].custid != 0) && (appt[i].custid == custidin) && (appt[i].beginmon == beginmonin) &&
                    (appt[i].beginday==begindayin) && (appt[i].beginyear == beginyearin) )
                {
                    int service4search=0;
                    service4search=appt[i].getservid();
                    int blocks = services[service4search].getminutes()/30;
                    int starttime = appt[i].getbegintime();
                    for (int ii=0;ii<blocks;ii++)
                    {
                        int firstemptyspot=NULL; // to hold empty spot
                        for(int f=0;f<24;f++)  //find first empty spot in appt array and mark it
                        {
                            if (takenlist_self[f].getcustid()==0)
                            {firstemptyspot=f;break;} // find empty spot and breaks after finding first empty spot
                        }
                        
                        takenlist_self[firstemptyspot].setbegintime( starttime+(30*ii) ); //market timein
                        //cout << "Mark Made @"<< ( starttime + (30*ii) )<<","<< c2h(starttime+ 30*ii) <<endl; //for debug
                         takenlist_self[firstemptyspot].setcustid(1); //mark taken

                    }
                }
            }                                  // end populate list
            //show contents of self compare list
//            cout <<"Self Values:"<<endl;
//            for (int i=0; i<24;i++)
//            {
//                if (takenlist_self[i].custid == 1){cout << takenlist_self[i].begintime<<" "<<endl;}
//            }
            cout << endl;
            
            for (int b=0;b<blocks;b++)        //check according to number of 30min blocks
            {
                for (int i=0;i<24;i++)       //check list against requested time
                    {
                        if ( takenlist_self[i].getcustid() != 0 )
                        {
                            if (takenlist_self[i].getbegintime() == c2m(begintimein) + 30*b)
                            {
                                cout << "<<Time Conflict with Self>>"<<"@"<< ( c2h(c2m(begintimein)+30*b) ) << endl;
                                flag_timeconflict= true;
                            }
                        }
                    }
            }
           

            //find workerid of requested service
            int workeridin = services[servnumin].getworkerid();
      if(workeridin != 1)
      {
            for (int i=0; i<20; i++) // search thru services match workerid
            {
                if(services[i].workerid == workeridin) //execute when matches workerid
                {
                    int svc_to_check = services[i].svcnum; //pull service number when matches
                    for(int ii=0; ii<appt_array_size; ii++) //search thru appt array to find service matches
                    {
                        if( (appt[ii].servid == svc_to_check) &&  // execute when svc number matches
                            (appt[ii].beginmon == beginmonin) &&  // month match
                            (appt[ii].beginday == begindayin) &&  // year match
                            (appt[ii].beginyear == beginyearin)
                           )
                        {   int blocks = (services[svc_to_check].getminutes())/30;
                            
                            for(int b=0;b<blocks;b++)//create entrys by number of block of service found
                            {
                                int firstemptyspot=0; //find first empty spot on takenlist_worker
                                for(int f=0;f<24;f++)
                                    {
                                        if(takenlist_worker[f].custid == 0)
                                        { firstemptyspot=f; break;}
                                    }                     //end find empty spot
                            
                                takenlist_worker[firstemptyspot].setbegintime(appt[ii].begintime + b*30); //populate takenlist
                                takenlist_worker[firstemptyspot].setcustid(1);
                            }
                        }
                    }
                }
                
            }
            for (int b=0;b<blocks;b++)        //check according to number of 30min blocks
            {
                for (int i=0;i<24;i++)       //check list against requested time
                {
                    if ( takenlist_worker[i].getcustid() != 0 )
                    {
                        if (takenlist_worker[i].getbegintime() == c2m(begintimein) + 30*b)
                        {
                            cout << "<<Worker Time Conflict>>"<<"@"<< c2h(takenlist_worker[i].begintime)<< endl;
                            flag_timeconflict= true;
                        }
                    }
                }
            }
      }
            //spit out self array info --- worky
            for(int i=0;i<24;i++)
//            {
//                if(takenlist_self[i].custid == 1){cout << takenlist_self[i].begintime;
//                    cout <<","<<c2h(takenlist_self[i].begintime) <<endl;}
//            }
            
            
            
            //spit out worker array info --  worky
//            for(int i=0;i<24;i++)
//            {
//            if(takenlist_worker[i].custid ==1) {cout<< takenlist_worker[i].begintime;
//            cout <<"," << c2h(takenlist_worker[i].begintime) <<endl;}
//            }
            
            
            for(int i=0; i<24;i++) //reinitialize taken lists
            {
                takenlist_self[i].custid=0;
                takenlist_self[i].begintime=0;
            }

            
            if(flag_timeconflict==true)
            {
                cout << "<There is a time conflict -- process aborted>" << endl;
                cout << endl;
            }
            else
            {
                int firstemptyspot=NULL;
                for(int i=0;i<10;i++)  //find first empty spot in appt array
                {
                    if (appt[i].getcustid()==0)
                    {firstemptyspot=i;break;} //breaks after finding first empty spot
                }
                                 //store collected values into appt spot found above
                appt[firstemptyspot].setcustid(custidin);
                appt[firstemptyspot].setservid(servnumin);
                appt[firstemptyspot].setbeginyear(beginyearin);
                appt[firstemptyspot].setbeginmon(beginmonin);
                appt[firstemptyspot].setbeginday(begindayin);
                appt[firstemptyspot].setbegintime( c2m(begintimein) );
                
               
                
                apptidin= timestamp(); // pulls timestamp to be stored in apptid from current function
                appt[firstemptyspot].setapptid(apptidin);
                appt[firstemptyspot].setresmon( resmon() );
                appt[firstemptyspot].setresday( resday() );
                appt[firstemptyspot].setresyear( resyear() );
                int restimein=0; restimein= restime();
                appt[firstemptyspot].setrestime( c2m(restimein) );
               
                cout << "Appointment Booked Successfully"<<endl;
                cout << "For  Customer#:"<<appt[firstemptyspot].getcustid()<<endl;
                
                cout << "On:"<<appt[firstemptyspot].getbeginmon()<<"/";
                cout << appt[firstemptyspot].getbeginday()<<"/";
                cout << appt[firstemptyspot].getbeginyear()<< endl;
                
                cout << "At:"<< c2h( appt[firstemptyspot].getbegintime() )<<endl;
                cout << "For:"<<services[appt[firstemptyspot].getservid()].getname();
                cout << ","<<services[appt[firstemptyspot].getservid()].getminutes()<<" minutes"<<endl;
                cout << "Reservation Id:"<<appt[firstemptyspot].getapptid() << endl;
                cout << endl;
                
                ofstream outfile; //output to file
                outfile.open("appt.txt");
                for(int i=0;i<appt_array_size;i++)
                {
                    if (appt[i].getcustid() !=0 )
                    {   //cout << "Record(s) found"<<endl;  //for testing if record ready to write to file
                        
                        outfile << appt[i].getcustid()<<endl;
                        outfile << appt[i].getservid()<<endl;
                      
                        outfile << appt[i].getbeginmon()<<endl;
                        outfile << appt[i].getbeginday()<<endl;
                        outfile << appt[i].getbeginyear()<<endl;
                        outfile << appt[i].getbegintime()<<endl;
                        
                
                        outfile << appt[i].getresmon() << endl;
                        outfile << appt[i].getresday() << endl;
                        outfile << appt[i].getresyear() << endl;
                        outfile << appt[i].getrestime() << endl;
                        outfile << appt[i].getapptid() << endl;
                    }
                }
                outfile.close();
                delete [] appt;  //delete appt array from memory
                appt=NULL;
            }
            break;
                    }
        case 2:
        {
            int custidin=0;
            cout<<"Cancel Reservation Menu"<<endl;
            
            int current_timein=0;     int current_dayin=0;    int current_monthin=0;    int current_yearin=0;//grab current time and date
            current_timein= c2m( restime() ); // pulls current time
            current_dayin=resday(); current_monthin=resmon(); current_yearin=resyear(); //pulls current month day year
            int beginyearin=0; // for storing when cancellation appt id matches
            int beginmonin=0;
            int begindayin=0;
            int begintimein=0;
            int resyearin=0;
            int resmonin=0;
            int resdayin=0;
            int restimein=0;
            
            cout<<"Enter CustomerID#:"<<endl;
            cin >> custidin;
            int findcount=0;
            for(int i=0;i<appt_array_size;i++)
            {
                if(appt[i].custid==custidin)
                {   cout << "Appointments for Customer#:"<<appt[i].custid<<endl;
                    int svc_to_lookup = appt[i].getservid();
                    int timeallocation = services[svc_to_lookup].getminutes();
                    cout << "ReservationID: " << appt[i].apptid << endl;
                    cout << "Date: " << appt[i].getbeginmon()<< "/" << appt[i].getbeginday() << "/" << appt[i].getbeginyear();
                    cout << " ";
                    cout << "Starts at: " << c2h( appt[i].getbegintime() )<< " ";
                    cout << "For: " << timeallocation << " minutes"<< endl;
                    cout << endl;
                    findcount++;
                }
            }
            cout <<"<" <<findcount <<" Reservations Found"<<">" << endl;
            findcount=0;
            bool entryerror = false;
            int entry= NULL;
            do {                     //validation loop
                entryerror = true;
                cout <<"(1) To Delete an Appointment"<< endl;
                cout <<"(0) To Go Back to Main Menu"<< endl;
                cin >> entry;
                if ( (entry==1) || (entry==0) )
                { entryerror=false;}
                if(entryerror==true){cout <<"<Invalid Entry>"<<endl;}
            } while(entryerror==true);
            if(entry==1)
            {
                cout <<"Enter Reservation Number to Cancel:"<<endl;
                cout <<"or Enter 0 to go back to Main" <<endl;
                int long res2cancel_in = 0;
                int long res2cancel_confirmed = 0;
                cin >> res2cancel_in;
                bool cancelationfound = false; //cancelation found detector
                bool flag_90mins_b4 = false;
                bool flag_within10mins_of_res = false;
                bool cancel_eligible=false;  // cancel eligibility detector
                
                for (int i=0; i<appt_array_size; i++) //look for appt by appt id
                {
                    if ( (appt[i].custid !=0) && (appt[i].getapptid() == res2cancel_in)  )
                    {
                        cout << "Reservation found"<< endl;
                        cancelationfound = true;
                        res2cancel_confirmed = res2cancel_in;
                        //pull values since appt id matched
                        beginyearin= appt[i].getbeginyear();   // pull reservation time values for comparison
                        beginmonin= appt[i].getbeginmon();
                        begindayin= appt[i].getbeginday();
                        begintimein= appt[i].getbegintime();
                        resyearin= appt[i].getresyear();
                        resmonin= appt[i].getresmon();
                        resdayin= appt[i].getresday();
                        restimein= appt[i].getrestime();
                       break;
                    }
                   // else{cout <<"Reservation not found" << endl;}
                }

                             //  if at least 90 mins b4
                if(beginyearin == current_yearin)  //  if begin year is same as current, check month
                {
                    if (beginmonin == current_monthin) // if begin year/month is same a current, check day
                    {
                        if(begindayin == current_dayin)   // if begin year/month/day is same as current - check for 90mins b4
                        {
                            if( (begintimein - current_timein) > 90 )
                            {
                                flag_90mins_b4 = true;
                            }
                            else{ flag_90mins_b4 = false;}
                        }
                        if (begindayin > current_dayin) // if begin year/month/day is higher than current -allow
                        {
                            flag_90mins_b4 = true;
                        }
                        if (begindayin < current_dayin) // if begin year/month/day is lower than current - refuse
                        {
                            flag_90mins_b4= false;
                        }
                    }
                    if (beginmonin > current_monthin){ flag_90mins_b4 = true;}   // if begin year/month > than cuurent - allow
                    if (beginmonin < current_monthin){ flag_90mins_b4 = false;}  // if begin year/month < than current -refuse
                    
                }
                if(beginyearin > current_yearin) {flag_90mins_b4=true;} //if begin year is higher than current - allow
                if(beginyearin < current_yearin) {flag_90mins_b4=false;} // if begin year is lower than current -refuse
               
                if ( (resyearin == current_yearin) &&   //check for within 10 mins res time - has to match current date
                     (resmonin == current_monthin) &&
                     (resdayin == current_dayin) )
                {
                    if (restimein-current_timein < 10)
                    {
                        flag_within10mins_of_res = true;
                    }
                }
                if (flag_90mins_b4 == true)               {cout << "Eligible for Cancelation <b490>" << endl; cancel_eligible=true;}
                else if (flag_within10mins_of_res == true) {cout << "Eligible for Cancelation <w10>" << endl; cancel_eligible=true;}
           
                
                if ( (flag_90mins_b4 = true) or (flag_within10mins_of_res =true)  )
                {
                    for(int i=0; i<appt_array_size; i++)
                    {
                        if ( (appt[i].getcustid() != 0) && ( appt[i].getapptid() == res2cancel_confirmed) )
                        {
                            appt[i].setcustid(0);
                            cout << "<Reservation Canceled>" << endl;
                        }
                    }
                    
                }
                if (cancelationfound == false)  {   cout << "<Reservation not found> Aborting"<< endl;}
                if ( (cancelationfound==true) && (cancel_eligible==false) )
                    { cout<<"<Reservation found, but not eligible for Cancellation>"<<endl; }
               
            
                cancelationfound = false;  //resetting cancelation detector
                cancel_eligible  = false; //reseting eligiblity detector
                flag_90mins_b4 = false; flag_within10mins_of_res = false;
            }
            ofstream outfile; //output to file
            outfile.open("appt.txt");
            for(int i=0;i<appt_array_size;i++)
            {
                if (appt[i].getcustid() !=0 )
                {   //cout << "Record(s) found"<<endl;  //for testing if record ready to write to file
                    
                    outfile << appt[i].getcustid()<<endl;
                    outfile << appt[i].getservid()<<endl;
                    
                    outfile << appt[i].getbeginmon()<<endl;
                    outfile << appt[i].getbeginday()<<endl;
                    outfile << appt[i].getbeginyear()<<endl;
                    outfile << appt[i].getbegintime()<<endl;
                    
                    
                    outfile << appt[i].getresmon() << endl;
                    outfile << appt[i].getresday() << endl;
                    outfile << appt[i].getresyear() << endl;
                    outfile << appt[i].getrestime() << endl;
                    outfile << appt[i].getapptid() << endl;
                }
            }
            outfile.close();
            delete [] appt;  //delete appt array from memory
            appt=NULL;
            
        }
            break;
        case 3:
        {
            cout << "Customer Billing Menu" << endl;
            int custidin=0;
            cout << "Enter CustomerID#;" << endl;
            cin >> custidin; // add validation
            cout << endl;
            cout << "<Bill begins here>" <<endl;
            double bill_total=0;
            for (int i=0; i<appt_array_size; i++)
            {
                if ( (appt[i].custid != 0)  && (appt[i].custid == custidin) )
                {
                    //cout << "Entry found" << endl; //for debug
                    int svc2lookup =0;
                    svc2lookup = appt[i].getservid();
                    //cout << "Need to lookup Service#" << svc2lookup << endl; //for debug
                    double ratein=0;
                    int minutesin=0;
                    double subtotal=0;
                    string servicenamein = "Nothing";
                    //find matching data for given service#
                    for (int s=0; s< svc_array_size; s++ )
                    {
                        if (services[s].svcnum == svc2lookup)
                        {
                            servicenamein=services[s].getname();
                            ratein=services[s].getrate();
                            minutesin=services[s].getminutes();
                            subtotal = minutesin * ratein;
                            
                        }
                    }
                    cout << servicenamein << "," << minutesin << " " << "minutes" << "," << "Cost:$" << subtotal << endl;
                    bill_total = bill_total + subtotal;
                    
                }
                
            }
            cout << "Total is:$"<< bill_total << endl;
            cout << "<Bill ends here>" << endl;
            cout << endl;
        }
            break;
        case 4:
        {
            cout<<"Lookup worker availablity Menu"<<endl;
            for (int i=0;i<svc_array_size;i++)     //   List out services
            {   if(services[i].svcnum != 999999)
                {
                    cout << services[i].getsvcnum()<<",";
                    cout << services[i].getname()<<","<<services[i].getminutes()<<",";
                    cout <<"Worker#"<<services[i].getworkerid() << endl;
                }
            }
                int servnumin = 0;
                int blocks =0;
                bool entryerror=false;
                
                do{ entryerror=false; //validation loop
                    cout <<"Enter Service Number:[0-19]"<<endl;
                    cin >> servnumin; //takes in service number according to above list ...need to add validation
                    blocks = (services[servnumin].getminutes())/30; //determines number of loops to search for conflicts
                    if(servnumin > 19){cout<<"<Invalid Service Number>"<<endl;entryerror=true;}
                } while (entryerror==true);
                entryerror=false;
                int beginmonin=0;
                do { entryerror=false; //validation loop
                    cout <<"Enter Appointment Month(1-12):"<<endl;
                    cin >> beginmonin;
                    if ( (beginmonin ==0)  || (beginmonin >12) ) {cout <<"<Invalid Month>"<<endl; entryerror=true;}
                } while (entryerror==true);
                int begindayin=0;
                do{ entryerror=false; // validation loop
                    cout <<"Enter Appointment Date (1-31):"<<endl;
                    cin >> begindayin;
                    if( (begindayin==0) || (begindayin>31) ) //add specific month- day limit matching later
                    {cout<<"<Invalid Date>"<<endl; entryerror=true; }
                } while(entryerror==true);
                int beginyearin=0;
                do { entryerror=false; //validation loop
                    cout <<"Enter Appointment Year (4 digits):"<<endl;
                    cin >> beginyearin;
                    if ( beginyearin < resyear() ) {cout <<"<Invalid Year>"<<endl; entryerror=true;}
                } while (entryerror==true);
                
            //find workerid of requested service
            int workeridin = services[servnumin].getworkerid();
            
            for (int i=0; i<20; i++) // search thru services match workerid
            {
                if(services[i].workerid == workeridin) //execute when matches workerid
                {
                    int svc_to_check = services[i].svcnum; //pull service number when matches
                    for(int ii=0; ii<appt_array_size; ii++) //search thru appt array to find service matches
                    {
                        if( (appt[ii].servid == svc_to_check) &&  // execute when svc number matches
                           (appt[ii].beginmon == beginmonin) &&  // month match
                           (appt[ii].beginday == begindayin) &&  // year match
                           (appt[ii].beginyear == beginyearin)
                           )
                        {   int blocks = (services[svc_to_check].getminutes())/30;
                            
                            for(int b=0;b<blocks;b++)//create entrys by number of block of service found
                            {
                                int firstemptyspot=0; //find first empty spot on takenlist_worker
                                for(int f=0;f<24;f++)
                                {
                                    if(takenlist_worker[f].custid == 0)
                                    { firstemptyspot=f; break;}
                                }                     //end find empty spot
                                
                                takenlist_worker[firstemptyspot].setbegintime(appt[ii].begintime + b*30); //populate
                                takenlist_worker[firstemptyspot].setcustid(1);
                            }
                        }
                    }
                }
                
            }
        //display worker availability
            //cout <<"0800 0830 0900 0930 1000 1030 1100 1130 1200 1230 1300 1330 1400 1430 1500 1530 1600 1630 1700 1730 1800 1830 1900 1930 2000";
            //cout << "     ";
            cout << endl;
            cout << "This is Worker#"<<workeridin<<","<<services[servnumin].getname()<<"Availability"<<endl;
            for (int i= c2m(800); i < c2m(2000);i=i+30)
            {   cout <<c2h(i);
                bool spottaken=false;
                for (int ii=0; ii<20; ii++)
                {
                    if (takenlist_worker[ii].begintime== i){spottaken=true;}
                    
                }
                if (spottaken==true){cout<<"**";}
                else{cout<< "__";}
            }
            cout << endl;
            
            for(int i=0; i<24;i++) //reinitialize taken lists
            {
                takenlist_self[i].custid=0;
                takenlist_self[i].begintime=0;
            }        }
            break;
        case 5:
        {
            to_exit=true;
            cout<<"Exiting Program"<<endl;
        }
            break;
        default:{cout<< "<Invalid entry>"<<endl;}
            break;
    
    };
    
 } while (to_exit==false); //only exits mainmenu when to_exit flag == true
    
    return 0;
}

    void showmainmenu()
{
    cout <<" Welcome to MIYE SPA Reservation System" << endl;
    cout <<" (1) Book Reservation"<< endl;
    cout <<" (2) Cancel Reservation" << endl;
    cout <<" (3) Bill Customer" << endl;
    cout <<" (4) Check Availablity" <<endl;
    cout <<" (5) Exit Program"<<endl;
    cout <<" ENTER SINGLE NUMBER CHOICE:" << endl;
}
    void showservicemenu()
{
    cout << "test";

}
void clearscreen(){system("clear");} //clears screen with console command, not the best way though

void pause()
{
    cout << "<Press ENTER to continue>";
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cin.ignore(26,'\n');
}
int c2m(int timein)
{
    int hours=0; int minutes=0;
    hours=(timein/100)*60;
    minutes= timein%100;
    return (minutes+hours);
}
int c2h(int timein)
{
    int hourtime=0;
    hourtime = (timein/60)*100 + (timein%60);
    return hourtime;
}
long int timestamp()
{
    int month, date, year, hour, minute, second;
    time_t ltime; /* calendar time */
    struct tm *Tm;
    ltime = time(NULL); /* get current cal time */
    Tm = localtime(&ltime);
    month = Tm->tm_mon+1;
    date = Tm->tm_mday;
    year = Tm->tm_year+1900; /* starts from the year of 1900 */
    
    hour = Tm->tm_hour;
    minute = Tm->tm_min;
    second = Tm->tm_sec;
    //cout << month << endl << date << endl << year << endl << hour << endl << minute << endl << second << endl;
    string timestamp = to_string(month) + to_string(date) + to_string(year) + to_string(hour) + to_string(minute) + to_string(second);
    long int timestampi=0;
    timestampi = stol(timestamp);
    
    return timestampi;
}


int restime()
{
    int month, date, year, hour, minute, second;
    time_t ltime; /* calendar time */
    struct tm *Tm;
    ltime = time(NULL); /* get current cal time */
    Tm = localtime(&ltime);
    month = Tm->tm_mon+1;
    date = Tm->tm_mday;
    year = Tm->tm_year+1900; /* starts from the year of 1900 */
    year = year%1000;
    hour = Tm->tm_hour;
    minute = Tm->tm_min;
    second = Tm->tm_sec;
    //cout << month << endl << date << endl << year << endl << hour << endl << minute << endl << second << endl;
    string timestamp = to_string(hour)+to_string(minute);
    int timestampi=0;
    timestampi = stoi(timestamp);
    return timestampi;
}

int resmon()
{
    int month, date, year, hour, minute, second;
    time_t ltime; /* calendar time */
    struct tm *Tm;
    ltime = time(NULL); /* get current cal time */
    Tm = localtime(&ltime);
    month = Tm->tm_mon+1;
    date = Tm->tm_mday;
    year = Tm->tm_year+1900; /* starts from the year of 1900 */
    year = year%1000;
    hour = Tm->tm_hour;
    minute = Tm->tm_min;
    second = Tm->tm_sec;
    //cout << month << endl << date << endl << year << endl << hour << endl << minute << endl << second << endl;
    string timestamp = to_string(month);
    int timestampi=0;
    timestampi = stoi(timestamp);
    return timestampi;
}
int resday()
{
    int month, date, year, hour, minute, second;
    time_t ltime; /* calendar time */
    struct tm *Tm;
    ltime = time(NULL); /* get current cal time */
    Tm = localtime(&ltime);
    month = Tm->tm_mon+1;
    date = Tm->tm_mday;
    year = Tm->tm_year+1900; /* starts from the year of 1900 */
    year = year%1000;
    hour = Tm->tm_hour;
    minute = Tm->tm_min;
    second = Tm->tm_sec;
    //cout << month << endl << date << endl << year << endl << hour << endl << minute << endl << second << endl;
    string timestamp = to_string(date);
    int timestampi=0;
    timestampi = stoi(timestamp);
    return timestampi;
}

int resyear()
{
    int month, date, year, hour, minute, second;
    time_t ltime; /* calendar time */
    struct tm *Tm;
    ltime = time(NULL); /* get current cal time */
    Tm = localtime(&ltime);
    month = Tm->tm_mon+1;
    date = Tm->tm_mday;
    year = Tm->tm_year+1900; /* starts from the year of 1900 */
    
    hour = Tm->tm_hour;
    minute = Tm->tm_min;
    second = Tm->tm_sec;
    //cout << month << endl << date << endl << year << endl << hour << endl << minute << endl << second << endl;
    string timestamp = to_string(year);
    int timestampi=0;
    timestampi = stoi(timestamp);
    return timestampi;
}

int getlines()
{
    int no_of_lines =0;
    string line;
    ifstream apfile("appt.txt");
    while (getline(apfile,line))
    {
    ++no_of_lines;
    }
    apfile.close();
    return no_of_lines;
}
int getlines_s()
{
    int no_of_lines=0;
    string line;
    ifstream svcfile("services.txt");
    while (getline(svcfile,line))
    {
        ++no_of_lines;
    }
    svcfile.close();
    return no_of_lines;
}
//void list_services(service services[])
//{
//    for (int i=0;i<20;i++)     //test pull data from objects
//    {
//        cout << services[i].getname()<<","<< services[i].getminutes()<<","<<services[i].getrate()<<endl;
//        cout << endl;
//    }
//}