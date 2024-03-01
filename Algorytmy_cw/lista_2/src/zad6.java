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
        System.out.println(iterator.next());
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
        public void remove() {
           for (int i=pos;i<array.length-1;i++){
               array[i] = array[i+1];
           }
           array[array.length-1] = null;
        }
    }
}
