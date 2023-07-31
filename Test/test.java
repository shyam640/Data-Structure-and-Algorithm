import java.util.HashMap;
import java.util.Map;

class Test {
    public int solution(int[] numbers) {
        Map<String, Integer> countMap = new HashMap<>();

        // Count the occurrences of numbers with the same first and last digits
        for (int num : numbers) {
            String key = getConcatenatedDigits(num);
            countMap.put(key, countMap.getOrDefault(key, 0) + 1);
        }

        int pairCount = 0;

        // Calculate the number of pairs for each concatenated string
        for (int count : countMap.values()) {
            pairCount += count * (count - 1) / 2;
        }

        return pairCount;
    }

    // Helper function to get the concatenated digits of a number
    private String getConcatenatedDigits(int num) {
        String numStr = String.valueOf(num);
        return numStr.charAt(0) + "" + numStr.charAt(numStr.length() - 1);
    }
}
