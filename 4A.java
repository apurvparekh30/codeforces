import java.util.*;
 
public class p4A  {
 
    static Scanner fs = new Scanner(System.in);
    static int w;
    public static void main(String[] args) {
        w = fs.nextInt();
        System.out.println((w%2==0 && w!=2) ? "YES":"NO");
    }
}
