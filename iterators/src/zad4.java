import java.util.ArrayList;
import java.util.Iterator;

public class zad4 {
    public static void main(String[] args) {
        ArrayList<Integer> array1 = new ArrayList<>();
        ArrayList<Integer> array2 = new ArrayList<>();
        for (int i = 1; i <= 3; i++){
            array1.add(i);
            array2.add(i*5);
        }
        array1.add(1);
        array1.add(2);
        Iterator<Integer> iterator1 = array1.iterator();
        Iterator<Integer> iterator2 = array2.iterator();

        Iterator<Integer> integerIterator = new SortTwoIterators(iterator1,iterator2);

        for (int i = 1; i <= 10; i++)
            System.out.println(integerIterator.next());
        }

    public static class SortTwoIterators implements Iterator<Integer> {

        Iterator<Integer> first_iterator;
        Iterator<Integer> second_iterator;
        Iterator<Integer> actual_iterator;

        public SortTwoIterators(Iterator<Integer> first_iterator, Iterator<Integer> second_iterator) {
            this.first_iterator = first_iterator;
            this.second_iterator = second_iterator;
            this.actual_iterator = first_iterator;
        }

        @Override
        public boolean hasNext() {
            return first_iterator.hasNext() || second_iterator.hasNext();
        }

        @Override
        public Integer next() {
            if (!hasNext())
                return null;

            Integer obj =  actual_iterator.next();
            if(actual_iterator == first_iterator && second_iterator.hasNext())
                actual_iterator = second_iterator;
            else if (first_iterator.hasNext())
                actual_iterator = first_iterator;

            return obj;
        }
    }
}
