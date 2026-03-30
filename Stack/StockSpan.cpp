/*
 * Problem: Stock Span
 * Return an array of element where each element represent span of stock price at that ith day. Span is counted as no. of previous days at which stock price remain less than or equal to stock price at current day
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int> stock_price)
{
    vector<int> ans;
    stack<int> st;
    ans.push_back(1);
    st.push(0);

    for (int i = 1; i < stock_price.size(); i++)
    {

        while (!st.empty() && stock_price[st.top()] <= stock_price[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            ans.push_back(i + 1);
        }
        else
        {
            ans.push_back(i - st.top());
        }

        st.push(i);
    }

    return ans;
}

int main()
{
    vector<int> stock_price = {10, 20, 100, 20, 30, 40};
    vector<int> ans = stockSpan(stock_price);

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}