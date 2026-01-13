class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<pair<int,int>> s;
        for(int i=0 ;i<n ; i++){
            s.push_back({score[i],i});
        }
        sort(s.begin(),s.end(),greater<>());
        vector<int> r(n);
        for(int i=0 ;i<n ; i++){
            r[s[i].second]=i+1;

        }
        vector<string> ans;
        for(int i=0 ; i<n ;i++){
            if(r[i]==1){
                ans.push_back("Gold Medal");
            }
            else if(r[i]==2){
                ans.push_back("Silver Medal");
            }else if(r[i]==3){
                ans.push_back("Bronze Medal");
            }else{
                ans.push_back(to_string(r[i]));
            }
        }
        return ans;

        
    }
};