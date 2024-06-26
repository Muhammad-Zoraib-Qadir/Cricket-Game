
#include<iostream>                          //Input, Output
#include<fstream>                          //Use for file handling
#include <stdlib.h>                       //Rand and Srand
#include<string>                           //For String
#include <ctime>                            //For Time
#include <iomanip>                           //To use setw
#include<conio.h>                               //console input output header file

using namespace std;

//Function Definations
void scoreboard(string team1[],string team2[],int overs,int	runst2[],int	ballst2[],int	runsg1[],int wicket1[],int sixt2[],int fourt2[],float RunR2[], int widet1[],	int noballt1[],int overnot1[], float economyt1[],int turn,int runst1[]); // Start of the scoreboard if team1 wins the toss
void scoreboard1(string team2[],string team1[],int overs,int	runst1[],int	ballst1[],int	runsg2[],int wicket2[],int sixt1[],int fourt1[],float RunR1[11],int widet2[],int noballt2[],int overnot2[], float economyt2[],int turn ,int runst2[]); // Start of the scoreboard if team2 wins the toss
void summary1(string team1[], string team2[], int overs, int	runst1[], int	ballst1[], int	runsg2[], int wicket2[], int sixt1[], int fourt1[], float RunR1[],int l,int widet2[],int noballt2[], float economyt2[],int overnot2[]); //Summary while Team#1 wins the match
void summary2(string team1[], string team2[], int overs, int	runst2[], int	ballst2[], int	runsg1[], int wicket1[], int sixt2[], int fourt2[], float RunR2[],int l,int widet1[],int noballt1[], float economyt1[],int overnot1[]); //Summary while Team#2 wins the match
int totalscoret1(int l,int runst1[]); //Total Score of Team#1
int totalscoret2(int l, int runst2[]); //Total Score of Team#2
float runratet1(int c , int ov); //RunRate for Team#1
float runratet2(int c , int ov); //Runrate for Team#2
int totalwickets(int wickets);    //Total Number of Wickets
int numberofovers(int ov );         //Total Number of Overs
int targetT1(int total);     //Target for Team#2
int targetT2(int total2);     //Target for Team#1
void mainbatsman(int runst1[],int runst2[],string team1[],string team2[]);//MAIN BATSMAN
void mainbowler(int wicket1[],int wicket2[],string team1[],string team2[]); //MAIN BOWLER    
void result (int runst1[], int runst2[], int l,string t1, string t2); //WINNER OF THE MATCH

