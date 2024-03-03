#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>::iterator begin, vector<int>::iterator end) {


}







// e.g.) print(vec.begin(), vec.end());
// e.g.) print(arr, arr+100); //サイズ100の場合
template<typename iterator>
void print(iterator begin, iterator end) {
    for (iterator p = begin; p < end; p++) cout << *p << " ";
    cout << endl;
}


int main() {
    int array[100];
    for (int i=0; i<100; i++) array[i] = i;
    print(array+10, array+80);
}