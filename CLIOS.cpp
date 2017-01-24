// Command LIne Operating System

#include<iostream.h>
#include"fileio.cpp"
#include<process.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include<dos.h>

class user{

/* -----variable for switching between superuser and guest---------------*/

			int flag;
/* -----variable for password comparison---------------------------------*/

			char ch[5];
/* -----shutdown function---------------------------------------*/

			void shut(){
					clrscr();
					flag = 0;
			}
		public:
/* ------revert function-------------------------------------------------*/

			void revert() {
				flag = 0;
		}
/* ------default constructor---------------------------------------------*/

			user(){
				flag = 0;
		}

/* ------super user return function--------------------------------------*/

			int ret(void){
				return flag;
		}

/* ------login function--------------------------------------------------*/

	void log(void){
		if(flag==0){
		cout<<"\nEnter password : ";cin>>ch;
			if(strcmp(ch,"toor")==0||strcmp(ch,"TOOR")==0) {flag = 1;}
			else cout<<"\nWrong password.\n";
		}
		else {
			shut();
		}
	}

}sudo; // end of class.

/* ------------------class for calculator--------------------------------*/

class calc{
	int x,var,var1,pro;
	char op;
public:
	calc(){
	var = var1 = x = 0;
}
	void getd(void) {
	cout<<"\n! ";
	cin>>var>>op>>var1;
	}
	void calcu(void);

}arith;

// Function Prototypes
void screensaver(void);	    // w
void caeser(int); 		   //  b     decryption prototyope
void caeser(void);     	  //   w     encryption prototype
void helpme(void);	     //    w
void ehelp(void);		//     w
void time(void);       //      w

// global variables
int duplicate;
char su[20];

// Main Function
void main(void){

int x;

clrscr();
cout<<CLIOS<<endl;
home:

duplicate = sudo.ret();

textcolor(2);		// sets the text below to green.
(duplicate==1) ? cprintf("clios # ") : cprintf("clios % ") ;
textcolor(7);		// restors the light gray interface of DOS

gets(su);
for(int i=0;su[i]!='\0';i++) {
	su[i] = tolower(su[i]);
} 

history.record(su);

if(strcmp(su,"ls")==0) {
	ls.listall();
}
else if (strcmp(su,"rm")==0) {
	rm.rem();
}
else if (strcmp(su,"cmore")==0) {
	cmore.disp();
}
else if (strcmp(su,"history")==0) {
	history.show();
}
else if (strcmp(su,"editt")==0) {
	bor.fileio();	
}
else if (strcmp(su,"create")==0||strcmp(su,"touch")==0) {
	ctouch.cre();
}
else if(strcmp(su,"help")==0){
	helpme(); 
}
else if (strcmp(su,"clios")==0) {
	puts(CLIOS);
}
else if (strcmp(su,"sudo halt!!")==0)
	exit(0);
else if (strcmp(su,"poweroff")==0) {
	if(duplicate==1) {clrscr();exit(0);}
	else cout<<"\nPERMISSION DENIED\n";
	}
else if (strcmp(su,"reboot")==0) {
	sudo.log();main();
	}
else if ((strcmp(su,"calculator")==0)||(strcmp(su,"calc")==0)) {
	arith.getd();
	arith.calcu();
	 }
else if (strcmp(su,"whoami")==0) {
	if(duplicate==0)
		cout<<" guest"<<endl;
	else
		cout<<" root"<<endl; }
else if (strcmp(su,"time")==0)
	time();
else if (strcmp(su,"cipher")==0||strcmp(su,"cry")==0)
	caeser();
else if (strcmp(su,"Decrypt")==0||strcmp(su,"dcry")==0) {
	cout<<"DECRYPTION~KEY # ";
	cin>>x;                // var to pass value ,stored in key.
	caeser(x);
	}
else if (strcmp(su,"logout")==0&&duplicate==1){
	sudo.revert();
	}
else if (strcmp(su,"clear")==0||strcmp(su,"cls")==0)
	clrscr();
else if (strcmp(su,"\0")==0)
	goto home;
else if (strcmp(su,"help-editt")==0)
	ehelp();
else if (strcmp(su,"ssaver")==0)
	screensaver();
else if (strcmp(su,"su")==0)
	sudo.log();
else   {
	 cout<<"SYNTAX ERROR:~% ~: ----> "<<su<<" <---- command does not exist."<<endl;
	 goto home;
	 }
goto home;

} // end of main

// calculator class calculator function defenetion
void calc::calcu(void)
{
//calculator function	BUILD*

if (isdigit(var))
	var = 0;
if (isdigit(var1))
	var1 = 0;
if (isalpha(op))
	op = '+';

switch (op)
{
case '+':cout<<"\n+ "<<(var)+(var1)<<endl;
	 break;
case '-':cout<<"\n-~ "<<var-var1<<endl;
	 break;
case '/':cout<<"\n/ "<<(float)var/(float)var1<<endl;
	 break;
case '*':cout<<"\n* "<<var*var1<<endl;
	 break;
case '%':cout<<"\n% "<<var%var1<<endl;
	 break;
case 'Q':cout<<"\nQuitting calculator programme.\n";
	 x=1;
	 break;
default: cout<<"\nInvalid / missing arithmatic opetator"<<endl;
	 x=1;break;
};

}

/* ------function to display time----------------------------------------*/

void time(void)
{
/* time function
 current date/time of system                *BUILD */
time_t now = time(0);
// string form
char* dt = ctime(&now);
cout<<"The local date and time is: "<<dt<<endl;
}

/* ------Encryption function---------------------------------------------*/

void caeser(void)
{
  int i,key;
  char txt[20];
  cout<<"ENCRYPTION~KEY # ";
  cin>>key;
  cout<<"TEXT % ";
  gets(txt);
  for(i=0;txt[i]!='\0';i++) {
	if(isalpha(txt[i])) {
		if(islower(txt[i])) {
			txt[i] = (((txt[i] - 97) + key) % 26) + 97; }
		else if(isupper(txt[i])) {
			txt[i] = (((txt[i] - 65) + key) % 26) + 65; }
	}
	else
		txt[i] = txt[i];
}
  cout<<"\n%% : "<<txt<<endl;
}

/* ------Decryption function---------------------------------------------*/

void caeser(int key){
  char txt[20];
  cout<<"TEXT % ";
  gets(txt);
  for(int i=0;txt[i]!='\0';i++) {
	if(isalpha(txt[i])) {
		if(islower(txt[i])) {
			txt[i] = (((txt[i] - 97) + (26-key)%26) % 26 ) + 97 ; }
		else if(isupper(txt[i])) {
			txt[i] = (((txt[i] - 65) + (26-key)%26) % 26 ) + 65 ; }
	}
	else
		txt[i] = txt[i];
}
  cout<<"\n%% "<<txt<<endl;
}

/* ------help function---------------------------------------------------*/

void helpme(void) {

	cout<<"\t\tHELP"<<endl;
	cout<<"\tA list of all the commands - "<<endl;
	cout<<"< su       > Grants Superuser privileges "<<endl;
	cout<<"< cry      > Encryption Command"<<endl;
	cout<<"< dcry     > Decryption Command"<<endl;
	cout<<"< calc     > Claculator"<<endl;
	cout<<"< time     > Displays the system time"<<endl;
	cout<<"< ls       > Directory View"<<endl;
	cout<<"< cls      > Clear screen"<<endl;
	cout<<"< create   > Creates files"<<endl;
	cout<<"< rm       > Removes files"<<endl;
	cout<<"< editt    > Text-editor (More help at help-editt)"<<endl;
	cout<<"< cmore    > Displays the content of a file"<<endl;
	cout<<"< ssaver   > Screen saver"<<endl;
	cout<<"< poweroff > Shuts down the emulation"<<endl;
	cout<<"< history  > Shows the list of commands used"<<endl;
	cout<<"< logout   > Reverts form superuser to guest"<<endl;
	cout<<"< reboot   > System reboots"<<endl;
	cout<<"< whoami   > Displays user Name"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"< SUDO HALT!! > EMERGENCY SHUTDOWN COMMAND"<<endl<<endl;
}

/* ------editt help function---------------------------------------------*/

void ehelp(void) {

	cout<<"\t\t\tEDITT"<<endl;
	cout<<"> When the \"STREAM OPENED\" warning is displayed, start edditing"<<endl;
	cout<<"> The changes will be writen line by line to the file."<<endl;
	cout<<"> The maximum number of charectres allowed per line is 500 "<<endl;
	cout<<"> To stop edditing type \":exit editor\" on a new line"<<endl;
	cout<<"> To view the text written onto the file type \":visual\" on a new line"<<endl;
	cout<<"> Wait till you see the \"STREAM REOPENED\" warning before edditing. "<<endl;
	cout<<"> The \"STREAM CLOSED\" warning will appear before exiting the editor."<<endl<<endl;
}

/* ------screen saver----------------------------------------------------*/

void screensaver(void){
textcolor(12);		// sets screensaver pictures color to light red.
clrscr();
	cputs(DRAGON);
	getch();
	cout<<"\nEnter Password : ";
	cin.getline(su,sizeof(su));
		if(strcmp(su,"password")!=0){
			screensaver();}
		else if(strcmp(su,"password")==0){
			cout<<endl;
			time(); 
	 }
textcolor(2);		// restors the color to green.
}
