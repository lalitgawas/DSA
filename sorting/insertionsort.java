/*
take an element and place it in correct position(adjacent swaps krke left side mai insert hote rhete)

psuedocode/implementation:
    1. find the correct position of the element(i moves one by one on each ele reducing the size of array i=0 to i=n-1)
    2. swap the element with the element at the correct position(acc to i index j moves from i to 1 )
    3. swap until it reaches its correct pos


*/

// code
public class insertionsort {

    static int swaps = 0;

    static void insertion_sort(int arr[], int n) {
        for (int i = 1; i < n; i++) { 
            for (int j = i; j > 0; j--) { 
                if (arr[j] < arr[j - 1]) {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                    swaps++;
                } else {
                    break; // No need to continue if the element is in the right position
                }
            }
        }
    }

    public static void main(String[] args) {

        int arr[] = {5,4,3,2,1};
        int n = arr.length;
        insertion_sort(arr, n);
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        System.out.println("Swaps: " + swaps);

    }
}

// complexties:
/*time complexity:
 * best case: O(n)  when all are sorted already only the outer loop runs for n times
 * worst ,avg case:O(n^2) in this the inner loop also runs until the outer loop run 
 * space complexity:
 * O(1)
 */