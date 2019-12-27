////////////////////////////////////////////////////////
// [5] Longest Palindromic Substring


class Solution {
public:
   string longestPalindrome(string s) {
        int maxlength=1;
        int start =0;
        int low, high;
        int n=s.length();
        if(n==0) return ""; // empty string
        if(n==1)  //1 character
        return s.substr(0,1);
         // One by one consider every character as center point of 
        // even and length palindromes
        for (int i=1;i<n; i++)
        {
            // Find the longest even length palindrome with center points
            // as i-1 and i.  
            low=i-1;
            high=i;
            while(low >=0 && high < n && s[low]==s[high])
            {
                if((high-low+1) > maxlength)
                {
                    start= low;
                    maxlength= high-low+1;

                }
                --low;
                ++high;
            }

            // Find the longest odd length palindrome with center 
           // point as i
            low= i-1;
            high=i+1;
            while(low >=0 && high < n && s[low]==s[high])
            {
                if((high-low+1) > maxlength)
                {
                    start= low;
                    maxlength= high-low+1;

                }
                --low;
                ++high;
            }
        }
        return s.substr(start, maxlength);

    }
};

//////////////////////////////////////////////////////
