class Solution{   
public:
    int median(vector<vector<int>> &A, int M, int N)
    {
           int k = ( M*N + 1 )/2 ;

        int l = INT_MAX ;
        int r = INT_MIN ;
        
        for( int i = 0 ; i < M ; i++ )
        {
        l = min( l , A[i][0] ) ;
        r = max( r , A[i][N-1] ) ;
        }
        
        while( l < r )
        {
            int m = ( l + r )/2 ;
        
            int cnt = 0 ;
        
            for( int i = 0 ; i < M ; i++ )
            {
                cnt = cnt + ( upper_bound( A[i].begin() , A[i].end() , m ) - A[i].begin() ) ;
            }
            if( cnt < k )
            {
                l = m + 1 ;
                
            }
            else r = m ;
        }
        
        return l ;  
    }
};
