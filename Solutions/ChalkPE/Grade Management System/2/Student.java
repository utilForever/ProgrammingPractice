package pe.chalk.gms;

import java.lang.reflect.Field;
import java.util.Arrays;
import java.util.IntSummaryStatistics;
import java.util.Objects;
import java.util.Scanner;
import java.util.function.Function;
import java.util.function.ToIntFunction;
import java.util.stream.Collectors;

/**
 * @author ChalkPE <chalk@chalk.pe>
 * @since 2017-06-02 11:03
 */
public class Student implements Comparable<Student> {
    @Input private String name;

    @Input @Score private byte korean;
    @Input @Score private byte english;
    @Input @Score private byte math;

    private short sum;
    private float average;
    private short rank;

    private static final Function<Student, ToIntFunction<Field>> scoreGetter = student -> field -> {
        try {
            return Byte.class.cast(field.get(student)).intValue();
        } catch (final Exception e) {
            e.printStackTrace();
            return 0;
        }
    };

    public Student(final Scanner scanner) {
        Arrays.stream(Student.class.getDeclaredFields())
                .filter(field -> Objects.nonNull(field.getAnnotation(Input.class)))
                .forEach(field -> this.readFromInput(field, scanner));

        scanner.nextLine();
        System.out.println();

        final IntSummaryStatistics statistics = Arrays.stream(Student.class.getDeclaredFields())
                .filter(field -> Objects.nonNull(field.getAnnotation(Score.class)))
                .collect(Collectors.summarizingInt(scoreGetter.apply(this)));

        this.sum = (short) statistics.getSum();
        this.average = (float) statistics.getAverage();
    }

    private void readFromInput(final Field field, final Scanner scanner) {
        final String fieldName = field.getName();
        System.out.printf("> %c%s : ", Character.toUpperCase(fieldName.charAt(0)), fieldName.substring(1));

        try {
            switch (field.getType().getSimpleName()) {
                case "String": field.set(this, scanner.nextLine()); break;
                case "byte":   field.set(this, scanner.nextByte(10)); break;
            }
        } catch (final Exception e) {
            e.printStackTrace();
        }
    }

    public Student setRank(final int index) {
        this.rank = (short) (index + 1);
        return this;
    }

    @Override
    public int compareTo(final Student student) {
        return Integer.compare(this.sum, student.sum);
    }

    @Override
    public String toString() {
        return String.format("%s\t%d\t%d\t%d\t%d\t%.1f\t%d",
                this.name, this.korean, this.english, this.math, this.sum, this.average, this.rank);
    }
}
