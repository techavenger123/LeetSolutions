class Solution {
public:
    static int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        for(auto& e: edges){
            int w=e[1];
            deg[w]++;
        }
        vector<int> deg0;
        for(int i=0; i<n; i++){
            if (deg[i]==0)
                deg0.push_back(i);
        }
        if (deg0.size()!=1) return -1;
        else return deg0[0];
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
