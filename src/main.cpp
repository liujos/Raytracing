#include <iostream>
#include "include/Vec3.h"
#include "include/Ray.h"

f32 hit_sphere(const Vec3 &center, f32 radius, const Ray &r)
{
    Vec3 oc = r.origin() - center;
    f32 a = dot(r.direction(), r.direction());
    f32 b = 2.0 * dot(oc, r.direction());
    f32 c = dot(oc, oc) - radius * radius;
    f32 d = b*b - 4 * a * c;

    if (d >= 0)
        return (-b - sqrt(d)) / (2.0 * a);
    return -1.0;
}

Vec3 ray_color(const Ray &r)
{
    f32 t = hit_sphere(Vec3(0, 0, -1), 0.5, r);
    if (t >= 0) {
        Vec3 normal = normalize(r.location(t) - Vec3(0, 0, -1));
        return 0.5 * (normal + Vec3(1, 1, 1));
    }

        
    Vec3 dir = normalize(r.direction());
    f32 v = (dir.y + 1.0) / 2;
    return (1.0 - v) * Vec3(1, 1, 1) + v * Vec3(0.5, 0.7, 1.0);
}

int main()
{
    f32 aspect_ratio = 16.0 / 9.0;
    u32 image_width = 400;
    u32 image_height = image_width / aspect_ratio;

    if (image_height < 1)
        image_height = 1;

    f32 focal_length = 1.0;
    f32 viewport_height = 2.0;
    f32 viewport_width = viewport_height * ((f32) image_width / image_height);

    Vec3 v_width {viewport_width, 0, 0};
    Vec3 v_length {0, -viewport_height, 0};

    Vec3 pixel_width = v_width / image_width;
    Vec3 pixel_height = v_length / image_height;
    Vec3 camera_center {0, 0, 0};

    Vec3 viewport_top_left_corner = camera_center - Vec3(0, 0, focal_length) - v_width / 2 - v_length / 2;
    Vec3 first_pixel = viewport_top_left_corner + (pixel_width + pixel_height) / 2;

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int i = 0; i < image_height; i++) {
        std::clog << "\rScanlines remaining: " << (image_height - i) << " " << std::flush;
        for (int j = 0; j < image_width; j++) {
            Vec3 pixel = first_pixel + (j * pixel_width) + (i * pixel_height);
            Vec3 ray_direction = pixel - camera_center;
            Ray r {camera_center, ray_direction};

            Vec3 pixel_color = ray_color(r);

            u32 ir = 255 * pixel_color.x;
            u32 ig = 255 * pixel_color.y;
            u32 ib = 255 * pixel_color.z;

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    return 0;
}
