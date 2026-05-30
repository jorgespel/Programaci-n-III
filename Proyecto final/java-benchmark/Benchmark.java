import java.io.FileWriter;
import java.util.HashMap;
import java.util.TreeMap;

public class Benchmark {

    public static void main(String[] args) {

        try {

            FileWriter writer = new FileWriter("java_results.csv");

            writer.write("language,operation,structure,records,time_ms\n");

            int records = 10000;

            // HASHMAP

            HashMap<Integer, String> hashMap = new HashMap<>();

            long start = System.nanoTime();

            for(int i=0;i<records;i++) {
                hashMap.put(i, "Student" + i);
            }

            long end = System.nanoTime();

            double timeInsertHash =
                    (end - start) / 1000000.0;

            writer.write("Java,insert,HashMap,"
                    + records + ","
                    + timeInsertHash + "\n");

            // SEARCH

            start = System.nanoTime();

            for(int i=0;i<records;i++) {
                hashMap.get(i);
            }

            end = System.nanoTime();

            double timeSearchHash =
                    (end - start) / 1000000.0;

            writer.write("Java,search,HashMap,"
                    + records + ","
                    + timeSearchHash + "\n");

            // TREEMAP

            TreeMap<Integer, String> treeMap =
                    new TreeMap<>();

            start = System.nanoTime();

            for(int i=0;i<records;i++) {
                treeMap.put(i, "Student" + i);
            }

            end = System.nanoTime();

            double timeTree =
                    (end - start) / 1000000.0;

            writer.write("Java,insert,TreeMap,"
                    + records + ","
                    + timeTree + "\n");

            writer.close();

            System.out.println("Benchmark completado");

        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
