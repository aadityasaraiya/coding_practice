///////////////////////////////////////////////////////////////
// [200] Number of islands unoptimized using unordered set 


class Solution {
public:

    struct pair_hash{
      
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1,T2> &p) const 
        {
            std::size_t h1 = std::hash<T1>{} (p.first);
            std::size_t h2 = std::hash<T2>{} (p.second);
            return h1 ^ h2; 
        }
    };
    
    void dfsMain(vector<vector<char>>& grid, unordered_set<pair<int, int>, pair_hash> &visited, 
             int row, int col, int num_rows, int num_cols)
    {
        
        // Insert pair to set 
        visited.insert(make_pair(row,col));
        
        if(row<0 || row> num_rows-1 || col<0 || col > num_cols - 1 || grid[row][col]!='1')
        {
            return;
        }
        
    
        if(visited.find(make_pair(row-1, col))== visited.end())
        {
            dfsMain(grid, visited, row-1,   col,   num_rows, num_cols); 
        }

        if(visited.find(make_pair(row, col-1))== visited.end())
        {
            dfsMain(grid, visited, row,   col-1, num_rows, num_cols);
            
        }
        
        if(visited.find(make_pair(row+1, col))== visited.end())
        {
            dfsMain(grid, visited, row+1, col, num_rows, num_cols);
            
        }
        
        if(visited.find(make_pair(row,   col+1))== visited.end())
        {
            dfsMain(grid, visited, row,   col+1, num_rows, num_cols);   
        }
        
        
        return; 
    }
    
    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty())
        {
            return 0; 
        }
        
        int num_rows= grid.size();
        int num_cols= grid[0].size(); 
        

        
        // Store the pairs of [r,c] which are already visited 
        unordered_set<pair<int, int>, pair_hash> visited;
        
        
        int num_islands= 0; 
        
        for(int row=0; row <num_rows; row++)
        {
            for(int col=0; col <num_cols; col++)
            {
                // If not visited, do DFS, pass vistied by reference and change it 
                if(visited.find(make_pair(row,col))== visited.end() && grid[row][col]== '1')
                {
                    dfsMain(grid, visited, row,  col, num_rows, num_cols);
                    num_islands ++; 
                }
                
            }
        }
        
        return num_islands; 
        
        
    }
};


///////////////////////////////////////////////////////////////

// replace set with a vector of characters to be able to store visited or not 

// [200] Number of islands optimized

class Solution {
public:
   
void dfsMain(vector<vector<char>>& grid, vector<vector<int>> &visited, 
         int row, int col, int num_rows, int num_cols)
{

    if(row<0 || row> num_rows-1 || col<0 || col > num_cols - 1 || grid[row][col]!='1') return;

    // Insert pair to set
    visited[row][col] = 1; 
        
    // Left 
    if( row-1 >= 0 && visited[row-1][col]!= 1) dfsMain(grid, visited, row-1, col, num_rows, num_cols); 
    // Right 
    if(row + 1 <= num_rows-1 && visited[row+1][col]!= 1) dfsMain(grid, visited, row+1, col, num_rows, num_cols); 
    // Up 
    if(col-1 >= 0 && visited[row][col-1]!= 1) dfsMain(grid, visited, row, col-1, num_rows, num_cols);     
    //Down 
    if(col + 1 <= num_cols-1 && visited[row][col+1]!= 1) dfsMain(grid, visited, row, col+1, num_rows, num_cols); 

    return; 
}
    
int numIslands(vector<vector<char>>& grid) {

    if(grid.empty()) return 0; 

    int num_rows= grid.size();
    int num_cols= grid[0].size(); 
    
    vector<vector<int>> visited(num_rows, vector<int>(num_cols, 0)); 
    int num_islands= 0; 

    for(int row=0; row <num_rows; row++)
    {
        for(int col=0; col <num_cols; col++)
        {
            // If not visited, do DFS, pass vistied by reference and change it 
            if(visited[row][col] == 0 && grid[row][col] == '1')
            {
                dfsMain(grid, visited, row,  col, num_rows, num_cols);
                num_islands ++; 
            }

        }
    }

    return num_islands; 
}
};

