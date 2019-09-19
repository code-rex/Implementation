//Time :n*2^n
bool isPalindrome(string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
void palinpart(string& A,vector<string>&aux,vector<vector<string>>&ans,int start)
{
    if(start == A.length())
    {
        ans.push_back(aux);
        return ;
    }
    for(int i=start;i<A.size();i++)
    {
        if(isPalindrome(A,start,i))
        {
            string k = A.substr( start, i-start+1 );
            aux.push_back(k);
            palinpart(A,aux,ans,i+1);
            aux.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>>ans;
    vector<string>aux;
    palinpart(A,aux,ans,0);
    return ans;
}
