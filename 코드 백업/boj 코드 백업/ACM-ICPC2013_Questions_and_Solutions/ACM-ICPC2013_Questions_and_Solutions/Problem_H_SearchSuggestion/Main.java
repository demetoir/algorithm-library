/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.*;
import java.util.*;

/**
 *
 * @author Keerati
 */
public class Main {
    final static boolean DEBUG = false;
    public static ArrayList<String> city = new ArrayList<String>();
    public static ArrayList<Integer> score = new ArrayList<Integer>();

    private static PrintWriter out;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        //FileReader fin = new FileReader("Suggestion.in");
//        FileReader fin = new FileReader(args[0]);
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//        FileWriter fout = new FileWriter(args[1]);
        //FileWriter fout = new FileWriter("Suggestion.out");
  //      out = new PrintWriter(fout);

        // read city names
        int n  = Integer.parseInt(in.readLine());
        for (int i=0; i<n; i++)
        {
            String s = in.readLine();
            String[] sa = s.split(",");
            city.add(sa[0].trim().toUpperCase());
            score.add(Integer.parseInt(sa[1].trim()));
        }

        // processing
        n  = Integer.parseInt(in.readLine());
        for (int i=0; i<n; i++)
        {
            String line = in.readLine();
            Query(line);
            /*
            char cmd = line.charAt(0);
            line = line.substring(2);
            if (cmd == 'Q')
                Query(line);
            else if (cmd == 'U')
            {
                String[] sa = line.split("\t");
                String c = sa[0].trim().toUpperCase();
                int s = Integer.parseInt(sa[1].trim());
                UpdateCity(c, s);
            }
             */
        }

    //    out.close();
        in.close();
    }

    public static void Query(String key)
    {
        System.out.println(key);
        if (key == null || key.length()==0)
        {
            return;
        }
        key = key.trim().toUpperCase();
        // generating next prefix
        String key2 = key.substring(0, key.length()-1);
        char ch = key.charAt(key.length()-1);
        ch++;
        key2 += ch;
        int i1 = Collections.binarySearch(city, key);
        i1 = (i1>=0)?i1:-i1-1;
        int i2 = Collections.binarySearch(city, key2);
        i2 = (i2>=0)?i2:-i2-1;
        if (DEBUG)
            System.out.println(i1+" to "+i2);
        int nmatch = i2-i1;
        if (nmatch == 0)
            System.out.println("N/A");
        //else
        //    FindTopThree(i1, i2);
        
        else if (nmatch > 0 && nmatch <= 1000)
        {
            FindTopThree(i1, i2);
        }
        else
            System.out.println(nmatch);
    }

    public static void UpdateCity(String name, int value)
    {
        int i = Collections.binarySearch(city, name);
        if (i>=0) // found, update
        {
            score.set(i, value);
        }
        else // not found, add new
        {
            i = -i-1;
            city.add(i, name);
            score.add(i, value);
        }
    }

    // find top 3 city (by score) is the score is equal simply order by name
    public static void FindTopThree(int r1, int r2)
    {
        int[] topScore = {Integer.MIN_VALUE,Integer.MIN_VALUE,Integer.MIN_VALUE};
        String[] topCity = new String[3];

        for (int i=r1; i<r2; i++)
        {
            int s = score.get(i).intValue();
            if (s > topScore[0])
            {
                topScore[2] = topScore[1];
                topCity[2] = topCity[1];
                topScore[1] = topScore[0];
                topCity[1] = topCity[0];
                topScore[0] = s;
                topCity[0] = city.get(i);
            }
            else if (s > topScore[1])
            {
                topScore[2] = topScore[1];
                topCity[2] = topCity[1];
                topScore[1] = s;
                topCity[1] = city.get(i);
            }
            else if (s > topScore[2])
            {
                topScore[2] = s;
                topCity[2] = city.get(i);
            }
        }
        for (int i=0; i<3; i++)
        {
            if (topCity[i]!=null)
                System.out.println(topCity[i]+","+topScore[i]);
        }
    }
}
