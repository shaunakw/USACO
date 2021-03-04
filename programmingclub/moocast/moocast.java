import java.io.*;
import java.util.*;

public class moocast {
    static ArrayList<Integer>[] adjList;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("moocast.in"));
        PrintWriter out = new PrintWriter("moocast.out");

        int N = in.nextInt();

        Cow[] cows = new Cow[N];

        for (int i = 0; i < N; i++) {
            cows[i] = new Cow(in.nextInt(), in.nextInt(), in.nextInt());
        }

        adjList = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adjList[i] = new ArrayList<>();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;

                int dx = Math.abs(cows[i].x - cows[j].x); // difference in x-coordinates
                int dy = Math.abs(cows[i].y - cows[j].y); // difference in y-coordinates

                if (dx * dx + dy * dy <= cows[i].power * cows[i].power) { // cow i can reach cow j
                    adjList[i].add(j);
                }
            }
        }

        int max = 1;
        for (int i = 0; i < N; i++) {
            visited = new boolean[N]; // all booleans initialize to false
            dfs(i);

            int total = 0; // total cows reached
            for (int j = 0; j < N; j++) {
                if (visited[j]) total++;
            }
            max = Math.max(max, total);
        }

        out.println(max);
        out.close();
    }

    static void dfs(int node) {
        if (visited[node]) return;
        visited[node] = true;

        for (int i : adjList[node]) {
            dfs(i);
        }
    }

    static class Cow {
        int x, y, power;
        
        Cow(int x, int y, int power) {
            this.x = x;
            this.y = y;
            this.power = power;
        }
    }
}
