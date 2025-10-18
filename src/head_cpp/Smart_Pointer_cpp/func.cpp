#include "func.h"


void smartptrs(){
    {
        // 1. unique_ptr 示例 (独占所有权)
        std::cout << "=== unique_ptr 示例 ===" << std::endl;
        std::unique_ptr<Report> uniquePtr(new Report("unique_ptr"));
        uniquePtr->comment();
        
        // 所有权转移
        std::unique_ptr<Report> uniquePtr2 = std::move(uniquePtr);
        if (!uniquePtr)
            std::cout << "独占指针现在是空的" << std::endl;
        uniquePtr2->comment();
    } // uniquePtr2 离开作用域，对象自动销毁

    {
        // 2. shared_ptr 示例 (共享所有权)
        std::cout << "\n=== shared_ptr 示例 ===" << std::endl;
        std::shared_ptr<Report> sharedPtr1(new Report("shared_ptr"));
        std::cout << "引用计数: " << sharedPtr1.use_count() << std::endl;
        
        {
            std::shared_ptr<Report> sharedPtr2 = sharedPtr1;
            std::cout << "引用计数: " << sharedPtr1.use_count() << std::endl;
            sharedPtr2->comment();
        }
        
        std::cout << "引用计数: " << sharedPtr1.use_count() << std::endl;
        sharedPtr1->comment();
    } // sharedPtr1 离开作用域，对象自动销毁

    {
        // 3. weak_ptr 示例 (避免循环引用)
        std::cout << "\n=== weak_ptr 示例 ===" << std::endl;
        std::shared_ptr<Report> sharedPtr(new Report("shared_ptr for weak_ptr"));
        std::weak_ptr<Report> weakPtr = sharedPtr;
        
        std::cout << "引用计数: " << sharedPtr.use_count() << std::endl;
        
        if (auto temp = weakPtr.lock()) { // 尝试获取 shared_ptr
            temp->comment();
            std::cout << "临时引用计数: " << sharedPtr.use_count() << std::endl;
        }
        
        sharedPtr.reset(); // 释放对象
        std::cout << "After reset - 引用计数: " << sharedPtr.use_count() << std::endl;
        
        if (weakPtr.expired())
            std::cout << "对象已被销毁" << std::endl;
    }

    {
        // 4. 使用 make_shared (推荐方式)
        std::cout << "\n=== make_shared 示例 ===" << std::endl;
        auto sharedPtr = std::make_shared<Report>("make_shared");
        sharedPtr->comment();
        
        auto uniquePtr = std::make_unique<Report>("make_unique");
        uniquePtr->comment();
    }
}
