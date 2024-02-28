#define TRUE 1
#define FALSE 0
# define MAX_ELEMENTS 20

int less(int i, int j) {
	if (i < j)
		return TRUE;
	else
		return FALSE;
}

void swap(int array[], int i, int j ) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void basicSort(int array[]) {
	for (int i = 0; i < MAX_ELEMENTS; i++)
		for (int j = i; j > 0; j--)
			if (less(array[j], array[j - 1]))
				swap(array, j, j - 1);
			else
				break;
}

int isSorted(int array[]) {
	for (int i = 1; i < MAX_ELEMENTS; i++) {
		if (less(array[i], array[i - 1]))
			return FALSE;
	}
	return TRUE;
}


void insertionSort(int array[]) {
	int i, j, key, comparisons = 0;
	for (i = 1; i < MAX_ELEMENTS; i++) {
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
			comparisons++;
		}
		array[j + 1] = key;
	}
	printf("%d comparisons\n\n", comparisons);
}

void selectionSort(int array[]) {
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		int min = i;
		for (int j = i + 1; j < MAX_ELEMENTS; j++) {
			if (less(array[j], array[min]))
				min = j;
		}
		swap(array, i, min);
	}
}

void merge(int array[], int l, int m, int r) {
	int i, j, k;
	int leftSize = m - l + 1;
	int rightSize = r - m;
	int leftArray[MAX_ELEMENTS], rightArray[MAX_ELEMENTS];
	for (i = 0; i < leftSize; i++)
		leftArray[i] = array[l + i];
	for (j = 0; j < rightSize; j++)
		rightArray[j] = array[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while ((i < leftSize) && (j < rightSize)) {
		if (leftArray[i] <= rightArray[j]) {
			array[k] = leftArray[i];
			i++;
		}
		else {
			array[k] = rightArray[j];
			j++;
		}
		k++;
	}
	while (i < leftSize) {
		array[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < rightSize) {
		array[k] = rightArray[j];
		j++;
		k++;
	}
}

void mergesort(int array[], int l, int r) {
	if (l >= r)
		return;
	int m = l + (r - l) / 2;
	mergesort(array, l, m);
	mergesort(array, m + 1, r);
	merge(array, l, m, r);
}

void mergeBU(int array[], int l, int m, int r) {
	int i, j, k;
	int leftSize = m - l + 1;
	int rightSize = r - m;
	int leftPart[MAX_ELEMENTS], rightPart[MAX_ELEMENTS];
	for (i = 0; i < leftSize; i++)
		leftPart[i] = array[l + i];
	for (j = 0; j < rightSize; j++)
		rightPart[j] = array[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < leftSize && j < rightSize) {
		if (leftPart[i] <= rightPart[j]) {
			array[k] = leftPart[i];
			i++;
		}
		else {
			array[k] = rightPart[j];
			j++;
		}
		k++;
	}
	while (i < leftSize) {
		array[k] = leftPart[i];
		i++;
		k++;
	}
	while (j < rightSize) {
		array[k] = rightPart[j];
		j++;
		k++;
	}
}

void mergesortBU(int array[], int arraySize) { // Bottom up merging
	int currSize;
	int leftStart;
	for (currSize = 1; currSize <= arraySize - 1; currSize = 2 * currSize) {
		for (leftStart = 0; leftStart < arraySize - 1; leftStart += 2 * currSize) {
			int mid = minimum(leftStart + currSize - 1, arraySize - 1);
			int right_end = minimum(leftStart + 2 * currSize - 1, arraySize - 1);
			mergeBU(array, leftStart, mid, right_end);
		}
	}
}


void quicksort(int array[], int l, int r) {
	if (r - l <= 0)
		return;
	int m = partition(array, l, r);
	quicksort(array, l, m - 1);
	quicksort(array, m + 1, r);
}

int partition(int array[], int l, int r) {
	int i = l - 1;
	int j = r;
	while (TRUE) {
		while (less(array[++i], array[r]))
			if (i == r)
				break;
		while (less(array[r], array[--j]))
			if (j == l)
				break;
		if (i >= j)
			break;
		swap(array, i, j);
	}
	swap(array, i, r);
	return i;
}