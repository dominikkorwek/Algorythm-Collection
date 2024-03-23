#include <iostream>

using  namespace std;
const int exam_number = 18;
const int maxPoints = 10;
int T[maxPoints + 1];	//dynamiczna

string whoWin(){
    int algosGrade = 0;
    int bajtekGrade = 0;


    for(int i=0; i < exam_number; i++){	//wczytywanie wyniku algosi
        int a;
        cin >>a;
        algosGrade+=a;
        T[a]++;			//do tablicy o indeksie wynik dodawane jest 1
    }
    for(int i=0; i < exam_number; i++){	//wczytywanie wyniku bajtka
        int a;
        cin >>a;
        bajtekGrade+=a;	//do tablicy o indeksie wynik odejmowane jest 1
        T[a]--;
    }
    if(algosGrade > bajtekGrade)
        return "Algosia";

    else if (bajtekGrade > algosGrade)
        return "Bajtek";

    int indeks = maxPoints;
    while(indeks >= 0){		//jezeli wynik jest wiekszy od 0 to oznacza ze algosia miala wiecej ocen
        if (T[indeks] > 0)
            return "Algosia";

        else if(T[indeks] < 0)	//na odwrot
            return "Bajtek";

        else			//jak rowne to dalej
            indeks --;
    }

    return "remis";
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cout<<whoWin();
    return 0;
}