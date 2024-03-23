public class Silnia {
    public static void main(String[] args) {
        System.out.println("witaj,podaj liczbe calkowita: ");
        int x=21;
        System.out.println("poddam liczbe: "+x+" uzyciu silni");
        System.out.println(silnia(x));
    }
    public static double silnia(int x){    //funkcja obliczajaca silnie
        double suma=1;
        if(x==0)                    // 0! = 1
            return 1;
        for(int i=1;i<=x;i++)   // liczenie silni poprzez mnozenie kolejnych liczb
            suma*=i;
        return suma;
    }
}