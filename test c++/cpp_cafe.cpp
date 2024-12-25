#include<iostream>
using namespace std;
int main(){
	float price,total=0.0;
	int drink,qty,choice;
	
	cout<<"====Welcome to our cafe=====";
	do{
	cout<<"====These are our menu======\n";
	cout<<"1. Ice latte\n2. Ice Cappuccino\n3. Ice Americano\n4. Green tea\n";
	cout<<"Input the numbers of menu that you want (0 to finish ordering):";cin>>drink;
	if(drink==0){
		break;
	}
	switch(drink){
		case 1:
			price=2.0;
			cout<<"Ice latte price $2.0 per one\n";
			cout<<"Input qty:";cin>>qty;
			total+=price*qty;
			break;
		case 2:
			price=3.0;
			cout<<"Ice cappuccino price $3.0 per one\n";
			cout<<"Input qty:";cin>>qty;
			total+=price*qty;
			break;
		case 3:
			price=4.0;
			cout<<"Ice Americano price $4.0 per one\n";
			cout<<"Input qty:";cin>>qty;
			total+=price*qty;
			break;
		case 4:
			price=5.0;
			cout<<"Green Tea  price $5.0 per one\n";
			cout<<"Input qty:";cin>>qty;
			total+=price*qty;
			break;			
			
	}
	}while(choice!=0);
	printf("total is $%.2f",total);
	
	
	
	
	
	return 0;
}
