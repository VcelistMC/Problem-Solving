import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class OpenLock {
    public int openLock(String[] deadends, String target) {
        int rotations = 0;
        Set<String> visited = new HashSet<>();
        Set<String> dedEnds = new HashSet<>();
        Queue<String> q = new LinkedList<>();

        for(String deadend: deadends)
            dedEnds.add(deadend);

        if(dedEnds.contains("0000")) return -1;


        q.offer("0000");
        visited.add("0000");
        

        int newVal;
        int oldVal;
        String currLockStr;
        while(!q.isEmpty()){
            int len = q.size();
            while(len-- > 0){
                StringBuilder currLock = new StringBuilder(q.poll());
                if(currLock.toString().equals(target)) return rotations;
                
                for(int i = 0; i < currLock.length(); i++){
                    oldVal = Character.getNumericValue(currLock.charAt(i));
                    newVal = oldVal + 1;
                    if(newVal == 10)
                        newVal = 0;
                    currLock.replace(i, i+1, String.valueOf(newVal));
                    currLockStr = currLock.toString();
                    if(!dedEnds.contains(currLockStr) && visited.add(currLockStr)){
                        q.offer(currLockStr);
                    }
                    
                    
                    newVal = oldVal - 1;
                    if(newVal == -1)
                        newVal = 9;
                    currLock.replace(i, i+1, String.valueOf(newVal));
                    currLockStr = currLock.toString();
                    if(!dedEnds.contains(currLockStr) && visited.add(currLockStr)){
                        q.offer(currLockStr);
                    }   
                    
                    
                    currLock.replace(i, i+1, String.valueOf(oldVal));
                }
            }
            rotations++;
        }

        return -1;
    }

    public static void main(String[] args) {
        OpenLock lock = new OpenLock();
        lock.openLock(new String[]{"8888"}, "0009");
    }
}
