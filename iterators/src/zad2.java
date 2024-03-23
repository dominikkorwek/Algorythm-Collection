public class zad2 {
    public static void main(String[] args) throws NoAnswerExeption {
        int[] T = {4,4,4,4};
        System.out.println(getSecondSmallest(T));
    }
    public static int getSecondSmallest(int[] T) throws NoAnswerExeption {
        int n = T[0];
        Integer m = null;
        for (int i = 1;i<T.length;i++) {
            if (T[i] < n) {
                m = n;
                n = T[i];
            }
            else if (T[i] != n && ( m == null ||  T[i] < m )) {
                m = T[i];
            }

        }
        if (m == null)
            throw new NoAnswerExeption();

        return m;
    }

    private static class NoAnswerExeption extends Exception {
        public NoAnswerExeption(){
            super();
        }
    }
}
