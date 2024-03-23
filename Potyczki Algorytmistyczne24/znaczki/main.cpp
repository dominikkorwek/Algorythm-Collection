#include <iostream>
#include <map>
#include <vector>

using namespace std;
int T[300000];
map<int, int> counts;	//mapa counts znaczkow;

void posibilities(int ilosc){
    for(int i = 0; i < ilosc; i++)
        T[i] += ( (i + 1) * (ilosc/(i + 1) ) );	//dla kazdej counts obliczana jest ilosc znaczkow na osobe

}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,element;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> element;
        counts[element]++;
    }

    for (const auto &pary: counts) {	//eksport counts znaczkow danego typu
        posibilities( pary.second );
    }

    for(int i=0; i < n; i++){
        cout<<T[i]<<" ";
    }


    return 0;
}