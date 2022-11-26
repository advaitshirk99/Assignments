#include<stdio.h>

//Swap function
void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

// A utility function to print array of size n
void print_array(int arr[], int n){
    for (int i = 0; i < n; ++i){-
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//Bubble sort
void bubbleSort(int arr[], int n){

    int i, j;
    
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//Function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

//Quick sort
void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

//Heapify function
void heapify(int arr[], int n, int i){

    int largest, left, right;

    //Starting with largest as node i
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    //Update indexes: > for MAX_HEAP, < for MIN_HEAP
    if (left < n && arr[left] > arr[largest])   largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    //Update the actual content on those indexes
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        //Recursive heapify to swap out the node and the smallest leaf node
        heapify(arr, n, largest);
    }
}

//Heap Sort function
void heapSort(int arr[], int n){

    //Build the max heap
    int i;
    for (i=(n/2 - 1); i>=0; i--) heapify(arr, n, i);

    for (i=0; i<n; i++) printf("%d ", arr[i]);

    //Heap sort
    for(i = n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

//Selection Sort
void selectionSort(int arr[], int n){

    int i, j, min_index;
    
    //First loop to iterate through all elements excluding last one
    for(i=0; i<n-1; i++){
        
        //Setting ith position as minimum index
        min_index = i;
        //j starts from i+1 because i elements are already checked, and are in ascending order
        for(j=i+1; j<n; j++){
            
            //If element on i+1 position is lesser than element on ith position, set min_index as i+1 position
            if(arr[j] < arr[min_index]){
                min_index = j;
            
            //The condition below only runs when the above if condition is satisfied. 
            if(min_index != i){
                swap(&arr[min_index], &arr[i]);
            }
            }
        }
    }
}

//Merge function
void merge(int arr[], int high, int mid, int low){

    //b will store the sorted array, hence will be of max size high
    int i, j, k, b[high+1];
    i = low;
    j = mid+1;
    k = low;

    /*dividing the array into two halves, i.e. from low to mid, and mid+1 to high
    The while loop runs till both sides are iterated till their respective ends (till mid and till high)*/
    while(i <= mid && j <= high){

        /*if element of left array is lesser than element of right array, place element of 
        right array in the new, b array (for ascending sort)*/
        if(arr[i] < arr[j]){
            b[k] = arr[i];
            i++; k++;
        }
        else{
            b[k] = arr[j];
            j++; k++;
        } 
    }

    //if the left array is bigger than the right array, the remaining elements of the left array are copied to the new array b
    while (i <= mid){
        b[k] = arr[i];
        i++; k++;
    }
    
    //if the right array is bigger than the right array, the remaining elements of the right array are copied to the new array b
    while (j <= high){
        b[k] = arr[j];
        j++; k++;
    }

    //The sorted array is stored back in the original array 
    for(i = low; i <= high; i++){
        arr[i] = b[i];
    }
}

//Merge sort function
void mergesort(int arr[], int high, int low){

    int mid;

    //Sorting will only occur if there are more than 1 elements in the array
    if(low < high){

        //mid is taken as the floor value (since if its an odd no, the decimal part will be ignored)
        mid = (low + high)/2;
        mergesort(arr, mid, low);
        mergesort(arr, high, mid+1);
        merge(arr, high, mid, low);
    }
}

//Insertion sort function
void insertionSort(int arr[], int n){

    int i, j, current;
    for(i=1; i<n; i++){

        current = arr[i];
        j = i - 1;

        /*This while loop will keep checking if the next element is 
        greater than the previous one, while j (the counter) is not less than 0 */
        //This will bring down the smallest element of the array to the 0th position
        //Use: > for ascending sort, < for descending sort
        while(j >= 0 && arr[j] > current){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = current;
    }
}

int main(){
    int i=7;
    while(i!=0){
        int arr[] = {21, 13, 53, 12, 46, 39, 78, 102};
        int n = sizeof(arr)/sizeof(int);
        printf("Unsorted array:\n");
        print_array(arr, n);
        printf("Enter the choice of sorting algorithm:\n");
        printf("1-->Bubble sort\n2-->Selection sort\n3-->Insertion sort\n4-->Quick sort\n5-->Merge sort\n6-->Heap sort\n0-->Exit\n");
        scanf("%d", &i);

        switch(i){
            case 0: exit(0);

            case 1: 
            bubbleSort(arr, n);
            print_array(arr, n);
            printf("\n------------------------------------\n");
            break;

            case 2:
            selectionSort(arr, n);
            print_array(arr, n);
            printf("\n------------------------------------\n");
            break;

            case 3:
            insertionSort(arr, n);
            print_array(arr, n);
            printf("\n------------------------------------\n");
            break;

            case 4:
            quickSort(arr, 0, n-1);
            print_array(arr, n);
            printf("\n------------------------------------\n");
            break;

            case 5:
            mergesort(arr, n-1, 0);
            print_array(arr, n);
            printf("\n------------------------------------\n");
            break;

            case 6:
            heapSort(arr, n);
            print_array(arr, n);
            printf("\n------------------------------------\n");
            break;

            default:
            printf("Invalid choice!\n");
            printf("\n------------------------------------\n");
            break;
        }
    }
}
