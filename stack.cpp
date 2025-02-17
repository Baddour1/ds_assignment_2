#include "bits/stdc++.h"
using namespace std;
template <class  T>
class Stack{
    private:
        T* arr ;
        int top;
        int maxsize;
    public:
        Stack(){
            arr = new T[1];
            top = -1;
            maxsize = 1;
        }
        void resize(){
            maxsize *= 2;
            T* temp_t = new T[maxsize];
            for(int i = 0;i <= top;i++){
                temp_t[i] = arr[i];
            }
            arr = temp_t;

        }
        void push(T e){
            if(top == maxsize - 1){
                resize();
            }
            top++;
            arr[top] = e;
        }
        T pop(){
            if(top == -1){
                cout << "Stack is empty" << endl;
            }
            T e = arr[top];
            top--;
            return e;
        }
        T getTop(){
            return arr[top];
        }
        bool isEmpty(){
            return top == -1;
        }
        int size(){
            return top + 1;
        }
        void clear(){
            top = -1;
        }
        void print(){
            cout << "[";
            for(int i = top;i >= 0;i--){
                cout << arr[i] << ",";
            }
            cout << "]" << endl;
        }
};
int longest_valid_perentces(string s){
    Stack<char> open;
    Stack<char> close;
    int longest = 0;
    int current = 0;
    for(auto c : s){
        if(c == ')'){
            if(open.isEmpty()){
                if(current > longest){
                    longest = current;
                }
                current = 0;
            }else{
                current += 1;
                open.pop();
            }
        }else{
            current += 1;
            open.push('(');
        }
    }
    return current > longest ? current - 1: longest;

}
int main(){
    Stack<int> st;
    cout << longest_valid_perentces("(()") << endl;


}