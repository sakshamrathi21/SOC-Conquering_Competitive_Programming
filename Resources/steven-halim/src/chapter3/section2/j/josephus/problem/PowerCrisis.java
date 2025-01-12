package chapter3.section2.j.josephus.problem;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by Rene Argento on 22/01/22.
 */
public class PowerCrisis {

    public static void main(String[] args) throws IOException {
        FastReader.init();
        OutputWriter outputWriter = new OutputWriter(System.out);
        int regions = FastReader.nextInt();

        while (regions != 0) {
            int offset = computeOffset(regions);
            outputWriter.printLine(offset);
            regions = FastReader.nextInt();
        }
        outputWriter.flush();
    }

    private static int computeOffset(int regions) {
        for (int offset = 1; offset <= regions; offset++) {
            if (josephus(regions - 1, offset) == 11) {
                return offset;
            }
        }
        return -1;
    }

    private static int josephus(int circleSize, int skip) {
        if (circleSize == 1) {
            return 0;
        }
        return (josephus(circleSize - 1, skip) + skip) % circleSize;
    }

    private static class FastReader {
        private static BufferedReader reader;
        private static StringTokenizer tokenizer;

        static void init() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = new StringTokenizer("");
        }

        private static String next() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        private static int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }

    private static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

        public void flush() {
            writer.flush();
        }
    }
}
