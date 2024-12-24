#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>


using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	int A = rand()%13+1;
	return A;
}

int calScore(int x,int y,int z){
	int sum = cardScores[x] + cardScores[y]+ cardScores[z]; 
    return sum%10; 
	
	 
}

int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1; 
	else{
		 int x = rand()%100+1;
		 if (x<=69)
		 {
			return 1;
		 }else return 2;
	}
}

void checkWinner(int p, int y){
	cout << "---------------------------------\n";
	if (p > y)
	{
		cout <<   "|         Player wins!!!        |\n"; 
	}
	else if(p==y)
	{
		cout <<   "|             Draw!!!           |\n"; 
	}
	else 
	{
		cout <<   "|          Yugi wins!!!         |\n";
	}
	cout << "---------------------------------\n";
}

int main(){	
    srand(time(0));  

	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0};
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],-1);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2);
	if(playerAction == 1)
	{
		playerCards[2] = drawCard(); 
        playerScore = calScore(playerCards[0], playerCards[1], playerCards[2]);
        cout << "Player draws the 3rd card!!!\n";
        cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
        cout << "Your new score: " << playerScore << "\n";
	}
	cout << "------------ Turn end -------------------\n\n";
	cout<<"---------YUGI'S TURN, DRAW!!!------------\n";
	cout<<"Yugi's cards: "<< cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],-1);
	cout<<"Yugi's score: "<< yugiScore<<endl;
	yugiAction = findYugiAction(yugiScore);
	if (yugiAction == 1)
	{
		cout<<"Yugi draws the 3rd card!!!\n";
		yugiCards[2] = drawCard();
		yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		cout<<"Yugi's 3rd card: "<<cardNames[yugiCards[2]]<<endl;
		cout<<"Yugi's new score: "<<yugiScore<<endl;
		cout<<"------------ Turn end -------------------"<<endl<<endl;

	}else if (yugiAction == 2){
		cout<<"------------ Turn end -------------------"<<endl<<endl;
	}
	checkWinner(playerScore,yugiScore);

	return (0);
	}