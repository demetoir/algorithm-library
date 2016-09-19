
import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;
import java.util.Timer;


class Node implements Comparable{
	private VacuumMachine[] vac;
	private int[] dirtAmount;
	private VacuumMachine[] room;
	private int g;	
	private int f=0;
	public Node(VacuumMachine[] inVac,int[] inDirtAmount,int g){
		vac = new VacuumMachine[inVac.length];
		dirtAmount = new int[inDirtAmount.length];
		room = new VacuumMachine[inDirtAmount.length];
		for(int i=0;i<inVac.length;i++) {
			vac[i] = new VacuumMachine();
			vac[i].pos = inVac[i].pos;
			vac[i].power = inVac[i].power;
			vac[i].mass = inVac[i].mass;
			room[vac[i].pos] = vac[i];
		}
		for(int i=0;i<inDirtAmount.length;i++) {
			dirtAmount[i] = inDirtAmount[i];
			if(dirtAmount[i]!=0) this.f++;
		}
		this.g = g;
	}
	public Node[] expand() {
		Node[] ans = new Node[dirtAmount.length*5];
		int ind = 0;
		for(int i=0;i<vac.length;i++) {
			// Move left 
			if( vac[i].pos > 0 && room[vac[i].pos - 1] == null ) { 
				Node newNode = new Node(vac,dirtAmount,g);
				newNode.room[vac[i].pos] = null;
				newNode.room[vac[i].pos - 1] = vac[i];
				newNode.vac[i].pos--;
				newNode.g += vac[i].mass;
				ans[ind++] = newNode;
			}
			// Step Over left 
			if( vac[i].pos > 1 && room[vac[i].pos - 1] != null && room[vac[i].pos - 2] == null ) { 
				Node newNode = new Node(vac,dirtAmount,g);
				newNode.room[vac[i].pos] = null;
				newNode.room[vac[i].pos - 2] = vac[i];
				newNode.vac[i].pos -= 2;
				newNode.g += vac[i].mass;
				ans[ind++] = newNode;
			}
			// Move Right 
			if( vac[i].pos < dirtAmount.length - 1 && room[vac[i].pos + 1] == null ) { 
				Node newNode = new Node(vac,dirtAmount,g);
				newNode.room[vac[i].pos] = null;
				newNode.room[vac[i].pos + 1] = vac[i];
				newNode.vac[i].pos++;
				newNode.g += vac[i].mass;
				ans[ind++] = newNode;
			}
			// Step Over Right 
			if( vac[i].pos < dirtAmount.length - 2 && room[vac[i].pos + 1] != null && room[vac[i].pos + 2] == null ) { 
				Node newNode = new Node(vac,dirtAmount,g);
				newNode.room[vac[i].pos] = null;
				newNode.room[vac[i].pos + 2] = vac[i];
				newNode.vac[i].pos += 2;
				newNode.g += vac[i].mass;
				ans[ind++] = newNode;
			}
			// Suck
			if( dirtAmount[vac[i].pos] > 0) {
				Node newNode = new Node(vac,dirtAmount,g);
				newNode.dirtAmount[vac[i].pos] -= vac[i].power;
				if(newNode.dirtAmount[vac[i].pos] <= 0) {
					newNode.dirtAmount[vac[i].pos] = 0;
				}
				newNode.g++;
				newNode.f--;
				ans[ind++] = newNode;
			}
		}
		return ans;
	}
	public int getG() {
		return g;
	}
	public boolean isGoal() {
		for(int i=0;i<dirtAmount.length;i++) {
			if(dirtAmount[i] > 0) return false;
		}
		return true;
	}
	@Override
	public int compareTo(Object arg0) {
		// TODO Auto-generated method stub
		if(((Node) arg0).g+((Node) arg0).f > this.g+this.f) return -1;
		if(((Node) arg0).g+((Node) arg0).f < this.g+this.f) return 1;
//		if(((Node) arg0).g > this.g) return -1;
//		if(((Node) arg0).g < this.g) return 1;
		return 0;
	}
	public String toString() { 
		String out = "";
		for(int i=0;i<dirtAmount.length;i++) {
			out = out+dirtAmount[i]+" ";
		}
		out = out + "| ";
		for(int i=0;i<vac.length;i++) {
			out = out+vac[i].pos + " ";
		}
		return out;
	}
}
class VacuumMachine {
	int power;
	int pos;
	int mass;
}
	
public class VacuumWorld {

	/**
	 * @param args
	 */
	final int numVac = 5;
	final int numRoom = 20;
	private static void insertFringe(Node n,LinkedList<Node> fringe) {
		ListIterator<Node> i = fringe.listIterator();
//		Node cur = i.next();
//		System.out.println(n.toString());
		if(fringe.isEmpty()) {
			fringe.add(n);
			return;
		}
		while(i.hasNext()) {
			if(i.next().compareTo(n) > 0 ) {
				i.previous();
				i.add(n);
				return;
			}
		}
		fringe.addLast(n);
	}
	
	private static void expand(Node n,LinkedList<Node> fringe) {
		Node[] children = n.expand();
		for(int i=0;children[i] != null && i < children.length;i++) {
			insertFringe(children[i],fringe);
		}
	}
	
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		long t = System.currentTimeMillis();
		Scanner in = new Scanner(System.in);
		int testCase = in.nextInt();
	        for(int ii = 0; ii < testCase; ii++){
		LinkedList<Node> fringe = new LinkedList<Node>();
		int vacNum = in.nextInt();
		int roomNum = in.nextInt();
		VacuumMachine[] vm = new VacuumMachine[vacNum];
//		System.out.println(vacNum + " " + roomNum);
		int[] dirt = new int[roomNum];
		for(int i=0;i<vacNum;i++) {
			vm[i] = new VacuumMachine();
			vm[i].power = in.nextInt();
			vm[i].pos = in.nextInt();
			vm[i].mass = in.nextInt();
//			System.out.println(vm[i].power + " " + vm[i].pos + " " + vm[i].mass);
		}
		for(int i=0;i<roomNum;i++) {
			dirt[i] = in.nextInt();
//			System.out.print(dirt[i] + " ");
		}
//		System.out.println();
		Node n = new Node(vm,dirt,0);
		insertFringe(n,fringe);
		while(true) {
			if(fringe.isEmpty()) {
				System.out.println("Fail");
				return;
			}
//			System.out.println("+++++");
//			for(ListIterator<Node> i=fringe.listIterator();i.hasNext();) {
//				Node cur = i.next();
//				System.out.print(cur.getG()+" ");
//				
//			}
//			System.out.println("\n+++++");
 			Node front = fringe.removeFirst();
//			System.out.println(front);
			if(front.isGoal()) {
				System.out.println(front.getG());
				break;
			}
			expand(front,fringe);
		}
		}
		long s = System.currentTimeMillis();
		in.close();
		//System.out.println("Time used: "+(s-t));
	}

}
