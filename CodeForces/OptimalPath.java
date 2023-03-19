import java.util.Scanner;

public class OptimalPath{
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        int n = Integer.parseInt(inp.nextLine());
        long ans = 0;
        String[] line;
        int rows, cols;
        while(n-- > 0){
            line = inp.nextLine().split(" ");
            rows = Integer.parseInt(line[0]);
            cols = Integer.parseInt(line[1]);
            
            ans = (cols*(cols + 1)) / 2;

            for(int i = 2; i <= rows; i++)
                ans += (i * cols);
            
            System.out.println(ans);
        }
    }
}