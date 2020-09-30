#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
  int size;
  int job;

  printf("Cac thao tac: \n");
  printf("1. In ra mang \n");
  printf("2. Tim phan tu co khoa la index co hay khong trong mang \n");
  printf("3. Tim phan tu co gia tri lon nhat trong mang \n");
  printf("4. Tim phan tu co gia tri nho nhat trong mang \n");
  printf("5. Tim so nguyen to trong mang \n");

  printf("Nhap thao tac Ban muon thuc hien.\n");
  printf("Vi du, neu muon dung in ra mang, nhap so 1, roi nhan enter: ");
  scanf("%d", &job);

  printf("Nhap so phan tu cua mang: ");
  size = inputSize();
  int array[size];

  // Nhap gia tri tung phan tu cua mang
  for (int i = 0; i < size; i++) {
    printf("Nhap phan tu [%d]: ", i);
    scanf("%d", &array[i]);
  }

  // In ra mang da nhap
  printArray(array, size);


  switch (job) {
  case 1:
    printf("\n1. In ra mang: \n");
    printArray(array, size);
    break;
  case 2:
    printf("\n2. Tim phan tu co khoa la index co hay khong trong mang \n");
    int index;
    printf("\nNhap index: ");
    scanf("%d", &index);
    findValueByIndex(array, size, index);
    break;
  case 3:
    printf("\n3. Tim phan tu co gia tri lon nhat trong mang \n");
    findMaxValue(array, size);
    break;
  case 4:
    printf("\n4. Tim phan tu co gia tri nho nhat trong mang \n");
    findMinValue(array, size);
    break;
  case 5:
    printf("\n5. Tim so nguyen to trong mang \n");
    checkArrayPrimeNumber(array, size);
    break;
  default:
    printf("Vui long nhap tu 1 toi 5");
  }
  return 0;
}

int inputSize() {
  int size;
  scanf("%d", &size);
  if (size >= 0 && size <=10000) {
    return size;
  } else {
    inputSize();
  }
}

// a. xuat chuoi vua nhap ra man hinh
void printArray(int * array, int size) {
  printf("Mang da nhap: ");
  printf("[");
  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("%d", array[i]);
    } else {
      printf("%d, ", array[i]);
    }
  }
  printf("]");
}

// b. Tim phan tu co khoa la index co hay khong trong mang
void findValueByIndex(int * array, int size, int index) {
  if (index < size && index >= 0) {
    printf("\nGia tri cua array[%d] la: [%d]\n", index, array[index]);
  } else {
    printf("\nError: Khoa khong nam trong pham vi so phan tu cua mang.\n");
  }
}

// c. Tim phan tu co gia tri lon nhat trong mang
void findMaxValue(int * array, int size) {
  if (size < 1) {
    printf("\nChuoi rong! Hay nhap lai\n");
    return;
  }
  int max = array[0];
  int maxIndex = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] > max) {
        max = array[i];
        maxIndex = i;
    }
  }
  printf("\nGia tri lon nhat trong mang la: array[%d] = %d\n", maxIndex, max);
}

// d. Tim phan tu co gia tri nho nhat trong mang
void findMinValue(int * array, int size) {
  if (size < 1) {
    printf("\nChuoi rong! Hay nhap lai\n");
    return;
  }
  int min = array[0];
  int minIndex = 0;
  for (int i = 0; i < size; i++) {
    if (array[i] < min) {
        min = array[i];
        minIndex = i;
    }
  }
  printf("\nGia tri nho nhat trong mang la: array[%d] = %d\n", minIndex, min);
}

// e. Tim so nguyen to trong mang
bool isPrimeNumber(int number) {
  if(number < 2){
    return false;
  }

  // bien count dem so ma number chia het
  int count = 0;
  for(int i = 2; i <= sqrt(number); i++){
    if(number % i == 0){
      count++;
    }
  }
  return (count == 0) ? true : false;
}

void checkArrayPrimeNumber(int * array, int size) {
  for (int i = 0; i < size; i++) {
    if (isPrimeNumber(array[i])) {
        printf("\nTim thay so nguyen to: array[%d] = %d", i, array[i]);
    }
  }
}
