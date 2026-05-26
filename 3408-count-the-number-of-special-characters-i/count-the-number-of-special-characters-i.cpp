class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> w;
        int ans=0;
        
        for(int x: word){
            w.insert(x);
        }
        vector<char> a;
        for(char x: w){
            a.push_back(x);
        }
        for(int i=0 ; i<a.size() ; i++){
            for(int j=i+1 ; j<a.size() ; j++){
                if(abs(a[i]-a[j])==32){
                    ans++;
                }
            }
        }
        return ans;   
    }
};