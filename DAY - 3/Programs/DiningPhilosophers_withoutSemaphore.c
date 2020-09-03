#include<stdio.h> 
#define n 4
int PhilosophersCompleted = 0,i;
struct fork{
  int ForkTaken;
}ForkAvailable[n];
struct Philosophers{
  int left;
  int right;
}PhilosopherStatus[n];
void dinner(int PhilosopherID){ 
  if(PhilosopherStatus[PhilosopherID].left==10 && PhilosopherStatus[PhilosopherID].right==10)
        printf("Philosopher %d has completed his dinner\n",PhilosopherID+1);
  else if(PhilosopherStatus[PhilosopherID].left==1 && PhilosopherStatus[PhilosopherID].right==1){
            printf("Philosopher %d has completed his dinner\n",PhilosopherID+1);
            PhilosopherStatus[PhilosopherID].left = PhilosopherStatus[PhilosopherID].right = 10; 
            int otherFork = PhilosopherID-1;
            if(otherFork== -1)
                otherFork=(n-1);
            ForkAvailable[PhilosopherID].ForkTaken = ForkAvailable[otherFork].ForkTaken = 0;
            printf("Philosopher %d released fork %d and fork %d\n",PhilosopherID+1,PhilosopherID+1,otherFork+1);
            PhilosophersCompleted++;
        }
        else if(PhilosopherStatus[PhilosopherID].left==1 && PhilosopherStatus[PhilosopherID].right==0){ 
                if(PhilosopherID==(n-1)){
                    if(ForkAvailable[PhilosopherID].ForkTaken==0){
                        ForkAvailable[PhilosopherID].ForkTaken = PhilosopherStatus[PhilosopherID].right = 1;
                        printf("Fork %d ForkTaken by philosopher %d\n",PhilosopherID+1,PhilosopherID+1);
                    }else{
                        printf("Philosopher %d is waiting for fork %d\n",PhilosopherID+1,PhilosopherID+1);
                    }
                }else{ 
                    int dupPhilosopherID = PhilosopherID;
                    PhilosopherID-=1;
 
                    if(PhilosopherID== -1)
                        PhilosopherID=(n-1);
 
                    if(ForkAvailable[PhilosopherID].ForkTaken == 0){
                        ForkAvailable[PhilosopherID].ForkTaken = PhilosopherStatus[dupPhilosopherID].right = 1;
                        printf("Fork %d ForkTaken by Philosopher %d\n",PhilosopherID+1,dupPhilosopherID+1);
                    }else{
                        printf("Philosopher %d is waiting for Fork %d\n",dupPhilosopherID+1,PhilosopherID+1);
                    }
                }
            }
            else if(PhilosopherStatus[PhilosopherID].left==0){ 
                    if(PhilosopherID==(n-1)){
                        if(ForkAvailable[PhilosopherID-1].ForkTaken==0){ 
                            ForkAvailable[PhilosopherID-1].ForkTaken = PhilosopherStatus[PhilosopherID].left = 1;
                            printf("Fork %d ForkTaken by philosopher %d\n",PhilosopherID,PhilosopherID+1);
                        }else{
                            printf("Philosopher %d is waiting for fork %d\n",PhilosopherID+1,PhilosopherID);
                        }
                    }else{ 
                        if(ForkAvailable[PhilosopherID].ForkTaken == 0){
                            ForkAvailable[PhilosopherID].ForkTaken = PhilosopherStatus[PhilosopherID].left = 1;
                            printf("Fork %d ForkTaken by Philosopher %d\n",PhilosopherID+1,PhilosopherID+1);
                        }else{
                            printf("Philosopher %d is waiting for Fork %d\n",PhilosopherID+1,PhilosopherID+1);
                        }
                    }
        }else{}
}
 
int main(){
  for(i=0;i<n;i++)
        ForkAvailable[i].ForkTaken=PhilosopherStatus[i].left=PhilosopherStatus[i].right=0;
 
  while(PhilosophersCompleted<n){
    for(i=0;i<n;i++)
            dinner(i);
    printf("\nTill now num of philosophers completed dinner are %d\n\n",PhilosophersCompleted);
  }
 
  return 0;
}