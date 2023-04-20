class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        unordered_set<int> st;
        for(auto vec:adjacentPairs){
            mp[vec[0]].push_back(vec[1]);
            mp[vec[1]].push_back(vec[0]);
        }
        int startEl=-1;
        for(auto el:mp){
            if(el.second.size()==1){
                startEl=el.first;
            }
        }
        st.insert(startEl);
        queue<int> q;
        q.push(startEl);
        vector<int> ans;
        ans.push_back(startEl);
        while(q.empty()==false){
            int el=q.front();
            q.pop();
            for(auto ngb:mp[el]){
                if(st.find(ngb)==st.end()){
                    ans.push_back(ngb);
                    st.insert(ngb);
                    q.push(ngb);
                }
            }
        }
        return ans;
    }
};