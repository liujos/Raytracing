#include <iostream>
#include "include/Vector3.h"

int main()
{
    u32 image_width = 256;
    u32 image_height = 256;

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int i = 0; i < image_height; ++i) {
        std::clog << "\rScanlines remaining: " << (image_height - i) << " " << std::flush;
        for (int j = 0; j < image_width; ++j) {
            Vector3 pixel = Vector3((f32) i / (image_width - 1), (f32) j / (image_height - 1), 0);

            u32 ir = 255 * pixel.x();
            u32 ig = 255 * pixel.y();
            u32 ib = 255 * pixel.z();

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    return 0;
}