int main()
{ 

//Array Declaration for first team 1
string t1;
string team1[11];      //Array for first team
	int runst1[11] = { 0 };                  // Runs for first team
	int ballst1[11] = { 0 };                               // ball faced for first team
	int ballbowl1[11] = { 0 };										// ball bowled for first team --For Bowlers
	int runsg1[11] = { 0 };                      // Runs given for first team --For Bowlers
	int wicket1[11] = { 0 };               //Wickets taken for first team --For Bowlers
	int sixt1[11] = { 0 };               //Number of sixes for a player if Team1
	int fourt1[11] = { 0 };                     //Number of sixes for a player if Team1
	float RunR1[11] = { 0 };                    //Strike Rate for player 2
	int widet1[11]= { 0 };
	int noballt1[11] = { 0 };
    int overnot1[11] =  { 0 };
    float economyt1[11] = {0};
//Array Declaration for team 2
string t2;
string team2[11];	                //Array for second team
	int runst2[11] = { 0 };                  // Runs for second team
	int ballst2[11] = { 0 };                               // ball faced for second team
	int ballbowl2[11] = { 0 };									// ball bowled for second team --For Bowlers
	int runsg2[11] = { 0 };                      // Runs given for second team --For Bowlers
	int wicket2[11] = { 0 };                           //Wickets taken for first team --For Bowlers
	int sixt2[11] = { 0 };                           //Number of sixes for player2
	int fourt2[11] = { 0 };                         //Number of fours for player2
	float RunR2[11] = { 0 };                      //Strike Rate for Player2
   	int widet2[11]= { 0 };
	int noballt2[11] = { 0 };
    int overnot2[11] = {  0  };
     float economyt2[11] = {0};
   //Random number generator     
srand(time(0));                    


//For Overs
int overs=0;                                  //Declaration of number of overs                         
overs =  rand( )%14+1;             //Generation of a random value 0 to 100   
int limit_over= overs/5;                   //Limit of the overs for the bowler.      

//For Toss
int toss=0;                   //Declaration for variable for the toss
int opn=0;
int call=0;                          //To Enter your descision to choose head or tales
toss=(rand()%2)+0;          //Random value generation either "zero" or "1".
//For Target
int turn = 0;


//***ScoreBoard***         First Phase **Team Name, Player Names, Toss
//-------------------------------------------------------------------------------------------
cout<<"Welcome"<<endl;                             //Welcoming statements
cout<<"Let's Start the Match"<<endl;                  //Starting Statements 
cout<<endl;                                           //New Line
//----------------------------Name of team
t1="Pakistani Legends";                 //First Team Name
t2="Hustlers ";                        //Second Team Name


//Names of the Team#1<>
int i=0;  
team1[i]="Babar Azam";                   //Player names            
team1[i+1]="M.Rizwan";               //Player names           
team1[i+2]="Shohaib Malik";               //Player names                       
team1[i+3]="Ramiz Raja";                    //Player names
team1[i+4]="Shahid Afridi"; 					//Player names
team1[i+5]="Imran Khan";                      //Player names
team1[i+6]="Saleem Malik";                //Player names
team1[i+7]="M.Hafeez";                   //Player names
team1[i+8]="Waseem Akram";                  //Player names
team1[i+9]="Shohaib Akthar";                       //Player names
team1[i+10]="Saeed Ajmal";                 //Player names


//Names of the Team#2<>
i=0;
team2[i]="Zoraib Qadir";                   //Player names            
team2[i+1]="Musa Yaseen";               //Player names           
team2[i+2]="Meeran Malik";               //Player names                       
team2[i+3]="Ahmed Kamran";                    //Player names
team2[i+4]="Abdul Rehman"; 					//Player names
team2[i+5]="Moeez Khan";                      //Player names
team2[i+6]="Ramish Shakeel";                //Player names
team2[i+7]="Shaheer Haq";                   //Player names
team2[i+8]="Shaheer Sheikh";                  //Player names
team2[i+9]="Haroon Boundary";                       //Player names
team2[i+10]="Balaj Shakell";                 //Player names
//cout statements for the teams         **Table Formation
//If you want to enter your team member names by yourself then uncomment the code


/*cout<<setw(5)<<"Players of " <<t1<<" Team."<<setw(35)<<"Players of "<<t2<<" Team."<<endl;       //For Table formation for the names of players
for(int i=0; i<11;i++)
{
	cout<<setw(5)<<i+1<<". "<<team1[i]<<" "<<setw(30)<<i+1<<". "<<team2[i]<<endl;                       //Display of the table of the names of the players
}
*/
//..............

//Toss Call
cout<<endl;                  //For New Line
cout<<endl;                       //For New Line
cout<<"Ok,Let's begin!"<<endl;            //START STATEMENT
cout<<"Head or Tail"<<endl;         //coin sides
cout<<"Both captains have choose their sides."<<endl;               //Cout statements to tell the user enter the number
call = rand()%2+0;;                                                     //Input of the values
if(call==toss)                       //Check Statement for toss
{
	cout<<"Team "<< t1<<" has won the toss."<<endl;         //Declaration of the result
	cout<<"Team "<<t1<<" will Bat first."<<endl;       //output of the statement
  
}


else                                    //If condition is wrong
{
		cout<<"Team  "<< t2<<" has won the toss."<<endl;         //Declaration of the result   
		cout<<"Team "<<t2<<" will Bat first."<<endl;       //output of the statement
}
cout<<endl;
//------------------------------------------------------------------------------------

//For Number of overs
char ch;           //To read from the file
ofstream write;
write.open("configuration.txt",ios::out);  //Opening the file and giving command to have input
write<<overs; 
write.close();                        //File contains number a random number from 1-100
ifstream take;
take.open("configuration.txt",ios::in); 
cout<<"The match will be of  ";
while(take.eof()==0)
{
	ch=take.get();
	cout<<ch;
}
cout<<" overs."<<endl;      //The Number of overs in the match
take.close();
cout<<endl;
//====================
//Total Score
int scores = 0;                     //Declaration of the variable of the scores
//Number of Balls
int balls=1;	      //For the number of balls
//Number of overs
int Tballs = overs * 6 ;
int v= overs/5;
//First Layout Design
if(call==toss)            //If first team wins the toss
{                    //First displaying code for the batsman and bowler
	scoreboard1( team2, team1, overs,runst1,ballst1,runsg2, wicket2,sixt1, fourt1, RunR1, widet2,noballt2, overnot2, economyt2,turn,runst2 );      //ScoreCard for the compelete Innings    
    cout<<"Now Lets start the second innings."<<endl;
    cout<<"Press Enter to Start Second Inning."<<endl;
    cin.ignore();
    system("CLS");
    cout<<"Starting Second Innings"<<endl;
    turn = 2;
     cin.ignore();
    system("CLS");
    scoreboard(team1, team2, overs,runst2,ballst2,runsg1,wicket1,sixt2,fourt2, RunR2,widet1,noballt1,overnot1,economyt1,turn,runst1);      //ScoreCard for the compelete Innings
    cin.ignore();
    system("CLS");
      cout<<"Result"<<endl;
      result ( runst1, runst2,  11, t1, t2);
     mainbowler(wicket1, wicket2, team1, team2);
     mainbatsman(runst1,runst2, team1, team2);
	   cin.ignore();
    system("CLS");
    cout<<"Summary"<<endl;
    cout<<"1. For First  Innings Summary"<<endl;
    cout<<"2. For Second Innings Summary"<<endl;
    cout<<"3. For Match   Innings Summary"<<endl;
    int choice;
    cout<<"Enter Your Choice"<<endl;
    cin>>choice;
    
    switch (choice)
    {
    	//FIRST INNINGS
    	case 1 : summary1( team1, team2,  overs, 	runst1,	ballst1, runsg2,  wicket2,  sixt1, fourt1,  RunR1,9,widet2,noballt2,economyt2,overnot2);
    	break;
    	case 2 : 
    	//SECOND INNINGS
			summary2(team1, team2,  overs, runst2, 	ballst2, runsg1, wicket1, sixt2,  fourt2,RunR2, 9,widet1, noballt1,  economyt1,overnot1);
    		break;
    	case 3 :
    		summary1( team1, team2,  overs, 	runst1,	ballst1, runsg2,  wicket2,  sixt1, fourt1,  RunR1,9,widet2,noballt2,economyt2,overnot2);
    		cout<<"Second Innings"<<endl;
    		summary2(team1, team2,  overs, runst2, 	ballst2, runsg1, wicket1, sixt2,  fourt2,RunR2, 9,widet1, noballt1,  economyt1,overnot1);
    		break;
	}
	
}
else         //If team1 wins the toss
{                             //Displaying code for the batsman and bowlers
   scoreboard(team1, team2, overs,runst2,ballst2,runsg1,wicket1,sixt2,fourt2, RunR2,widet1,noballt1,overnot1,economyt1,turn,runst1);      //ScoreCard for the compelete Innings
	cout<<"Now Lets start the second innings."<<endl;
    cout<<"Press Enter to Start Second Inning."<<endl;
    cin.ignore();
    system("CLS");
    cout<<"Starting Second Innings"<<endl;
    turn = 2;
     cin.ignore();
    system("CLS");
   
    scoreboard1( team2, team1, overs,runst1,ballst1,runsg2, wicket2,sixt1, fourt1, RunR1, widet2,noballt2, overnot2, economyt2,turn,runst2);    //ScoreCard for the compelete Innings
    cin.ignore();
    system("CLS");
     cout<<"Result"<<endl;
       result ( runst1, runst2,  11, t1, t2);
    mainbowler(wicket1, wicket2, team1, team2);
    mainbatsman(runst1,runst2, team1, team2);
	   cin.ignore();
    system("CLS");
    cout<<"Summary"<<endl;
    cout<<"1. For First  Innings Summary"<<endl;
    cout<<"2. For Second Innings Summary"<<endl;
    cout<<"3. For Match   Innings Summary"<<endl;
    int choice;
    cout<<"Enter Your Choice"<<endl;
    cin>>choice;
    
    switch (choice)
    {
    	//FIRST INNINGS
    	case 1 : summary2(team1, team2,  overs, runst2, 	ballst2, runsg1, wicket1, sixt2,  fourt2,RunR2, 9,widet1, noballt1,  economyt1,overnot1);
    	break;
    	case 2 : 
    	//SECOND INNINGS
			summary1( team1, team2,  overs, 	runst1,	ballst1, runsg2,  wicket2,  sixt1, fourt1,  RunR1,9,widet2,noballt2,economyt2,overnot2);
    		break;
    	case 3 :
    			summary2(team1, team2,  overs, runst2, 	ballst2, runsg1, wicket1, sixt2,  fourt2,RunR2, 9,widet1, noballt1,  economyt1,overnot1);
    		cout<<"Second Innings"<<endl;
    		summary1( team1, team2,  overs, 	runst1,	ballst1, runsg2,  wicket2,  sixt1, fourt1,  RunR1,9,widet2,noballt2,economyt2,overnot2);
    		break;
	}
	
}

//*******************************************************************************************************************************
return 0;
}
	
	

//ScoreBoard for Live Match Card
void scoreboard(string team1[],string team2[],int overs,int	runst2[],int	ballst2[],int	runsg1[],int wicket1[],int sixt2[],int fourt2[],float RunR2[], int widet1[],	int noballt1[],int overnot1[], float economyt1[],int turn,int runst1[])//If  Team2 wins the toss
{
	

		int ov=1;            //Number of overs       // Limit for each bowler
	int limit2=0;        //Limit for total number of overs
	int x=0;             //Integer for total score
	int s=0;            //Number of sixes
	int f=0;               //Number of fours
	int t_ball=1;           //Total number of balls faced by the batsman
	int h=0; 
	int extras = 0;        
	int l;
	int wickets = 0;
	int check = 1;          
  	double remaining = 1;       //REMAINING SCORE IN FOR WINNING

for (int i=10,y=0;i>5,y<11;i--)       //Loop FOR NUMBER OF BATSMAN AND NUMBER OF BOWLER
{
while(ov<=overs&&limit2<10)         //Conditon that task should not be performed when number of wickets or overs exclude
{
		l = y;
int overcompelete = numberofovers( ov) ;
if(overcompelete != 0)
{
	cout<<"Number of over compeleted : "<<overcompelete<<endl;  //NUMBER OF OVERS COMPELETED
}
if(overcompelete == 5 )
{
	i = 10;               //REPEAT OF BOWLERS AFTER EVERY 5 PLAYERS
}

	cout<<"Start of Over #"<<ov<<" : "<<endl;
int	balls=1;                    //No of Balls in an over
int	scores=0;                    //Score  per ball
int	t=0;                 //Total Score given by the player     
overnot1[i] = overnot1[i] + 1;  //NUMBER OF THE OVERS OF THE PLAYERS
                   

float r=0;
	while(balls<7)
	{
	
			
			scores = (rand() % 9) - 1;           //Random value generation of the score
			if(y<5)
			{
				if((scores == -1)&&(check<4))
				{
				scores = scores + 3;
				check++;	
				}
			}
			if(scores==7)
				{
					scores = 1;
					widet1[i] = widet1[i] + 1;
					extras++;             //WIDE
					balls--;
				}
				if(scores==8)
				{
					scores=1;
					noballt1[i] = noballt1[i] + 1;    //NO BALL
					extras++;
					balls--;
				}
	if(scores==-1)              //Condition for out
	{

	wicket1[i] =    wicket1[i] + 1; 
	wickets++;         //number of wickets
			cout<<team2[y]<<" is out"<<endl;        //Name of out Batsman
		cout<<endl;
		scores=0;
			cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Batsman Name"<<"\t\tTotal Runs "<<"\tBall Faced"<<"\tSix"<<"\tFour"<<"\tStrike Rate"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<team2[y]<<"\t\t "<<runst2[y]<<"\t\t "<<	ballst2[y]<<"\t\t"<<s<<"\t"<<f<<"\t"<<r<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<endl;
	cout<<"Number of wicket :"<<wickets<<endl;
	cin.ignore();
	system("CLS");
		
		y++;                   //Intalizing different variables equal to zero so it can calculate values again from the start
		limit2++;
		x=0;
		f=0;
		s=0;
		t_ball=1;
		
		check = 1;
		
	}
	
	                  //Total Score
	runsg1[i] =	scores + runsg1[i];  
	economyt1[i] = ( static_cast < float >(runsg1[i]))/(static_cast < float >(overnot1[i])); 
	
	//Table Formation
				cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout << "Bowler Name\t" << "  No of Balls\t" << "Runs\t" << "Total Runs\t" << "Wickets\t" << "   Wide\t   " << "No Ball  "<<"\tNo of Over"<<endl;
			cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout << team1[i] << "\t\t" << balls << "\t " << scores << "\t  " << runsg1[i] << "\t\t  " << wicket1[i] << "\t   "<<widet1[i]<<"\t     "<<noballt1[i]<<"\t\t  "<<overnot1[i]<<endl;
					cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;


	cout<<endl;
	cout<<"\t\t\t\t\t\tFor Batsman"<<endl<<endl;		
	runst2[y] = runst2[y] + scores;
	if(scores==6)
	{
		s++;                  //Number of Sixes
		sixt2[y]=s; 
	}
	if(scores==4)
	{
		f++;               //Number of fours
		fourt2[y] = f;
	}
	x = runst2[y];                 //Addition  of the scores
		ballst2[y] = ballst2[y] + 1;
	r= ( static_cast < float >(x))/(static_cast < float >(t_ball))*100;  //Strike Rate
	RunR2[y] = r;
	//Table Formation
	cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Batsman Name"<<"\t\t"<<"Runs"<<"\t\tTotal Runs "<<"\tBall Faced"<<"\tSix"<<"\tFour"<<"\tStrike Rate"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<team2[y]<<"\t\t"<<scores <<"\t\t "<<runst2[y]<<"\t\t "<<	ballst2[y]<<"\t\t"<<s<<"\t"<<f<<"\t"<<r<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<endl;
	
	cout<<"Total Score of Hustler : ";
		int c =	totalscoret2( l,runst2);
		cout<<c<<endl;
		if(extras!=0)
		{
			cout<<"Extra = "<<extras<<endl;
		}
		
		float cc = runratet2( c , ov);
		cout<<"Run Rate Of Hustlers : ";
		cout<<cc<<endl;
		int w = totalwickets( wickets );
				if(w!=0)
		{
		cout<<"Total Number of Wickets : "<<w<<endl;
	}
		if (turn == 2)
	{
	
		 
		 remaining = totalscoret1( 11,runst1)+1 - totalscoret2( l,runst2);
		 if(remaining>0)
		 {
		 
		cout<<"Remaining Score is : "<<remaining<<endl;
	
}

		int rovers = overs - ov;
		int rr = remaining / rovers;
		if(rr>0&&remaining>0)
		{
		
		cout<<"Recquired Run Rate = "<<rr<<endl;
	}
	
}
	
	
	   cin.ignore();
	system("CLS");         //To clear the screen
	//CHANGE OF THE SECORES AFTER EVERY ODD NUMBERS
			if ((scores == 1) || (scores == 3) || (scores == 5) || (balls == 6))
					{
						if (h % 2 == 0)
						{
							y = y + 1;
							h++;
						}
						else	if (h % 2 == 1)
						{
							y = y - 1;
							h++;
						}


					}
					
	balls++;
	t_ball++;

}


	ov++;      //Incremant in the number of overs
	i--;
}
cout<<endl;
cout<<endl;
cout<<endl;

	//TOTAL SCORE
	cout<<"Total Score of Hustler : ";
		int c =	totalscoret2( l,runst2);
		int total2= c;
		cout<<total2<<endl;
		if(extras!=0)
		{
			cout<<"Extra = "<<extras<<endl;
		}
		//RUN RATE OF THE TEAM
		float cc = runratet2( c , ov);
		cout<<"Run Rate Of Hustlers : ";
		cout<<cc<<endl;
		//TOTAL WICKETS OF THE TEAM
		int w = totalwickets( wickets );
		cout<<"Total Number of Wickets : "<<w<<endl;
		int overcompelete = numberofovers( ov) ;
	
		if(overcompelete != 0)
		{
	//NUMBER OF OVERS COMPELETED
	cout<<"Number of over compeleted : "<<overcompelete<<endl;
	
		}
		//SUMMARY DISPLAY
	summary2(team1, team2,  overs, runst2, 	ballst2, runsg1, wicket1, sixt2,  fourt2,RunR2, l,widet1, noballt1,  economyt1,overnot1);

//FOR THE TARGET DISPLAY FOR THE SECOND TEAM
if(turn < 2)
	{
	
	int target = targetT2(total2);
	cout<<"Recquired Target is : "<<target<<" runs."<<endl;
}
	y = 15;
	i=3;
}
}


