/* Current list of features 
1) Support for matrix addition, subtraction and multiplication 
2) Accepts C++ matrices of type vector<vector<int>> 
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<assert.h>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

class SparseMat{
    public:
        // Representation for the Sparse matrix 
        unordered_map<pair<int,int>, int, pair_hash> uMap; 
        // Initialize number of rows and columns in the matrix 
        int numRows = 0, numCols = 0;
        // Default constructor for sparse matrix class
        SparseMat()= default;  
        // Overloaded Constructor for sparse matrix class     
        SparseMat(vector<vector<int>>& mat)
        {
            // Setting number of rows and columns 
            numRows = mat.size();
            numCols = mat[0].size();
            // Convert input matrix to its sparse representation 
            matToSparse(mat);
        }

        // Adding sparse matrices 
        SparseMat operator + (SparseMat& mat2)
        {
            SparseMat ans; 
            // Check that both of the sparse matrices are valid (aka they have been initialized)
            assert (numCols!=0 && numRows!=0);
            assert (mat2.numCols!=0 && mat2.numRows!=0);
            // Check if the two matrices can be added 
            assert(numCols== mat2.numCols && numRows == mat2.numRows);
            // Loop through the pairs in the uMap for first matrix 
            // p.first = pair[r,c] , p.second = val 
            for(auto p: uMap)
            {
                auto it = mat2.uMap.find(p.first);
                // If index pairs p is present in 
                if(it!= mat2.uMap.end()) 
                {
                    ans.uMap.insert({p.first, p.second + it->second});
                } 
            }
            return ans; 
        }

        // Subtracting sparse matrices 
        SparseMat operator - (SparseMat& mat2)
        {
            SparseMat ans; 
            // Check that both of the sparse matrices are valid (aka they have been initialized)
            assert (numCols!=0 && numRows!=0);
            assert (mat2.numCols!=0 && mat2.numRows!=0);
            // Check if the two matrices can be added 
            assert(numCols== mat2.numCols && numRows == mat2.numRows);
            // Loop through the pairs in the uMap for first matrix 
            // p.first = pair[r,c] , p.second = val 
            for(auto p: uMap)
            {
                auto it = mat2.uMap.find(p.first);
                // If index pairs p is present in 
                if(it!= mat2.uMap.end()) 
                {
                    ans.uMap.insert({p.first, p.second - it->second});
                } 
            }
            return ans; 
        }

        // Sparse matrix multiplication 
        SparseMat operator * (SparseMat& mat2)
        {
            SparseMat ans; 
            // Check that both of the sparse matrices are valid (aka they have been initialized)
            assert (numCols!=0 && numRows!=0);
            assert (mat2.numCols!=0 && mat2.numRows!=0);
            // Check if the two matrices can be multiplied
            assert(numCols== mat2.numRows);
            // Multiplying two matrices 
            for(auto x: uMap)
            {
                for(auto y: mat2.uMap)
                {
                    // Check if multiplication is required
                    // Col index of first mat = Row index of second mat  
                    if(x.first.second == y.first.first) 
                    {
                        ans.uMap[make_pair(x.first.first, y.first.second)]+= x.second * y.second;
                    }
                }
            }
            return ans; 
        }
        ///////////////////////// Helper functions 
        void printNumNZ() 
        {
            cout << "Number of non-zero elments in sparse matrix " << uMap.size() << endl; 
        }

        void printDims()
        {
            cout << "Number of rows in matrix: " << numRows << " " << "Number of columns in matrix: " << numCols << endl; 
        }

        void printSparseMat()
        {
            for(auto p: uMap)
            {
                cout << "Row index, Col index: " << p.first.first << " " << p.first.second << " Value: " << p.second << endl; 
            }
        }
        //////////////////////////////////////////////
    private:
        // Convert the input matrix into its sparse representation (Requires O(n^2) operation once)
        void matToSparse(vector<vector<int>>& mat)
        {
            for(int i= 0; i< numRows; i++)
            {
                for(int j= 0; j< numCols; j++)
                {
                    // Adding all nonzero elements
                    // Insert row and corresponding column if its a nonzero element 
                    if(mat[i][j]!= 0) uMap.insert({make_pair(i,j), mat[i][j]}); 
                }
            }
        }
};

int main()
{
    // Create two dummy matrices 
    vector<vector<int>> mat1 {
                                {1, 2, 0}, 
                                {0, 3, 7}, 
                                {0, 0, 1}, 
                             };

     vector<vector<int>> mat2 {
                                {1, 2, 0}, 
                                {0, 3, 7}, 
                                {0, 0, 1}, 
                             };   

    SparseMat sMat1(mat1);
    SparseMat sMat2(mat2);

    // Add two sparse matrices 
    SparseMat sMat3 = sMat1 * sMat2; 

    sMat3.printSparseMat();


    
}