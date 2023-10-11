import std;

int main()
{
    auto triples{ std::views::iota(1) | std::views::transform([](int z) {
            return std::views::iota(1, z + 1) | std::views::transform([z](int x) {
                return std::views::iota(x, z + 1) | std::views::transform([x, z](int y) {
                    return std::views::repeat(std::tuple{ x, y, z }, x * x + y * y == z * z ? 1 : 0);
                }) | std::views::join;
            }) | std::views::join;
        }) | std::views::join
    };

    for (auto const& [x, y, z] : triples | std::views::take(20))
    {
        std::println("{}^2 + {}^2 == {}^2", x, y, z);
    }
}
