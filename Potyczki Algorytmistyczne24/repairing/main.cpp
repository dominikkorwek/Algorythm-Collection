#include <bits/stdc++.h>

using namespace std;

struct Atom {
    int number;
    set<Atom*> neighbourhood;
};


long long r = 0;
stringstream output;

void addToFirstAtom(vector<Atom>& T) { //z in do graf
    unordered_map<int, bool> visited;

    // BFS z pierwszego wierzchołka
    queue<Atom*> queue;
    queue.push(&T[1]);
    visited[1] = true;

    while (!queue.empty()) {
        Atom* atom = queue.front();
        queue.pop();

        for (Atom* neighbour : atom->neighbourhood) {//sprawdza neighbourow
            if (!visited[neighbour->number]) {  //dodaje nie odwiedzone wieszcholki

                queue.push(neighbour);
                visited[neighbour->number] = true;

                int l = neighbour->number;
                if(T[1].neighbourhood.find(&T[l]) == T[1].neighbourhood.end()){ //laczenie wierzcholkow z 1 jezeli ich nie ma
                    output << "+ 1 " << l << "\n";
                    ++r;
                }
            }
        }
    }
}

void sekwencjaUsuwania(vector<Atom>& Tback) {//z out do graf
    unordered_map<int, bool> visited;

    // BFS z pierwszego wierzchołka
    queue<Atom*> queue;
    queue.push(&Tback[1]);
    visited[1] = true;
    vector<string> operationDeleteTo1;

    while (!queue.empty()) {
        Atom* atom = queue.front();
        queue.pop();

        for (Atom* neighbour : atom->neighbourhood) { //sprawdzenie sasuadow
            if (!visited[neighbour->number]) {

                queue.push(neighbour);
                visited[neighbour->number] = true;

                int l = neighbour->number;
                if(Tback[1].neighbourhood.find(&Tback[l]) == Tback[1].neighbourhood.end()){ //laczenie wierzcholkow z 1
                    operationDeleteTo1.push_back("- 1 " + to_string(l) + "\n");
                    ++r;
                }
            }
        }
    }
    reverse(operationDeleteTo1.begin(), operationDeleteTo1.end());

    for (const auto& operation : operationDeleteTo1)
        output << operation;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k, a, b;
    cin >> n >> k;
    vector<Atom> T(n+1);
    vector<Atom>  Tback(n+1);

    for(int i=1; i <= n; i++){
        T[i].number = i;
        Tback[i].number = i;
    }

    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        T[a].neighbourhood.insert(&T[b]);
        T[b].neighbourhood.insert(&T[a]);
    }

    addToFirstAtom(T);    //tworzenie polaczen dla wierzcholka 1
    cin >> k;


    for(int i=0;i<k;i++){
        cin>>a>>b;
        int c = min(a,b);
        int d = max(a,b);

        Tback[a].neighbourhood.insert(&Tback[b]);
        Tback[b].neighbourhood.insert(&Tback[a]);

        if(c==1)
            continue;


        if (T[d].neighbourhood.find(&T[c]) == T[d].neighbourhood.end()){
            output << "+ " << c << " " << d << "\n";    //dodaje polaczenie
            ++r;
        }
    }

    for(int i = 1 ;i <=n ;i++) //usuwa links miedzy wierzcholkami roznymi
        for(Atom *pAtom : T[i].neighbourhood)
            if(Tback[i].neighbourhood.find(&Tback[pAtom->number]) == Tback[i].neighbourhood.end() &&pAtom->number!=1 ){

                output << "- " << T[i].number << " " << pAtom->number << "\n";
                ++r;

                Tback[i].neighbourhood.insert(&Tback[pAtom->number]); //dodawanie aby nie powtrzalo sie
                Tback[pAtom->number].neighbourhood.insert(&Tback[i]);
            }


    sekwencjaUsuwania(Tback);   //usuwa links z wierzcholka 1

    cout<<r<<"\n";
    cout<<output.str();


    return 0;

}
