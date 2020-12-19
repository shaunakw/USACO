import java.util.*;

public class lifeguards {
    static Scanner in;
    static PrintWriter out;
    public static void main(String[] args) {
        in = new Scanner(System.in);

        System.out.println(bruteforce2());
    }

    static int bruteforce1() {
        int N = in.nextInt();
        Shift[] lifeguards = new Shift[N];

        for (int i = 0; i < N; i++) {
            lifeguards[i] = new Shift(in.nextInt(), in.nextInt());
        }

        int max = 0;
        for (int i = 0; i < N; i++) {
            int total = 0;
            for (int j = 0; j < 1000; j++) {
                for (int k = 0; k < N; k++) {
                    if (k != i && lifeguards[k].start <= j && lifeguards[k].end > j) {
                        total++;
                        break;
                    }
                }
            }
            max = Math.max(total, max);
        }
        return max;
    }

    static int bruteforce2() { // a little faster
        int N = in.nextInt();
        ArrayList<Integer>[] times = new ArrayList[1000];

        for (int i = 0; i < 1000; i++) {
            times[i] = new ArrayList<>();
        }

        for (int i = 0; i < N; i++) {
            int start = in.nextInt();
            int end = in.nextInt();
            for (int j = start; j < end; j++) {
                times[j].add(i);
            }
        }

        int max = 0;
        for (int i = 0; i < N; i++) {
            int total = 0;
            for (ArrayList<Integer> time : times) {
                if (time.size() > 1 || (time.size() == 1 && time.get(0) != i)) {
                    total++;
                }
            }
            max = Math.max(total, max);
        }
        return max;
    }

    static class Shift {
        int start, end;

        Shift(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}
