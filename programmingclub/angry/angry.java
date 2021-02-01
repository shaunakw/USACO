import java.io.*;
import java.util.*;

public class angry {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("angry.in"));
        PrintWriter out = new PrintWriter("angry.out");

        int N = in.nextInt();
        int K = in.nextInt();
        
        int[] hay = new int[N];

        for (int i = 0; i < N; ++i) {
            hay[i] = in.nextInt();
        }

        Arrays.sort(hay);

        int lo = 0;
        int hi = 500000000;
        while (lo < hi) {
            int r = (lo + hi) / 2;
            
            // Check if r is valid
            int cows = 1; // Number of cows used
            int x = hay[0] + r; // Location of current cow
            for (int i = 1; i < N; ++i) {
                if (hay[i] > x + r) {
                    cows++;
                    x = hay[i] + r;
                }
            }

            if (cows > K) { // R value needs too many cows (is lower than minimum)
                lo = r + 1;
            } else { // R value is greater than or equal to minimum
                hi = r;
            }
        }

        out.println(lo);

        out.close();
    }
}
