import java.util.Iterator;
import java.util.NoSuchElementException;

public class zad7 {
    public static void main(String[] args) {
        Integer[][] array = {{1,2,3},{4,5},{6,7}};
        Iterator<Integer> iterator = new Array2DIterator<>(array);
        while (iterator.hasNext())
            System.out.println(iterator.next());
    }

    public static class Array2DIterator<T> implements Iterator<T> {
        private final T[][] array;
        private int pos_x = 0;
        private int pos_y = 0;

        public Array2DIterator(T[][] anArray) {
            array = anArray;
        }

        public boolean hasNext() {
            return pos_y < array.length && pos_x < array[pos_y].length ;
        }

        public T next() throws NoSuchElementException {
            if (hasNext()){
                T number = array[pos_y][pos_x++];
                if (pos_x == array[pos_y].length){
                    pos_y ++;
                    pos_x = 0;
                }

                return number;
            }
            else
                throw new NoSuchElementException();
        }

    }
}
