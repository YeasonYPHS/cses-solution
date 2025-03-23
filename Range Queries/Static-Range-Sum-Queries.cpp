#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long int
using namespace __gnu_pbds;
using namespace std;
template < class Node_CItr , class Node_Itr , class Cmp_Fn , class _Alloc >
struct my_node_update {
    virtual Node_CItr node_begin () const = 0;
    virtual Node_CItr node_end () const = 0;
    typedef int metadata_type ;
    inline void operator ()( Node_Itr it , Node_CItr end_it ){
        Node_Itr l = it . get_l_child () , r = it . get_r_child ();
        int left = 0, right = 0;
        if(l != end_it ) left = l. get_metadata ();
        if(r != end_it ) right = r. get_metadata ();
        const_cast < metadata_type & >( it . get_metadata ()) = left + right + (* it )-> second ;
    }
    inline int prefix_sum ( int x ){
        int ans = 0;
        Node_CItr it = node_begin ();
        while ( it != node_end ()){
            Node_CItr l = it . get_l_child () , r = it . get_r_child ();
            if( Cmp_Fn ()( x , (* it )-> first )) it = l;
            else {
                ans += (* it ) -> second ;
                if(l != node_end ()) ans += l. get_metadata ();
                it = r;
            }
        }
        return ans ;
    }
    inline int interval_sum (int l , int r ){
        return prefix_sum (r) - prefix_sum (l - 1);
    }
};
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,Q,a,b;
    cin>>N>>Q;
    tree<int,int,less_equal<int>,rb_tree_tag,my_node_update> T;
    for(int i=0;i<N;++i) cin>>T[i];
    while(Q--){
        cin>>a>>b;
        cout<<T.interval_sum(a,b)<<'\n';
    }
}