void selectionSort(vector<int>& arr){
    int n=arr.size();
    int mn;
    for(i=0;i<n-1;i++){
        mn=i;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[i]) mn=j;
        if(i!=mn) swap(arr[i],arr[mn]);
    }
}

// Time complexity: best O(n^2)
//                  avg O(n^2)
//                  worst O(n^2)

//Space complexity O(1)


// 4 1 3 5 2
// 1 4 3 5 2
// 1 2 3 5 4
// 1 2 3 5 4
// 1 2 3 4 5
