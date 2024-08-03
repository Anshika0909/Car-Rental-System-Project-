#include<iostream>
#include<vector>
#include<string>
using namespace std;
class car
{
public:
car(string make,string model,int year,double dailyRate)
:make(make),model(model),year(year),dailyRate(dailyRate),rented(false)
{}
void rentCar(){
	rented= true;
	}	
	void returnCar(){
		rented= false;
	}
	bool isRented()const{
	return rented;
	}
	double getDailyRate()const{
	return dailyRate;
	}
	void displayCarDetails()const{
	cout<<"Make:,"<<make<<"Model:,"<<model<<"Year:,"<<year<<"DailyRate:,"<<dailyRate<<endl;
	}
	private:
		string make;
		string model;
		int year;
		double dailyRate;
		bool rented;
};
int main()
{
	string name;
	int id;
	cout<<"\n\n\t\tWelcome To Rent A Car Systems"<<endl;
     vector<Car>cars;
	cars.push_back(Car("Toyota," "Camry",2002,50.0));
	cars.push_back(Car("Honda," "Accord",2001,40.0));
	cars.push_back(Car("Ford," "Mustang",2022,70.0));
	int choice;
	do{
		cout<<"Menu:"<<endl;
		cout<<"\n\n\t\t1. Rent a Car"<<endl;
		cout<<"\n\n\t\t2. Return a Car"<<endl;
		cout<<"\n\n\t\t3. Display Car Details"<<endl;
		cout<<"\n\n\t\t4. Exit"<<endl;
		cout<<"Enter Your Choice:";
		cin>>choice;
		if(choice==1 || choice==2){
			cout<<"Enter Your Name"<<endl;
			cin>>name;
			cout<<"Enter Your ID"<<endl;
			cin>>id;
			int carIndex;
			cout<<"Enter the Car Index(1-"<<cars.size()<<") ";
			cin>>carIndex;
			carIndex--;
			if(carIndex>0 && carIndex< cars.size()){
				if(choice== 1){
					if(!cars[carIndex].isRented()){
						cars[carIndex].rentCar();
						cout<<"Car is Rented Successfully."<<endl;
					}
					else{
						cout<<"Car is Already Rented"<<endl;
					}
				}
				else{
					if(cars[carIndex].isRented()){
						cars[carIndex].returnCar();
						cout<<"Car Rented Successfully."<<endl;
					}
					else{
						cout<<"Car is Not Rented."<<endl;
					}
				}
			}
			else{
				  cout<<"Invalid Car Index"<<endl;
			}
		}
		else if(choice==3){
			for(size_t i=0;i<cars.size();i++)
			{
				cout<<"Car"<<i+1<<":";
				cars[i].displayCarDetails();
			}
		}
	}
	while(choice != 4);
	return 0;
}
