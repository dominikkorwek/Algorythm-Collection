import java.util.Scanner;

public class Palindrome
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("write a text to check if it is Palindrome: ");
        while(scan.hasNext())
        {
            String text=scan.nextLine();
            if(text.equals("end"))
                break;
            boolean palindrome = text.length() >= 2;
            for(int i=0; i<text.length()/2 ; i++)
            {
                char currentfront = text.charAt(i);
                char currentend = text.charAt(text.length()- 1 - i);
                if(currentend != currentfront)
                {
                    palindrome = false;
                    break;
                }
            }
            if(palindrome)
                System.out.println("text: "+text + " is a Palindrome");
            else
                System.out.println("text: " + text + " is not a Palindrome");
            System.out.println("write another text or write 'end' to end a Programme");
        }
        System.out.println(" end of a Programme");
    }

}