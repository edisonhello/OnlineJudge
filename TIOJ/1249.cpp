//
// Created by Wayne Tu on 3/6/16.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct SORT {

    string unsorted;
    string sorted;

    bool operator < (const SORT& sort) const {
        if (sorted < sort.sorted)
            return true;
        else if (sorted > sort.sorted)
            return false;
        else {
            return unsorted < sort.unsorted;
        }
    }

};

void stringOutput(string temp) {
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i];
    }
}

void answerOutput(vector<string> answer) {
    unsigned long len = answer.size();
    for (int i = 0;i < len;i++) {
        if (i == len - 1) {
            stringOutput(answer[i]);
            cout << '\n';
        }

        else {
            stringOutput(answer[i]);
            cout << ',';
        }
    }
}

void readInput(FILE* in, vector<SORT>& accounts) {
    int len;
    fscanf(in, "%d\n", &len);
    if (len == 0) {
        accounts.resize(0);
        return;
    }
    accounts.resize(len);
    for (int i = 0; i < len; i++) {
        string array;
        char temp[128];
        fgets(temp, 127, in);

        array = temp;
        array.erase(remove(array.begin(), array.end(), '\n'), array.end());

        string array2 = array;
        accounts[i].unsorted = array;
        sort(array2.begin(), array2.end());
        accounts[i].sorted = array2;
    }

}

void solve(vector<SORT> accounts) {
    unsigned long len = accounts.size();
    int count = 0;
    vector<vector<string>> unsortedArray;
    for (int i = 0; i < len-1; i++) {
        if (accounts[i].sorted == accounts[i+1].sorted) {
            vector<string> elements;
            elements.push_back(accounts[i].unsorted);
            int j = i + 1;
            while (accounts[j].sorted == accounts[j-1].sorted && j < len) {
                if (j == len - 1) {
                    elements.push_back(accounts[j].unsorted);
                    unsortedArray.push_back(elements);
                    count++;
                    i++;
                    break;
                }
                else if (accounts[j].sorted != accounts[j+1].sorted) {
                    elements.push_back(accounts[j].unsorted);
                    count++;
                    unsortedArray.push_back(elements);
                    i++;
                    break;
                }
                elements.push_back(accounts[j].unsorted);
                count++;
                i++;
                j++;
            }
        }
    }
    if (count == 0) {
        cout << "No Answer" << "\n";
    }

    else {
        sort(unsortedArray.begin(), unsortedArray.end());
        unsigned long length = unsortedArray.size();
        for (int i = 0; i < length; i++){
            answerOutput(unsortedArray[i]);
        }
    }
}
int main(int argc,char* argv[]) {
    FILE* in = stdin;
    if (argc == 2) {
        in = fopen(argv[1], "r");
    }


    while (true) {
        vector<SORT> accounts;
        readInput(in, accounts);
        if (accounts.size() == 0) {
            break;
        }
        sort(accounts.begin(), accounts.end());
        solve(accounts);

    }
    if (in != stdin) {
        fclose(in);
    }
    return 0;
}

