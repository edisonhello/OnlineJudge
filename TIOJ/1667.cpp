#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*bool readInput(FILE* in, vector<int>& ret) {
    int count;
    
    fscanf(in, "%d", &count);
    if (count == 0)
        return false;
    
    ret.clear();
    ret.resize(count);
    for (int i = 0; i < count; i++) {
        int value;
        fscanf(in, "%d", &value);
        ret[i] = value;
    }
    
    return true;
}*/
void readInput(int count,vector<int>& ret){
    int num;
    for(int i=0;i<count;i++){
        scanf("%d",&num);
        ret[i]=num;
    }
}

int mergeSort(vector<int>& data, int start, int end) {
    int length = end - start + 1;
    if (length <= 1)
        return 0;
    
    int mid = (start + end) / 2;
    
    int count = 0;
    
    count += mergeSort(data, start, mid);
    count += mergeSort(data, mid+1, end);
    
    int left = start;
    int right = mid+1;
    
    vector<int> t;
    while (left <= mid && right <= end) {
        if (data[left] <= data[right]) {
            t.push_back(data[left]);
            left++;
        }
        else /* data[left] > data[right] */ {
            count += mid-left+1;
            t.push_back(data[right]);
            right++;
        }
    }
    if (left <= mid) {
        while (left <= mid) {
            t.push_back(data[left]);
            left++;
        }
    }
    else {
        while (right <= end) {
            t.push_back(data[right]);
            right++;
        }
    }
    for (int i = start, j = 0; i <= end; i++, j++) {
        data[i] = t[j];
    }
    return count;
}

long alg_1080_2(const vector<int>& src) {
    vector<int> sorted = src;
    return mergeSort(sorted, 0, sorted.size()-1);
}

/*int main() {
    vector<int> vec;
    int loop = 1;
    while (readInput(stdin, vec)) {
        int count = alg_1080_2(vec);
        printf("Case #%d: %d\n", loop, count);
        loop += 1;
    }
    
    return 0;
}*/
int main(){
    vector<int> vec;
    int n;
    while (scanf("%d", &n) != EOF) {
        vec.resize(n);
        for (int i = 0; i < n; ++i) scanf("%d", &vec[i]);
        printf("%d\n", mergeSort(vec, 0, n - 1));
    }
    
    return 0;
}