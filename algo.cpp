#include"algo.h"


//This is the helper function for the SRT and PQ-Based algos.
bool completed(vector<int> arrayOfBurst)
{
  bool allDone = true;
  for(int i=0;i<arrayOfBurst.size();i++)
    {
      if(arrayOfBurst[i]!=0)
      {
        return false;
      }
      else
      {
        continue;
      }
    }
  return allDone;
}




void Fcfs(vector<string> process,vector<int> arrayOfArrival, vector<int> arrayOfBurst)
{

queue<string> store;

//Uncomment This for review the inside process of algoritm.
//   for(int i=0;i<5;i++)
//   {
//     cout << process[i] << " " ;
//   }
//  cout << endl;

//   for(int i=0;i<5;i++)
//   {
//     cout << arrayOfArrival[i] << " " ;
//   }
//   cout << endl;
//   for(int i=0;i<5;i++)
//   {
//     cout << arrayOfBurst[i] << " " ;
//   }
// cout << endl;
// cout << endl; 

 int fixedLoopsize= process.size();
 int sizeOfProcess = process.size();  
 for(int a=0;a<fixedLoopsize;a++)
   {
 
  int smallindex=0;
  for(int i=1;i<sizeOfProcess;i++)
    {
      if(arrayOfArrival[smallindex]>arrayOfArrival[i])
      {
        smallindex = i;
      }
    }
    store.push(process[smallindex]);

      process.erase(process.begin()+smallindex);
      arrayOfArrival.erase(arrayOfArrival.begin()+smallindex);
      arrayOfBurst.erase(arrayOfBurst.begin()+smallindex);
      sizeOfProcess--;
      
    //Uncomment This for review the inside process of algoritm. 
    //   for(int i=0;i<sizeOfProcess;i++)
    //   {
    //     cout << process[i] << " " ;
    //   }
    //   cout << endl;
    //   for(int i=0;i<sizeOfProcess;i++)
    //   {
    //     cout << arrayOfArrival[i] << " " ;
    //   }
    //   cout << endl;
    //   for(int i=0;i<sizeOfProcess;i++)
    //   {
    //     cout << arrayOfBurst[i] << " " ;
    //   }
  }

 cout << "This is the sequence of the proccess completion according to FCFS algoritm" << endl;
  for(int i=0;i<fixedLoopsize;i++)
    {
      cout << store.front() << " " ;
      store.pop();
    }
  
}




