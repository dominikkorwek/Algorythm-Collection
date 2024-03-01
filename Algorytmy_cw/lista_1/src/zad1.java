public class zad1 {
    public static void main(String[] args) {
        int[] T = {1,4,6,4,1};
        int n = T.length + 1 ;

        int[] M = new int[n];
        M[0] = 1;
        M[n-1] = 1;

        for(int i =1;i<n-1;i++){
            M[i] = T[i] + T[i-1];
        }

        for(int i : M){
            System.out.println(i + " ");
        }
    }
}
