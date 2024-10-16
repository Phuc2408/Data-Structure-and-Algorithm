#include <iostream>
using namespace std;

int minCoinsToBuyFruits(int prices[], int n) {
    int totalCoins = 0;
    int i = 0;

    // Duyệt qua tất cả các trái cây và tính tổng tiền
    while (i < n) {
        // Mua trái cây hiện tại và thêm giá vào tổng tiền
        totalCoins += prices[i];
        cout << "Buying fruit at index " << i << " with price " << prices[i] << endl;
        cout << "Total coins so far: " << totalCoins << endl;

        // Nếu có thể, chúng ta sẽ tiếp tục mua trái cây tiếp theo
        // Nếu không có trái cây tiếp theo thì dừng lại
        if (i + 1 < n) {
            totalCoins += prices[i + 1];  // Mua trái cây tiếp theo
            cout << "Buying fruit at index " << i + 1 << " with price " << prices[i + 1] << endl;
        }

        // Tiếp tục với trái cây tiếp theo
        i += 2;  // Di chuyển đến trái cây tiếp theo
    }

    return totalCoins;
}

int main() {
    // Example 1
    int prices1[] = { 3, 1, 2 };
    int n1 = sizeof(prices1) / sizeof(prices1[0]);
    cout << "Minimum coins needed for example 1: " << minCoinsToBuyFruits(prices1, n1) << endl;

    // Example 2
    int prices2[] = { 1, 10, 1, 1 };
    int n2 = sizeof(prices2) / sizeof(prices2[0]);
    cout << "Minimum coins needed for example 2: " << minCoinsToBuyFruits(prices2, n2) << endl;

    // Example 3
    int prices3[] = { 26, 18, 6, 12, 49, 7, 45, 45 };
    int n3 = sizeof(prices3) / sizeof(prices3[0]);
    cout << "Minimum coins needed for example 3: " << minCoinsToBuyFruits(prices3, n3) << endl;
    system("pause");
    return 0;
}
