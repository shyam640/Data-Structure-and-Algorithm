import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(scanner.nextInt());
        }
        scanner.close();

        int result = solve(arr);
        System.out.println(result);
    }

    public static int solve(List<Integer> arr) {
        Map<Integer, Integer> mp1 = new HashMap<>();
        Map<Integer, Integer> mp2 = new HashMap<>();

        for (int val : arr) {
            String k = String.valueOf(val);
            mp1.put(k.charAt(0) - '0', mp1.getOrDefault(k.charAt(0) - '0', 0) + 1);
            mp2.put(k.charAt(k.length() - 1) - '0', mp2.getOrDefault(k.charAt(k.length() - 1) - '0', 0) + 1);
        }

        int ans = 0;
        for (Map.Entry<Integer, Integer> entry : mp1.entrySet()) {
            int key = entry.getKey();
            int count1 = entry.getValue();
            int count2 = mp2.getOrDefault(key, -1);
            ans += Math.max(count1, count2);
        }

        return ans;
    }
}
