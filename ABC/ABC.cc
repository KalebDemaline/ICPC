#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    int A, B, C;
    string order;

    cin >> A;
    cin >> B;
    cin >> C;

    if(B < A) swap(A, B);
    if(C < B) swap(B, C);
    if(B < A) swap(A, B);

    cin >> order;

    for(int i = 0; i < order.length(); i++){
        string temp = order.substr(i, 1);
        if(temp == "A") cout << A << " ";
        else if(temp == "B") cout << B << " ";
        else cout << C << " ";
    }
}