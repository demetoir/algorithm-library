import java.io.*;

public class MaxFilterSeparable {
	StreamTokenizer in;
	PrintWriter out;

	private int nextInt() throws IOException {
	    in.nextToken();
	    return (int)in.nval;
	}
	
	public void solve() throws IOException {
		in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	    out = new PrintWriter(new OutputStreamWriter(System.out));
		int R = nextInt();
		int C = nextInt();
		int M = nextInt();
		int N = nextInt();
		
		int[][] arData0 = new int[R][C];
		for(int r = 0; r < R; ++r) {
			for(int c = 0; c < C; ++c) {
				arData0[r][c] = nextInt();
			}
		}
		
		int[][] arData1 = new int[R][C];
		
		// Perform row max
		for(int r = 0; r < R; ++r) {
			for(int c = 0; c < C; ++c) {
				int max = -1;
				int begin = Math.max(0, c - N);
				int end = Math.min(C-1, c + N);
				for(int i = begin; i <= end; ++i) {
					if(arData0[r][i] > max)
						max = arData0[r][i];
				}
				arData1[r][c] = max;
			}
		}
		
		// Perform column max
		for(int c = 0; c < C; ++c) {
			for(int r = 0; r < R; ++r) {
				int max = -1;
				int begin = Math.max(0, r - M);
				int end = Math.min(R-1, r + M);
				for(int i = begin; i <= end; ++i) {
					if(arData1[i][c] > max)
						max = arData1[i][c];
				}
				arData0[r][c] = max;
			}
		}
		
		// Print result
		for(int r = 0; r < R; ++r) {
			for(int c = 0; c < C; ++c) {
				out.print(arData0[r][c]);
				out.print(" ");
			}
			out.println("");
		}
		out.flush();
	}
	
	public static void main(String[] args) throws IOException {
		long startTime = System.currentTimeMillis();
		
		MaxFilterSeparable filter = new MaxFilterSeparable();
		filter.solve();
		
		long stopTime = System.currentTimeMillis();
	    long elapsedTime = stopTime - startTime;
	    //System.out.println(elapsedTime);
	}

}
