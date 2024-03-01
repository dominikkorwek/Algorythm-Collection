import java.util.Iterator;

public class zad2 {
    public static void main(String[] args) {
        Integer number = 4;
        Iterator<Integer> iterator = new FibInterator(number);
        System.out.println(iterator.next());
        System.out.println(iterator.next());

    }
    public static class FibInterator implements Iterator<Integer>{
        Integer number;

        public FibInterator(Integer number) {
            this.number = number;
        }

        @Override
        public boolean hasNext() {
            return true;
        }

        @Override
        public Integer next() {
            return number++;
        }
    }
}
