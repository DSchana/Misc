public class LinkTest {
    public static void main(String[] args) {
        LList nums = new LList();
        nums.enqueue(17);
        nums.enqueue(38);
        nums.enqueue(41);
        nums.enqueue(43);
        System.out.println(nums);
        nums.deleteAt(2);
        System.out.println(nums);
    }
}