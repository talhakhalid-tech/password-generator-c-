#include<iostream>
#include<string>
#include<stdlib.h>    
#include<time.h>
using namespace std;
class pass_gen{
	string password,Ualpha,Lalpha,spec_char,num;
	int passLength,choice;
	char inc;
	bool Ualph,Lalph,special,numb;
public:
	pass_gen():password(""),Ualpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),Lalpha("abcdefghijklmnopqrstuvwxyz"),spec_char("@#$%&*"),num("0123456789"),
		Ualph(true),Lalph(true),special(true),numb(true),inc(' '){}
	void setter();
	void passwordGenerator();
	void getter() const;
};
void pass_gen::setter(){
	while(1){
	cout<<"enter the length of password (min 7 & max 100): ";
	cin>>passLength;
	if(passLength<7 || passLength>100)
		cout<<"length must be greater than or equal to 7 and less than or equal to 100!!!";
	else
		break;
	}
	while(1){
	while(1){
		cout<<"wanna include Uppercase alphabets? 'y' for yes and 'n' for no: ";
		cin>>inc;
		if(inc == 'y' || inc == 'Y'){
			Ualph=true;
			break;
		}
		else if(inc == 'n' || inc == 'N'){
			Ualph=false;
			break;
		}
		else
			cout<<"invalid choice!!!";		
	}
	while(1){
		cout<<"wanna include Lowercase alphabets? 'y' for yes and 'n' for no: ";
		cin>>inc;
		if(inc == 'y' || inc == 'Y'){
			Lalph=true;
			break;
		}
		else if(inc == 'n' || inc == 'N'){
			Lalph=false;
			break;
		}
		else
			cout<<"invalid choice!!!";		
	}
	while(1){
		cout<<"wanna include Numbers? 'y' for yes and 'n' for no: ";
		cin>>inc;
		if(inc == 'y' || inc == 'Y'){
			numb=true;
			break;
		}
		else if(inc == 'n' || inc == 'N'){
			numb=false;
			break;
		}
		else
			cout<<"invalid choice!!!";		
	}
	while(1){
		cout<<"wanna include Special characters? 'y' for yes and 'n' for no: ";
		cin>>inc;
		if(inc == 'y' || inc == 'Y'){
			special=true;
			break;
		}
		else if(inc == 'n' || inc == 'N'){
			special=false;
			break;
		}
		else
			cout<<"invalid choice!!!";		
	}
	if(Ualph == false && Lalph == false && special == false && numb == false)
		cout<<"you must include at least one thing!!!!";
	else
		break;
	}

}
void pass_gen::passwordGenerator(){
	 srand(time(NULL));
	for(int i=0;i<passLength;i++){
		choice=rand()%4 + 1;
		switch(choice){
			case 1:
				{
				if(Ualph == true){
					choice=rand()%26;
					password=password+Ualpha[choice];
					break;
				}
				else
					i--;
				break;
				}
			case 2:
				{
				if(Lalph == true){
					choice=rand()%26;
					password=password+Lalpha[choice];
					break;
				}
				else
					i--;
				break;
				}
			case 3:
				{
					if(special == true){
					choice=rand()%6;
					password=password+spec_char[choice];
					break;
				}
				else
					i--;
				break;
				}
			case 4:
				{
					if(numb == true){
					choice=rand()%10;
					password=password+num[choice];
					break;
				}
				else
					i--;
				break;
				}
			default:
				break;
		}
	}
}
void pass_gen::getter() const{
	cout<<"password: "<<password<<endl;
}
int main()
{
	pass_gen obj;
	obj.setter();
	obj.passwordGenerator();
	obj.getter();
	system("pause");
	return 0;
}