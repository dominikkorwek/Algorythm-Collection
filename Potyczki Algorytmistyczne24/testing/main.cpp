#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> rozkazy;
int K[35];
char stan[35];
int n, m;

void znajdz_jedyny_mozliwy_przedzial() {
    bool ciag = false;
    int start = -1;
    int ostatnijeden = -1;
    int koniec = n;

    for (int i = 0; i < n; ++i) {
        if(stan[i] == '1' && !ciag){
            if(start == -1) {
                start = i;
                ciag = true;
            }
            else
                return;
        }else if(stan[i] =='0' && ciag){
            ciag = false;
            koniec = i - 1;
        }else if(stan[i] == '1' && ciag){
            ostatnijeden = i;
        }
    }
    int pierwszyzapytania = start;

    for( int i = start - 1;i>=0;i++){
        if(stan[i] !='?')
            i = -1;
        pierwszyzapytania--;
    }
    int k = ostatnijeden - start + 1;
    for(int i=0;i<start - pierwszyzapytania;i++){
        for(int j = 0;j<koniec - ostatnijeden;j++){
            K[k+i+j]++;
        }
    }
}

void rekurencja(int pozycja = 0) {
    if (pozycja == rozkazy.size()) {
        znajdz_jedyny_mozliwy_przedzial();
        return;
    }

    int a = rozkazy[pozycja].first - 1, b = rozkazy[pozycja].second - 1;
    if (stan[a] == '?' && stan[b] == '?') {
        // Rozbijamy na trzy opcje, ale dwie z nich redukujemy do jednej w kontekście modulo 2
        stan[a] = '0'; stan[b] = '1'; rekurencja(pozycja + 1);
        stan[a] = '1'; stan[b] = '1'; rekurencja(pozycja + 1);
        stan[a] = '1'; stan[b] = '0'; // Reset stanu
    }else if (stan[a] == '?') {
        stan[a] = 0; rekurencja(pozycja + 1);
        if(stan[b] == '1'){
            stan[a] = 1;rekurencja(pozycja + 1);
        }else{
            stan[b] = 1;rekurencja(pozycja + 1);
        }
    }else if(stan[b] =='?'){
        stan[b] = 1;rekurencja(pozycja + 1);
        if(stan[a] == 0){
            stan[b] = 0;rekurencja(pozycja + 1);
        }
        else{
            stan[a] = 0;rekurencja(pozycja + 1);
        }
    }
    else if(stan[a] == '1' && stan[b] == '0'){
        swap(stan[a],stan[b]);
        rekurencja(pozycja + 1);
    }

}


int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        rozkazy.emplace_back(a, b);
    }

    fill(begin(stan), end(stan), '?');
    rekurencja();

    // Wypisujemy wyniki
    for (int i = 1; i <= n; i++) {
        cout << K[i] % 2 << " ";
    }
    return 0;
}
