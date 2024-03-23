#include <iostream>

using namespace std;

long long sum = 0;
int paintings[30];

bool paintingCount(int w, int h, int index) {
    if(index <0){
        if(h * w != 0)
            return 0;
        return 1;
    }

    if(paintings[index] <= h){	//jezeli wysokosc obrazow mniejsza od wysokosci ciany
        if(paintings[index] <= w){	//to samo dla dlugosci

            long long countX = w/paintings[index];		//sprawdza ile zmiesci sie obrazow dla szerokosci
            long long countY = h/paintings[index];		//to samo dal wysokosci

            sum+=countX * countY;	//dodaje ilosc obrazow

            return paintingCount(w - countX * paintings[index],countY * paintings[index],index - 1)	//dzielimy sciane na mniejsze czesci
            && paintingCount(w,h - countY * paintings[index],index - 1);

        } else
            return paintingCount(w,h,index - 1);
    }
    else
        return paintingCount(w,h,index - 1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int wallWidth, WallHeight, n;
    cin >> WallHeight >> wallWidth>>n;

    for (int i = 0; i < n; ++i)
        cin >> paintings[i];


    if(!paintingCount(wallWidth,WallHeight,n-1))
        cout<<-1;
    else
        cout<<sum;
    return 0;
}
