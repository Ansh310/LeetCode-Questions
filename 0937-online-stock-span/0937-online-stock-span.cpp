class StockSpanner {
public:
    stack<pair<int, int>> s;
    int ind = -1;
    StockSpanner() {
        ind = -1;
        //s.clear();
    }
    
    int next(int price) {
        ind = ind + 1;
        while(!s.empty() && s.top().first <= price) s.pop();

        int ans = ind - (s.empty() ? -1 : s.top().second);

        s.push({price, ind});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */