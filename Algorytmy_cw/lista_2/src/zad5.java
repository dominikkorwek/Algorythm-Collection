import java.util.Iterator;

public class zad5 {
    public static void main(String[] args) {
        Iterator<Integer> iterator = new PrimeIterator();
        for (int i=0;i<100;i++){
            System.out.println(iterator.next());
        }
    }

    public static class PrimeIterator implements Iterator<Integer>{
        int pos = 2;

        @Override
        public boolean hasNext() {
            return false;
        }

        @Override
        public Integer next() {
            while(!PrimeNumber(pos)){
                pos++;
            }

            return pos++;
        }

        private boolean PrimeNumber(int n){
            if(n < 2)
                return false;

            for(int i = 2; i*i<=n; i++ )
                if (n%i==0)
                    return false;

            return true;
        }
    }
}
