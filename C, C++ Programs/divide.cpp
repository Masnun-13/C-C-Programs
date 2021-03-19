#include<iostream>
#include<cmath>
using namespace std;

int* find_crossing_subarray(int* arr,int low,int mid,int high)
{
    int sum=0,max_left_sum=-99999,max_right_sum=-99999,max_left_index,max_right_index;
    for(int i=mid;i>=low;i--)
    {
        sum += arr[i];
        if(sum > max_left_sum)
        {
            max_left_sum = sum;
            max_left_index=i;
        }
    }
    sum =0;
    for(int i=mid+1;i<=high;i++)
    {
        sum += arr[i];
        if(sum > max_right_sum)
        {
            max_right_sum = sum;
            max_right_index=i;
        }
    }
    int* result = new int[3];
    result[0] = max_left_index;
    result[1] = max_right_index;
    result[2] = max_left_sum + max_right_sum;
    return result;
}

int* find_max_subarray(int* arr,int low,int high)
{
    //Base Case
    if(high==low)
    {
        int* ret = new int[3];
        ret[0] = low;
        ret[1] = high;
        ret[2] = arr[high];
        return ret;
    }
    //Divide and Conquer
    else
    {
        int mid = floor((low+high)/2) ;
        int* left_result = find_max_subarray(arr,low,mid);
        int* right_result = find_max_subarray(arr,mid+1,high);
        int* crossing_result = find_crossing_subarray(arr,low,mid,high);

        if(left_result[2]>=right_result[2] && left_result[2]>=crossing_result[2])
        {
            return left_result;
        }
        else if(right_result[2]>=left_result[2] && right_result[2]>=crossing_result[2])
        {
            return right_result;
        }
        else return crossing_result;
    }
}

int main()
{
    int *arr = new int[5];
    for(int i=0;i<5;i++)cin>>arr[i];
    int* result = find_max_subarray(arr,0,4);
    cout<<result[0]<<" "<<result[1]<<" "<<result[2];
}
