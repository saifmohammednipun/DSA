int binarySearch(int* arr, int target, int start, int end)
{
    // base case
    if(start > end)
    return -1;

    int m = (start + end)/2;
    if(arr[m] == target)
    {
        return m;
    }

    else
    {
        if(arr[m] < target)
        {
            return binarySearch(arr,target,start,m-1);
        }
        else
        {
            return binarySearch(arr,target,m+1,end);
        }

    }

}