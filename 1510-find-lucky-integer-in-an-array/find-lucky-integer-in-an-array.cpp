class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans=INT_MIN;
        sort(arr.begin(),arr.end());
        vector<int> freq(arr[arr.size()-1]+1,0);
        for(int x : arr){
            freq[x]++;
        }
        for(int i=1 ; i < freq.size() ;i++ ){
            if(freq[i]==i){
                ans=max(ans,i);
            }
        }

        if(ans==INT_MIN){
            return -1;
        }
        return ans;   
    }
};