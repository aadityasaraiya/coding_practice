# C++ Cheat- sheet 

**Vectors**

* Sorting a vector

~~~
sort(vec.begin(), vec.end());
~~~

* Passing a vector of lists into a function  

~~~
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
~~~

* Size of a vector 

~~~
std::vector<int>vec;
vec.size()
~~~

* Initializing a vector with zeros 

~~~
vector<int> ans(<size_val>)
~~~

* Insert element at start of vector 

~~~
auto it = vec.insert(vec.begin(), 3); 
~~~

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

* To check if string is empty 

~~~
std::string s;
s.empty(); 
~~~

* To convert upper-case to lower case

~~~
s[j]= ::tolower(s[j]);
~~~

* To convert a character to an integer 

~~~
char a= '1';
int ai= a- '0'; 
~~~

* To find length of string 

~~~
string s;
s.length(); 
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

**power**

~~~
pow(a,b)  = a^b
~~~

**Max and min values of types**

* In cases where you are accumulating integers, the value could go above the max value of int or go below the min value of int. 
  In such cases, we may have to return INT_MAX or INT_MIN as an output. 


## Arrays 

**To fill an array with given value**

~~~
std::fill_n(dp, 1000, -1);
~~~

## Structs in C++

* While defining an object of a C++ struct, the struct keyword has to be always used with it 

~~~

struct Node* temp= newNode(5);

~~~ 


## new operator 

* The new operator requires the name of a class. It returns a pointer to the object of that class and allocates memory for that object. 

~~~
struct Node* temp= new Node; 

~~~

## Queues

~~~
std::queue<int> q;    // To create an empty queue
~~~

* Add elements to the queue
~~~
q.push(s);
~~~

* Get first element of the queue

~~~
v= q.front();
~~~

* Removes first element from the queue  (Note: Keep in mind that this function has a void return type)

~~~
q.pop();
~~~