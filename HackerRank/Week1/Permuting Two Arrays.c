#include stdio.h

void sortAsc(int arr[], int n) {
    for(int i = 0; i  n-1; i++) {
        for(int j = i+1; j  n; j++) {
            if(arr[i]  arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortDesc(int arr[], int n) {
    for(int i = 0; i  n-1; i++) {
        for(int j = i+1; j  n; j++) {
            if(arr[i]  arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

const char checkArrays(int size, int limit, int arr1[], int arr2[]) {
    sortAsc(arr1, size);
    sortDesc(arr2, size);
    for(int i = 0; i  size; i++) {
        if(arr1[i] + arr2[i]  limit) return NO;
    }
    return YES;
}

int main() {
    int q;
    scanf(%d, &q);
    for(int t = 0; t  q; t++) {
        int n, k;
        scanf(%d %d, &n, &k);
        int A[n], B[n];
        for(int i = 0; i  n; i++) scanf(%d, &A[i]);
        for(int i = 0; i  n; i++) scanf(%d, &B[i]);
        printf(%sn, checkArrays(n, k, A, B));
    }
    return 0;
}
