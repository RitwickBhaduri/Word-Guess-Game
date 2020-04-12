#include<iostream.h>
#include<stdio.h>
#include<conio.h>
// character array used to build the table
char arr[40];

//integer arrays to store column numbers
int pos1[20];
int pos2[20];

//function for multiple “endl”s
void printendls(int n=1)
{
	for(int i=0; i<n; i++)
	{
		cout<<endl;
	}
}

//function for introduction lines
void lines()
{
	cout<<"Hello, I am Ritwick!";
	printendls();
	cout<<"Welcome to 'THE MIND READER'";
	printendls(23);
	cout<<"I am now going to read your mind!";
	printendls(2);
	cout<<"Please do the following steps:";
	printendls(3);
	cout<<"Now, Think of ANY Word!";
}

//function for step1 consisting of table1
void table1()
{
	cout<<"Step 1:";
	printendls(2);
	cout<<"Tabel 1:";
	printendls(2);
	cout<<"-----------";
	printendls();

	//loop to print column numbers of table1
	for(int i=0; i<5; i++)
	{
		cout<<i+1<<" ";
	}
	printendls();
	cout<<"-----------";

	//loop to create and print table1
	for(i=0; i<30; i++)
	{
		if(i%5==0)
		{
			printendls();
		}
		cout<<arr[i]<<" ";
	}
	printendls();
	cout<<"-----------";
}

//function for step2 consisting of table2
void table2(int no)
{
	cout<<"Step 2:";
	printendls(2);
	cout<<"Tabel 2:";
	printendls(2);
	cout<<"-----------";
	printendls();

	//loop to print column numbers of table2
	for(int i=0; i<6; i++)
	{
		cout<<i+1<<" ";
	}
	printendls();
	cout<<"-----------";

	//loop to create and print table2
	for(i=0; i<no; i++)
	{
		printendls();
		for(int j=pos1[i]; j<30; j= j + 5)
		{
			cout<<arr[j]<<" ";
		}
	}
	printendls();
	cout<<"-----------";
}

//function for the main game
void game()
{
	int i, no, j, z;
	char ch;
	clrscr();

	//calling of introduction lines function
	lines();
	printendls(2);
	cout<<"Enter total number of letters in the word: ";
	cin>>no;

	//loop to enter column number(s) from table1 of each letter of the word
	for(i=0; i<no; i++)
	{
		clrscr();

		//calling of table1 function
		table1();
		printendls(2);
		cout<<"Enter Letter "<<i+1<<"'s Coloumn number: ";
		cin>>pos1[i];
		pos1[i]=pos1[i]-1;
	}
	clrscr();

	//loop to enter column number(s) from table2 of each letter of the word
	for(i=0; i<no; i++)
	{
		clrscr();

		//calling of table2 function
		table2(no);
		printendls(2);
		cout<<"Enter Letter "<<i+1<<"'s Coloumn number: ";
		cin>>pos2[i];
		pos2[i]=pos2[i]-1;
	}
	clrscr();
	cout<<"Gottcha! ";
	printendls(2);
	cout<<"You Thought Of The Word: ";

	//loop for printing the word assumed
	for(i=0; i<no; i++)
	{
		cout<<arr[pos2[i]*5+pos1[i]];
	}
	printendls(2);
	cout<<"SURPRISED!";
	printendls(7);
}

//function to create array for alphabets
void createarray()
{
	char j='A';

	//loop to enter each alphabets into the array
	for(int i=0; i<26; i++)
	{
		arr[i]=j;
		j++;
	}
}

//main function
void main()
{
	char ch;
	createarray();
	do
	{
		//calling of game function
		game();

		//to repeat the program as per user's choice
		cout<<"Would you like to play again? (Y/N)...";
		cin>>ch;
		getch();
	} while(ch!='n'  && ch!='N');
	clrscr();

	//to end the game
	cout<<"Enter ESC to end the game...";
	while(getch()!=27);
}
