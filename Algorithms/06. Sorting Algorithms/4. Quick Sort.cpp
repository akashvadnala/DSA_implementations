void quickSort(vector<int>& arr,int low,int high){
    int p=partition(arr,low,high);
    quickSort(arr,low,p-1);
    quickSort(arr,p,high);
}

int partition(vector<int>& arr,int low,int high){
    int pivot=arr[high];
    int i=low;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            if(i!=j) swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
}

// Time complexity: best O(nlogn)
//                  avg O(nlogn)
//                  worst O(n^2)   if it is in reverse order

// Space complexity O(logn)


// 4 1 3 5 2 ->pivot=2

// 1 2 3 5 4 i=1
// 1    2 3 5 4 ->pivot=4

// 1    2 3 4 5