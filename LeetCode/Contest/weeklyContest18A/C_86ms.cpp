class Solution {
public:

    struct Node{
        int p,c;
        bool operator < (const Node& a) const {
            return p<a.p;
        }
    };
    
    static int cmp(pair<int,int>& a, pair<int, int>& b){
        return a.second<b.second;
    }

    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<Node> q;
        vector<pair<int,int> > pc;
        for(int i=0;i<Profits.size();i++){
            pc.push_back(make_pair(Profits[i],Capital[i]));
        }
        sort(pc.begin(),pc.end(),cmp);
        int i=0;
        while(k--){
            for(;i<pc.size() && pc[i].second<=W;i++)
                q.push(Node{pc[i].first,pc[i].second});
            if(q.empty()) break;
            Node t = q.top();q.pop();
            W+=t.p;
        }
        return W;
    }
};




