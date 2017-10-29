#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string str){
    std::stack<char> st;
    char a;
    for(int i=0;i<str.length();i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            st.push(str[i]);
        }else{
            switch(str[i])
            {
            case ')':
                a = st.top();
                st.pop();
                if(a == '{' || a == '['){
                    return false;
                }
                break;
            case '}':
                a = st.top();
                st.pop();
                if(a == '(' || a == '['){
                    return false;
                }
                break;
            case ']':
                a = st.top();
                st.pop();
                if(a == '{' || a == '('){
                    return false;
                }
                break;
            }
        }
    }
    return true;
}

int main(){
    string exp = "{()[}]";
    if(isBalanced(exp)){
        cout<<"Balanced";
    }else{
        cout<<"Not Balanced";
    }
return 0;
}
