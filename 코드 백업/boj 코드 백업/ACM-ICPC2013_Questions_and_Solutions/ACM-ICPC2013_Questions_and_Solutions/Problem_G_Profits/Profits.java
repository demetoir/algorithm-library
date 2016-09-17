
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import static java.lang.String.format;


/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Use the linear max subsequence code from Ryan Stansifer 
 * @author apirakhoonlor
 */
public class Profits {
      public static class Subsequence {
        int first=0, last=0, sum=0;
        void addIfBigger (int s, int f, int l) {
           if (s>sum) {sum=s; first=f; last=l;}
        }
        public String toString () {
            if(sum <= 0){
                return format("%d %d %d", 0, 0, 0);
            }
           return format ("%d %d %d", first+1, last+1, sum);
        }
     }    
    public int N; 
    public int M;
    public int[] input;
            
    public Profits(){
        readIn();
    }
    
    // Linear algorithm
    public static Subsequence maxSubsequenceSum1 (int[] sequence) {
       final Subsequence max = new Subsequence ();
       int i=0, sum=0; // Accumulate the sum from i..j
       for (int j=0; j<sequence.length; j++) {
          sum += sequence[j];
          max.addIfBigger (sum,i,j);
          if (sum<=0) {
             i=j+1;
             sum=0;
          }
       }
       return max;
    }    
    
    public void readIn(){
        try{
            BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
            String line, token;
            StringTokenizer tokens;
            line = stdin.readLine().trim();
            N = Integer.parseInt(line);
            int ndex, total_time, idex, vdex;
            int bdex, edex, output_time;
            for(ndex = 0; ndex < N; ndex++){
                line = stdin.readLine().trim();
                tokens = new StringTokenizer(line, " \t\r\n");
                M = Integer.parseInt(tokens.nextToken());
                input = new int[M];
                for(idex = 0; idex < M; idex++){
                    input[idex] = Integer.parseInt(tokens.nextToken()); 
                }
                System.out.println(maxSubsequenceSum1(input).toString());
            }
            stdin.close();
        }catch (IOException err){
            err.printStackTrace();
        }
    }
    
    public void clearInput(){
        for(int i = 0; i < 100; i++){
            input[i] = 0;
        }
    }
        
    public static void main(String[] args){
        new Profits();
    }        
}
