import java.util.*;

public class teleport {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int a = in.nextInt();
        int b = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();

        int d1 = Math.abs(a - b);
        int d2 = Math.abs(a - x) + Math.abs(b - y);
        int d3 = Math.abs(a - y) + Math.abs(b - x);

        System.out.println(Math.min(d1, Math.min(d2, d3)));
    }
}
