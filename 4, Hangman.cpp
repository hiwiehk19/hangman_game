#include <iostream>
#include<cstring>
#define MAX_TRIAL 10

using namespace std;

int main(){
	system("color B1");//background and text colour
struct player{
    char name[20];
    int wins;
    int loses;
};

player player_1={"",0,0};//initializing the struct variable
player player_2={"",0,0};
char word[100];//stores the entered word maximum of 100 character

int contin,temp2;
int clue; 
cout<<"-------------------------------------------Hangman Game v1.0------------------------------------\n";

cout<<"\n\t The Hangman Game is a game played with two players The first player Enters any word and  gives \n";
cout<<"\n\t some clues  to his  opponent then the second one guesses each and every characters of the word\n";
cout<<"+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\t\t you have 10 chances to gues the word:\n";
//read players name

cout<<"\nplayer-1 Enter your name =>";
    cin>>player_1.name;
cout<<"\nplayer-2 Enter your name =>";
   cin>>player_2.name;
 
   do{
   	
   	int correct=1;//count the frequency of the entered alphabet
   	int trial=0; //counts number of trials
   	char guess;    //stores the  guessed character
	char temp[20];
   	char word_table[]={"_______________"}; //holds the characters of the word and reveals the characters for correct guesses.
        
		system("CLS");
        cout<<"------------------------ Hangman Game ----------------------------";
        
        cout<<"\n\n\t\tRound "<<player_1.wins+player_1.loses+1;
    //list of catagories for the word to be entered
        cout<<"\n\n\tTHE WORD IS : ";
        cout<<"\n\n\t01. Name of a person";
		cout<<"\n\n\t02. Cities or towns in Ethiopia ";
		cout<<"\n\n\t03. Name of country in Africa";
		cout<<"\n\n\t04. Name of country in the world";
		cout<<"\n\n\t05. Name of an animal";
		cout<<"\n\n\t06. No clues";
		cout<<"\n\n\t"<<player_1.name<<" select Your Option (1-6)  => ";
        cin>>clue;   	
 a:

cout<<endl<<player_1.name<<" Enter word => "; //enter he word the word tha is ging to be guessed
cin>>word;
 
int word_length=strlen(word);
for(int i=0;i<word_length; i++){
	word[i]=tolower(word[i]);
}

for(int j=0;j<word_length;j++)
{

if(isalpha(word[j])==0){
cout<<"\n\t\tThe word can not contain number (must be aplhabet)!\n";
goto a;
}

system("CLS"); //Clears the screen and the word disapears
cout<<"\t\t\t Hangman Game v1.0\n";
cout<<"\t\t"<<player_1.name<<" vs "<<player_2.name<<"\t\t\tRound "<<player_1.wins+player_1.loses+1;

switch(clue){
	case 1:
	      cout<<"\n\n\t\t\tThe word is Name of a person ";
	      break;
	case 2:      
	      cout<<"\n\n\t\t\tThe word is City or town in Ethiopia ";
	      break;
	case 3:
	      cout<<"\n\n\t\t\tThe word is Name of country in Africa ";
	      break;
    case 4:
	      cout<<"\n\n\t\t\tThe word is Name of country in the world ";
	      break;
	case 5:
	      cout<<"\n\n\t\t\tThe word is Name of an animal ";
	      break;     
	default:
	      cout<<"\n\n\t\t\tNo clues ";	  	        
	
}

do{
	cout<<endl<<"\n\t\t"<<player_2.name<<" you have "<<MAX_TRIAL-trial<<" chances to guess the word:";

cout<<"\n\nGuess the word: ";
cin>>guess;
guess=tolower(guess);

for(int i=0;i<word_length;i++)
{
      if(word[i]==guess)
    {

	    word_table[i]=word[i];
	    correct++;
     
    }
    else
    word_table[i]=word_table[i];
}


cout<<"\t\t";
if(correct>1)
	trial;
else 
  trial++;
correct=1;

for(int i=0;i<word_length;i++)
{
 cout<<word_table[i]<<" ";
 }

if(strcmp(word,word_table)!=1)
{

  cout<<endl<<"\n\t\t "<<player_2.name<<"   you won the game\n";
  player_2.wins+=1;
  player_1.loses+=1;
  break;  
  
}
if(trial==10){
  cout<<endl<<endl<<"The word is "<<word;
	cout<<endl<<"\n\t\t "<<player_1.name<<"   you won the game\n";
  player_1.wins+=1;
  player_2.loses+=1;
  break; 
}


}while(MAX_TRIAL>trial);

    cout<<"\t\t THE FINAL RESULT \n"<<endl;
    cout<<" Name \tWins \tLoses \n";
    cout<<player_1.name<<"\t"<<player_1.wins<<"\t "<<player_1.loses<<"\n";
    cout<<player_2.name<<"\t"<<player_2.wins<<"\t "<<player_2.loses<<"\n";
    cout<<"\t\t\ttotal plays= "<<player_1.wins+player_1.loses;
   
   
   	
break;

}
strcpy(temp,player_1.name);
    strcpy(player_1.name,player_2.name);
   	strcpy(player_2.name,temp);
   	
	   temp2=player_1.loses;
   	player_1.loses=player_2.loses;
   	player_2.loses=temp2;
   	
	   temp2=player_1.wins;
   	player_1.wins=player_2.wins;
   	player_2.wins=temp2;
   	cout<<"\nEnter 0 to continue and other umber to leave \n";
   
  	cin>>contin;
  	system("CLS");
  	cout<<"\t\t\t Hangman Game v1.0\n";
  	
}while(contin==0);
return 0;
}
