import java.util.*;
 
public class Solution {
 
    static int n,t,c;
    static Scanner fs = new Scanner(System.in);
    public static void main(String[] args) {
        n = fs.nextInt();
        t = fs.nextInt();
        c = fs.nextInt();
 
        List<Integer> list = new ArrayList<>();
        list.add(-1);
        for(int i=0;i<n;i++){
            int no = fs.nextInt();
            if(no > t)
                list.add(i);
        }
        list.add(n);
        int ans = 0;
        for(int i=1;i<list.size();i++){
            int diff = list.get(i) - list.get(i-1) - 1;
            ans+=Math.max(0,diff-c+1);
        }
        System.out.println(ans);
    }
}