void SJF(vector<string> &process,vector<int> &arrayOfArrival, vector<int> &arrayOfBurst)
 {
    queue<string> store;

//Uncomment This for review the inside process of algoritm.
//   for(int i=0;i<5;i++)
//   {
//     cout << process[i] << " " ;
//   }
//  cout << endl;

//   for(int i=0;i<5;i++)
//   {
//     cout << arrayOfArrival[i] << " " ;
//   }
//   cout << endl;
//   for(int i=0;i<5;i++)
//   {
//     cout << arrayOfBurst[i] << " " ;
//   }
// cout << endl;
// cout << endl; 

 int fixedLoopsize= process.size();
 int sizeOfProcess = process.size();  
 for(int a=0;a<fixedLoopsize;a++)
   {
 
  int smallindex=0;
  for(int i=1;i<sizeOfProcess;i++)
    {
      if(arrayOfBurst[smallindex]>arrayOfBurst[i])
      {
        smallindex = i;
      }
    }
    store.push(process[smallindex]);

      process.erase(process.begin()+smallindex);
      arrayOfArrival.erase(arrayOfArrival.begin()+smallindex);
      arrayOfBurst.erase(arrayOfBurst.begin()+smallindex);
      sizeOfProcess--;
      
    //Uncomment This for review the inside process of algoritm. 
    //   for(int i=0;i<sizeOfProcess;i++)
    //   {
    //     cout << process[i] << " " ;
    //   }
    //   cout << endl;
    //   for(int i=0;i<sizeOfProcess;i++)
    //   {
    //     cout << arrayOfArrival[i] << " " ;
    //   }
    //   cout << endl;
    //   for(int i=0;i<sizeOfProcess;i++)
    //   {
    //     cout << arrayOfBurst[i] << " " ;
    //   }
    }

 cout << "This is the sequence of the proccess completion according to SJF algoritm" << endl;
  for(int i=0;i<fixedLoopsize;i++)
    {
      cout << store.front() << " " ;
      store.pop();
    }
  
 }




 void SRT(vector<string> &process,vector<int> &arrayOfArrival, vector<int> &arrayOfBurst)
 {
  
  int timer = 0;
  vector<string> processStore;
  vector<string> processCopy = process;

  //Uncomment This for review the inside process of algoritm. 
  // for (int i = 0; i < process.size(); i++) {
  //   cout << process[i] << " ";
  // }
  // cout << endl;

  // for (int i = 0; i < arrayOfArrival.size(); i++) {
  //   cout << arrayOfArrival[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < arrayOfBurst.size(); i++) {
  //   cout << arrayOfBurst[i] << " ";
  // }

  // cout << endl;
  // cout << endl;


    while(1)
    {
      int smallestindex = 0;
      for (int i = 1; i < arrayOfArrival.size(); i++) 
       {
        if (arrayOfArrival[smallestindex] > arrayOfArrival[i] ) 
          {
           smallestindex = i;
          }
       }
      
      if(arrayOfArrival.size()==0)
        {
        smallestindex=INT_MAX;
        }


  if (arrayOfArrival[smallestindex] <= timer &&  arrayOfArrival.size()>0)
        {

          int processNumber = (process[smallestindex].at(1) - '0') - 1;
          arrayOfArrival.erase(arrayOfArrival.begin() + smallestindex);
          process.erase(process.begin() + smallestindex);
          processStore.push_back(processCopy[processNumber]);

          //Uncomment This for review the inside process of algoritm. 
          // cout << "Queue is " ;
          // for (int i = 0; i < processStore.size(); i++)
          //   {
          //   cout << processStore[i] << " ";
          //  }
          // cout << endl ;
           

          int smallestBurst = (processStore[0].at(1) - '0') - 1;
         
          for(int i=1;i<processStore.size();i++ )
            {
              int processNo = (processStore[i].at(1) - '0') - 1;
            
              if(arrayOfBurst[smallestBurst]==0)
              {
                smallestBurst++;
                continue;
              }
              else if(arrayOfBurst[processNo]==0)
              {
                continue;
              }
              else if( arrayOfBurst[smallestBurst] > arrayOfBurst[processNo])
              {
                smallestBurst = processNo;
              }
            }
         
          arrayOfBurst[smallestBurst]--;
          cout << processCopy[smallestBurst] << " ";


          //Uncomment This for review the inside process of algoritm. 
          // for (int i = 0; i < arrayOfBurst.size(); i++)
          //   {
          //   cout << arrayOfBurst[i] << " ";
          //   }
          // cout << endl;
          // cout << endl;

          if(completed(arrayOfBurst))
          {
            cout << endl;
            cout << "The proccess are compeleted" << endl;
            break;
          }
         
        }
      else
       {
          if(processStore.size()==0)
          {
            
          }
         else
          {
        //Uncomment This for review the inside process of algoritm. 
        //  cout << "Queue is " ;
        //  for (int i = 0; i < processStore.size(); i++)
        //    {
        //    cout << processStore[i] << " ";
        //   }
        //  cout << endl ;


         int smallestBurst = (processStore[0].at(1) - '0') - 1;
       
         bool waiting=false;   
         for(int i=1;i<processStore.size();i++ )
           {
             int processNo = (processStore[i].at(1) - '0') - 1;
             
             if(1)
               {
                
                  for(int i=0;i<processStore.size();i++ )
                    {
                      if(arrayOfBurst[(processStore[i].at(1)-'0')-1]==0)
                      {
                         waiting=true;
                      }
                      else
                      {
                       
                        waiting=false;
                        break;
                      }
                    }
               }
         

             if(!waiting)
             {
             if(arrayOfBurst[smallestBurst]==0)
               {
                smallestBurst++;
                continue;
               }
             else if(arrayOfBurst[processNo]==0)
               {
                continue;
               }
             else if( arrayOfBurst[smallestBurst] > arrayOfBurst[processNo])
               {
                smallestBurst = processNo;
               }
             }
           }
        if(!waiting)
        {
         
         arrayOfBurst[smallestBurst]--;
         cout << processCopy[smallestBurst] << " ";
        
        }


        //Uncomment This for review the inside process of algoritm. 
        //  for (int i = 0; i < arrayOfBurst.size(); i++)
        //    {
        //    cout << arrayOfBurst[i] << " ";
        //    }
        //  cout << endl;
        //  cout << endl;

         if(completed(arrayOfBurst))
           {
             cout << endl;
             cout << "The proccess are compeleted" << endl;
             break;
           }
          }
      }
      timer++;
      
    }
 }




