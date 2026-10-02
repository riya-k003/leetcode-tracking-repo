class Solution {
public:
void dfs(int i , int j , int color ,  int startpixel , vector<vector<int>>& image){
    int m = image.size();
    int n = image[0].size();
    if(image[i][j] != startpixel){
        return;
    }
    if(image[i][j] == startpixel ){
        image[i][j] = color;
    }
    if(i+1 < m)dfs(i+1 , j , color , startpixel , image);
    if(i-1 >= 0)dfs(i-1 , j ,  color , startpixel , image);
    if(j+1 < n)dfs(i , j+1 , color , startpixel , image);
    if(j-1 >= 0)dfs(i , j-1 ,color , startpixel , image);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int startpixel = image[sr][sc];
        if(image[sr][sc] == color)return image;

      dfs(sr , sc , color , startpixel ,  image);

        return image;
    }
};