package pe.chalk.gms;

import java.util.Scanner;

/**
 * @author ChalkPE <chalk@chalk.pe>
 * @since 2017-06-02 13:33
 */
public class Main {
    public static void main(final String... args) {
        try (final Scanner scanner = new Scanner(System.in)) {
            new StudentManager(scanner).run();
        } catch (final Exception e) {
            e.printStackTrace();
        }
    }
}