void RR(vector<string> &process,vector<int> &arrayOfArrival, vector<int> &arrayOfBurst ,int quantum)
{

  queue<string> readyqueue;
  queue<string> runningqueue;
  int timer=0;
  


int initialsize=arrayOfArrival.size();
for(int a=0;a<initialsize;a++)
  {
    int size=arrayOfArrival.size();
    for(int i=0;i<size;i++)
      {
        if(arrayOfArrival[i]<=timer)
          {
           readyqueue.push(process[i]);
           process.erase(process.begin() + i);
           arrayOfArrival.erase(arrayOfArrival.begin() + i);
           break;
        }
      }
  }

bool tOrf=true;

while(tOrf)
   {

      if(!readyqueue.empty())
        {
         runningqueue.push(readyqueue.front());
         cout << runningqueue.front() << " ";
         string processElement = runningqueue.front();
         int numberForBurst=(processElement.at(1)-'0')-1;
         int storeValue = arrayOfBurst[numberForBurst];
       
          if(arrayOfBurst[numberForBurst]<2)
            {
             arrayOfBurst[numberForBurst]=arrayOfBurst[numberForBurst]-storeValue;
            }
          else
            {
             arrayOfBurst[numberForBurst]=arrayOfBurst[numberForBurst]-quantum;
            }
  timer=timer+quantum;
   
 int initialsize=arrayOfArrival.size();
     for(int a=0;a<initialsize;a++)
        {
         int size=arrayOfArrival.size();
         for(int i=0;i<size;i++)
           {
             if(arrayOfArrival[i]<=timer)
             {
               readyqueue.push(process[i]);
               process.erase(process.begin() + i);
               arrayOfArrival.erase(arrayOfArrival.begin() + i);
               break;
             }
           }
         }

         
   if(arrayOfBurst[numberForBurst]!=0)
     {
       readyqueue.push(readyqueue.front());
     }
   else
     {
       arrayOfBurst[numberForBurst]=0;
     }
      readyqueue.pop();
      runningqueue.pop(); 

     for(int i=0;i<arrayOfBurst.size();i++)
        {
          if(arrayOfBurst[i]==0)
            {
             tOrf=false;
            }
           else
            {
             tOrf=true;
             break;
            }
         }
    }
    timer++;
    for(int a=0;a<initialsize;a++)
     {
      int size=arrayOfArrival.size();
      for(int i=0;i<size;i++)
        {
        if(arrayOfArrival[i]<=timer)
          {
           readyqueue.push(process[i]);
           process.erase(process.begin() + i);
           arrayOfArrival.erase(arrayOfArrival.begin() + i);
           break;
          }
        }
     }

 }
cout << endl;
}

 void PQ(vector<string> &process,vector<int> &arrayOfArrival, vector<int> &arrayOfBurst , vector<int> &priority)
 {
  int timer = 0;
  vector<string> processStore;
  vector<string> processCopy = process;
 
  //Uncomment This for review the inside process of algoritm. 
  // for (int i = 0; i < process.size(); i++) {
  //   cout << process[i] << " ";
  // }
  // cout << endl;

  // for (int i = 0; i < arrayOfArrival.size(); i++) {
  //   cout << arrayOfArrival[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < arrayOfBurst.size(); i++) {
  //   cout << arrayOfBurst[i] << " ";
  // }

  // cout << endl;
  // cout << endl;



  while(1)
    {
      int smallestindex = 0;
      for (int i = 1; i < arrayOfArrival.size(); i++) 
       {
        if (arrayOfArrival[smallestindex] > arrayOfArrival[i] ) 
          {
           smallestindex = i;
          }
       }
      if(arrayOfArrival.size()==0)
        {
        smallestindex=INT_MAX;
        }


  if (arrayOfArrival[smallestindex] <= timer &&  arrayOfArrival.size()>0)
        {

          int processNumber = (process[smallestindex].at(1) - '0') - 1;
          arrayOfArrival.erase(arrayOfArrival.begin() + smallestindex);
          process.erase(process.begin() + smallestindex);
          processStore.push_back(processCopy[processNumber]);
          //Uncomment This for review the inside process of algoritm.
          // cout << "Queue is " ;
          // for (int i = 0; i < processStore.size(); i++)
          //   {
          //   cout << processStore[i] << " ";
          //  }
          // cout << endl ;

          
          int higherPriority = (processStore[0].at(1) - '0') - 1;
          for(int i=1;i<processStore.size();i++ )
            {
              int processNo = (processStore[i].at(1) - '0') - 1;
              if(priority[higherPriority]==0)
               {
                higherPriority++;
                continue;
               }
              else if(priority[processNo]==0)
               {
                continue;
               }
              else if( priority[higherPriority] < priority[processNo])
               {
                higherPriority= processNo;
               }
            }
          
          arrayOfBurst[higherPriority]--;
          if(arrayOfBurst[higherPriority]==0)
          {
            priority[higherPriority]=0;
          }
          cout << processCopy[higherPriority] << " ";
 
          

          //Uncomment This for review the inside process of algoritm. 
          // for (int i = 0; i < arrayOfBurst.size(); i++)
          //   {
          //   cout << arrayOfBurst[i] << " ";
          //   }
          // cout << endl;
          // cout << endl;

          if(completed(arrayOfBurst))
          {
            cout << endl;
            cout << "The proccess are compeleted" << endl;
            break;
          }
        }
    else
       {
         //Uncomment This for review the inside process of algoritm.
         // cout << "Queue is " ;
         // for (int i = 0; i < processStore.size(); i++)
         //   {
         //   cout << processStore[i] << " ";
         //   }
         // cout << endl ;
       if(processStore.size()==0)
         {

         }
         else
         {

         int higherPriority = (processStore[0].at(1) - '0') - 1;
         //Uncomment This for review the inside process of algoritm.
         // cout << "before " << smallestBurst << endl;
         bool waiting=false;  
         for(int i=1;i<processStore.size();i++ )
           {
             int processNo = (processStore[i].at(1) - '0') - 1;
             if(1)
                {
                  for( int i=0;i<processStore.size();i++ )
                     {
                       if(arrayOfBurst[(processStore[i].at(1)-'0')-1]==0)
                       {
                          waiting=true;
                       }
                       else
                       {
                         waiting=false;
                         break;
                       }
                     }
                }
           if(!waiting)
            {
             if(priority[higherPriority]==0)
              {
               higherPriority++;
               continue;
              }
             else if(priority[processNo]==0)
              {
               continue;
              }
             else if( priority[higherPriority] < priority[processNo])
              {
               higherPriority= processNo;
              }
            }
           }
        
         if(!waiting)
            {
             arrayOfBurst[higherPriority]--;
             if(arrayOfBurst[higherPriority]==0)
               {
                 priority[higherPriority]=0;
               }
             cout << processCopy[higherPriority] << " ";
            }


         //Uncomment This for review the inside process of algoritm.
         // for (int i = 0; i < arrayOfBurst.size(); i++)
         //   {
         //   cout << arrayOfBurst[i] << " ";
         //   }
         // cout << endl;
         // cout << endl;

         if(completed(arrayOfBurst))
           {
           cout << endl;
           cout << "The proccess are compeleted" << endl;
           break;
           }
         }
      }
      timer++;
     
    
    }
 }