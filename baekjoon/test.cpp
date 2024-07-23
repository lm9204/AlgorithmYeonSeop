#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N,M; cin>>N>>M;

    vector<pair<int, int>> v;
    vector<int> dp(N+1, 1);

    // a b a가 b의 선수
    int a,b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        v.push_back({b,a}); // b 듣기 위해 a 수강
    }

    sort(v.begin(), v.end());

    for(int i=0; i<M; i++){
        int pre = v[i].second;
        int next = v[i].first;
        dp[next] = max(dp[next], dp[pre]+1);
    }

    for(int i=1; i<=N; i++) cout<<dp[i]<<" ";

}