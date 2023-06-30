class Solution {
public:
    static const int maxN=20004;
    int p[maxN],size[maxN];
    void make_set(int n)
    {
        for(int i=0;i<n;i++)
        {
            p[i]=i;
            size[i]=1;
        }
    }
    int find(int a)
    {
        if(a==p[a]) return a;
        return p[a]=find(p[a]);
    }
    void Union(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            if(size[b]>size[a]) swap(a,b);
            p[b]=a;
            size[a]+=size[b];
        }
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        int grid[row][col];
        memset(grid,0,sizeof(grid));
        int top=row*col,bottom=row*col+1;
        p[top]=top,p[bottom]=bottom;
        size[top]=size[bottom]=1;
        make_set(row*col);
        for(int i=cells.size()-1;i>=0;i--)
        {
            int x=cells[i][0]-1,y=cells[i][1]-1;
            int idx1=x*col+y;
            grid[x][y]=1;
            int dx[]={0,-1,0,1};
            int dy[]={1,0,-1,0};
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k],ny=y+dy[k];
                if(nx>=0&&nx<row&&ny>=0&&ny<col&&grid[nx][ny]==1)
                {
                    int idx2=nx*col+ny;
                    Union(idx1,idx2);
                    if(nx==0) Union(idx2,top);
                    if(nx==row-1) Union(idx2,bottom);
                }
            }
            if(x==0) Union(idx1,top);
            if(x==row-1) Union(idx1,bottom);
            if(find(top)==find(bottom)) return i;
        }
        return -1;
    }
};