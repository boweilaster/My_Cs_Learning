#include <iostream>
#include <vector>
#include <stdexcept>

// 工业级二维数组封装类
template <typename T>
class Matrix2D {
private:
    size_t rows_;
    size_t cols_;
    // 核心秘密：用一维的 vector 存储二维的数据
    // vector 的控制块（24字节）在栈上，但它内部的巨量数据在堆 (Heap) 上！
    std::vector<T> data_; 

public:
    // 构造函数：在堆上一次性分配 rows * cols 个元素的连续内存
    Matrix2D(size_t rows, size_t cols) 
        : rows_(rows), cols_(cols), data_(rows * cols) {}

    // 核心魔法：重载 operator() 来模拟二维访问
    // 我们自己实现编译器的寻址公式：row * cols_ + col
    T& operator()(size_t row, size_t col) {
        // 工业界的好习惯：加上越界检查 (虽然会损失一点点性能，但极其安全)
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Matrix index out of bounds!");
        }
        return data_[row * cols_ + col];
    }

    // 提供 const 版本，用于只读访问
    const T& operator()(size_t row, size_t col) const {
        if (row >= rows_ || col >= cols_) {
            throw std::out_of_range("Matrix index out of bounds!");
        }
        return data_[row * cols_ + col];
    }
};

int main() {
    // 1. 尝试分配一个 2000 x 2000 的矩阵 (约 15.2 MB)
    // 如果用 int arr[2000][2000]; 程序在这里已经崩溃了 (栈溢出)
    
    // 但使用我们的 Matrix2D，数据分配在堆上，轻松搞定！
    Matrix2D<int> image(2000, 2000);

    // 2. 像二维数组一样使用它
    image(10, 20) = 255; // 设置第 10 行，第 20 列的像素值为 255
    image(1999, 1999) = 128;

    std::cout << "image(10, 20) 的值: " << image(10, 20) << '\n';
    std::cout << "image(1999, 1999) 的值: " << image(1999, 1999) << '\n';

    // 3. 越界测试
    try {
        image(2000, 0) = 0; // 故意越界
    } catch (const std::exception& e) {
        std::cout << "捕获到异常: " << e.what() << '\n';
    }

    return 0; 
    // 函数结束，image 对象销毁，vector 的析构函数自动释放堆内存 (RAII)
}
