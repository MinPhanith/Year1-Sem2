#include<iostream>
#include<string>
int qty;
float price,payment,total;
string Menuname;
using namespace std;
void showbar(){
	cout<<"==========>Nith Store<=========\n";
	cout<<"1.Start Order\n2.Veiw Order\n3.Payment\n4.Exit\n";
}
void order(){
	int menu;
	cout<<"=========>Welcome to our menu<=============\n";
	cout << "1. Ice latte\n2. Ice Cappuccino\n3. Ice Americano\n4. Green tea\n";
    cout << "Input the numbers of menu that you want (0 for finished your older): ";cin>>menu;
    while(menu!=0){
    	
    	switch (menu){
    	case 1:
    		price=2.00;
    		Menuname ="Ice latte";
    		cout<<"Ice latte per one price $2\n";
    		cout<<"Input your qty:";cin>>qty;
    		payment+=qty*price;	
    		break;
    	case 2:
    		price=4.00;
    		Menuname="Ice Cappuccino";
    		cout<<"Ice Cappuccino per one price $4\n";
    		cout<<"Input your qty:";cin>>qty;
    		payment+=qty*price;	
			break;
		case 3:
			Menuname="Ice Americano";
			price=3.00;
    		cout<<"Ice Americano  per one price $3\n";
    		cout<<"Input your qty:";cin>>qty;
    		payment+=qty*price;	
			break;
		case 4:
			Menuname="Grean tea";
			price=5.00;
    		cout<<"Green Tea per one price $5\n";
    		cout<<"Input your qty:";cin>>qty;
    		payment+=qty*price;
			break;
	    default :
	    	cout<<"You order success! have a nice day\n";
	    	break;
    	
	}
	}
    
}
void veiworder(){
	cout<<"This the information that you was ordered:\n";
	cout<<Menuname<<endl;
	cout<<qty<<endl;
}	
		
int main(){
	int op;
	showbar();
	cout<<"Please choose one option:";
	cin>>op;
	while(op!=0){
		switch (op){
			case 1:
				order();
				break;
			case 2:
				veiworder();
				break;
			case 3:
				break;
			case 4:
				exit(0);
			   break;	
				
		
	}
}
}
