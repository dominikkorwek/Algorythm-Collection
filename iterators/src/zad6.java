import java.util.Iterator;
import java.util.NoSuchElementException;

public class zad6 {
    public static void main(String[] args) {
        Integer[] tab = {1,2,3,4,5,6};
        Iterator<Integer> iterator = new ArrayIterator<>(tab);
        Iterator<Integer> another = new ArrayIterator<>(tab);

        System.out.println(iterator.next());
        System.out.println(iterator.next());
        System.out.println("other iterator: "+another.next());
        System.out.println("other iterator: "+another.next());
        iterator.remove();
        System.out.println(iterator.next());
        System.out.println(iterator.next());
        System.out.println(iterator.next());
        //System.out.println(iterator.next());
        System.out.println("other iterator: "+another.next());
    }

    public static class ArrayIterator<T> implements Iterator<T> {
        private T array[];
        private int pos = 0;
        public ArrayIterator(T anArray[]) {
            array = anArray;
        }
        public boolean hasNext() {
            return pos < array.length;
        }
        public T next() throws NoSuchElementException {
            if (hasNext())
                return array[pos++];
            else
                throw new NoSuchElementException();
        }
        @SuppressWarnings("unchecked")
        public void remove() {
            T[] copy  = (T[]) (new Object[array.length-1]);
            System.arraycopy(array,0,copy,0,pos);

            if (array.length - 1 - pos >= 0)
                System.arraycopy(array, pos + 1, copy, pos, array.length - 1 - pos);
            array = copy;
        }
    }
}
