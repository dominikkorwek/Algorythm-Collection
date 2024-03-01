
public class zad3 {
    public static void main(String[] args) {
        int[] T = {3,4,5,2,1};
        System.out.println(nextPermutation(T));

        for (int i : T){
            System.out.print(i+" ");
        }
    }

    public static boolean nextPermutation(int[] T){

        for (int i = T.length - 2;i>=0;i--){

            if(T[i]<T[i+1]){    //find fist digit that is smaller than digit ahead
                for(int j=T.length-1;j>i;j--){

                    if (T[i]<T[j]){    //find first digit that is bigger than the chosen one to swap them
                        swap(T,i,j);    //swap digits
                        reverse(T,i+1,T.length-1);  //reverse digits after the chosen one to make increasing sequence
                        return true;
                    }
                }
            }
        }

        return false;
    }
    private static void swap(int[] T, int i, int j) {
        int temp = T[i];
        T[i] = T[j];
        T[j] = temp;
    }
    private static void reverse(int[] T, int start, int end) {
        while (start < end) {
            swap(T, start, end);
            start++;
            end--;
        }
    }
}
