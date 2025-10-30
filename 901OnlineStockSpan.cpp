class StockSpanner {
private:
    vector<int> prices;   
    stack<int> st;        

public:
    StockSpanner() {}

    int next(int price) {
        int i = prices.size();  
        prices.push_back(price);


        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }


        int prevGreaterIndex = st.empty() ? -1 : st.top();


        st.push(i);


        return i - prevGreaterIndex;
    }
};