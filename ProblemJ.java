import java.util.Scanner;
import java.util.Queue;
import java.util.Stack;
import java.util.LinkedList;

public class ProblemJ {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		
		Stack<Character> stack = new Stack<Character>();
		Queue<Character> queue = new LinkedList<Character>();
		
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) == '\\' && i + 1 < s.length()) {
				while(stack.peek() != '/') {
					char c = stack.pop();
					queue.add(c);
				}
				
				stack.pop();
				
				while(!queue.isEmpty()) {
					char c = queue.peek();
					stack.push(c);
					queue.remove();
				}
			} else {
				stack.push(s.charAt(i));
			}
		}
		
		stack.pop();
		
		while(!stack.isEmpty()) {
			System.out.print(stack.pop());
			
			if(stack.size() == 1) break;
		}
	}
}