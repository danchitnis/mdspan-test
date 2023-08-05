#include <iostream>
#include <string>
#include <vector>

#include <mdspan.hpp>

namespace stdex = std::experimental;

int main()
{
    std::vector v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    stdex::mdspan m{v.data(), stdex::extents{6, 2}};

    std::cout << "extent is: " << m.extent(0) << " " << m.extent(1) << std::endl;

    std::cout << "ms2: " << m[0, 0] << std::endl;
    std::cout << "ms2: " << m[3, 5] << std::endl;

    for (std::size_t i = 0; i < m.extent(0); ++i)
    {
        for (std::size_t j = 0; j < m.extent(1); ++j)
        {
            std::cout << m[i, j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
