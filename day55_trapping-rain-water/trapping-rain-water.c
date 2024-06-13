int trap(int* height, int heightSize) {
    int a, b, v, x;
    a = 0, b = heightSize - 1, v = 0;
    while (a < b) {
        if (height[a] < height[b]) {
            for (x = a + 1; height[x] < height[a] && x < b; ++x) {
                v += height[a] - height[x];
            }
            a = x;
        } else {
            for (x = b - 1; height[x] < height[b] && x > a; --x) {
                v += height[b] - height[x];
            }
            b = x;
        }
    }
    return v;
}
