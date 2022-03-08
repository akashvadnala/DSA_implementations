void insertionSort(vector<int>& arr){
    int n=arr.size();
    int key,j;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(int& i:arr) cout<<i<<' '; cout<<endl;
}

// Time complexity: best O(n)   if already sorted
//                  avg O(n^2)
//                  worst O(n^2)

// Space complexity O(1)

// j i
// 4 3 2 1 5 ->key=3
// key<4

//   j i
// 3 4 2 1 5 ->key=2
// key<4,3

//     j i
// 2 3 4 1 5 ->key =1
// key<4,3,2

//       j i
// 1 2 3 4 5 ->key=5
//key>4