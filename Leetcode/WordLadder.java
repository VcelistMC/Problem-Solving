import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;

public class WordLadder {
    public int getDiff(String word1, String word2){
        int diff = 0;
        for (int i = 0; i < word1.length(); i++) {
            if(word1.charAt(i) != word2.charAt(i)) diff++;
        }
        return diff;
    }
    public List<String> getNextWords(String word, List<String> wordList) {
        List<String> list = new ArrayList<>();
        for(String word2: wordList){
            if(getDiff(word, word2) == 1) list.add(word2);
        }
        return list;
    }
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> visited = new HashSet<>();
        Queue<String> q = new LinkedList<>();
        q.offer(beginWord);
        visited.add(beginWord);
        int changes = 1;
        while (!q.isEmpty()) {
            int len = q.size();
            while(len -- > 0){
                String currWord = q.poll();
                if(currWord.equals(endWord)) return changes;

                List<String> nextWords = getNextWords(currWord, wordList);
                for(String nextWord: nextWords){
                    if(visited.add(nextWord)) q.offer(nextWord);
                }
            }
            changes++;
        }
        return 0;
    }
}
