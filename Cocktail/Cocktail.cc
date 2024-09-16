#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, char *argv[]){
    priority_queue<int> pq;
    int N, T, input;

    cin >> N;
    cin >> T;

    for(int i = 0; i < N; i++){
        cin >> input;
        pq.push(input);
    }

    while(!pq.empty()){
        int temp = pq.top();
        if(temp <= T*(N-1)){
            cout << "NO";
            return 0;
        }
        pq.pop();
        N--;
    }

    cout << "YES";
}