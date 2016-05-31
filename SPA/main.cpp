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
    string name;
    int minutes;
    double rate;
    int svcnum;
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
    
    void setid(int n){id=n;};
    void setfname(string f){fname=f;};
    void setlname(string l){lname=l;};
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

int main() {

    
//create services array ..should auto create size later should read from file-->services.txt afterwards
service services[20];
    
    ifstream inputfile; //open services.txt file to read in services parameters
    inputfile.open("services.txt");
    if (inputfile.is_open()) {cout << "Service File Opened Successfully.\n";}; //check if services file opens
    for (int i=0;i<20;i++)    // loop to file array from file static array size 20
    {
        //cout << i <<endl;  // cycle test counter
        string namein;int minutein=0; double ratein=0.00; int workeridin=0; //create temp reader buckets
        inputfile >> namein; inputfile  >> minutein; inputfile >> ratein; inputfile >> workeridin;
        //cout << namein<<" " << minutein <<" "<<ratein<<endl; //test dump reader buffer contents
        services[i].setname(namein);
        services[i].setminutes(minutein);
        services[i].setrate(ratein);
        services[i].setsvcnum(i);
        services[i].setworkerid(workeridin);
    };
    //cout <<"<end cycle test>"<< endl;           //end cycle test
    inputfile.close(); //close service.txt file
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
    { int custidin; string fnamein; string lnamein;
        inputfile2 >> custidin; inputfile2 >> fnamein; inputfile2 >> lnamein;
        customers[i].setid(custidin);
        customers[i].setfname(fnamein);
        customers[i].setlname(lnamein);
        
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
        //create appt array --assuming book holds 10 records for simplicity--expand later
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
            
            for (int i=0;i<20;i++)     //   List out services
                    {
                        cout << services[i].getsvcnum()<<",";
                        cout << services[i].getname()<<","<<services[i].getminutes()<<",";
                        cout <<"Worker#"<<services[i].getworkerid() << endl;
                        
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
            
            //composite date time check
            
            // insert calculation of end time here if necessary --no yet necessary
            
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
            //spit out self array info --- no worky
            for(int i=0;i<24;i++)
//            {
//                if(takenlist_self[i].custid == 1){cout << takenlist_self[i].begintime;
//                    cout <<","<<c2h(takenlist_self[i].begintime) <<endl;}
//            }
            
            
            
            //spit out worker array info -- no worky
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

            
            //            int workeridin = NULL;                      //populate list start
//            workeridin= services[servnumin].getworkerid(); //pull workerid from requested service
//            
//            for (int s=0; s<20;s++)                        //scans through services for worker related services
//            {
//                if(services[s].getworkerid()==workeridin) //search for matching worker in services[]
//                {
//                    //int svc_to_check = 0;
//                    //svc_to_check = services[s].getsvcnum(); //pulls service number(s) matching worker
//                    int svc_to_check  = servnumin;
//                    for (int i =0;i<appt_array_size;i++)  //search for matching service in appt[]
//                    {
//                        if ((appt[i].custid != 0) &&
//                            (appt[i].servid == svc_to_check) &&
//                            (appt[i].beginmon == beginmonin) &&
//                            (appt[i].beginday == begindayin) &&
//                            (appt[i].beginyear == beginyearin)  )
//                        {
//                            int starttime = 0;
//                            starttime = appt[i].begintime;
//                            int blocks= (services[svc_to_check].getminutes())/30; //calculates blocks
//                            for (int ii =0; ii<blocks; ii++)
//                            {
//                                int firstemptyspot =0;
//                                for(int f=0;f<24;f++)
//                                {
//                                    if ( takenlist_worker[f].getcustid() == 0 )
//                                    {firstemptyspot = f;break;} //breaks after finding first empty spot
//                                }
//                                takenlist_worker[firstemptyspot].setbegintime(starttime + ii*30);
//                                takenlist_worker[firstemptyspot].setcustid(1);
//                            }
//                            
//                        }
//                    }
//                }
//            }
            
            //check for conflicts
            

            
            
//            for (int i=0; i<(blocks);i++) //search for conflicts with self on appt array or temp table --test appt first
//            {   cout <<"Checking block:"<<(i+1)<<endl;
//                for (int ii=0;ii<10; ii++) //search through appt array for conflicts
//                {   if (appt[ii].custid == custidin )
//                    {   if(appt[ii].beginyear==beginyearin) //need to check for accuracy
//                        {   if(appt[ii].beginmon==beginmonin)
//                            { if(appt[ii].beginday==begindayin)
//                                {
//                                
//                                    if(appt[ii].begintime== c2m(begintimein)+ (ii*30) )
//                                    {
//                                        flag_timeconflict = true;
//                                    }
//                                }
//                            }
//                        }
//                    }
//                    
//                }
//            }
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
                
               
                
                apptidin= timestamp(); // pulls timestamp to be stored as apptid from current function
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
        case 4:
        {
            cout<<"Lookup worker availablity Menu"<<endl;
            for (int i=0;i<20;i++)     //   List out services
            {
                cout << services[i].getsvcnum()<<",";
                cout << services[i].getname()<<","<<services[i].getminutes()<<",";
                cout <<"Worker#"<<services[i].getworkerid() << endl;}
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
        }
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
//void list_services(service services[])
//{
//    for (int i=0;i<20;i++)     //test pull data from objects
//    {
//        cout << services[i].getname()<<","<< services[i].getminutes()<<","<<services[i].getrate()<<endl;
//        cout << endl;
//    }
//}