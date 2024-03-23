import java.util.Scanner;

public class NWD {
    public static void main(String[] args) {

//wpisanie dwoch liczb
        Scanner skaner = new Scanner(System.in);
        int n = skaner.nextInt();
        int m = skaner.nextInt();
        int pom;
        System.out.print("NWD liczb " + n + " i " + m + " wynosi ");

//algorytm Euklidesa
        while (m != 0) {
            pom = m;
            m = n % m;
            n = pom;
        }
        if(n<0)
            n*=-1;
        System.out.println(n);

    }
}