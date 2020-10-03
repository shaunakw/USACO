import java.io.*;
import java.util.*;

public class teleport {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("teleport.in"));
        PrintWriter out = new PrintWriter("teleport.out");

        int a = in.nextInt();
        int b = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();

        int d1 = Math.abs(a - b);
        int d2 = Math.abs(a - x) + Math.abs(b - y);
        int d3 = Math.abs(a - y) + Math.abs(b - x);

        out.println(Math.min(d1, Math.min(d2, d3)));

        out.close();
    }
}
