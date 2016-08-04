//
// Created by Wayne Tu on 5/16/16.
//

int sum(void* p, size_t size, size_t block_num) {
    int sum1 = 0;
    long long int sum2 = 0;
    int ans;
    if (size == 4) {
        for (int i = 0; i < block_num; ++i) {
            sum1 += p[i];
        }
        ans = int(sum1);
    }
    else if (size == 8) {
        for (int i = 0; i < block_num; ++i) {
            sum2 += p[i];
        }
        ans = int(sum2);
    }
    return ans;
}