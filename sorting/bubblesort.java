/*
select max and move it rightwards by adjacent swaps


psuedocode/implementation:
    1.  Find the maximum element in the array(move index j=0 till second last ele of the arr)
    2.  Move the maximum element to the end of the array(shift max to right as the arr size becomes short gradually)
    3.  Repeat the process until the array is sorted(repeat until i=n-1 to i=1)

*/

// code

public class bubblesort {
    static int swaps = 0;

    static void bubble_sort(int arr[], int n) {
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 0; j <= i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swaps++;
                }

            }
            if (swaps == 0) {
                System.out.println("Array is already sorted");
                break;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = { 6, 5, 4, 3, 2, 1 };
        int n = arr.length;
        bubble_sort(arr, n);
        if (swaps != 0) {

            System.out.println("Sorted array is");
        }
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        System.out.println("Swaps:" + swaps);
    }

}
/*
 * complexities
 * time complexity:
 * avg,worst case:O(n^2) =>
 * the inner loop run for(approx): n+n-1+n-2+.....+2 (till the outer loop gets
 * over it also runs n times)
 * if we add 1 to it then its sum of first n natural numbers= n(n+1)/2
 * addition of 1 is negligible
 * thus if n is very big infinity then
 * best case:O(n) =>
 * the inner loop runs for n times as outer loop runs for only 1 time then it breaks out the func as its sorted already
 * space complexity:
 * O(1)
 */
