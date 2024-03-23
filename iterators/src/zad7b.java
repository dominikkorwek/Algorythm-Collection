import java.util.Iterator;
import java.util.NoSuchElementException;

public class zad7b {
    public static void main(String[] args) {
        Integer[][] array = {{1,2,3},{4,5},{6,7}};
        Iterator<Integer> iterator = new Array2DIterator<>(array);
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }
    }

    public static class Array2DIterator<T> implements Iterator<T> {
        private final T[][] array;
        private int pos_x;
        private int pos_y;

        public Array2DIterator(T[][] anArray) {
            array = anArray;
            pos_y = anArray.length-1;
            pos_x = anArray[pos_y].length - 1;
        }

        public boolean hasNext() {
            return pos_y > -1;
        }

        public T next() throws NoSuchElementException {
            if (hasNext()){
                T number = array[pos_y][pos_x--];
                if (pos_x <0){
                    pos_y --;
                    if (pos_y>-1)
                        pos_x = array[pos_y].length - 1;
                }

                return number;
            }
            else
                throw new NoSuchElementException();
        }

    }
}