/////////////////////////////////////////////////////////////////////////////////
// [695] Max area of island 
class Solution {
public:
    
    int currArea = 0; 
    int maxArea = 0; 
    
    void dfsMain(vector<vector<int>>& grid, vector<vector<int>> &visited, int row, int col, int num_rows, int num_cols)
    {

        if(row<0 || row> num_rows-1 || col<0 || col > num_cols - 1 || grid[row][col]!= 1) return;

        // Insert pair to set
        visited[row][col] = 1; 
        currArea ++; 

        // Left 
        if( row-1 >= 0 && visited[row-1][col]!= 1) dfsMain(grid, visited, row-1, col, num_rows, num_cols); 
        // Right 
        if(row + 1 <= num_rows-1 && visited[row+1][col]!= 1) dfsMain(grid, visited, row+1, col, num_rows, num_cols); 
        // Up 
        if(col-1 >= 0 && visited[row][col-1]!= 1) dfsMain(grid, visited, row, col-1, num_rows, num_cols);     
        //Down 
        if(col + 1 <= num_cols-1 && visited[row][col+1]!= 1) dfsMain(grid, visited, row, col+1, num_rows, num_cols); 

        return; 
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
    if(grid.empty()) return 0; 

    int num_rows= grid.size();
    int num_cols= grid[0].size(); 
    
    vector<vector<int>> visited(num_rows, vector<int>(num_cols, 0)); 
    int num_islands= 0; 

    for(int row=0; row <num_rows; row++)
    {
        for(int col=0; col <num_cols; col++)
        {
            // If not visited, do DFS, pass vistied by reference and change it 
            if(visited[row][col] == 0 && grid[row][col] == 1)
            {
                dfsMain(grid, visited, row,  col, num_rows, num_cols);
                maxArea = max(currArea, maxArea); 
                currArea = 0; 
            }

        }
    }

        
        return maxArea; 
        
    }
};

//////////////////////////////////////////////////////////////////////////////
// [1254] Number of closed islands 

class Solution {
public:
    
    bool is_closed_island = true; 
    
    void dfsMain(int r, int c, int num_rows, int num_cols, vector<vector<int>>& grid, vector<vector<int>>& visited)
    {
        if(r < 0 || r > num_rows-1 || c < 0 || c > num_cols-1 || grid[r][c]!= 0) return; 
        
        // This particular index has been visited
        visited[r][c] = 1;
        
        //if(!is_closed_island) return; 

        // There is an index in the island which is at the edge of the grid, we don't have a closed island 
        if(r == 0 || r == num_rows-1 || c == 0 || c == num_cols-1) 
        {
            is_closed_island = false; 
        }
                
        // Left 
        if(r-1 >= 0 && visited[r-1][c]!= 1)          dfsMain(r-1, c, num_rows, num_cols, grid, visited); 
        // Right 
        if(r+1 <= num_rows-1 && visited[r+1][c]!= 1) dfsMain(r+1, c, num_rows, num_cols, grid, visited); 
        // Up 
        if(c-1 >=0 && visited[r][c-1]!= 1)           dfsMain(r, c-1, num_rows, num_cols, grid, visited);
        // Down
        if(c+1 <= num_cols-1 && visited[r][c+1]!= 1) dfsMain(r, c+1, num_rows, num_cols, grid, visited);
        return; 
    }
    
    
    int closedIsland(vector<vector<int>>& grid) {
        
        // Grid dimensions 
        int num_rows = grid.size(); 
        int num_cols = grid[0].size(); 
        
        // Counting number of closed islands 
        int num_closed_islands = 0; 
        
        // Storing information of visited points 
        vector<vector<int>> visited(num_rows, vector<int>(num_cols, 0));
        
        for(int r=0; r< num_rows; r++)
        {
            for(int c=0; c< num_cols; c++)
            {
                // If we haven't visited it alredy
                // Land is designated by 1 in this case
                if(grid[r][c] == 1)
                {
                    visited[r][c] = 1;
                    continue; 
                }
                
                if(visited[r][c] == 0 && grid[r][c] == 0)
                {
                    // Main driver DFS call 
                    dfsMain(r,c, num_rows, num_cols, grid, visited);
                    // Check for if the island is closed or not 
                    if(is_closed_island) num_closed_islands ++; 
                    is_closed_island = true; 
                }
            }
        }
        
        return num_closed_islands; 
        
        
    }
};


