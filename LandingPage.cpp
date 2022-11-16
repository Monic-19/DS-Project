#include <iostream>
#include<conio.h>
#include<cstdlib>
#include<time.h>
#include<windows.h>
using namespace std;


 void Loading(){
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
 cout<<"\t\t\t\t\t\t\t   Loading ";


 char x=219;
 for(int i=0;i<35;i++){
 cout<<x;
 if(i<10)
        Sleep(100);
 if(i>=10 && i<20)
        Sleep(150);
 if(i>=10)
        Sleep(25);
 }
 system("CLS");

 }

//Nqueens
bool isSafe(int** arr,int x,int y,int n){
	for(int row=0;row<x;row++){
		if(arr[row][y]==1){
			return false;
		}
	}
	
	int row=x;
	int col=y;
	while(row>=0  && col>=0){
		if(arr[row][col]==1){
			return false;
		}
	row--;
	col--;
	}
	
	row=x;
	col=y;
		while(row>=0  && col<n){
		if(arr[row][col]==1){
			return false;
		}
	row--;
	col++;
	}
	
	return true;
}
int countnq=0;
bool nQueen( int** arr,int x,int n){
  
  if(x>=n){
  	return true;
  }	
  
  for(int col=0;col<n;col++){
  	if(isSafe(arr,x,col,n)){
  		arr[x][col]=1;
        countnq++;
       if(nQueen(arr,x+1,n)){
       	return true;
	   }
	   
	   arr[x][col]=0;
	   countnq--;
	}
  }
  return false;
}
void NQUEENS(){
	
	srand(time(0));
	int no=rand()%6;
	int ar[6]={4,5,6,7,8,9};
	int n=ar[no];
	cout<<"\n\n\n\t\t   IN this game you have to find an arrangement of N queens on a  "<<n<<" x "<<n<<" chess board, \n\t\t   such that no queen can attack any other queens on the board.\n\t\t   The chess queens can attack in any direction as horizontal, vertical, horizontal and diagonal way.\n\n";
	cout<<"\t\t   -----------------------------------------------------------------------------------------------------------------------------\n";	
	cout<<"\n\n\n";
	int valnq;
	cout<<"\t\t\t Enter your answer : ";
	cin>>valnq;
	cout<<"\n\n";
		
	int **arr=new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
		for(int j=0;j<n;j++){
		arr[i][j]=0;	
		}
	}
	
    if(nQueen(arr,0,n)){
		cout<<"\t\t\tYour Answer is : ";
		
	if(countnq==valnq){
		Sleep(400);
		cout<<" CORRECT ! \n";
		cout<<"\n\t\t\t\t\t\tYou are smart :) \n ";
	}
	else{
		Sleep(400);
		cout<<" INCORRECT ! \n";
		cout<<"\n \t\t\tThe correct answer was : "<<countnq;
		cout<<"\n \t\t\tBetter Luck Next Time  :( \n";
	}  
	  cout<<"\n\n\t\t\t Correct Sequence :\n\n\n";
	  cout<<"\t\t\t\t\t  ";
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(arr[i][j]==1)
				cout<<" Q ";
				else
				cout<<" _ ";
			}
			cout<<endl<<endl<<"\t\t\t\t\t  ";
   }
	
	}
	    
}


//Hangman


struct node {
  char data;
  struct node *next;
}*head, *temp, *newnode, *head2, *temp2;

struct node createhm(char s) {
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data=s;
  newnode->next=NULL;
  if (head == NULL)
    head=newnode;
  else
    temp->next = newnode;
  temp=newnode;
  return *newnode;
}

struct node createBlankLL(char s){
  newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data=s;
  newnode->next=NULL;
  if (head2 == NULL)
    head2=newnode;
  else
  	temp2->next = newnode;
  	temp2=newnode;
}

void printhm(struct node *p) {
  while (p != NULL) {
    cout<<p->data<<" ";
    p = p->next;
  }
}

void drawhm(int i){	

  if(i==4){
  	cout<<"\t\t    _____ \n";
  	cout<<"\t\t      |       \n";
  	cout<<"\t\t      0       \n";
  	cout<<"\t\t     /|\\     \n";
  	cout<<"\t\t     / \\     \n";
  }
  else if(i==3){
  	cout<<"\t\t    _____ \n";
  	cout<<"\t\t      |       \n";
  	cout<<"\t\t      0       \n";
  	cout<<"\t\t     /|\\     \n";
  }
    else if(i==2){
  	cout<<"\t\t    _____ \n";
  	cout<<"\t\t      |       \n";
  	cout<<"\t\t      0       \n";
  }
    else if(i==1){
  	cout<<"\t\t    _____ \n";
  	cout<<"\t\t      |       \n";
  }
    else if(i==0){
  	cout<<"\t\t    _____ \n";
  }
}


