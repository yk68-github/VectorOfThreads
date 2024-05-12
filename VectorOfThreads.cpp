#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <functional>

int main()
{
    const auto processor_count = std::thread::hardware_concurrency();
    std::vector<std::thread> vecOfThreads;

    std::function<void(const unsigned int)> func = [](const unsigned int pause) {
        std::this_thread::sleep_for(std::chrono::milliseconds(pause));
        std::cout << "From Thread ID : " << std::this_thread::get_id() << "\n";
        };

    for (unsigned int i = 0; i < (processor_count - 2); i++)
    {
         vecOfThreads.push_back((std::thread(func, 100)));
    }

    for (std::thread& th : vecOfThreads)
    {
        if (th.joinable())
            th.join();
    }

    std::string s;
    
    std::cin.ignore();
    std::getline(std::cin, s);


    return 0;
}