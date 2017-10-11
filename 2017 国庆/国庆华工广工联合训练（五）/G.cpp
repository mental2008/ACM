#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
};

Point solve(int depth, int n) {
    if(depth == 1) {
        if(n == 0) return (Point){0, 0};
        else if(n == 1) return (Point){0, 1};
        else if(n == 2) return (Point){1, 1};
        else return (Point){1, 0};
    }
    int area = n / (1 << (2 * (depth - 1)));
    int num = n % (1 << (2 * (depth - 1)));
    if(area == 0) {
        Point temp = solve(depth - 1, (1 << (2 * (depth - 1))) - num - 1);
        // printf("temp: (%d, %d)\n", temp.x, temp.y);
        return (Point){temp.y, (1 << (depth - 1)) - temp.x - 1};
    }
    else if(area == 1) {
        Point temp = solve(depth - 1, num);
        // printf("temp: (%d, %d)\n", temp.x, temp.y);
        return (Point){temp.x, (1 << (depth - 1)) + temp.y};
    }
    else if(area == 2) {
        Point temp = solve(depth - 1, num);
        // printf("temp: (%d, %d)\n", temp.x, temp.y);
        return (Point){(1 << (depth - 1)) + temp.x, (1 << (depth - 1)) + temp.y};
    }
    else {
        Point temp = solve(depth - 1, (1 << (2 * (depth - 1))) - num - 1);
        // printf("temp: (%d, %d)\n", temp.x, temp.y);
        return (Point){2 * (1 << (depth - 1)) - temp.y - 1, temp.x};
    }
}

int main() {
    int caseCnt;
    scanf("%d", &caseCnt);
    while(caseCnt--) {
        int n, a, b;
        scanf("%d%d%d", &n, &a, &b);
        a--;
        b--;
        Point A = solve(n, a);
        A.x *= 10, A.y *= 10;
        // printf("A: (%d, %d)\n", A.x, A.y);
        Point B = solve(n, b);
        B.x *= 10, B.y *= 10;
        // printf("B: (%d, %d)\n", B.x, B.y);
        double ans = sqrt(1LL * (A.x - B.x) * (A.x - B.x) + 1LL * (A.y - B.y) * (A.y - B.y));
        printf("%d\n", (int)round(ans));
    }
    return 0;
}
