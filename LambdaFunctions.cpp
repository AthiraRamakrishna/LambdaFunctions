#include <iostream>
#include <algorithm>
#include <string_view>
#include <array>
#include <vector>
#include <functional>

void repeat(int reps, const std::function<void(int)>& fn )
{
    for (int i =0; i< reps; ++i)
    {
        fn(i);
    }
}
int main()
{
    //At runtime, when the lambda definition is encountered, the lambda object is instantiated, and the members of the lambda are initialized at that point.
    
    //Lambda Example 1
    std::string_view strToFind{"nut"};
    constexpr std::array<std::string_view, 4> arr{"apple", "banana","walnut", "groundnut"};
    
    //The captured variables of a lambda are clones of the outer scope variables, not the actual variables.
    //Captures default to const value
    const auto found{std::find_if(arr.begin(), arr.end(),[strToFind](std::string_view str)
    {
         return (str.find(strToFind) != std::string_view::npos);
    })};
    
    if(found == arr.end())
    {
        std::cout<<" No nut"<<std::endl;
    }
    else
    {
        std::cout<< " found nut" <<std::endl;
    }
    
    //Lambda Example 2
    
    int i = 3;
    std::vector<int> v{2,2,2,2};
    auto isEven{
    [](int i)
    {
        return ((i % 2)== 0);
    }};
    
    const auto iamEven{std::all_of(v.begin(), v.end(), isEven)};
    
    
    if(iamEven)
        std::cout<<" Yes even "<< std::endl;
        
    else
        std::cout<<" No I am not even "<< std::endl;
        
    
    //Lambda Example 3

    repeat(3, [](int i){
        std::cout << i << "\n";
    });
    
    
    //Lambda Example 4
    
    int x{10};
    
    auto decrement
    {
      [&x]() mutable // all values are captured by default as const, without mutable --x is Illegal // see the diff with and without & while capturing the x value
      {
          --x;
          std::cout <<"x val "<< x<< std::endl;
          
      }  
    };
    
    decrement();
    
    // Lambda x value is a copy of original x value // if you want lambda to operate on the same x capture the reference
    std::cout <<"x val "<< x << std::endl;
    
}
