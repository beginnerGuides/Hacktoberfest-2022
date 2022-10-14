class Solution {
	public:            
		bool palindrome(string s,int st,int end){
        while(st<=end)
        {
            if(s[st]==s[end])
            {
                st++;
                end--;
            }
            else
                return false;
        }
       return true;
    }         
    
    
    vector<vector<string>> partition(string s) {
        unordered_map<int,vector<vector<string>>> um;
        vector<string> temp2;
        um[-1].push_back(temp2);
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(palindrome(s,j,i))
                {
                    vector<vector<string>> first = um[j-1];
                    string str = s.substr(j,i-j+1);
                    for(int k=0;k<first.size();k++)
                    {
                        vector<string> v = first[k];
                        v.push_back(str);
                        um[i].push_back(v);
                    }
                }
            }
        }
        
        return um[s.length()-1];
    }
};

