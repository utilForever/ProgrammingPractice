package pe.chalk.gms;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class StudentManager implements Runnable {
    private final static String MENU =
            "- Menu Select -%n" +
            "   1. Input Student's grade%n" +
            "   2. Print Student's grade%n" +
            "   3. Exit%n" +
            "%n" +
            "Select : ";

    private final static String HEADER =
        "Name\tKor\tEng\tMath\tSum\tAvg\tRank%n" +
        "====================================================%n";

    private final static String QUESTION = "> Do you continue to input (Y/N)? ";

    private final Scanner scanner;
    private final List<Student> students;

    public StudentManager(final Scanner scanner) {
        this.scanner = scanner;
        this.students = new ArrayList<>();
    }

    @Override
    public void run() {
        while (true) if (select()) break;
    }

    private boolean select() {
        System.out.printf(MENU);
        final int num = scanner.nextInt(10);

        scanner.nextLine();
        System.out.println();

        switch (num) {
            case 1: input(); return false;
            case 2: print(); return false;
            case 3: return true;

            default: return false;
        }
    }

    private void input() {
        while (true) {
            students.add(new Student(scanner));

            System.out.printf(QUESTION);
            final String answer = scanner.nextLine();
            System.out.println();

            switch (answer) {
                case "Y": continue;
                case "N": default: return;
            }
        }
    }

    private void print() {
        final List<Student> sorted = students.stream()
                .sorted(Comparator.reverseOrder())
                .collect(Collectors.toList());

        System.out.printf(HEADER);

        students.stream()
                .map(student -> student.setRank(sorted.indexOf(student)))
                .forEach(System.out::println);

        System.out.println();
    }
}
