
import java.util.Objects;
import java.util.Scanner;

public class Document {

    public static void loadDocument(String name, Scanner scan) {
        String current;
        while((!Objects.equals(current = scan.next(), "eod"))){
            current =current.toLowerCase();

            if(current.startsWith("link="))
                if (correctLink(current = current.substring(5)))
                    System.out.println(current);

        }
    }

    // accepted only small letters, capitalic letter, digits nad '_' (but not on the begin)
    public static boolean correctLink(String link) {
        if (link.isEmpty())
            return false;

        if(!((link.charAt(0))<='z'&& link.charAt(0)>='a'))
            return false;

        for (int i=1;i<link.length();i++){
            char letter = link.charAt(i);
            if (!((letter<='z'&& letter>='a') ||
                    letter == '_'||
                    (letter>='0'&&letter<='9'))){
                return false;
            }
        }
        return true;
    }
}