import java.util.*;

public class lostcow {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int X = in.nextInt();
        int Y = in.nextInt();

        double log = Math.log(Math.abs(X - Y)) / Math.log(2); // log base 2
        double iteration;
        if (Y > X) {
            iteration = Math.ceil(log / 2.0) * 2;
        } else {
            iteration = Math.ceil((log + 1) / 2.0) * 2 - 1;
        }

        int total = (int) (Math.pow(2, iteration) - 1) * 2 + (int) Math.abs(Y - X);
        System.out.println(total);
    }
}
