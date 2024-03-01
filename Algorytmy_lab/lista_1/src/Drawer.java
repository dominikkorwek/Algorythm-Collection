public class Drawer {
    private static void drawLine(int n, char ch) {
        for(int i=0;i<n;i++){
            System.out.print(ch);
        }
    }

    public static void drawPyramid(int n) {
        drawPyramid(n,0);
    }

    public static void drawPyramid(int n, int extra_empty){
        int leaf_number = 1;
        int empty_number = n-1 + extra_empty;

        for(int i=0;i<n;i++){
            drawLine(empty_number,'.');
            drawLine(leaf_number,'X');
            drawLine(empty_number,'.');
            System.out.println();

            leaf_number+=2;
            empty_number-=1;
        }
    }

    public static void drawChristmassTree(int n) {
        for(int i=1;i<=n;i++){
            drawPyramid(i,n-i);
        }

    }

}