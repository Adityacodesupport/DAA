#include<bits/stdc++.h>
using namespace std;

struct object{
    int profit;
    int weight;
    object(int profit,int weight)
    {
        this->profit=profit;
        this->weight=weight;
    }
};
bool compare(struct object a, struct object b)
{
    double r1=(double)a.profit / (double)a.weight;
    double r2=(double)b.profit / (double)b.weight;
    return r1>r2;
}
double fractional_knapsack(int W, struct object arr[],int N)
{
    sort(arr,arr+N,compare);
    double FinalProfit=0.0;
    for(int i=0;i<N;i++)
    {
        if(arr[i].weight<=W)
        {
            W=W-arr[i].weight;
            FinalProfit=FinalProfit+arr[i].profit;
        }else{
            FinalProfit=FinalProfit+((double)W/(double)arr[i].weight)*arr[i].profit;
            break;
        }
    }
    return FinalProfit;
}
int main()
{
    int W = 50;
	object arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int N = sizeof(arr) / sizeof(arr[0]);
    cout<<fractional_knapsack(W,arr,N);
    return 0;
}
