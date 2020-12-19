import java.util.*;

public class whereami {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();
        String farms = in.next();

        int k = N;
        for (int i = 1; i < N; i++) {
            ArrayList<String> substrings = new ArrayList<>();
            boolean duplicate = false;
            for (int j = 0; j <= N - i; j++) {
                String substring = farms.substring(j, j + i);
                if (substrings.contains(substring)) {
                    duplicate = true;
                    break;
                }
                substrings.add(substring);
            }
            if (!duplicate) {
                k = i;
                break;
            }
        }

        System.out.println(k);
    }
}