bool chkhm(struct node * p){
  bool a=false;
  while(p!=NULL){
  if(p->data==95)
  a=true;	
  p=p->next;
  }	
  return a;
}

void findhm(){
int tries=4;
char ch;
int a;
bool kval;
	
while(tries>0){
a=0;
temp=head;
temp2=head2;
cout<<"\n\n\t\t   In the game of Hangman, the computer chooses a word at random from a given list of words. \n";
cout<<"\t\t   This word is the answer. You have tries to guess the word, by guessing one letter at a time.\n";
cout<<"\t\t   Whenever the user guesses a letter that is in the answer, all occurrences of that letter are revealed to you.\n";
cout<<"\t\t   The game ends when the you have guessed every letter in the word, before you reach the allowed number of strikes\n\n";
cout<<"\t\t   HINT : It's a FRUIT \n";
cout<<"\t   -----------------------------------------------------------------------------------------------------------------------------\n";	
cout<<"\n\n";
cout<<"\t\t   Tries :  "<<tries;	
cout<<"\n\n\t\t   Word  : ";
printhm(head2);
cout<<endl<<endl;
drawhm(tries);
cout<<endl<<endl;
cout<<" \n\t\t   enter the letter : ";
cin>>ch;
system("cls");

 while(temp!=NULL){
	if(temp->data == ch){
	temp2->data=ch;
	a=1;
	}
	temp2=temp2->next;
    temp=temp->next;
 }
 
 
 kval=chkhm(head2);
 
 if(a==0)
 tries--;
 if(kval==false){
 	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t   YOU WIN \n \t\t\t\t\t\t\t\t\t   Amazing :) \n\n";
	cout<<"\t\t\t\t\t\t\t   The word was : " ;
    printhm(head);	
	break;
 }
 
  
}
if(tries==0){
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t   GAME OVER \n \t\t\t\t\t\t\t   Better Luck Next Time :( \n\n";
	cout<<"\t\t\t\t\t\t\t   The word was : " ;
    printhm(head);	
}

}


void HANGMAN(){	
    
    srand (time(0));
	string wordList[10] = {"apple","peach","banana","strawberry","mango","watermelon","kiwi","dates","orange","coconut"};
	string word;
	word = wordList[rand()%10];
	int wordLength = word.length();
	char guess;
	for(int i=0;i<wordLength;i++){
		createhm(word[i]);
		createBlankLL(95);
	}
	findhm();
}


int main()
{
    Sleep(2500);
    Loading();
    cout<<"    -------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"                                                                           WELCOME to GAMESPACE\n";
    cout<<"    -------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t    Select Games you want to play :  \n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t  (1) Sudoku Solver \n\n";
    cout<<"\t\t\t\t\t\t\t\t\t  (2) Rat in a maze \n\n";
    cout<<"\t\t\t\t\t\t\t\t\t  (3) N Queens \n\n";
    cout<<"\t\t\t\t\t\t\t\t\t  (4) Winner prediction \n\n";
    cout<<"\t\t\t\t\t\t\t\t\t  (5) Tic Tac Toe \n\n";
    cout<<"\t\t\t\t\t\t\t\t\t  (6) N Knights \n\n";
    cout<<"\t\t\t\t\t\t\t\t\t  (7) Hangman \n\n";
    cout<<"\n\n\n";
    
    
    int a ;
    cout<<"\t\t\t\t\t    Select the game you want to play : ";
    cin>>a;
    switch(a){
    case 1 :
          system("CLS");
          Loading();
          system("CLS");
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t\t\t\t\t\t Sudoku Solver";
          Sleep(900);
          system("CLS");
    break;

    case 2:
          system("CLS");
          Loading();
          system("CLS");
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t\t\t\t\t\t Rat in a maze";
          Sleep(900);
          system("CLS");

    break;

    case 3:
          system("CLS");
          Loading();
          system("CLS");
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t\t\t\t\t\t N Queens";
          Sleep(900);
          system("CLS");
          NQUEENS();

    break;

    case 4:
          system("CLS");
          Loading();
          system("CLS");
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t\t\t\t\t\t  Winner prediction";
          Sleep(900);
          system("CLS");

    break;

    case 5:
          system("CLS");
          Loading();
          system("CLS");
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t\t\t\t\t\t Tic Tac Toe ";
          Sleep(900);
          system("CLS");

    break;

    case 6:
          system("CLS");
          Loading();
          system("CLS");
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t\t\t\t\t\t N Knights ";
          Sleep(900);
          system("CLS");

    break;

    case 7:
          system("CLS");
          Loading();
          system("CLS");
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t\t\t\t\t\t Hangman ";
          Sleep(900);
          system("CLS");
          HANGMAN();

    break;

    default :
    cout<<"\t\t\t\t\t    Not a great choice TRY AGAIN \n";
    }

    getch();
    return 0;
}

