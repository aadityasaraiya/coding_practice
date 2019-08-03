### C++ Cheat- sheet 


**Strings**

* Pass complete string into a function using the following general prototype

~~~
void trialFunc(const std::string &s)
{

}
~~~

* Pass individual characters of a string using the following general prototype:

~~~
void isLetter(char &singleChar)
{
   if( (singleChar > = 'a' && singleChar <= 'z') || (singleChar > = 'A' && singleChar <= 'Z') 
    {
	return true; 
    }

return false; 
}
~~~

**Maps** 

* Check if a particular pair exists in a map- Key functions to note (umap.find(s[i]), umap.insert(make_pair(s[i],i)); 

~~~
        for(int i=0; i<s.length(); i++)
        {
            if(umap.find(s[i])== umap.end())
            {
                //umap.insert(make_pair<char, int>(s[i], 1));
                umap.insert(make_pair(s[i], 1));
            }
            
            else
            {
                it= umap.find(s[i]);
                it->second= it->second + 1;
            }
                            
        }
~~~





