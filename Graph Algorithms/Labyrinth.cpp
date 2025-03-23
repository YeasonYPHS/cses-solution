#include <iostream>
#include <stack>

using namespace std;

#define optimizeIO() cin.tie(0)->sync_with_stdio(0)
#define pii pair<int,int>
#define MAX 1005

pii start, dest;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
char dir[4] = {'D', 'R', 'U', 'L'};

deque<char> track;
int N, M;
bool mp[MAX][MAX] = {}, occupy[MAX][MAX] = {}, flag = 0;

bool out_of_bound(pii coor) {
    return (coor.first < 1 && coor.first > N && coor.second < 1 && coor.second > M) || (!mp[coor.first][coor.second]); 
}

void dfs(pii curr, int curr_iter) {
    

    if(out_of_bound(curr) || flag) {
        return;
    }//cout << curr.first << ' ' << curr.second << '\n';
    if(curr == dest) {
        cout << "YES\n";
        cout << curr_iter << '\n';
        for(auto it = track.begin(); it != track.end(); ++it) {
            cout << *it;
        }
        flag = 1;
        return;
    }

    for(int i = 0;i < 4; ++i) {
        track.push_back(dir[i]);
        mp[curr.first][curr.second] = 0;
        dfs({curr.first + dy[i], curr.second + dx[i]}, curr_iter + 1);
        track.pop_back();
        mp[curr.first][curr.second] = 1;
    }
}

int main(){
    //optimizeIO();

    char ch;

    cin >> N >> M;
    for(int i = 1;i <= N; ++i) {
        for(int j = 1;j <= M; ++j) {
            cin >> ch;
            if(ch != '#') {
                mp[i][j] = 1;
                if(ch == 'A') start = {i, j};
                if(ch == 'B') dest = {i, j};
            }
        }
    }

    dfs(start, 0);
    if(!flag) cout << "NO\n";

    return 0;
}