import java.util.ArrayList;
import java.util.Iterator;

public class zad8 {
    public static void main(String[] args) {
        ArrayList<Integer> array = new ArrayList<>();
        for (int i = 1; i <= 10; i++)
            array.add(i);
        Integer k = 2;
        Iterator<Integer> iterator = array.iterator();

        NumberPredicate<Integer> predicate = new NumberPredicate<>(k);
        IteratorIterator<Integer> ite = new IteratorIterator<>(iterator,predicate);
        System.out.println(ite.next());
        System.out.println(ite.next());

    }

    public interface Predicate<T>{
        boolean accept(T arg);
    }
    public static class NumberPredicate<T> implements Predicate<T>{
        int actual_pos = 1;
        int number;

        public NumberPredicate(int number) {
            this.number = number;
        }

        @Override
        public boolean accept(T arg) {
            if(actual_pos==number){
                actual_pos = 1;
                return true;
            }
            actual_pos++;
            return false;
        }
    }

    public static class IteratorIterator<T> implements  Iterator<T>{
        private Iterator<T> iterator;
        private Predicate<T> predicate;
        private T nextelem;
        private boolean bhasnext = true;

        public IteratorIterator(Iterator<T> iterator, Predicate<T> predicate) {
            this.iterator = iterator;
            this.predicate = predicate;
            findnextValid();

        }
        public void findnextValid(){
            while(iterator.hasNext()){
                nextelem = iterator.next();
                if (predicate.accept(nextelem))
                    return;
            }
            bhasnext = false;
            nextelem = null;
        }

        @Override
        public boolean hasNext() {
            return bhasnext;
        }

        @Override
        public T next() {
            T next = nextelem;
            findnextValid();
            return next;
        }
    }
}
