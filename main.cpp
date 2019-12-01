/*冒泡排序、简单选择排序、直接插入排序、希尔排序、堆排序、归并排序、快速排序及优化*/
#include <iostream>

using namespace std;
#define MAXSIZE 10
typedef struct {
    int r[MAXSIZE + 1];
    int length;
} sqList;

void BubbleeSort(sqList *L) {
    for (int i = 1; i < L->length; ++i) {
        for (int j = L->length - 1; j >= i; j--) {
            if (L->r[j] > L->r[j + 1]) {
                swap(L->r[j], L->r[j + 1]);
            }
        }
    }
}

void BubbleSort2(sqList *L) {
    bool flag = true;
    for (int k = 1; k < L->length && flag; ++k) {
        flag = false;
        for (int l = L->length - 1; l >= k; l--) {
            if (L->r[l] > L->r[l + 1]) {
                swap(L->r[l], L->r[l + 1]);
                flag = true;
            }
        }
    }
}

void SelectSort(sqList *L) {
    int min;
    for (int i = 1; i < L->length; ++i) {
        min = i;
        for (int j = i + 1; j <= L->length; ++j) {
            if (L->r[min] > L->r[j]) {
                min = j;
            }
            if (i != min) {
                swap(L->r[i], L->r[min]);
            }
        }
    }
}

void InsertSort(sqList *L) {
    for (int i = 2; i <= L->length; ++i) {
        if (L->r[i] < L->r[i - 1]) {
            L->r[0] = L->r[i];
            int j;
            for (j = i - 1; L->r[j] > L->r[0]; j--) {
                L->r[j + 1] = L->r[j];
            }
            L->r[j + 1] = L->r[0];
        }
    }
}

void ShellSort(sqList *L) {
    int increment = L->length;
    do {
        increment = increment / 3 + 1;
        for (int i = increment + 1; i <= L->length; i++) {
            if (L->r[i] < L->r[i - increment]) {
                L->r[0] = L->r[i];
                int j;
                for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment) {
                    L->r[j + increment] = L->r[j];
                }
                L->r[j + increment] = L->r[0];
            }
        }
    } while (increment > 1);
}

void HeapAdjust(sqList *L, int s, int m) {
    int temp = L->r[s];
    for (int i = 2 * s; i <= m; i *= 2) {
        if (i < m && L->r[i] < L->r[i + 1]) {
            ++i;
        }
        if (temp >= L->r[i]) {
            break;
        }
        L->r[s] = L->r[i];
        s = i;
    }
    L->r[s] = temp;
}


void HeapSort(sqList *L) {
    for (int j = L->length / 2; j > 0; j--) {
        HeapAdjust(L, j, L->length);
    }
    for (int i = L->length; i > 1; i--) {
        swap(L->r[1],L->r[i]);
        HeapAdjust(L, 1, i - 1);
    }
}

void merge(int SR[], int TR[], int i, int m, int n) {
    int j, k, l;
    for (j = m + 1, k = i; j <= n && i <= m; k++) {
        if (SR[i] < SR[j]) {
            TR[k] = SR[i++];
        } else {
            TR[k] = SR[j++];
        }
    }
    if (i <= m) {
        for (l = 0; l <= m - i; l++) {
            TR[k + 1] = SR[i + 1];
        }
    }
    if (j <= n) {
        for (l = 0; l <= n - j; l++) {
            TR[k + 1] = SR[j + 1];
        }
    }
}

void MergePass(int SR[], int TR[], int s, int n) {
    int i = 1;
    int j;
    while (i <= n - 2 * s + 1) {
        merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
        i = i + 2 * s;
    }
    if (i < n - s + 1) {
        merge(SR, TR, i, i + s - 1, n);
    } else {
        for (j = i; j <= n; j++) {
            TR[j] = SR[j];
        }
    }
}

int partition(sqList *L, int low, int high) {
    int pivotkey;
    pivotkey = L->r[low];
    L->r[0] = pivotkey;
    while (low < high) {
        while (low < high && L->r[high] >= pivotkey) {
            high--;
        }
        L->r[low] = L->r[high];
        while (low < high && L->r[low] <= pivotkey) {
            low++;
        }
        L->r[high] = L->r[low];
    }
    L->r[low] = L->r[0];
    return low;
}

void QSort(sqList *L, int low, int high) {
    int pivot;
    while (low < high) {
        pivot = partition(L, low,high);
        QSort(L, low, pivot - 1);
        low = pivot + 1;
    }
}

void QuickSort(sqList *L) {
    QSort(L, 1, L->length);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sqList *L=new sqList;
        cin>>L->length;
        for (int i = 1; i <=L->length ; ++i) {
            cin>>L->r[i];
        }
        //sort here
    }
}