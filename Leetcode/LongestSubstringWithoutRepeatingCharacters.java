import java.util.Hashtable;

/**
 * Undone
 */
public class LongestSubstringWithoutRepeatingCharacters {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0 || s.length() == 1)
            return s.length();
        int max = 1;
        int i = 0;
        int j = 1;
        Hashtable<Character, Integer> table = new Hashtable<>();
        table.put(s.charAt(i), i);
        int pmax = 1;
        while(j < s.length()){
            // if(j >= s.length())
            //     return (max > pmax? max: pmax) + 1;
            
            Integer ind = table.get(s.charAt(j));
            //Case: char doesn't already exist
            if(ind == null){
                table.put(s.charAt(j), j);
                j++;
                pmax++;
            }
            //Case: char already exists
            else{
                i = ind + 1;
                table.replace(s.charAt(j), j);
                pmax = j-i;
                if(pmax > max)
                    max = pmax;
                j++;
            }
            max = pmax>max? pmax: max;
        }

        int returnVal = max+1;
        System.out.println(returnVal);
        return returnVal;
    }

    public static void main(String[] args) {
        LongestSubstringWithoutRepeatingCharacters solve = new LongestSubstringWithoutRepeatingCharacters();
        solve.lengthOfLongestSubstring("abcabcbb"); // 3
        solve.lengthOfLongestSubstring("pwwkew"); // 3
        solve.lengthOfLongestSubstring("bbbbb"); // 1
        solve.lengthOfLongestSubstring("au"); // 2
        solve.lengthOfLongestSubstring("dvdf"); // 3
        solve.lengthOfLongestSubstring("abba"); // 2
    }
}