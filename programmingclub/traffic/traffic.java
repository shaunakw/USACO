import java.io.*;
import java.util.*;

public class traffic {
    public static void main(String[] args) throws IOException{
        Scanner in = new Scanner(new File("traffic.in"));
        PrintWriter out = new PrintWriter("traffic.out");

        int N = in.nextInt();
        String types[] = new String[N];
        int lbounds[] = new int[N]; // lower bounds
        int ubounds[] = new int[N]; // upper bounds

        for (int i = 0; i < N; i++) {
            types[i] = in.next();
            lbounds[i] = in.nextInt();
            ubounds[i] = in.nextInt();
        }

        int min = 0, max = 1000000;
        for (int i = N - 1; i >= 0; i--) { // Iterating in reverse to get the initial flow range
            if (types[i].equals("on")) {
                min = Math.max(min - ubounds[i], 0);
                max -= lbounds[i];
            } else if (types[i].equals("off")) {
                min += lbounds[i];
                max += ubounds[i];
            } else {
                min = Math.max(min, lbounds[i]);
                max = Math.min(max, ubounds[i]);
            }
        }
        out.println(min + " " + max);

        min = 0; max = 1000000;
        for (int i = 0; i < N; i++) { // Iterating normally to get the ending range
            if (types[i].equals("on")) {
                min += lbounds[i];
                max += ubounds[i];
            } else if (types[i].equals("off")) {
                min = Math.max(min - ubounds[i], 0);
                max -= lbounds[i];
            } else {
                min = Math.max(min, lbounds[i]);
                max = Math.min(max, ubounds[i]);
            }
        }
        out.println(min + " " + max);
        out.close();
    }
}