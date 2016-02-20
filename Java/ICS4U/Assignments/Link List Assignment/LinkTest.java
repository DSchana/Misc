public class LinkTest {
    public static void main(String[] args) {
        LList nums = new LList();
        nums.push(17);
        nums.push(41);
        nums.push(38);
        System.out.println(nums);
        System.out.println(nums.pop());
        nums.enqueue(41);
        System.out.println(nums);
        System.out.println(nums.dequeue());
        System.out.println(nums);
    }
}