#include<iostream>
using namespace std;
const int MAX_FLIGHTS=10;
class FlightRecord
{
	protected:
		string flight_name, flight_id,flight_arrival_time, flight_departure_time, flight_class;
		int flight_capacity;
	public:
		FlightRecord(string fn,string fid,string at, string dt,string fc,int cap)
		{
			flight_name=fn; 
			flight_id=fid;
			flight_arrival_time=at; 
			flight_departure_time=dt; 
			flight_class=fc;
			flight_capacity=cap;	 	
	    }	
		virtual void displayDetails()
		{
			cout<<"Flight name: "<<flight_name<<endl;
			cout<<"Flight Id: "<<flight_id<<endl;
			cout<<"Flight arrival time: "<<flight_arrival_time<<endl;
			cout<<"Flight departure time: "<<flight_departure_time<<endl;
			cout<<"Flight class: "<<flight_class<<endl;
			cout<<"Flight capacity: "<<flight_capacity<<endl<<endl;
		}
};
class VIPFlight:public FlightRecord
{
	string vip_category;
	public:
		VIPFlight(string fn,string fid,string at, string dt,string fc,int cap,string vc):FlightRecord(fn,fid,at,dt,fc,cap)
		{
			vip_category=vc;	 	
	    }
		void displayDetails()
		{
			cout<<"Flight name: "<<flight_name<<endl;
			cout<<"Flight Id: "<<flight_id<<endl;
			cout<<"Flight arrival time: "<<flight_arrival_time<<endl;
			cout<<"Flight departure time: "<<flight_departure_time<<endl;
			cout<<"Flight class: "<<flight_class<<endl;
			cout<<"Flight capacity: "<<flight_capacity<<endl;
			cout<<"VIP Category: "<<vip_category<<endl<<endl;
		}	
};
class VVIPFlight:public FlightRecord
{
	string vvip_name;
	public:
		VVIPFlight(string fn,string fid,string at, string dt,string fc,int cap,string vn):FlightRecord(fn,fid,at,dt,fc,cap)
		{
			vvip_name=vn;	 	
	    }
		void displayDetails()
		{
			cout<<"Flight name: "<<flight_name<<endl;
			cout<<"Flight Id: "<<flight_id<<endl;
			cout<<"Flight arrival time: "<<flight_arrival_time<<endl;
			cout<<"Flight departure time: "<<flight_departure_time<<endl;
			cout<<"Flight class: "<<flight_class<<endl;
			cout<<"Flight capacity: "<<flight_capacity<<endl;
			cout<<"VVIP Name: "<<vvip_name<<endl<<endl;
		}	
};
class PublicFlight:public FlightRecord
{
	string source,destination;
	public:
		PublicFlight(string fn,string fid,string at, string dt,string fc,int cap,string s,string d):FlightRecord(fn,fid,at,dt,fc,cap)
		{
			source=s;
			destination=d;	 	
	    }
		void displayDetails()
		{
			cout<<"Flight name: "<<flight_name<<endl;
			cout<<"Flight Id: "<<flight_id<<endl;
			cout<<"Flight arrival time: "<<flight_arrival_time<<endl;
			cout<<"Flight departure time: "<<flight_departure_time<<endl;
			cout<<"Flight class: "<<flight_class<<endl;
			cout<<"Flight capacity: "<<flight_capacity<<endl;
			cout<<"Source: "<<source<<endl;
			cout<<"Destination: "<<destination<<endl;
		}	
};
class FlightManager
{
	FlightRecord* flight[MAX_FLIGHTS];
	int num_flights;
	public:
		FlightManager()
		{
			num_flights=0;
		}
		void insert_flight(string fn,string fid,string at, string dt,string fc,int cap)
		{
			if(num_flights<MAX_FLIGHTS)
			{
				flight[num_flights]= new FlightRecord(fn,fid,at,dt,fc,cap);
				num_flights++;	
			}
			else
			{
				cout<<"Flight management database is full.Cannot insert more flights."<<endl;
			}
		}
		void insert_vipflight(string fn,string fid,string at, string dt,string fc,int cap,string vc)
		{
			if(num_flights<MAX_FLIGHTS)
			{
				flight[num_flights]= new VIPFlight(fn,fid,at,dt,fc,cap,vc);
				num_flights++;	
			}
			else
			{
				cout<<"Flight management database is full.Cannot insert more flights."<<endl;
			}
		}
		void insert_vvipflight(string fn,string fid,string at, string dt,string fc,int cap,string vn)
		{
			if(num_flights<MAX_FLIGHTS)
			{
				flight[num_flights]= new VVIPFlight(fn,fid,at,dt,fc,cap,vn);
				num_flights++;
			}
			else
			{
				cout<<"Flight management database is full.Cannot insert more flights."<<endl;
			}
		}
		void insert_publicflight(string fn,string fid,string at, string dt,string fc,int cap,string s,string d)
		{
			if(num_flights<MAX_FLIGHTS)
			{
				flight[num_flights]= new PublicFlight(fn,fid,at,dt,fc,cap,s,d);
				num_flights++;
			}
			else
			{
				cout<<"Flight management database is full.Cannot insert more flights."<<endl;
			}
		}
		void get_num_of_flights()
		{
			cout<<"Number of flights is: "<<num_flights<<endl;		
		}
		void displayDetail()
		{
			for(int i=0;i<=MAX_FLIGHTS;i++)
			{
				flight[i]->displayDetails();
				cout<<endl;	
			}	
		}		
};
int main()
{
	FlightManager f;
	
	f.insert_flight("flight 1","A101","8:00pm","6:45pm","Buisness",100);
	f.insert_publicflight("flight 2","B101","9:00pm","6:00pm","Economic",150,"Nagpur","Mumbai");
	f.insert_vipflight("flight 3","C101","12:00pm","8:00am","Buisness",80,"z+");
	f.insert_vvipflight("flight 4","D101","4:00pm","2:00pm","IAF",4,"President");
	f.insert_flight("flight 5","Z101","8:00pm","6:45pm","Buisness",100);
	f.displayDetail();
	
}
