#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> commend;
int K[35];

string earlier_sequention(string sequention,int T, int F){
    string pom = sequention;
    if(sequention[T] == '1' && sequention[F] == '0')
        swap(pom[T],pom[F]);
    return pom;
}

void posibleToMake(string sequention, int k, reverse_iterator<vector<pair<int, int>>::iterator> it){
    if(it == commend.rend()){
        K[k]++;
        return;
    }

    int T = it->first - 1 ,F =it->second - 1;

    if(earlier_sequention(sequention,T,F) == sequention)
        posibleToMake(sequention,k,next(it));

    if(sequention[T]==sequention[F])
        return;

    string pom = sequention;
    swap(sequention[T],sequention[F]);

    if(earlier_sequention(sequention,T,F) == pom)
        posibleToMake(sequention,k,next(it));
}

void generateSequences(int n) {
    for (int k = 2; k <= n-1; ++k) {
        // Przechodzi przez wszystkie możliwe pozycje bloku "k" jedynek
        for (int start = 0; start <= n - k; ++start) {
            string sequence(n, '0'); // Tworzy ciąg "0" o długości "n"
            // Umieszcza blok "k" jedynek w odpowiedniej pozycji
            for (int j = start; j < start + k; ++j) {
                sequence[j] = '1';
            }
            // Wypisuje wygenerowany ciąg
            posibleToMake(sequence,k,commend.rbegin());
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        commend.emplace_back(a,b);
    }

    generateSequences(n);
    K[1] = n;
    K[n] = 1;
    for(int i=1;i<=n;i++)
        cout<<K[i]%2<<" ";
    return 0;
}