import java.util.*;
 
public class p1A {
    static Scanner fs  = new Scanner(System.in);
    static int n,m,a;
 
    public static void main(String[] args) {
        n = fs.nextInt();
        m = fs.nextInt();
        a = fs.nextInt();
 
        System.out.println(((long)(n/a + (n%a==0 ? 0 : 1))) * ((long)(m/a + (m%a==0 ? 0 : 1))));
    }
}
