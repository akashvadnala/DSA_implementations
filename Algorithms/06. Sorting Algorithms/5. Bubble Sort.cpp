void bubbleSort(vector<int>& arr){
    int n=arr.size();
    bool t;
    for(int i=0;i<n-1;i++){
        t=true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                t=false;
            }
        }
        if(t) return;
    }
}

// Time complexity: best O(n)  if it is already sorted
//                  avg O(n^2)
//                  worst O(n^2)

// Space complexity: O(1)