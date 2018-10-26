package GenericExamples;

public class GenericBox <T> {

    private T t;

    public void set(T t) {
        this.t = t;
    }

    public T get() {
        return t;
    }

    public static void main(String[] args) {

        GenericBox<Integer> b = new GenericBox<>();
        b.set(1);
        System.out.println(b.get());

        int i = (int) b.get();
        System.out.println(b.get());

    }
}