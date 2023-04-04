/*

Given 2  binary strings, your task is to make those 2 strings equal by performing following operation
-> select any 2 adjacent characters from any string and flip/invert them i.e 0 -> 1 or 1 -> 0

Find the minimum number of operations required to make 2 strings equal.


For example, A = 0101, B = 1111, the optimal approach is 
first select middle 2 characters from A and invert them, 
then, A becomes 0011.
Now, select first 2 characters from B and invert them, Now, B becomes 0011.
so, A = B.
So, the number of operations required to make A and B equal is 2.

*/



public class Main {
    public static void main(String[] args) {
        var s1 = "00".toCharArray();
        var s2 = "11".toCharArray();
        var n = s1.length;
        var i = 0;
        var flips = 0;
        while (i < n) {
            if (s1[i] == s2[i]) {
                i++;
            }
            else if (i + 1 < n && s1[i] == s2[i+1] && s1[i+1] == s2[i]) {
                flips++;
                i += 2;
            }
            else if (s1[i] != s2[i]) {
                flips++;
                i++;
            }
            else {
                i++;
            }
        }
        System.out.println(flips);
    }
}