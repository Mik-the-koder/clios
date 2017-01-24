/* ------------------file input output-----------------------------------*/

// cmore is an object used to view data in files ,
// History is an object used to record commands ,
// editt is an object used for editing text ,
// touch is an object used to create files ,
// ls is an object used for listing files ,
// rm is an object used to remove files ,


#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>


/* ---------------function to check for system files---------------------*/

int check(char ar[]) {
	for(int i=0;i<20;i++) {
		ar[i] = toupper(ar[i]);
	}
	if((strcmp(ar,"ALLFILES.BOR")==0)||(strcmp(ar,"CLIOS.CPP")==0)||(strcmp(ar,"FILEIO.CPP")==0)||(strcmp(ar,"FILEIO.OBJ")==0)) {
			return 1;
	}
	return 0;   // returns "zero" if file name does not interfear with system files.... 
}

/* ------------------------super class-----------------------------------*/

class super {
	protected:
		ofstream writeobj;
		ifstream readobj;
		char name[20];
};

/* ------------------------ls--------------------------------------------*/

class listfile : private super {
	public:
		void listall(void);
}ls;

void listfile::listall(void) {
	readobj.open("ALLFILES.BOR",ios::in);

	while(!readobj.eof()) {
		readobj.getline(name,20);
		cout<<name<<" ";
     		cout<<endl;
	}
	cout<<endl;
	readobj.close();
}

/* ------------------------rm--------------------------------------------*/

class removefile : private super {
		char buff[50];
		int flag;
	public:
		removefile() {
			flag = 1;
		}
		void rem(void);

}rm;
void removefile::rem(void) {
		cout<<"\nEnter file name : ";
		cin.getline(name,sizeof(name));
	if(check(name)!=0)
		cout<<name<<endl;
	else {
		writeobj.open("TEMPFILES",ios::app);
		readobj.open("ALLFILES.BOR",ios::in);
			while(!readobj.eof()) {
				readobj.getline(buff,50);

				for(int i=0;buff[i]!='\0';i++) {
					buff[i] = toupper(buff[i]);
				}

				if(strcmp(name,buff)==0) {
					flag = 1;
					cout<<"\nFile found!!\n";
					remove(name);
				}
				else {
					writeobj<<endl<<buff;
				}
			}
		readobj.close();
		writeobj.close();

		remove("ALLFILES.BOR");
		if(rename("TEMPFILES","ALLFILES.BOR")==0) {
			cout<<endl;
		}
	}
}
/* ------------------------cmore-----------------------------------------*/

class VIEW : private super  {
		char buffer[500];
	public:
		void disp(void);
		void help(void);
		void disp(char ar[]);
}cmore;

void VIEW::disp(void) {
	cout<<"\nFile name : ";
	cin.getline(name,sizeof(name));
	if(check(name)!=0) {
		cout<<"\nFILE DOES NOT EXIST!!\n";
	}
	else
		disp(name);
}
void VIEW::help(void) {
	cout<<"\n--EDITT--\n\n";
	cout<<"Cmore is a simple file viewing program.\n\n";
	cout<<"usage :  cmore <file> \n\n";
}
void VIEW::disp(char ar[]) {
	int i=0;
	char j;
	readobj.open(ar,ios::in);
	if(!readobj) {
		cout<<"File \' "<<ar<<" \' does not exist!!\n";
	}
	else {
		while(!readobj.eof()&&j!='q') {
			readobj.getline(buffer,500);
			cout<<buffer<<endl;
			if(i<25) {
				i++;
			}
			else {
				i = 0;
				getch();
			}
		}
	}
	readobj.close();
}

/* ------------------------editor----------------------------------------*/

class EDIT : private super {
		char buffer[500];
		fstream writeobj;
	public:
		void write(void) {
			cin.getline(buffer,sizeof(buffer));
		}
		void fileio(void);
		void fileio(char ar[]);
}bor;
void EDIT::fileio(void) {
	cout<<"--EDITT--"<<endl;
	cout<<"\nEnter file name : ";
	cin.getline(name,sizeof(name));

	if(check(name)!=0) {
		cout<<"\nFILE DOES NOT EXIST!!\n";
	}
	else if(strcmp(name,"\0")==0) {
		strcpy(name,"untitled.bor");
	}
	else
		fileio(name);
}
void EDIT::fileio(char ar[]) {
	VIEW cobject;
	cout<<"STREAM OPENED\n\n";
		do {
			write();
				writeobj.open(ar,ios::app);
					if(strcmp(buffer,":exit editor")!=0&&strcmp(buffer,":visual")!=0) {
							writeobj<<buffer<<endl; }
					else if(strcmp(buffer,":visual")==0) {
							writeobj.close();
							cobject.disp(ar);
							getch();
							cout<<"STREAM REOPENED\n";
							writeobj.open(ar,ios::app);
						}
			       writeobj.close();
		}while(strcmp(buffer,":exit editor")!=0);

	cout<<"\n\nSTREAM CLOSED\n";
}

/* ------------------------create----------------------------------------*/

class create : private super  {
	public:
	       void cre(void);

}ctouch;
void create::cre(void) {
	cout<<"\nEnter file name : ";
	cin.getline(name,sizeof(name));

	if(check(name)==0) {

		writeobj.open("ALLFILES.BOR",ios::app);
		writeobj<<endl<<name;
		writeobj.close();

		writeobj.open(name,ios::noreplace);
		writeobj.close();
	}
	else
		cout<<"\nIllegal name!!\n";
}
/* ------------------------history---------------------------------------*/

class HISTORY : private super {
	public:
		void record(char su[]);
		void show(void);
}history;
void HISTORY::record(char ar[]) {
	writeobj.open(".clios_history",ios::app);
		if(strcmp(ar,"\0")!=0)
			writeobj<<ar<<endl;
	writeobj.close();
}
void HISTORY::show(void) {
	cmore.disp(".clios_history");
}
