class StockSpanner {
    vector<int> spans;
    vector<int> stocks;
    int size;
public:

    StockSpanner() {
        size = 0;
    }
    
    int next(int price) {
        stocks.push_back(price);
        size++;
        if(size == 1) {
            spans.push_back(1);
            return 1;
        }
        else if(price < stocks[size-2]) {
            spans.push_back(1);
            return 1;
        }
        else{
            int i = size-2;
            while(i >= 0){
                if(stocks[i] > price) break;
                i -= spans[i];
            }
            spans.push_back(size-i-1);
            return size - i - 1;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