//ScoreBoard of Live Match Card
void scoreboard1(string team2[],string team1[],int overs,int	runst1[],int	ballst1[],int	runsg2[],int wicket2[],int sixt1[],int fourt1[],float RunR1[11],int widet2[],int noballt2[],int overnot2[], float economyt2[],int turn,int runst2[]) //If  Team1 wins the toss
{
		int ov=1;          //Number of overs
	        // Limit for each bowler
	int limit2=0;              //Limit for total number of overs
	int x=0;                   //Integer for total score
	int s=0;                   //Number of sixes
	int f=0;                    //Number of fours
	int t_ball=1;               //Total number of balls faced by the batsman
	int h=0;
	int extras = 0;
	int l = 0;
	int wickets = 0;
	int check = 1;
    double remaining = 1;
for (int i=10,y=0;i>=5,y<11;)    //Loop FOR NUMBER OF BATSMAN AND NUMBER OF BOWLER
{
	
while(ov<=overs&&limit2<10)         //Conditon that task should not be performed when number of wickets or overs exclude
{
int overcompelete = numberofovers( ov) ;
if(overcompelete != 0)
{
	cout<<"Number of over compeleted : "<<overcompelete<<endl;       //OVERS COMPELETED
}
if(overcompelete == 5 )
{              //REPEAT OF THE BOWLERS AFTER EVERY FIVE OVERS
	i = 10;
}

	cout<<"No of Over = "<<ov<<endl;
int	balls=1;               //No of Balls in an over
int	scores=0;                    //Score  per ball
overnot2[i] = overnot2[i] + 1;
float r=0;
	while(balls<7)                //To compelete the over
	{
			l = y;	
	scores =(rand()%9) - 1;           //Random value generation of the score
    if(y<5)
			{
				if((scores == -1)&&(check<4))
				{
				scores = scores + 7;        //PROBALITY TEST
				check++;	
				}
			}
	if(scores==7)
				{
					scores = 1;
					widet2[i] = widet2[i] + 1;    //WIDE
					extras++;
				}
				
				if(scores==8)
				{
					scores=1;
					noballt2[i] = noballt2[i] + 1;  //NO BALL
					extras++;
				}
				
	if(scores==-1)                  //Condition for out
	{

		wicket2[i] =   	wicket2[i] + 1;        //number of wickets
			cout<<team1[y]<<" is out"<<endl;   //Name of the Batsman
		cout<<endl;
		wickets++;
				scores=0;
				//TABLE DISPLAY WHEN PLAYER GETS OUT
			cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Batsman Name"<<"\t\tTotal Runs "<<"\tBall Faced"<<"\tSix"<<"\tFour"<<"\tStrike Rate"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<team1[y]<<"\t\t "<<runst1[y]<<"\t\t "<<	ballst1[y]<<"\t\t"<<s<<"\t"<<f<<"\t"<<r<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<endl;
		cout<<"Number of Wicket : "<<wickets<<endl;
		cin.ignore();
		system("CLS");

		y++;
		x=0;                    //Intalizing different variables equal to zero so it can calculate values again from the start
		f=0;
		s=0;
		t_ball=1;
		
		check = 1;
	}
	
	runsg2[i] = runsg2[i] + scores;            //Total Score     //Storing value in an array   
	economyt2[i] = ( static_cast < float >(runsg2[i]))/(static_cast < float >(overnot2[i]));
	//Table Formation
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "Bowler Name\t" << "  No of Balls\t" << "Runs\t" << "Total Runs\t" << "Wickets\t" << "   Wide\t   " << "No Ball  "<<"\tNo of Over"<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;

	cout << team2[i] << "\t\t" << balls << "\t " << scores << "\t  " << runsg2[i] << "\t\t  " << wicket2[i] << "\t   "<<widet2[i]<<"\t     "<<noballt2[i]<<"\t\t  "<<overnot2[i]<<endl;
				cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<endl;
	cout<<"\t\t\t\t\t\tFor Batsman"<<endl<<endl;		
		runst1[y] = runst1[y] + scores;
	if(scores==6)
	{
		s++;              //Number of Sixes
		sixt1[y] = s;
	}
	if(scores==4)
	{
		f++;                   //Number of Fours
		fourt1[y] = f;
	}
	x = runst1[y];                //Addition  of the scores
		ballst1[y] = ballst1[y] + 1;
		
	//STRIKE RATE FOR EACH PLAYERS				
	r= ( static_cast < float >(x))/(static_cast < float >(t_ball))*100;      //Strike Rate
	RunR1[y] = r;
	//Table Formation
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Batsman Name"<<"\t\t"<<"Runs"<<"\t\tTotal Runs "<<"\tBall Faced"<<"\tSix"<<"\tFour"<<"\tStrike Rate"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<team1[y]<<"\t\t"<<scores <<"\t\t "<<runst1[y]<<"\t\t "<<	ballst1[y]<<"\t\t"<<s<<"\t"<<f<<"\t"<<r<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<endl;
		cout<<"Total Score of Pakistani : ";
		int c =	totalscoret1( l,runst1);
		int total = c;
		cout<<total<<endl;
		if(extras!=0)
		{
			cout<<"Extra = "<<extras<<endl;
		}
		
		float cc = runratet1( c , ov);
		cout<<"Run Rate Of Pakistnai : ";
		cout<<cc<<endl;
		int w = totalwickets( wickets);
		if(w!=0)
		{
		cout<<"Total Number of Wickets : "<<w<<endl;
	}
			if (turn == 2)
	{
	
	    //REAMINING SCORE 
			remaining =  totalscoret2( 11,runst2)+1-totalscoret1( l,runst1) ;
			int rovers = overs - ov;
		int rr = remaining / rovers;
		if(remaining>0)
		{
		
		cout<<"Remaining Score is : "<<remaining<<endl;
	}
	if(rr>0&&remaining>0)
	{
	
		cout<<"Recquired Run Rate = "<<rr<<endl;
	}
}
	

	
	
	   cin.ignore();
	system("CLS");         //To clear the screen

			if ((scores == 1) || (scores == 3) || (scores == 5) || (balls == 6))
					{
						if (h % 2 == 0)
						{
							y = y + 1;
							h++;
						}
						else	if (h % 2 == 1)
						{
							y = y - 1;
							h++;
						}


					}
	//INCREASE IN NUMBER OF BALLS				
								
	balls++;
	t_ball++;

}
//INCREMENT IN NUMBER OF OVER
	ov++;
	i--;
	
}
cout<<endl;
cout<<endl;
cout<<endl;
//TOTAL SCORE OF PAKISTAN
		cout<<"Total Score of Pakistani : ";
		int c =	totalscoret1( l,runst1);
		int total  = c;
		cout<<total<<endl;
		if(extras!=0)
		{
			cout<<"Extra = "<<extras<<endl;
		}
		//RUNRATE OF PAKISTAN
		float cc = runratet1( c , ov);
		cout<<"Run Rate Of Pakistnai : ";
		cout<<cc<<endl;
			int w = totalwickets( wickets);
			if(w!=0)
		{
		cout<<"Total Number of Wickets : "<<w<<endl;
	}
	//NUMBER OF OVER
	int overcompelete = numberofovers( ov) ;
if(overcompelete != 0)
{
	cout<<"Number of over compeleted : "<<overcompelete<<endl;
	
}
if(turn < 2)
//TARGET FOR THE SECOND TEAM
	{
int target = targetT1(total);
cout<<"Recquired Target is : "<<target<<" runs."<<endl;
}

summary1( team1, team2,  overs, 	runst1,	ballst1, runsg2,  wicket2,  sixt1, fourt1,  RunR1,l,widet2,noballt2,economyt2,overnot2);
	y = 15;
	i=3;


}
}

//Summary for teams while Team#2 wins the toss
void summary2(string team1[], string team2[], int v, int	runst2[], int	ballst2[], int	runsg1[], int wicket1[], int sixt2[], int fourt2[], float RunR2[],int l,int widet1[],int noballt1[], float economyt1[],int overnot1[])
{
		cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<"Summary of Innnings"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Batting Summary : "<<endl;
	cout << "Batsman Name" << "\t\t" << "\t\tTotal Runs " << "\tBall Faced" << "\tSix" << "\tFour" << "\tStrike Rate" << endl;
	for(int y=0; y<=l+1; y++)
	{
		cout << team2[y]  << "\t\t\t\t " << runst2[y] << "\t\t " << ballst2[y] << "\t\t" << sixt2[y] << "\t" << fourt2[y] << "\t" << RunR2[y] << endl;
	}
		cout<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	if(l<9){

	cout<<"Batsman who didnot play : "<<endl;
	for(int i = (l+2); i<11; i++)
	{
		cout<<team2[i]<<endl;
	}
}

//BOWLING SUMMARY
	cout<<endl;
	cout<<endl;
		cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<"Bowling Summary"<<endl;
	cout << "Bowler Name" << "\t\t" << "\t\t Overs" << "\t\tRuns Given" << "\tWides" << "\tNo" << "\tEconony" <<"\t  Wickets" <<endl;
	for (int y=10; y>5;y--)
	{
	cout << team1[y]  << "\t\t\t\t " << overnot1[y] << "\t\t " << runsg1[y] << "\t\t" << widet1[y] << "\t" << noballt1[y] << "\t" << economyt1[y]<<"\t   "<<wicket1[y]<< endl;	
	}
		cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl;
	cout<<endl;
}
//Summmary for Teams While Team#1 Wins the toss
void summary1(string team1[], string team2[], int v, int	runst1[], int	ballst1[], int	runsg2[], int wicket2[], int sixt1[], int fourt1[], float RunR1[],int l,int widet2[],int noballt2[], float economyt2[],int overnot2[])
{
		cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<"Summary of Innnings"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Batting Summary : "<<endl;
	cout << "Batsman Name" << "\t\t" << "\t\tTotal Runs " << "\tBall Faced" << "\tSix" << "\tFour" << "\tStrike Rate" << endl;
	for(int y=0; y<=l+1; y++)
	{
		cout << team1[y]  << "\t\t\t\t " << runst1[y] << "\t\t " << ballst1[y] << "\t\t" << sixt1[y] << "\t" << fourt1[y] << "\t" << RunR1[y] << endl;
	}
	cout<<endl;
	//PLAYERS WHO DID NOT PLAY
	if(l<9)
	
	{
		cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<"Batsman who didnot play : "<<endl;
	for(int i = (l+2); i<11; i++)
	{
		cout<<team1[i]<<endl;
	}
}
//Bowling Summary
	cout<<endl;
	cout<<endl;
		cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;

	cout<<"Bowling Summary"<<endl;
	cout << "Bowler Name" << "\t\t" << "\t\t Overs" << "\t\tRuns Given" << "\tWides" << "\tNo" << "\tEconony" <<"\t  Wickets"<< endl;
	for (int y=10; y>5;y--)
	{
	cout << team2[y]  << "\t\t\t\t " << overnot2[y] << "\t\t " << runsg2[y] << "\t\t" << widet2[y] << "\t" << noballt2[y] << "\t" << economyt2[y]<<"\t   "<<wicket2[y] <<endl;	
	}
	cout<<"--------------------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<endl;
	cout<<endl;
}

