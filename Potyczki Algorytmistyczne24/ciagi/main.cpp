#include <bits/stdc++.h>


using namespace std;

vector<int> values;
map<int, int> counts;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, element;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> element;
        counts[element]++;
    }

    for (const auto &pary: counts)
        values.push_back(pary.second); //bierzemy sama ilosc wystapien

    sort(values.begin(), values.end());	//sortujemy aby wieksze byly z tylu

    int countNumber = values.size();
    int index_min = 0;
    int index_maks = values.size() - 1;


    while (index_min != index_maks) {	//dopoki mamy ciagi do sprawdzania
        int ciag_min = values[index_min];
        int ciag_maks = values[index_maks];

        if(ciag_min < ciag_maks){
            values[index_maks] -= values[index_min]; // dodajemy elementy ( zmniejszamy liczbe elementow ktore mozemy dodac)
            index_min++;
            countNumber--;
        }
        else{
            values[index_min] -= values[index_maks] - 1; //bierzmy kolejny ciag do lidera
            index_maks--;
        }

    }
    cout << countNumber;
    return 0;
}