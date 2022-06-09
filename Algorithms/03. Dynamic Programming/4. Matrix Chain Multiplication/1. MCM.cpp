
int MatrixChainOrder(vector<int>& p){
    int n=p.size();  // n=5
    int m[n][n];
    int j,q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++){   // L=2->4                 L=2     3       4
        for (int i = 1; i < n - L + 1; i++){ //  i=1->5-L => i=1 2 3, i=1 2, i=1
            j = i + L - 1;                                 //j=2 3 4  j=3 4  j=4
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++){          
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q<m[i][j]) m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}

// p=[1,2,3,4,3]

// A1 = (1 x 2)
// A2 = (2 x 3)
// A3 = (3 x 4)
// A4 = (4 x 3)


//   0 1  2  3  4
// 0
// 1   0
// 2   6  0
// 3   18 24 0
// 4   30 48 36 0

