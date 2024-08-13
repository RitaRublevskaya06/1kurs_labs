#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");

    stack <char> st;
    string s, answer = "Скобки расставлены верно";
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        }

        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (!st.empty() &&
                ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '[' && s[i] == ']') ||
                    (st.top() == '{' && s[i] == '}'))) {
                st.pop();
            }
            else {
                answer = "Скобки расставлены не верно";
            }
        }
    }
    if (!st.empty()) {
        answer = "Скобки расставлены не верно";
    }
    std::cout << answer << std::endl;
    return 0;
}