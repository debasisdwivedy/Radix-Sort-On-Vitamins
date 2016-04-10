#include <iostream>
#include<vector>
#include "RadixSort"
#include<cstring>
#include<ctime>
#include<algorithm>
#include<limits>
#include<sstream>
#include<bitset>
using namespace std;
void higherBaseSort();
void floatSort();
void quickSort(std::vector<float>, int , int );
int main() {
    //higherBaseSort();
    floatSort();
    return 0;
}

void floatSort()
{
    clock_t start,end;
    std::vector<float> inputArr(10000,0);
    int imax=std::numeric_limits<float>::max();
    int max=pow(10,to_string(imax).length()-1);
    for (int count = 0; count < 10000; count++) {
        //float generated_num = rand() % max;
        float generated_num =static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        inputArr[count] = generated_num;
    }
    /*float input[]={123.4567890,
                   45.7,
                   6.57,
                   8.39,
                   -43.6,
                   -720,
                   -3.55,
                   -0.123,
                   12.34,
                   1234.5,
                   -1.23456};
    std::vector<float> inputArr (input, input + sizeof(input) / sizeof(float) );*/
    start=clock();
    quickSort(inputArr,0,inputArr.size());
    end=clock();
    cout<<"time difference in microsec for quick sort:- "<<end-start<<endl;

    std::vector<float> outArr(inputArr.size(),0);
    start=clock();
    floatRadixSort(inputArr,outArr);
    end=clock();
    cout<<"time difference in microsec for counting sort:- "<<end-start<<endl;
    /*for (int i = 0; i < outArr.size(); ++i) {
        cout<<outArr[i]<<endl;
    }*/
}

void higherBaseSort()
{
    clock_t start,end;
    int imax=std::numeric_limits<int>::max();
    int max=pow(10,to_string(imax).length()-1);
    std::vector<int> inputArr(1000,0);
    /*int input[]={1234567890,
                 457,
                 657,
                 839,
                 436,
                 720,
                 355,
                 123,
                1234,
                12345,
                123456};*/
    for (int count = 0; count < 1000; count++) {
        int generated_num = rand() % max;
        inputArr[count] = generated_num;
    }
    int base=40;
    //std::vector<int> inputArr (input, input + sizeof(input) / sizeof(int) );
    std::vector<int> outArr(inputArr.size(),-1);
    std::vector<string> inputBaseArr(inputArr.size(),"");
    std::vector<string> outBaseArr(inputArr.size(),"");
    std::vector<string> maxBaseNumber(1,"");
    std::vector<int> backDeci(inputArr.size(),-1);
    auto minmax = std::minmax_element(inputArr.begin(),inputArr.end());
    //std::cout << "min element " << *(minmax.first) << "\n";
    //std::cout << "max element " << *(minmax.second) << "\n";
    int max_digits=to_string(minmax.second[0]).length();
    cout<<max_digits<<endl;
    start=clock();
    radixSort(inputArr,outArr,max_digits,10);
    end=clock();
    cout<<"time difference in microsec for normal:- "<<end-start<<endl;
    /*for (int i = 0; i < inputArr.size(); ++i) {
        cout<<inputArr[i]<<"------"<<outArr[i]<<"-------"<<endl;
    }*/

    int maxbase=minmax.second[0];
    int arr[]={maxbase};
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
    changeBase(vec,maxBaseNumber,base);
    max_digits=(maxBaseNumber[0]).size();

    changeBase(inputArr,inputBaseArr,base);
    start=clock();
    radixSortBase(inputBaseArr,outBaseArr,max_digits,base);
    end=clock();
    convtodecnum(outBaseArr,backDeci,base);

    cout<<"time difference in microsec for higher base:- "<<end-start<<endl;
    /*for (int i = 0; i < outBaseArr.size(); ++i) {
        cout<<inputBaseArr[i]<<"------"<<outBaseArr[i]<<"-------"<<backDeci[i]<<endl;
    }*/
}
void quickSort(std::vector<float> arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

//x is the number to be decomposed
//m is the mantissa
//n is the exponent
//sort on sign , mantissa,exponent
/*bool sign;
int n;
sign=std::signbit(x);
double m = frexp(x, &n);
std::bitset<sizeof(int) * 8> binaryMantissa(m);
std::bitset<sizeof(int) * 8> binaryExponent(n);*/