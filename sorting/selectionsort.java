// select minimum and swap (isme leftwards sort hote rhga)
// (or select max and swap & isme rightwards sort hote rhega)

// psuedocode/implementation
/*
 * ex: 13,46,24,52,20,9
 * step1- select mini by travelling through entire array
 *        inner loop- move from index j from 0 to n-1 
 * step2-put mini ele in leftmost correct pos(swap)
 *       outer loop- swap the i ind ele by the mini index element
 * step3- leftmost gets sorted outer loop i moves from 0 to n-2
 */

// code
public class selectionsort {

    static int swaps = 0;

    static void selection_sort(double arr[], int n) {
        for (int i = 0; i <= n - 2; i++) { // till n-1 or n-2 kuch bhi likho 
            int mini = i;
            for (int j = i+1; j <= n - 1; j++) {
                if (arr[j] < arr[mini]) {
                    mini = j;
                }

            }
            if (mini != i) {
            double temp = arr[mini];
            arr[mini] = arr[i];
            arr[i] = temp;

                swaps++;
            }

        }

    }

    public static void main(String[] args) {
       
        double arr[] = { -1,0.2,0.1 ,0};
        int n = arr.length;
        selection_sort(arr, n);
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");

        }
        System.out.println();
        System.out.println("Swaps:"+swaps);

    }
}

// complexities
/*
 * time complexity:
 * the inner loop run for(approx): n+n-1+n-2+.....+2 (till the outer loop gets
 * over it also runs n times)
 * if we add 1 to it then its sum of first n natural numbers= n(n+1)/2
 * addition of 1 is negligible
 * thus if n is very big infinity then
 * best ,avg,worst case:O(n^2)
 * 
 * space complexity:
 * O(1)
 */
