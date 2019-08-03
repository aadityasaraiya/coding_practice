# C++ Cheat- sheet 


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


**Looping tips**

* If there is a while loop inside of another while loop, the condition in the first while loop has to be put inside the nested while loop as well. 

~~~
while(k>0)
{
    while(isString(s) && k> 0)
    {

    }	
}


~~~

* While comparing a counter to the size of say a string, the condition should be less than s.size() and **NOT** <= s.size()

~~~
int i = 0;

while(i<s.size())
{
    // Do something
    i++; 
}


~~~


## Mathematical operations 


**Division**

* When dividing two integers, if we want the result to be float, both the integers need to be static_cast<float> separately before the division. 


**ceil**

* To find the ceil, use the ceil function from the math.h library 
~~~
ceil(2.5) 
~~~



