// Q4: You are given n jobs and m workers. Each job has a difficulty and a profit, and each worker has
// an ability which represents the maximum difficulty level they can handle. The task is to assign
// jobs to workers in such a way that maximizes the total profit. Write a C program that performs
// the above-mentioned task and returns only the maximum total profit possible. Function
// prototype is given below with explanation of all the argument and return value: -.
// Sample Output:
// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100
// Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
// Output: 0

#include <stdio.h>

int maxTotalProfit(int difficulty[], int profit[], int n, int worker[], int m){
    int totalprofit = 0 ;
    for (int i = 0; i < m ; i++)
    {
        int maxprofitforworker = 0 ;
        for (int j = 0; j < n; j++)
        {
            if (worker[i] >= difficulty[j] && profit[j] >= maxprofitforworker)
            {
                maxprofitforworker = profit[j] ;
            }
        }
        totalprofit += maxprofitforworker ;
    }
    return totalprofit ;
}

int main(){
    int difficulty1[] = {2,4,6,8,10} ;
    int profit1[] = {10,20,30,40,50} ;
    int worker1[] = {4,5,6,7} ;

    int n1 = 5 , m1 = 4 ;

    printf("Output: %d\n", maxTotalProfit(difficulty1, profit1, n1, worker1, m1));

}