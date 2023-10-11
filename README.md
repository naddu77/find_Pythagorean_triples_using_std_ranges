# find_Pythagorean_triples_using_std_ranges
This code uses C++20 Standard Ranges Library to find Pythagorean triangles.
But it uses C++23 Standard Library Modules.

```C++
import std;

int main()
{
    auto triples{ std::views::iota(1) | std::views::transform([](int z) {
            return std::views::iota(1, z + 1) | std::views::transform([z](int x) {
                return std::views::iota(x, z + 1) | std::views::transform([x, z](int y) {
                    return std::views::single(std::tuple{ x, y, z }) | std::views::take(x * x + y * y == z * z ? 1 : 0);
                }) | std::views::join;
            }) | std::views::join;
        }) | std::views::join
    };

    for (auto const& [x, y, z] : triples | std::views::take(20))
    {
        std::println("{}^2 + {}^2 == {}^2", x, y, z);
    }
}
```

# Reference
https://ericniebler.com/2014/04/27/range-comprehensions/
