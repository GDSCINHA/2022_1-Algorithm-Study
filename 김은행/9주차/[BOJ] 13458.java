import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static double B, C, ans;
    
    public static void solution(double ai) {
        
        if (ai > 0) {
            ans += Math.ceil(ai / C);
        }
    }

    
    public static void main(String [] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        double [] A = new double[N];
        
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextDouble();
        }
        ans = N;
        
        B = sc.nextDouble();
        C = sc.nextDouble();
        
        for (int i = 0; i < N; i++) {
            solution(A[i] - B);
        }
        
        System.out.println((long)ans);

        sc.close();
    }
}