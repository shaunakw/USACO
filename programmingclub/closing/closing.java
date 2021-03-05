import java.io.*;
import java.util.*;

public class closing {
    static ArrayList<Integer>[] adjList;
    static boolean[] visited;
    static boolean[] open;

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("closing.in"));
        PrintWriter out = new PrintWriter("closing.out");

        int N = in.nextInt();
		int M = in.nextInt();

        adjList = new ArrayList[N];
        for (int i = 0; i < N; i++) { // initialize adjList
            adjList[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            int b1 = in.nextInt()-1; // subtract one from inputs so so indices start at 0
            int b2 = in.nextInt()-1;
            adjList[b1].add(b2);
            adjList[b2].add(b1);
        }

        int[] order = new int[N]; // order of closing farms
        for (int i = 0; i < N; i++) {
            order[i] = in.nextInt()-1;
        }
        open = new boolean[N];
        ArrayList<Boolean> ans = new ArrayList<>();
        for (int i = N - 1; i >= 0; i--) { // start with last farm to be closed and loop backwards
            visited = new boolean[N];
            open[order[i]] = true; // open next farm in order
            dfs(order[i]);
            for (int j = 0; j < N; j++) {
                if (open[j] && !visited[j]) { // open farm was not directly reached by dfs
                    ans.add(0, false);
                    break;
                } else if (j == N - 1) { // no unconnected farms
                    ans.add(0, true);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            out.println(ans.get(i) ? "YES" : "NO");
        }

        out.close();
    }

    static void dfs(int node) {
        visited[node] = true;
        for (int i : adjList[node]) {
            if (open[i] && !visited[i]) {
                dfs(i);
            }
        }
    }
}