////////////////////////////////////////////////////////////////////////////
// [463] Island Perimeter 

class Solution {
public:
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int perimeter = 0; 
        int curr_lengths = 0; 
        
        for(int r=0; r< num_rows; r++)
        {
            for(int c=0; c< num_cols; c++)
            {
                curr_lengths = 4; 
                // If its an element in the island 
                if(grid[r][c])
                {
                    // Check for top 
                    if(r!= 0)
                    {
                       if(grid[r-1][c] == 1) curr_lengths--;   
                    }
                    
                    // Check for down 
                    if(r!= num_rows - 1)
                    {
                        if(grid[r+1][c] == 1) curr_lengths--; 
                    }
                    
                    // Check for left 
                    if(c!= 0)
                    {
                        if(grid[r][c-1] == 1) curr_lengths--; 
                    }
                    
                    // Check for right 
                    if(c!= num_cols - 1)
                    {
                        if(grid[r][c+1] == 1) curr_lengths--; 
                    }
                    
                    //cout << "Current addition: " << curr_lengths <<  " Perimeter: " << perimeter << endl; 
                    perimeter+= curr_lengths; 
                }
                
            }
        }
        
        return perimeter; 
    }
};

//////////////////////////////////////////////////////////////////////////
// [934] Shortest bridge (using manhattan distance method)



/*
Key steps 

2) Find the  two indices where the distance between them is minimum. 
3) Use a method to find how many blocks need to be traversed to be able to reach to that 
*/


class Solution {
public:
    
    vector<pair<int,int>> extractIsland(int r, int c, int num_rows, int num_cols, vector<vector<int>>& A,  vector<vector<int>>& visited, vector<pair<int,int>>& island)
    {
        if(r < 0 || r > num_rows-1 || c < 0 || c > num_cols-1 || A[r][c]!= 1) return island; 
        
        // This particular index has been visited
        visited[r][c] = 1;
        
        // Push r and c index to island
        island.push_back(make_pair(r,c)); 
                
        // Left 
        if(r-1 >= 0 && visited[r-1][c]!= 1) island = extractIsland(r-1, c, num_rows, num_cols, A, visited, island); 
        // Right 
        if(r+1 <= num_rows-1 && visited[r+1][c]!= 1) island = extractIsland(r+1, c, num_rows, num_cols, A, visited, island); 
        // Up 
        if(c-1 >=0 && visited[r][c-1]!= 1)           island = extractIsland(r, c-1, num_rows, num_cols, A, visited, island);
        // Down
        if(c+1 <= num_cols-1 && visited[r][c+1]!= 1) island = extractIsland(r, c+1, num_rows, num_cols, A, visited, island);
        return island;         
    }    
    
    int shortestBridge(vector<vector<int>>& A) {
        
        
        // Number of columns and rows in the matrix 
        int num_rows = A.size();
        int num_cols = A[0].size(); 
        
        // To store all the visited points
        vector<vector<int>> visited(num_rows, vector<int>(num_cols, 0));
        
        
        vector<vector<pair<int,int>>> islands; 
        
        for(int r= 0; r< num_rows; r++)
        {
            for(int c=0; c<num_cols; c++)
            {
                if(visited[r][c] == 0 && A[r][c] == 1)
                {
                    vector<pair<int,int>> island; 
                    island= extractIsland(r,c,num_rows, num_cols, A, visited, island);
                    islands.push_back(island);
                    island.clear(); 
                }
            }
        }
        
        
        vector<pair<int,int>> island1 = islands[0]; 
        vector<pair<int,int>> island2 = islands[1]; 
        
        int dist = 0;
        int min_dist = INT_MAX; 
        
        for(int i=0; i<island1.size(); i++)
        {
            for(int j=0; j<island2.size(); j++)
            {
                dist = (abs(island1[i].first - island2[j].first) + abs(island1[i].second - island2[j].second))-1;
                min_dist = min(dist, min_dist);
            }
        }
        
        return min_dist; 
        
    }
};
