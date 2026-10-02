class Solution {
public:
vector<pair<int , int>>ordi {{-1,0} , {1,0} , {0,-1} , {0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int startpix = image[sr][sc];
        if(image[sr][sc] == color)return image;
        queue<pair<int , int>>q;
        image[sr][sc] = color;
        q.push({sr , sc});
        while(!q.empty()){
            pair<int , int>cord = q.front();
            q.pop();
            for(auto &k : ordi){
                int new_i = cord.first+k.first;
                int new_j = cord.second+k.second;

                if( new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&image[new_i][new_j] == startpix){
                    image[new_i][new_j] = color;
                    q.push({new_i , new_j});
                }

            }
        }

        return image;
    }
};