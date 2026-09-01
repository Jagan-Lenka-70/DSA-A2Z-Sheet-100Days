class Solution {
public:
    int minMoves(vector<string>& g, int e) {
        int m=g.size(),n=g[0].size();
        int sx=-1,sy=-1,l=0;
        vector<vector<int>>li(m,vector<int>(n,-1));
        
        int i=0;
        while(i<m){
            int j=0;
            while(j<n){
                g[i][j]=='S'?(sx=i,sy=j):0;
                g[i][j]=='L'?(li[i][j]=l++):0;
                j++;
            }
            i++;
        }
        
        if(!l)return 0;
        
        int fm=(1<<l)-1,me=e,ms=1<<l;
        long ts=1LL*m*n*ms*(me+1);
        vector<char>v(ts,0);
        
        queue<tuple<int,int,int,int>>q;
        int im=0,ie=me;
        long ic=(((1LL*sx*n+sy)*ms+im)*(me+1)+ie);
        v[ic]=1;
        q.emplace(sx,sy,im,ie);
        
        int s=0,dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty()){
            int ls=q.size();
            while(ls--){
                auto[x,y,mk,en]=q.front();
                q.pop();
                
                if(mk==fm)return s;
                
                if(!en&&g[x][y]!='R')continue;
                
                int d=0;
                while(d<4){
                    int nx=x+dir[d][0],ny=y+dir[d][1];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&g[nx][ny]!='X'&&en>0){
                        int ne=en-1;
                        g[nx][ny]=='R'?ne=me:0;
                        
                        int nm=mk;
                        if(g[nx][ny]=='L'){
                            int id=li[nx][ny];
                            if(id>=0)nm|=(1<<id);
                        }
                        
                        long nc=(((1LL*nx*n+ny)*ms+nm)*(me+1))+ne;
                        if(!v[nc]){
                            v[nc]=1;
                            q.emplace(nx,ny,nm,ne);
                        }
                    }
                    d++;
                }
            }
            s++;
        }
        return -1;
    }
};