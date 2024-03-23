#include <bits/stdc++.h>

#define INF (long long)(1e18)

using namespace std;

struct jelly {  //cukierki
    int k;
    long long m;
    int c;

    bool operator<(const jelly& o) {    //potrzebne do sortowania
        return k < o.k;
    }
};

int N, K;
long long M;
vector<jelly> jellies;

long long dp[7005][7005]; //perfiks dla kolorow i reszty to min koszt uzyskania reszty w tym kolorze
bool exist[7005];
long long cost[7005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K >> M;
    for (int i = 0; i < N; ++i) {
        int k, m, c;
        cin >> k >> m >> c;
        jellies.push_back({k,m,c}); //dodawanie cukierkow
    }

    sort(jellies.begin(), jellies.end());   //sortowanie po kolorze

    for (int i = 0; i <= K; ++i)
        for (int j = 0; j <= M; ++j)
            dp[i][j] = INF;     //dodawanie do dp najwiekszych wartosci
    dp[0][0]=0;

    int prev_k = -1;
    int cur_k = 0;
    for (auto jelly : jellies) {
        if (jelly.k != prev_k) {    //podzielenie na kolory
            cur_k++;
            prev_k = jelly.k;
        }
        for (int r = 0; r < M; ++r) {   //dla pojedynczych wartosci cukierka
            int new_r = (r+jelly.m)%M;  //dodanie cukierka i liczenie % M

            dp[cur_k][new_r] = min(dp[cur_k][new_r], dp[cur_k-1][r]+jelly.c);//min dodania cukierka do zbioru albo zmiana cukierka na inny
        }
    }

    //znajdowanie i minimalizowanie reszt
    vector<int> rest;
    for (int i = 0; i < M; ++i) {
        if(dp[K][i] != INF){
            rest.push_back(i);  //dodajemy indeksy reszt
            exist[i] = 1;
            cost[i] = dp[K][i]; //dodajemy kosz cukierkow
        }else{
            cost[i] = INF;
        }
    }
    cost[0]=0;

    bool changer = true;
    while(changer){
        changer = false;
        int basic_size = rest.size();   //aby nie bylo time limit

        for(int i = 0; i < basic_size; ++i)
            for(int j = 0; j < basic_size; ++j){

                int new_rest = (rest[i] + rest[j])%M;   //reszta zlozona z dodania roznych ilosci zbiorow

                if(!exist[new_rest]){   //nie bylo takiej
                    rest.push_back(new_rest);
                    changer = true;
                    exist[new_rest] = 1;
                }
                else if(cost[rest[i]]+cost[rest[j]] < cost[new_rest])   //koszt mniejszy
                    changer = true;

                cost[new_rest] = min(cost[new_rest],cost[rest[i]]+cost[rest[j]]);   //min stara lub nowa
            }
    }

    for(int i =0 ;i<M;++i){
        if(cost[i] == INF)  //nie znaleziono
            cost[i]=-1;
        cout << cost[i]<<"\n";
    }

    return 0;
}
