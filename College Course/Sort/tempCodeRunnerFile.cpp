void selsort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min_index=i;
        for (int j = i+1; j<n; j++)
        {
            if(arr[min_index]<arr[j]) min_index=j;
            else{
                swap(arr[min_index],arr[i]);
            }
        }   
    }   
}