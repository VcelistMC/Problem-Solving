import java.util.Stack;

public class RPN {
    public int evalRPN(String[] tokens) {
        Stack<Integer> currStack = new Stack<>();
        int n1, n2, res;
        for(String s: tokens){
            switch (s) {
                case "+":
                    n1 = currStack.pop();
                    n2 = currStack.pop();
                    res = n1+n2;
                    currStack.push(res); 
                    break;
                case "-":
                    n1 = currStack.pop();
                    n2 = currStack.pop();
                    res = n2-n1;
                    currStack.push(res);
                    break;
                case "*":
                    n1 = currStack.pop();
                    n2 = currStack.pop();
                    res = n1*n2;
                    currStack.push(res);
                    break;
                case "/":
                    n1 = currStack.pop();
                    n2 = currStack.pop();
                    res = n2/n1;
                    currStack.push(res);
                    break;
                default:
                    int num = Integer.parseInt(s);
                    currStack.push(num);
            }
        }
        return currStack.pop();
    }
    public static void main(String[] args) {
        RPN rpn = new RPN();
        rpn.evalRPN(new String[]{"4","13","5","/","+"});
    }
}
