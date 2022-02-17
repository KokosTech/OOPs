#include <iostream>

using namespace std;

void refExample(int &a){
    a++;
}

char *Malloc(size_t size){
    return new char[size];
}

char *Realloc(char *arr, size_t old, size_t size){
    char *newArr = new char[size];
    for(int i = 0; i < old; ++i){
        newArr[i] = arr[i];
    }
    delete [] arr;
    return newArr;
}
// malloc, calloc, realloc, free - C
// new, delete - C++

int main(){
    cout << "Hello, World!" << endl;
    printf("Hello, World!\n");

    int a, b;
    cin >> a, b;
    scanf("%d", &a);
    refExample(a);

    cout << a 
        << " "
        << b
        << endl;

    // Malloc
    char *arr = Malloc(10);
    // Realloc
    arr = Realloc(arr, 10, 20);

    int *i = new int(0);

    cout << *i << endl;

    delete [] arr;
    delete i;
    return 0;
}