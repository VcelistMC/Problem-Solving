import java.util.Arrays;
import java.util.HashMap;

public class PermutationinString {
    public boolean checkInclusion(String s1, String s2) {
        int[] s1Arr = new int[26];
        int[] s2Arr = new int[26];
        

        for(int i = 0; i <s1.length(); i++){
            s1Arr[s1.charAt(i) - 'a']++;
            s2Arr[s2.charAt(i) - 'a']++;
        }

        if(Arrays.equals(s1Arr, s2Arr))
            return true;
        
        int i = 0;
        int j = s1.length();
        while(j < s2.length()){
            s2Arr[s2.charAt(i) - 'a']--;
            s2Arr[s2.charAt(j) - 'a']++;
            
            if(Arrays.equals(s1Arr, s2Arr))
                return true;
            
            i++;
            j++;
            
        }
        return false;
    }
    public boolean checkInclusion2(String s1, String s2) {
        HashMap<Character, Boolean> map = buildMap(s1);
        int permutationLength = s1.length();
        int i = 0;
        
        while(i < s2.length()){
            int currLength = permutationLength;
            while(map.get(s2.charAt(i)) != null && map.get(s2.charAt(i))){
                map.replace(s2.charAt(i), false);
                i++;
                currLength--;
                if(currLength <= 0)
                    return true;
                if(i >= s2.length()-1)
                    return false;
            }
            if(currLength != permutationLength){
                for(Character c: map.keySet())
                    map.replace(c, true);
            }
            else
                i++;

            
        }
        return false;
    }

    HashMap<Character, Boolean> buildMap(String s){
        HashMap<Character, Boolean> map = new HashMap<>();
        for(int i = 0; i < s.length(); i++)
            map.put(s.charAt(i), true);

        return map;
    }

    public static void main(String[] args) {
        PermutationinString string = new PermutationinString();
        System.out.println(string.checkInclusion("ab","eidbaooo")); //true
        System.out.println(string.checkInclusion("hello" ,"ooolleooole")); //false
        System.out.println(string.checkInclusion("adc" ,"dcda")); //true
    }
}
