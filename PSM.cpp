//c++ File managment Project
#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

class Market{
	private: 
		 string Name;
		 int quant,price;
		public:
			Market():Name(""),quant(0),price(0){}
			
		//setter function
		setName(string name){
			Name=name;
		}
		setquant(int q){
			quant=q;
		}
		setPrice(int p){
			price=p;
		} 
		
		//Gtter funcitons 
		string getName(){
			return Name;	
		}
		int getPrice(){
			return price;
		}
		int getQuant(){
			return quant;
		}
		
};
 addItems(Market m){
	string name;
	int quant,price;
	cout<<"Enter the Name of the Item"<<endl;
	cin>>name;
	cout<<"Enter the price of the Item"<<endl;
	cin>>price;
	cout<<"Enter the Quantity of the Item"<<endl;
	cin>>quant;
	m.setName(name);
	m.setPrice(price);
	m.setquant(quant);
	ofstream out("D:/My_Data_Begins/CodeCode/SuperMarketdata.txt",ios::app);
	if(!out){
		cout<"FIle to h vhud gaya";
	}
	else{
		out<<m.getName()<<" | "<<m.getPrice()<<" | "<<m.getQuant()<<endl;
		cout<<"Saved!"<<endl;
	}
	out.close();
}
searchItems(Market m){
	string names;
	cout<<"Enter the Product Name or Product ID"<<endl;
	cin>>names;
	ifstream in("D:/My_Data_Begins/CodeCode/SuperMarketdata.txt");
	if(!in){
		cout<<"File Unavailable"<<endl;
		
	}else{
		string line;
		bool fnd=false;
		while(getline(in,line)){
			int pos=line.find(names);
			if(pos!=string::npos){
				cout<<"Item|Quant|Price"<<endl;
				cout<<line<<endl;
				fnd =true;
				break;
			}
		}
		if(!fnd){
			cout<<"Item Not Found"<<endl;
		}
	}
}
int main(){
	Market m;
		bool exit=false;
		while(!exit){
			system("cls");
			
			cout<<"Welcome to Suoer MArket Mngmnt System"<<endl;
			
			cout<<endl<<"1.Add Items"<<endl;
			cout<<"2.Search Items"<<endl;
			cout<<"3.Exit"<<endl;
			cout<<"4 . Delete and restore"<<endl;
			int ch;
			cin>>ch;
//			if(ch==1) cout<<"return the Vlas"<<endl;
//			addItems(m);
			
			switch(ch){
				case 1: 
						system("cls");
						addItems(m);
						Sleep(5000);
						cout<<"Wroked";
				break;
				case 2: 	system("cls");
						searchItems(m);
						Sleep(5000);
						cout<<"Wroked";
				break;
				case 3: exit = true;
				break;
				case 4: {
				ofstream ofs;
ofs.open("SuperMarketdata.txt", std::ofstream::out | std::ofstream::trunc);
ofs.close();

				}
			
				default: 
				cout<<"Wrong Choices Selected"<<endl;
			}
				
		}	
}

