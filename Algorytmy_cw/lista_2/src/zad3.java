import java.util.Iterator;

public class zad3 {
    public static void main(String[] args) {

        Iterator<Integer> iterator = new FibInterator();
        for (int i=0;i<10;i++)
            System.out.println(iterator.next());

    }
    public static class FibInterator implements Iterator<Integer>{
        int second_number = 1;
        int first_number = 0;

        int pos = 1;

        @Override
        public boolean hasNext() {
            return true;
        }

        @Override
        public Integer next() {
           int number =  second_number + first_number;
           if(pos%2==1)
               first_number += second_number;
           else second_number += first_number;

           pos++;
           return number;
        }
    }
}