//Runrate for Team#2
float runratet2(int c , int ov)
{
	int rr = (static_cast <float>(c)) / (static_cast <float>(ov)) ;
	return rr;
}
//Runrate for Team#1
float runratet1(int c , int ov)
{
	int rr = (static_cast <float>(c)) / (static_cast <float>(ov)) ;
	return rr;
}

//Total Score of Team#1
int totalscoret1(int l, int runst1[])
{
	int total = 0;
	
	for(int i=0; i<=11; i++)
	{
		 total += runst1[i];
	}
	
return total;
}
//Total Score of Team#2
int totalscoret2(int l, int runst2[])
{
	int total = 0;
	
	for(int i=0; i<=11; i++)
	{
		 total += runst2[i];
	}
	
return total;
}
//Total Number of Wickets
int totalwickets(int wickets)
{
	int wicket =  wickets;
	return wicket;
}
//Number of Overs
int numberofovers(int ov)
{
	int overs = ov - 1;
	return overs;
}
//Target for Team#1
int targetT1(int total)
{
int target1 = total + 1;
return target1;	
}
//Target for Team#2
int targetT2(int total2)
{
	int target2 = total2 + 1;                
return target2;	
}
//Main Batsman of the Match



//Result  for winner of the match
void result (int runst1[], int runst2[], int l,string t1, string t2)
{
	int rt1= totalscoret1( 11, runst1);
	int rt2= totalscoret2( 11, runst2);
	if(rt1>rt2)
	{
		cout<<"Winner  of the Match is : "<<t1<<endl;
	}
	else
	{
		cout<<"Winner  of the match is : "<<t2<<endl;
	}
}
void mainbowler(int wicket1[],int wicket2[],string team1[],string team2[])
{

for (int i=6; i>11;i++)
{
		if(wicket1[i+1]<wicket1[i])
		{
			int temp = wicket1[i];
			wicket1[i] = wicket1[i+1];
			wicket1[i+1]= temp;
			string tempo = team1[i];
		team1[i] =team1[i+1];
			team1[i+1]= tempo;
}
}
for(int i = 6; i>11;i++)
{
			int temp = wicket2[i];
			wicket2[i] = wicket2[i+1];
			wicket2[i+1]= temp;
			string tempo = team2[i];
			team2[i] =team2[i+1];
			team2[i+1]= tempo;	
}
if(wicket1[10]>wicket2[10])
{
	cout<<"Bowler  of the Match is  "<<team1[10]<<endl;
	
}
else
cout<<"Bowler  of the Match is  "<<team2[10]<<endl;
}
//Batsman of the Match
void mainbatsman(int runst1[],int runst2[],string team1[],string team2[])
{

for (int i=0; i>3;i++)
{
		if(runst1[i+1]<runst1[i])
		{
			int temp = runst1[i];
		runst1[i] = runst1[i+1];
		runst1[i+1]= temp;
			string tempo = team1[i];
		team1[i] =team1[i+1];
			team1[i+1]= tempo;
}
}
for(int i = 0; i>3;i++)
{
if(runst2[i+1]<runst2[i])
		{
			int temp = runst2[i];
			runst2[i] = runst2[i+1];
		runst2[i+1]= temp;
			string tempo = team2[i];
			team2[i] =team2[i+1];
			team2[i+1]= tempo;	
}
}
if(runst1[2]>runst2[2])
{
	cout<<"Batsman of the Match is  "<<team1[2]<<endl;
	
}
else
cout<<"Batsman of the Match is  "<<team2[2]<<endl;
}

