#include <iostream>
#include <vector>

void bubblesort(int *arr, int len) {
        int i, j, temp;
        //std::cout<<"length: "<<len<<std::endl;
        for (i = 0; i < len - 1; i++){
                for (j = 0; j < len - 1 - i; j++){
                        if (arr[j] > arr[j + 1]){
                                temp = arr[j] ;
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                        }
                }
        }
}

int main(){
        srand(time(nullptr));
        int m = 0;
        int n = 100;
        int size = 32;
        int* Stack_ptr = new int[size]();
        for (int i=0; i<32; i++){
                int iNumber = rand() % n + m ;   // Zufallszahl zwischen [m, m+n[, kann öfters verendet werden  
                Stack_ptr[i] = iNumber;
        }
        for (int i=0; i<32; i++){
                std::cout<<Stack_ptr[i]<<std::endl;
        }
        bubblesort(Stack_ptr, size);
        std::cout<<"------------Sortiert------------"<<std::endl;
        for (int i=0; i<32; i++){
                std::cout<<Stack_ptr[i]<<std::endl;
        }
        delete []Stack_ptr;
        return 0;
}
