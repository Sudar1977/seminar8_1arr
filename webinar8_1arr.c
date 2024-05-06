#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


enum {SIZE = 12, SIZE2=20, SEED = 123,MAX=100};

int random_number(int n)
{
    return rand() % n - n/2;
}

void init_array(int size, int a[], int max_random)
{
    //~ printf("Size= %lld %lld %lld\n",sizeof(a)/sizeof(a[0]),sizeof(a),sizeof(a[0]));
    for (size_t i = 0; i < size; i++ )//size_t unsigned long
        a[i] = random_number(max_random);
}

void print_array(int size, int a[]) {
    for (size_t i = 0; i < size; i++ )
    {
        printf("%4d",a[i]);
    }
    printf("\n");
    return;
}

// циклический сдвиг массива влево на 1 элемент
void shift_array_left(int size, int a[])
{
    int tmp=a[0];
    for (size_t i=0; i < size-1; i++ )
        a[i] = a[i+1];
    a[size-1] = tmp;//a[size]
}

//void swap_arr(int i, int j,int arr[])
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*
 Реверс массива
 */
void revers_array(int size, int a[])
{
    for(size_t i=0; i<size/2; i++)
        //~ swap(&a[i], &a[size-1-i]);
        swap(a+i, a+size-1-i);
}
// Сортировка пузырьком
void buble_sort_array(int size, int a[]) {
    int i = 0;
    _Bool flag;
    do {
        flag = 0; // сбросить флаг
        for (int j = size-2; j >= i ; j-- )
            if ( a[j] > a[j+1] ) {
                swap(&a[j], &a[j+1]);
                flag = 1;  // поднять флаг если есть обмен
            }
        i++;
    }
    while ( flag );  // выход при flag = 0
}

// Сортировка выбором
void choose_sort_array(int size, int a[]) {
    int nMin=a[0];
    for(int i = 0; i <  size-1 ; i ++ )
    {
        for (int j =  i+1; j < size; j ++)
        {
            if( a[j] < a[nMin] )
                nMin = j;
        }
        if( nMin != i ) {
            swap(&a[i], &a[nMin]);
        }
    }
}


int main(int argc, char **argv)
{
    int a[SIZE];//={0};
    //~ for (i = 0; i < SIZE; i++
        //~ a[i]=0;
    memset(a,0,SIZE*sizeof(a[0]));
    //~ memcpy()
    //~ memcmp()
    print_array(SIZE,a);
    printf("Size= %lld\n",sizeof(a)/sizeof(a[0]));
    srand(SEED);
    init_array(SIZE, a, MAX);
    int len = SIZE;
    print_array(len,a);
    shift_array_left(SIZE,a);
    print_array(SIZE,a);
    revers_array(SIZE,a);
    print_array(SIZE,a);
    for (int i = 0; i < 3; i++)
    {
        shift_array_left(SIZE/3,a+i*SIZE/3);//сдвиг 1ой трети
    }
    //~ shift_array_left(SIZE/3,a+0*SIZE/3);//сдвиг 1ой трети
    //~ shift_array_left(SIZE/3,a+1*SIZE/3);//сдвиг 2ой трети
    //~ shift_array_left(SIZE/3,a+2*SIZE/3);//сдвиг 3ой трети
    print_array(SIZE,a);
    //замерить время начала
    choose_sort_array(SIZE,a);
    //замерить время конца
    print_array(SIZE,a);
    return 0;
}

