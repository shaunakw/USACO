import java.util.*;

public class speeding {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();
        int M = in.nextInt();

        int[] segmentLength = new int[N];
        int[] segmentLimit = new int[N];
        int[] cowLength = new int[M];
        int[] cowSpeed = new int[M];

        for (int i = 0; i < N; i++) {
            segmentLength[i] = in.nextInt();
            segmentLimit[i] = in.nextInt();
        }

        for (int i = 0; i < M; i++) {
            cowLength[i] = in.nextInt();
            cowSpeed[i] = in.nextInt();
        }

        int segment = 0; // current road segment
        int segmentStart = 0; // start of the current road segment
        int cow = 0; // current cow segment
        int cowStart = 0; // start of the current cow segment
        int speeding = 0; // max over speed limit
        for (int i = 0; i < 100; i++) {
            if (segmentStart + segmentLength[segment] == i) {
                segmentStart = i;
                segment++;
            }
            if (cowStart + cowLength[cow] == i) {
                cowStart = i;
                cow++;
            }
            speeding = Math.max(speeding, cowSpeed[cow] - segmentLimit[segment]);
        }

        System.out.println(speeding);
    }
}
