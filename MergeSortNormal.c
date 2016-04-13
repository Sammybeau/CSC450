#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char** argv)
{
    srand(time(NULL));
    int num;
    int i;
    
    int numTotal = 10;
    
    int begin = 0;
    int end = numTotal-1;
    
    int nums[numTotal];
    
    for(i = 0; i < numTotal; i++)
    {
        nums[i] = rand()%10;
    }
    
     for(i = 0; i < numTotal; i++)
    {
        printf("Original List: %d\n", nums[i]);
    }
    
    mergeSortDriver(nums, numTotal);
    
    for(i = 0; i < numTotal; i++)
    {
        printf("Sorted List: %d\n", nums[i]);
    }
}
    
//---------------------------------------------------------------------------

void mergeSortDriver(int ar[], int arLength)
{
    mergeSort(ar, 0, arLength-1);
}
    
void mergeSort(int ar[], int begin, int end)
{
    if(begin != end)
    {
       
        int leftBegin = begin;
        int rightBegin = ((end-begin)/2 + begin) + 1;
        int leftEnd = ((end-begin)/2) + begin;
        int rightEnd = end;
        
        mergeSort(ar, leftBegin, leftEnd);
        mergeSort(ar, rightBegin, rightEnd);
        
        int tempAr[rightEnd-leftBegin+1];
        int currLeft = leftBegin;
        int currRight = rightBegin;
        
        int tempPos = 0;
        for(; tempPos < (rightEnd-leftBegin+1); tempPos++)
        {
            if(currLeft > leftEnd)
            {
                tempAr[tempPos] = ar[currRight];
                currRight++;
            }
            
            else if(currRight > rightEnd)
            {
                tempAr[tempPos] = ar[currLeft];
                currLeft++;
            }
            else
            {
                if(ar[currLeft] < ar[currRight])
                {
                    tempAr[tempPos] = ar[currLeft];
                    currLeft++;
                }
                else
                {
                    tempAr[tempPos] = ar[currRight];
                    currRight++;
                }
            }
        }
        int tempPos2 = 0;
        int loopVar = leftBegin;
        for(; loopVar<= rightEnd; loopVar++)
        {
            ar[loopVar] = tempAr[tempPos2];
            tempPos2++;
        }
   
    }
}
    
