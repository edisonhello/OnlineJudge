
int main() {
    initialize();
    int right = 2147483647;
    int left = 1;
    int mid = (2147483647 + 1) / 2;
    while (true) {
        if (left >= right) answer(mid);
        if (throw_egg(mid)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    return 0;
}