import java.io.*;
import java.util.*;


public class VoteHashMap {
	StreamTokenizer in;
	PrintWriter out;

	private int nextInt() throws IOException {
	    in.nextToken();
	    return (int)in.nval;
	}
	
	public int violation = 0;
	public HashMap<Integer, Integer> hash;
	
	public void solve() throws IOException {
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	    out = new PrintWriter(new OutputStreamWriter(System.out));
		int nVotes = nextInt();
		int nCands = nextInt();
		int K = nextInt();
		
		int[] arScore = new int[nCands + 1];
		Arrays.fill(arScore, 0);
		
		int initCapacity = Math.min(1000000, nVotes);
		hash = new HashMap<Integer, Integer>(initCapacity); 
		
		// Count votes
		for(int i = 0; i < nVotes; ++i) {
			Integer phone = nextInt();
			Integer id = nextInt();
			
			Integer count = hash.get(phone);
			if(count == null) {		// Fist-time voter.
				hash.put(phone, 1);	
				count = 0;			// Count before this register
			} 
			
			count = count + 1;		// Count after vote register
			hash.put(phone, count);	// Register vote
			
			// To students: uncomment this if you want to see what's going on with counting.
			//System.out.println(i + ": (" + phone + ", " + count + ")");
			
			if(count <= K && id >= 1 && id <= nCands) {
				arScore[id] += 1;
			}
			
			if(count > K) ++violation;
		}

		for(int i = 1; i <= nCands; ++i) {
			out.println(arScore[i]);
		}
		out.flush();
	}
	
	public static void main(String[] args) throws IOException {
		long startTime = System.currentTimeMillis();
		
		VoteHashMap vote = new VoteHashMap();
		vote.solve();
		
		long stopTime = System.currentTimeMillis();
	    long elapsedTime = stopTime - startTime;
	    //System.out.println("Distinct elements = " + vote.hash.size());
	    //System.out.println("Time = " + elapsedTime);
	    //System.out.println("Violation = " + vote.violation);
	}
}
