void mergeSort(vector<int>& arr,int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergerSort(arr,m+1,r);
        mergeit(arr,l,m,r);
    }
}

void mergeit(vector<int>& arr,int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    vector<int> a1(n1),a2(n2);
    for(int i=0;i<n1;i++)
        a1[i]=arr[l+i];
    for(int i=0;i<n2;i++)
        a2[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j])
            arr[k++]=a1[i++];
        else
            arr[k++]=a2[j++];
    }
    while(i<n1)
        arr[k++]=a1[i++];
    while(j<n2)
        arr[k++]=a2[j++];
}

// Time complexity: best O(nlogn)
//                  avg O(nlogn)
//                  worst O(nlogn)

// Space complexity O(n)

// [4 1 3 5 2]
//     /   \
// [4 1]    [3 5 2]
//   /\        /\
// [4] [1]  [3] [5 2]
//                /\
// [4] [1]  [3] [5] [2]
//  \  /          \ /
// [1 4]    [3]  [2 5]
//           \    /
// [1 4]    [2 3 5]
//   \       /
// [1 2 3 4 5]