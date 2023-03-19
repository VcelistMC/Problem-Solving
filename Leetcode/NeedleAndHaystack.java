public class NeedleAndHaystack {
    public static int strStr(String haystack, String needle) {
        // if(needle.length() > haystack.length())
        //     return -1;
        // int startIndex = -1;
        // int hayIndex = 0;
        // int needleIndex = 0;
        // while(hayIndex < haystack.length() && needleIndex < needle.length()) {
        //     if(haystack.charAt(hayIndex) == needle.charAt(needleIndex)){
        //         startIndex = startIndex == -1? hayIndex: startIndex;
        //         hayIndex++;
        //         needleIndex++;
        //     }
        //     else{
        //         needleIndex = 0;
        //         startIndex = -1;
        //         hayIndex++;
        //     }
        // }
        // return startIndex;
        return haystack.indexOf(needle);
    }

    public static void main(String[] args) {
        NeedleAndHaystack.strStr("mississippi", "issip");
    }
}
