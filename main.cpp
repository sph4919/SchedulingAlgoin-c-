#include"algo.h"



int main()
{

cout << endl;
// cout << "------------------------------------------------------------------Welcome to the world of scheduling Algos....-----------------------------------------------------------------" << endl << endl;
// cout << "This Algos assigned the process to CPU in such a manner, that it reduce response, waiting & turnaround time of proccess to make computer more efficient & have high performance. \n" << endl;
// cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;


// int numOfProcess;
// cout << "Plz Enter the number of process you want to generate:- " ;
// cin >> numOfProcess;
// cout << endl;

//   vector<string> process(numOfProcess);
//   vector<int> arrayOfArrival(numOfProcess);
//   vector<int> arrayOfBurst(numOfProcess);
//   vector<int> priority(numOfProcess);
//   int quantum;
//   cout << "                                                                                   Generating the Processes \n" ;

// for(int i=0;i<numOfProcess;i++)
//   {
//     process[i]="p" + to_string(i+1);
//   }
// cout << "                                                                            Generated Sucessfully !!!! " << endl << endl;;


// cout << "                                      Plz Provide the arrival time for " << numOfProcess << " Proccess: EG-For 5 process formate will be (1 2 3 4 5 ) [It can be random numbers for the " << endl;cout << "                                                            FCFS ,SJF , RR ] But for the SRT and PQ arrival time must be in increasing order. " << endl;
// for(int i=0;i<numOfProcess;i++)
//   {
//     cin >> arrayOfArrival[i];
//   }
// cout << endl << endl;

// cout << "Plz Provide the Burst time for " << numOfProcess << " Proccess: EG-For 5 process formate will be (1 2 3 4 5 ) [It can be random numbers]" << endl;
// for(int i=0;i<numOfProcess;i++)
//   {
//     cin >> arrayOfBurst[i];
//   }
// cout << endl << endl;
cout << "------------------------------------------------------------------Welcome to the world of scheduling Algos....-----------------------------------------------------------------" << endl << endl;
cout << "This Algos assigned the process to CPU in such a manner, that it reduce response, waiting & turnaround time of proccess to make computer more efficient & have high performance. \n" << endl;
cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
int options;
do
{

int numOfProcess;
cout << "Plz Enter the number of process you want to generate:- " ;
cin >> numOfProcess;
cout << endl;

  vector<string> process(numOfProcess);
  vector<int> arrayOfArrival(numOfProcess);
  vector<int> arrayOfBurst(numOfProcess);
  vector<int> priority(numOfProcess);
  int quantum;
  cout << "                                                                            Generating the Processes \n" ;

for(int i=0;i<numOfProcess;i++)
  {
    process[i]="p" + to_string(i+1);
  }
cout << "                                                                            Generated Sucessfully !!!! " << endl << endl;;


cout << "                                      Plz Provide the arrival time for " << numOfProcess << " Proccess: EG-For 5 process formate will be (1 2 3 4 5 ) [It can be random numbers for the " << endl;cout << "                                                            FCFS ,SJF , RR ] But for the SRT and PQ arrival time must be in increasing order. " << endl;
for(int i=0;i<numOfProcess;i++)
  {
    cin >> arrayOfArrival[i];
  }
cout << endl << endl;

cout << "Plz Provide the Burst time for " << numOfProcess << " Proccess: EG-For 5 process formate will be (1 2 3 4 5 ) [It can be random numbers]" << endl;
for(int i=0;i<numOfProcess;i++)
  {
    cin >> arrayOfBurst[i];
  }
cout << endl << endl;




cout << "Selection the options below for verifying the algoritms :- " << endl;
cout << "1 - FCFS(First come First serve)" << endl;
cout << "2 - SJF(Sortest Job First)" << endl;
cout << "3 - SRT(Sortest Remaining Time) " << endl;
cout << "4 - RR(Round Robin)" << endl;
cout << "5 - PQ(Priority Quene)" << endl;
cout << "0 - To End Anaylsis" << endl;
cout << "Enter the number for selecting the algo: " << endl;
cin >> options;
cout << endl;


if(options==1)
{
 Fcfs( process,arrayOfArrival,arrayOfBurst);
 cout << "The proccess are compeleted" << endl;
 cout << endl << endl;
}
else if(options==2)
{
SJF( process,arrayOfArrival,arrayOfBurst); //Assuming that the arrival time is same for all the process.
 cout << "The proccess are compeleted" << endl;
 cout << endl << endl;
}
else if(options==3)
{
SRT( process,arrayOfArrival,arrayOfBurst);
cout << endl << endl;
}
else if(options==4)
{
cout << "Enter the time quantum for RR" << endl;
cin >> quantum;
RR( process,arrayOfArrival,arrayOfBurst,quantum);
cout << "The proccess are compeleted" << endl;
cout << endl << endl;
}
else if(options==5)
{
 cout << "Plz Provide Priority for " << numOfProcess << " Proccess: EG-For 5 process formate will be (1 2 3 4 5 ) [Higher the number - Higher the priority]" << endl;
for(int i=0;i<numOfProcess;i++)
  {
    cin >> priority[i];
  }
cout << endl << endl;
PQ( process,arrayOfArrival,arrayOfBurst ,priority);
cout << endl << endl;
}
else if(options==0)
{
  cout << "---------------------------------------------------------------The program ends , Hopes that you are satisfied by result....---------------------------------------" << endl;
  break;
}
}while(options!=0);

    return 0;
}