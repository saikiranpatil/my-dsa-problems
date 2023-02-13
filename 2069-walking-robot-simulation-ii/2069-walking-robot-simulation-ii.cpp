class Robot {
public:
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<string> dir_str = {"East","North","West","South"};
    vector<int> pos = {0,0};
    int w, h, idx=0, count=0;
    
    Robot(int width, int height) {
        w=width;
        h=height;
    }
    
    void step(int num) {
        cout<<num<<endl;
        count = (count + num) % (2*(w + h - 2));
        
        if(count >=0 && count < w){
            pos={count, 0};
            idx = count==0 ? 3 : 0;
        }else if(count >= w && count < w + h - 1){
            pos={w-1, count - w + 1};
            idx=1;
        }else if(count >= w + h - 1 && count < 2*w + h - 2){
            pos={2*w + h - count - 3, h - 1};
            idx=2;
        }else{
            pos={0, 2*h + 2*w - count - 4};
            idx=3;
        }
        cout<<count<<" "<<pos[0]<<" "<<pos[1]<<" "<<dir_str[idx]<<endl;
    }
    
    vector<int> getPos() {
        return pos;
    }
    
    string getDir() {
        return dir_str[idx];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */