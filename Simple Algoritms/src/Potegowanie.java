public class Potegowanie {
    public static void main(String[] args) {
        System.out.println("witaj, podaj liczbe oraz potege tej liczby (liczby musza byc calkowite)");
        double x=2;                                              //liczba ktora bedzie potegowana
        int k=1000;                                                 //liczba ktora bedzie potega
        System.out.println("spoteguje dla ciebie liczbę: "+x+" do potegi: "+k);
        System.out.println(potegowanie(x,k));
    }
    public static double potegowanie(double x, int k){              //funkcja liczaca potege
        boolean ujemne =false;
        double w = 1;
        if(k<0){                         // gdy k<0 to x^k = 1/(x^-k)
            k*=-1;
            ujemne = true;
        }
        while(k>0)                 //pętla liczaca
        {
            if (k%2 == 1)            //jesli k jest nieparzyste to podzielenie go przez 2 zaokragli
                w *= x;              //go w dol, dlatego mnozymy w przez x

            x*= x;
            k/=2;           //zmniejszamy k o polowe gdyz x^n = (x^(n/2))^(n/2)
        }
        if(ujemne)
            return 1/w;            /// gdy k<0 to x^k = 1/(x^-k)
        return w;
    }
}