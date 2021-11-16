#include <iostream>
#include <stack>
using namespace std;
// Идея: добавлять не шарики, а количество подряд идущих шариков этого цвета
// (или пары цвет, количество)


int main() {
    size_t N;
    cin >> N;
    stack<pair<size_t, size_t>> st;
    size_t num_of_deleted = 0;
    while (N--){
        uint16_t color;
        cin >> color;
        if (st.empty())
            st.push({color, 1});
        else {
            if (st.top().first == color)
                st.push({color, st.top().second + 1});
            else {
                size_t curr_size = st.top().second;
                if (curr_size >= 3){
                    for (; curr_size > 0; curr_size--){
                        st.pop();
                        num_of_deleted++;
                    }
                    if (st.top().first == color)
                        st.push({color, st.top().second + 1});
                    else
                        st.push({color, 1});
                }
                else
                    st.push({color, 1});
            }
        }
    }
    if (!st.empty()){
        size_t curr_size = st.top().second;
        if (curr_size >= 3) {
            for (; curr_size > 0; curr_size--) {
                st.pop();
                num_of_deleted++;
            }
        }
    }
    printf("%d", num_of_deleted);
    return 0;
}
